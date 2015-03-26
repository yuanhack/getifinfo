#ifndef __YH_GETLOCALIP_H__
#define __YH_GETLOCALIP_H__

//#include <sys/socket.h>
#include <sys/ioctl.h>

#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <net/if.h>

#ifdef __cplusplus
extern "C"
{
#endif

int getLocalIp(struct sockaddr_in *paddr_in);

#ifdef __cplusplus
}
#endif
#endif /* __YH_GETLOCALIP_H__ */
