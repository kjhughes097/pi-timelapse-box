#include "version.h"
#include <unistd.h>
#include <string>
#include "CStatusVersion.h"

void CStatusVersion::configure()
{
    printf("CStatusVersion->configure()\n");
}


void CStatusVersion::refreshStatus()
{
    printf("Running TimelapseApp (version %s.%s.%s)\n", VERSION_MAJOR, VERSION_MINOR, VERSION_REV);
}

std::string CStatusVersion::getLabel()
{
    return "APP ";
}

std::string CStatusVersion::getValue()
{
    sprintf("V %s.%s.%s",VERSION_MAJOR, VERSION_MINOR, VERSION_REV);
}
