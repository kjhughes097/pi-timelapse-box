#include "version.h"
#include <unistd.h>
#include <stdio.h>
#include <string>
#include "CStatusEntry.h"

class CStatusVersion : public CStatusEntry 
{
    void refreshStatus()
    {
        printf("Running TimelapseApp (version %s.%s.%s)\n", VERSION_MAJOR, VERSION_MINOR, VERSION_REV);
    }
};