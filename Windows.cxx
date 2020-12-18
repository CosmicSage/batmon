#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char *argv[]) {
    SYSTEM_POWER_STATUS spsPwr;
    if( GetSystemPowerStatus(&spsPwr) ) {
        cout << "\nAC Status : " << static_cast<double>(spsPwr.ACLineStatus)
             << "\nBattery Status : " << static_cast<double>(spsPwr.BatteryFlag)
             << "\nBattery Life % : " << static_cast<double>(spsPwr.BatteryLifePercent)
             << endl;
        return 0;
    } else return 1;
}
spsPwr.BatteryLifePercent holds re
