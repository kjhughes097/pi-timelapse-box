#ifndef CTIMELAPSE_H
#define CTIMELAPSE_H

#include <vector>
#include <memory>
#include "CStatusEntry.h"

class CTimelapseApp
{
    public:
//        CTimelapseApp();
        void run();
        void loadStatusEntries();
        void refreshStatusEntries();
        void refreshDisplay();
        void shortPress();
        void longPress();

    private:
        SSD1306 myDisplay;
        std::vector<std::unique_ptr<CStatusEntry> > entries;
        int currentEntry;

        void setupDisplay();
        void setupButton();
        void buttonCallback();
        void nextEntry();
};

#endif