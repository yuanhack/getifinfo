#include "getifaddr.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char ip[46];
    char err[256];

    if (argc != 3) {
        printf("usage: %s <interface name> <mode>\n", argv[0]);
        printf("  mode value: 4 or 6\n");
        printf("  mode 4: IPv4\n");
        printf("  mode 6: IPv6\n");
        return 1;
    }

    int mode = atoi(argv[2]); 
    if (mode != 4 && mode != 6) {
        printf("%s mode error: %s\n", argv[0], argv[2]);
        return 1;
    }
    mode = mode == 4 ? AF_INET :AF_INET6;

    if (getifaddr(argv[1], mode, ip, sizeof(ip), err, sizeof(err)) < 0) {
        printf("%s\n", err);
        return 1;
    }
    printf("%s\n", ip);
    return 0;
}
