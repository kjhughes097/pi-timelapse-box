#ifndef CSTATUSWIFI_H
#define CSTATUSWIFI_H

#include "version.h"
#include <stdio.h>
#include <string>
#include "CStatusEntry.h"

class CStatusWifi : public CStatusEntry {
    public:
        void configure();
        void refreshStatus();
        std::string getLabel();
        std::string getValue();
};

#endif