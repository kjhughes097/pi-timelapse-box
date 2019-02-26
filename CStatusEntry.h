#ifndef CSTATUSENTRY_H
#define CSTATUSENTRY_H

#include <string>

class CStatusEntry
{
    public:
        virtual void configure() = 0;
        virtual void refreshStatus() = 0;
        virtual std::string getLabel() = 0;
        virtual std::string getValue() = 0;
};

#endif