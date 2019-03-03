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
//#include <linux/wireless.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include "CStatusIpAddr.h"


#define IP_INTERFACE "wlan0"

void CStatusIpAddr::configure()
{
    printf("CStatusIpAddr->configure()\n");
}


void CStatusIpAddr::refreshStatus() { }

std::string CStatusIpAddr::getLabel()
{
    return "IP   ";
}

std::string CStatusIpAddr::getValue()
{
    char ip_address[15];
    int fd;
    struct ifreq ifr;
     
    /*AF_INET - to define network interface IPv4*/
    /*Creating soket for it.*/
    fd = socket(AF_INET, SOCK_DGRAM, 0);
     
    /*AF_INET - to define IPv4 Address type.*/
    ifr.ifr_addr.sa_family = AF_INET;
     
    /*eth0 - define the ifr_name - port name
    where network attached.*/
    memcpy(ifr.ifr_name, IP_INTERFACE, IFNAMSIZ-1);
     
    /*Accessing network interface information by
    passing address using ioctl.*/
    ioctl(fd, SIOCGIFADDR, &ifr);
    /*closing fd*/
    close(fd);
     
    /*Extract IP Address*/
    strcpy(ip_address,inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
     
    return string_format("%s", ip_address);
}