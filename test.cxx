#include <iostream>
#include <windows.h>
#include <typeinfo>
int main(int argc, char const *argv[]) {
  // Sleep(10 * 1000);
  // while(1) {
  //   // std::cout << "Batman" << '\n';
  //   Beep(175, 5000);
  //   Sleep(160*10);
  //   // Beep(523, 500);
  // }
  int xyz[] = {MB_ICONASTERISK,MB_ICONINFORMATION,MB_ICONWARNING,MB_ICONHAND,MB_ICONINFORMATION,MB_ICONQUESTION};
  for (size_t i = 0; i < 6; i++) {
    std::cout << typeid(xyz[i]).name() << "\t" << xyz[i] << "\n";
    int xxx = MessageBeep(xyz[i]);
    Sleep(3000);
    std::cout << xxx << '\n';
  }
  return 0;
}
