#include "resolve_dns.h"
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>


struct HostDetails *resolve_dns(const char *host) {

    struct addrinfo hints, *result, *rp;
    memset(&hints, 0, sizeof(hints));


    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    const int s = getaddrinfo(host, NULL, &hints, &result);
    if (s != 0) {
        return NULL;
    }


    struct HostDetails *details = malloc(sizeof(struct HostDetails));
    details->host = host;

    for (rp = result; rp != NULL; rp = rp->ai_next) {

        switch (rp->ai_family) {
            case AF_INET:
                details->ipv4 = inet_ntoa(((struct sockaddr_in *)rp->ai_addr)->sin_addr);
                break;
            case AF_INET6:
                struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)rp->ai_addr;
                char ipstr[INET6_ADDRSTRLEN];
                void *addr_ptr =  &(ipv6->sin6_addr);

                inet_ntop(rp->ai_addr->sa_family, addr_ptr, ipstr, sizeof(ipstr));

                details->ipv6 = ipstr;

                break;
            default:
                printf("Unknown address family\n");

        }
    }

    freeaddrinfo(result);

    return details;
}

