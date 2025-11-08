#include <stdio.h>
#include "resolve_dns.h"

int main(int argc, char *argv[]) {

    const char *hostname = "google.com";

    struct HostDetails *hd = resolve_dns(hostname);



    return 0;
}