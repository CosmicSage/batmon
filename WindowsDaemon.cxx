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
        int AC = systemPower.ACLineStatus;

        // Alert User to Unplug device
        if (BatteryPercentage >= 26) {
          cout << "\nAC Status : " << static_cast<double>(systemPower.ACLineStatus)
          << "\nBattery Status : " << static_cast<double>(systemPower.BatteryFlag)
          << "\nBattery Life % : " << BatteryPercentage
          << "\n" << systemPower.BatteryFullLifeTime
          << endl;
          // while (!systemPower.ACLineStatus && x <= 10) {
          // while (!systemPower.ACLineStatus) {
          while (true) {
            // if () {
            SYSTEM_POWER_STATUS systemPower2;
            printf("%i\n", static_cast<int>(systemPower2.ACLineStatus));
            if (systemPower2.ACLineStatus != 0) {
              printf("\n\n\n\n\n\n\nbreaking\n\n\n\n\n\n\n\n");
              break;
            }
            printf("%i\n", systemPower.ACLineStatus);
            // printf("%i\n", systemPower.ACLineStatus);
            printf("%i\n", x);
            x++;
            //   break;
            //   // return 0;
            // }
            // Beep(523, 500);
          }
      }

      // Alert user to pluggin the device if battery low
      else if (BatteryPercentage <= 20) {
        std::cout << "Im batman" << '\n';
      }
    } else return 1;
      printf("%i\r", systemPower.ACLineStatus);
    }
}
// systemPower.BatteryLifePercent holds re

/*
List of todos
Import a C function to file
Add argvs to set trigger extremes
Send Notis
*/
