#include <unistd.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
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
    /* Any file on the filesystem in question */
    char *filename = (char *)"/";
    
    struct statvfs buf;
    if (!statvfs(filename, &buf)) 
    {
        double blksize, blocks, freeblks, disk_size, used, free;
        
        blksize = buf.f_bsize;
        blocks = buf.f_blocks;
        freeblks = buf.f_bfree;
        
        disk_size = blocks * blksize / (1024 * 1024 * 1024);
        free = freeblks * blksize / (1024 * 1024 * 1024);
        used = disk_size - free / (1024 * 1024 * 1024);
        
        return string_format("%.0fGB (%.0fGB free)", disk_size, free);
    }
    else
    {
        return "UNKNOWN";
    }
}