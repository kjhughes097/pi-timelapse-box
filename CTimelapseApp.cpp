#include <unistd.h>
#include "ssd1306.h"
#include "CTimelapseApp.h"
#include "CStatusVersion.h"
#include "CStatusWifi.h"
#include "CStatusIpAddr.h"
#include "CStatusDisk.h"

void CTimelapseApp::run()
{
    printf("Running TimelapseApp\n");

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
    entries.push_back( std::unique_ptr<CStatusEntry>(new CStatusWifi) );
    entries.push_back( std::unique_ptr<CStatusEntry>(new CStatusIpAddr) );
    entries.push_back( std::unique_ptr<CStatusEntry>(new CStatusDisk) );

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
        for(int i = 0; i < entries.size(); i++)
    {
        printf("%s: %s\n", entries[i]->getLabel().c_str(), entries[i]->getValue().c_str());
    }
}

