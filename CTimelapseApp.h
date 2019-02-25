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
        CStatusEntry* entries[10];
        int currentEntry;

        void setupDisplay();
        void setupButton();
        void buttonCallback();
        void nextEntry();
};