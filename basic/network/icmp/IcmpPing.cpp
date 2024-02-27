#include <unistd.h>

#include "IcmpPing.h"

namespace icmp {

#ifndef offsetof
#define offsetof(type, member)    ((int) & ((type*)0) -> member )
#endif

#define ICMP_BUF_SIZE           256
#define ICMP_RECVBUF_SIZE       (50 * 1024)

#define ICMP_PROTO_NAME         "icmp"
#define ICMP_DATA               "my ICMP Ping"

#define ICMP_PING_SUCC          0
#define ICMP_PING_FAIL          -1

#define ICMP_LOG(fmt...)        printf(fmt);

#define ICMP_LOG_ERR(fmt...)       printf(fmt);

#define ICMP_PKG_CHKSUM_OFFSET  offsetof(struct icmp, icmp_cksum)
#define ICMP_PKG_CHKSUM_SIZE    2
#define ICMP_PING_COUNT         4

IcmpPing::IcmpPing() {
}

IcmpPing::~IcmpPing() {
}

int IcmpPing::icmpSocket(const char* srcIp, const char* dstIp) {
    int sockfd;
    int size = ICMP_RECVBUF_SIZE;

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
           usleep(1000);
        if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
            ALOGE("creat socket failed %d, %s", errno, strerror(errno));
            return -1;
        }
    }

    //过滤响应来源地址，绑定来源IP
    {
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(struct sockaddr_in));
        addr.sin_family = AF_INET;
        addr.sin_port = 0;
        addr.sin_addr.s_addr = inet_addr(srcIp);
        int32_t ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in));
        if (ret < 0) {
            ALOGE("bind rtp server failed, ret = %d, %s", errno, strerror(errno));
            close(sockfd);
            return -1;
        }
    }

    {
        struct sockaddr_in serv_addr;
        uint32_t ul = 1;

        ioctl(sockfd, FIONBIO, &ul); //设置为非阻塞模式

        memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
        serv_addr.sin_family = AF_INET;  //使用IPv4地址
        serv_addr.sin_addr.s_addr = inet_addr(dstIp);  //具体的IP地址
        serv_addr.sin_port = htons(1234);  //端口随意填写

        // 将套接字和IP、端口绑定
        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
            struct timeval tm;
            fd_set set;
            int error=-1, len;

            len = sizeof(int);
            tm.tv_sec = 1;
            tm.tv_usec = 0;
            FD_ZERO(&set);
            FD_SET(sockfd, &set);
            if (select(sockfd+1, NULL, &set, NULL, &tm) > 0) {
                getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, (socklen_t *)&len);
                if (error != 0) {
                    ALOGE("connect[%s] socket failed", dstIp);
                    close(sockfd);
                    return -1;
                }
            } else {
                ALOGE("connect[%s] socket failed", dstIp);
                close(sockfd);
                return -1;
            }
        }
        ul = 0;
        ioctl(sockfd, FIONBIO, &ul); //设置为阻塞模式
    }
    //设置接收buf大小
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &size, sizeof(size)) != 0) {
        ALOGE("setsockopt SO_RCVBUF error.\n\r");
        close(sockfd);
        return -1;
    }

    //设置超时时间，影响后面revform函数，让其不会一直阻塞
    struct timeval icmp_wait_timeout = { 0, 100000 }; //sec
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*)&icmp_wait_timeout, sizeof(struct timeval)) != 0) {
        ALOGE("setsockopt SO_RCVTIMEO error.\n\r");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

uint16_t IcmpPing::icmpGenChksum(uint16_t *data, int len) {
    int nleft = len;
    int sum = 0;
    uint16_t *w = data;
    uint16_t answer = 0;

    while (nleft > 1) {
        sum += *w++;
        nleft -= 2;
    }

    if (nleft == 1) {
        *(uint8_t *)(&answer) = *(uint8_t *)w;
        sum += answer;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = ~sum;

    return answer;
}

int IcmpPing::icmpPkgPack(char* buffer, const char* data, int data_size) {
    int packsize = 0;
    struct icmp icmp;
    (void)memset(&icmp, 0, sizeof(icmp));
    icmp.icmp_type = ICMP_ECHO;
    icmp.icmp_code = 0;
    icmp.icmp_cksum = 0;
    icmp.icmp_seq = htons(0);
    icmp.icmp_id = 0xff00;

    gettimeofday((struct timeval *)&icmp.icmp_data, NULL);
    memcpy(buffer, &icmp, sizeof(struct icmp));
    packsize += sizeof(struct icmp);

    if (data && data_size) {
        memcpy(buffer + packsize, data, data_size);
        packsize += data_size;
    }

    return packsize;
}

int IcmpPing::icmpDstAddr(const char* addrHost, struct sockaddr_in* dst_addr) {
    struct hostent *host = NULL;
    uint32_t inaddr = 0;

    bzero(dst_addr, sizeof(struct sockaddr_in));
    dst_addr->sin_family = AF_INET;

    if ((inaddr = inet_addr(addrHost)) == INADDR_NONE) {
        if ((host = gethostbyname(addrHost)) == NULL) {
            ALOGE("gethostbyname error.\n\r");
            return -1;
        }
        memcpy((char *)&dst_addr->sin_addr, host->h_addr, host->h_length);
    }
    else {
        memcpy((char *)&dst_addr->sin_addr, (char *) &inaddr, sizeof(dst_addr->sin_addr));
    }

    return 0;
}

int IcmpPing::icmpSendPkg(const char* ipv4, int socket, const char* data, int size) {
    int packetsize;
    unsigned short checksum = 0;
    int n = 0;
    struct sockaddr_in dst_addr;
    char pkg_buffer[ICMP_BUF_SIZE];

    packetsize = icmpPkgPack(pkg_buffer, data, size);
    checksum = icmpGenChksum((uint16_t *)pkg_buffer, packetsize);

    icmpDstAddr(ipv4, &dst_addr);
    memcpy(pkg_buffer + ICMP_PKG_CHKSUM_OFFSET, &checksum, ICMP_PKG_CHKSUM_SIZE);
    if ((n = sendto(socket, pkg_buffer, packetsize, 0, (struct sockaddr *) &dst_addr, sizeof(struct sockaddr_in)))< 0) {
        ALOGE("send icmp failed = %d\n", n);
        return 0;
    }

    return n;
}

int IcmpPing::icmpRecvPkg(int socket, char* recvbuf, int size) {
    int n;
    socklen_t fromlen;
    struct sockaddr_in from_addr;

    fromlen = sizeof(struct sockaddr_in);
    if((n = recvfrom(socket, recvbuf, size, 0, (struct sockaddr *) &from_addr, &fromlen)) < 0) {
        ALOGE("recvfrom error.n = %d errno=%d strerror(%s)\n\r", n, errno, strerror(errno));
        return 0;
    }
    return n;
}

int IcmpPing::icmpPkgUnpack(char* buf, int len) {
    int iphdrlen;
    struct ip* ip = NULL;
    struct icmp* icmp = NULL;

    if (buf == NULL) {
        return -1;
    }
    ip = (struct ip *)buf;
    iphdrlen = ip->ip_hl << 2;
    icmp = (struct icmp*)(buf + iphdrlen);
    len -= iphdrlen;

    if (len < 8) {
        ALOGE("ICMP packet\'s length is less than 8\n\r");
        return - 1;
    }
    if (icmp->icmp_type != ICMP_ECHOREPLY && icmp->icmp_type != ICMP_ECHO) {
        ALOGE("ICMP icmp_type = %d %d\n\r", icmp->icmp_type, ICMP_ECHOREPLY);
        return - 1;
    }
    return 0;
}

bool IcmpPing::icmpPing(const char* srcIp, const char *dstIp) {
    int pingOkCount = 0;
    char pkg_buffer[ICMP_BUF_SIZE];
    int ping_socket = 0;
    int count = ICMP_PING_COUNT;

    ping_socket = icmpSocket(srcIp, dstIp);
    if(ping_socket < 0) {
        return false;
    }
    do {
        int n = icmpSendPkg(dstIp, ping_socket, ICMP_DATA, sizeof(ICMP_DATA));
        if (n < 8) {
            break;
        }
        n = icmpRecvPkg(ping_socket, pkg_buffer, ICMP_BUF_SIZE);
        if (n < 8) {
            break;
        }
        if (icmpPkgUnpack(pkg_buffer, n) == 0) {
            pingOkCount++;
        }

    } while (--count > 0);
    close(ping_socket);

    return (pingOkCount>0?true:false);
}

}