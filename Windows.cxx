#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char *argv[]) {
    SYSTEM_POWER_STATUS systemPower;
    int x = 1;
    // GEt Status
    while (true) {
      if( GetSystemPowerStatus(&systemPower) ) {
        if (systemPower.BatteryLifePercent <= 53) {
          cout << "\nAC Status : " << static_cast<double>(systemPower.ACLineStatus)
          << "\nBattery Status : " << static_cast<double>(systemPower.BatteryFlag)
          << "\nBattery Life % : " << static_cast<double>(systemPower.BatteryLifePercent)
          << "\n" << systemPower.BatteryFullLifeTime
          << endl;
          return 0;

      }
    } else return 1;
      printf("%i\r", systemPower.BatteryLifePercent);
    }
}
// systemPower.BatteryLifePercent holds re
