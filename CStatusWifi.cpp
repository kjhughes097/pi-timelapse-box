#include <unistd.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <fcntl.h>
#include <errno.h>
#include <linux/wireless.h>
#include "CStatusWifi.h"

#define IW_INTERFACE "wlan0"

extern int errno;
struct iwreq wreq;

void CStatusWifi::configure()
{
    printf("CStatusWifi->configure()\n");
}


void CStatusWifi::refreshStatus() { }

std::string CStatusWifi::getLabel()
{
    return "WIFI ";
}

std::string CStatusWifi::getValue()
{
    int sockfd;
    char * id;

    memset(&wreq, 0, sizeof(struct iwreq));
    sprintf(wreq.ifr_name, IW_INTERFACE);

    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        return "NOT FOUND1";
    }
    else
    {
        id = new char(IW_ESSID_MAX_SIZE+1);
        wreq.u.essid.pointer = id;
        if (ioctl(sockfd,SIOCGIWESSID, &wreq) == -1) {
            return "NOT FOUND2";
        }
        return string_format("%s", wreq.u.essid.pointer);
    }
}