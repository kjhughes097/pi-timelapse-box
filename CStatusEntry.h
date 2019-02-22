struct CStatusEntry
{
    public:
        CStatusEntry();
        void refreshStatus();

    private:
        char *label = (char*)"BASE:";
        char *value = (char*)"UNKNOWN";
};