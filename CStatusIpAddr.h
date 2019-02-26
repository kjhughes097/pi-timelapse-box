#ifndef CSTATUSIPADDR_H
#define CSTATUSIPADDR_H

#include "version.h"
#include <stdio.h>
#include <string>
#include "CStatusEntry.h"

class CStatusIpAddr : public CStatusEntry {
    public:
        void configure();
        void refreshStatus();
        std::string getLabel();
        std::string getValue();
};

#endif