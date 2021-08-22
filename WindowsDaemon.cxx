#include <iostream>
#include <windows.h>
#include "message.h"
#include <chrono>
#include <thread>
void hide(void);

using namespace std;

int main(int argc, char *argv[]) {
    hide();
    SYSTEM_POWER_STATUS systemPower;
    int x = 0;
    // GEt Status
    while (true) {
      if( GetSystemPowerStatus(&systemPower) ) {

        // if (!WinToastLib::isCompatible()) {
        //   std::wcout << L"Error, your system is not supported" << std:endl;
        // }

        // All System Normal thus get battery percentage
        int BatteryPercentage = systemPower.BatteryLifePercent;
        int AC = systemPower.ACLineStatus;

        if (BatteryPercentage >= 86) {
          // if (!WinToastLib::isCompatible()) {
          //   std::wcout << L"Error, your system is not supported" << std:endl;
          // }
          cout << "\nAC Status : " << static_cast<double>(systemPower.ACLineStatus)
          << "\nBattery Status : " << static_cast<double>(systemPower.BatteryFlag)
          << "\nBattery Life % : " << BatteryPercentage
          << "\n" << systemPower.BatteryFullLifeTime
          << endl;
        }


        // Alert User to Unplug device
        if ((BatteryPercentage >= 86 && AC == 1) || (BatteryPercentage <= 20 && AC == 0)) {
          std::cout << "Im batman" << '\n' << BatteryPercentage << '\n';
          int sound_off = alertx(x);
          if (sound_off)
            Sleep(5 * 1000);
          x++;
        }

        // Alert user to pluggin the device if battery low
        // else if  {
        // std::cout << "Im batman" << '\n' << BatteryPercentage << '\n';
        //   alertx();
        // }

        else {
          // Sleep
          // Iterations to zero
          x = 0;
          // 60ms * 1000 * 5 = 300s
          Sleep(60 * 1000 * 5);
          // try {
          //   std::this_thread::sleep_for(std::chrono::milliseconds(x));
          // }
          // catch (std::exception& e) {
          //   std::cerr << e.what() << '\n';
          // }
          // Print Iterations
          printf("%i\r", x);
        }
    } else return 1;
      // printf("%i\r", systemPower.ACLineStatus);
    }
}
// systemPower.BatteryLifePercent holds re
void hide(void) {

  HWND stealth;
  AllocConsole();
  stealth = FindWindowA("ConsoleWindowClass", NULL);
  ShowWindow(stealth, 0);
}
/*
List of todos
Import a C function to file
Add argvs to set trigger extremes
Send Notis
*/
