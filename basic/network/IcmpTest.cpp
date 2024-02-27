#include "icmp/IcmpPing.h"


int main() {
    bool network_ok = icmp.icmpPing("10.41.233.1", "10.41.233.1");
    if (!network_ok) {
        printf("ping [%s] error !! \n", def.dst_rtp_ip);
    } else {
        printf("ping [%s] OK \n", def.dst_rtp_ip);
    }

    return 0;
}