#ifndef ICMP_PING_H
#define ICMP_PING_H

#include <string>

#include <fcntl.h>
// #include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>

#include <log/log.h>

namespace icmp {

class IcmpPing {
public:
    IcmpPing();
    ~IcmpPing();
    bool icmpPing(const char* srcIp, const char *dstIp);

private:
    int icmpSocket(const char* srcIp, const char *dstIp);
    int icmpDstAddr(const char* addrHost, struct sockaddr_in* dst_addr);
    uint16_t icmpGenChksum(uint16_t *data, int len);
    int icmpPkgPack(char *buffer, const char *data, int data_size);
    int icmpSendPkg(const char* ipv4, int socket, const char* data, int size);
    int icmpRecvPkg(int socket, char *recvbuf, int size);
    int icmpPkgUnpack(char* buf, int len);
};

} //namespace icmp

#endif