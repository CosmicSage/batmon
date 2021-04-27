#include <iostream>
#include <windows.h>

int main(int argc, char const *argv[]) {
  // Sleep(10 * 1000);
  while(1) {
    // std::cout << "Batman" << '\n';
    Beep(175, 5000);
    Sleep(160*10);
    // Beep(523, 500);
  }
  return 0;
}
