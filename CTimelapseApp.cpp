#include "ssd1306.h"
#include "CTimelapseApp.h"
#include "version.h"
#include <unistd.h>

CTimelapseApp::CTimelapseApp()
{
}

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
}

void CTimelapseApp::refreshStatusEntries()
{
    printf("refreshStatusEntries()\n");
}

void CTimelapseApp::refreshDisplay()
{
    printf("refreshDisplay()\n");
}

