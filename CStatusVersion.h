#ifndef CSTATUSVERSION_H
#define CSTATUSVERSION_H

#include "version.h"
//#include <unistd.h>
#include <stdio.h>
#include <string>
#include "CStatusEntry.h"

class CStatusVersion : public CStatusEntry {
    public:
        void configure();
        void refreshStatus();
        std::string getLabel();
        std::string getValue();
};

#endif