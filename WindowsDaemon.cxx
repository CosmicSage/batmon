#include <iostream>
#include <windows.h>

#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char *argv[]) {
    SYSTEM_POWER_STATUS systemPower;
    int x = 0;
    // GEt Status
    while (true) {
      if( GetSystemPowerStatus(&systemPower) ) {

        // All System Normal thus get battery percentage
        int BatteryPercentage = systemPower.BatteryLifePercent;
        int AC = systemPower.ACLineStatus;

        if (BatteryPercentage >= 86) {
          cout << "\nAC Status : " << static_cast<double>(systemPower.ACLineStatus)
          << "\nBattery Status : " << static_cast<double>(systemPower.BatteryFlag)
          << "\nBattery Life % : " << BatteryPercentage
          << "\n" << systemPower.BatteryFullLifeTime
          << endl;
        }


        // Alert User to Unplug device
        if (BatteryPercentage >= 86 && AC == 1) {
          Beep(175, 5000);
          Sleep(160*10);
        }

        // Alert user to pluggin the device if battery low
        else if (BatteryPercentage <= 21 && AC == 0) {
          std::cout << "Im batman" << '\n' << BatteryPercentage << '\n';
          Beep(175, 5000);
          Sleep(160*10);
        }

        else {
          // Sleep
          Sleep(60 * 1000);
          // try {
          //   std::this_thread::sleep_for(std::chrono::milliseconds(x));
          // }
          // catch (std::exception& e) {
          //   std::cerr << e.what() << '\n';
          // }
          // Print Iterations
          printf("%i\r", x);
        }
        x++;
    } else return 1;
      // printf("%i\r", systemPower.ACLineStatus);
    }
}
// systemPower.BatteryLifePercent holds re

/*
List of todos
Import a C function to file
Add argvs to set trigger extremes
Send Notis
*/
