#include "ssd1306.h"
#include "CTimelapseApp.h"
#include "CStatusVersion.h"
#include "version.h"
#include <unistd.h>

void CTimelapseApp::run()
{
    printf("Running TimelapseApp (version %s.%s.%s)\n", VERSION_MAJOR, VERSION_MINOR, VERSION_REV);

    setupDisplay();
    setupButton();
    loadStatusEntries();

    while(true)
    {
        refreshStatusEntries();
        refreshDisplay();
        usleep(1000 * 1000 * 10);
    }

}

void CTimelapseApp::setupDisplay()
{
    printf("setupDisplay()\n");
	//myDisplay.initDisplay();
}

void CTimelapseApp::setupButton()
{
    printf("setupButton()\n");
}

void CTimelapseApp::loadStatusEntries()
{
    printf("loadStatusEntries()\n");
    entries.push_back( std::unique_ptr<CStatusEntry>(new CStatusVersion) );

    for(size_t i = 0; i < entries.size(); i++)
    {
        entries[i]->configure();
    }
    
}

void CTimelapseApp::refreshStatusEntries()
{
    for(int i = 0; i < entries.size(); i++)
    {
        entries[i]->refreshStatus();
    }
}

void CTimelapseApp::refreshDisplay()
{
    printf("refreshDisplay()\n");
}

