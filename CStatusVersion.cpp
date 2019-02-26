#include "version.h"
#include <unistd.h>
#include <string>
#include "CStatusVersion.h"
#include "CStatusWifi.h"

void CStatusVersion::configure()
{
    printf("CStatusVersion->configure()\n");
}


void CStatusVersion::refreshStatus() { }

std::string CStatusVersion::getLabel()
{
    return "APP  ";
}

std::string CStatusVersion::getValue()
{
    return string_format("V%s.%s.%s",VERSION_MAJOR, VERSION_MINOR, VERSION_REV);
}
