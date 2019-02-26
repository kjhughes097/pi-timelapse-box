#include <unistd.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "CStatusDisk.h"


void CStatusDisk::configure()
{
    printf("CStatusDisk->configure()\n");
}


void CStatusDisk::refreshStatus() { }

std::string CStatusDisk::getLabel()
{
    return "DISK ";
}

std::string CStatusDisk::getValue()
{

    return "88GB of 99GB";     
}