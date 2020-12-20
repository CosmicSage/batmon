#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char *argv[]) {
    SYSTEM_POWER_STATUS systemPower;
    int x = 1;
    // GEt Status
    while (true) {
      if( GetSystemPowerStatus(&systemPower) ) {

        // All System Normal thus get battery percentage
        int BatteryPercentage = systemPower.BatteryLifePercent;

        // Alert User to Unplug device
        if (BatteryPercentage >= 49) {
          cout << "\nAC Status : " << static_cast<double>(systemPower.ACLineStatus)
          << "\nBattery Status : " << static_cast<double>(systemPower.BatteryFlag)
          << "\nBattery Life % : " << static_cast<double>(systemPower.BatteryLifePercent)
          << "\n" << systemPower.BatteryFullLifeTime
          << endl;
          while (true) {
            if (systemPower.ACLineStatus == 1) {
              /* code */
              cout << "\a";
              break;
              // return 0;
            }
            Beep(523, 500);
          }
      }

      // Alert user to pluggin the device if battery low
      else if (BatteryPercentage <= 20) {
        std::cout << "Im batman" << '\n';
      }
    } else return 1;
      printf("%i\r", systemPower.BatteryLifePercent);
    }
}
// systemPower.BatteryLifePercent holds re

/*
List of todos
Import a C function to file
Add argvs to set trigger extremes
Send Notis
*/
