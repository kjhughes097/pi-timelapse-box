#include "CStatusEntry.h"
#include <stdio.h>
#include <string.h>

CStatusEntry::CStatusEntry()
{
}

void CStatusEntry::refreshStatus()
{
    printf("refreshing Status for %s : Value is %s\n", label, value);
}
