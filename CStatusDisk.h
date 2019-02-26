#ifndef CSTATUSDISK_H
#define CSTATUSDISK_H

#include "version.h"
#include <stdio.h>
#include <string>
#include "CStatusEntry.h"

class CStatusDisk : public CStatusEntry {
    public:
        void configure();
        void refreshStatus();
        std::string getLabel();
        std::string getValue();
};

#endif