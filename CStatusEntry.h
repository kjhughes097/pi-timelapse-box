#include <string>

class CStatusEntry
{
    public:
        virtual void refreshStatus() = 0;
        virtual std::string getLabel() = 0;
        virtual std::string getValue() = 0;
};
