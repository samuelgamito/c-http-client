#ifndef C_HTTP_CLIENT_RESOLVE_DNS_H
#define C_HTTP_CLIENT_RESOLVE_DNS_H

struct HostDetails {
    char *host;
    char *ipv4;
    char *ipv6;
};


struct HostDetails *resolve_dns(const char *host);

#endif //C_HTTP_CLIENT_RESOLVE_DNS_H