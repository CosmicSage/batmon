#include "message.h"
#include <iostream>
#include <windows.h>

using namespace std;
int messagex(void) {
  std::cout << "some variable" << IDCANCEL <<'\n';
  int msgboxID = MessageBox(NULL, "Something up with your charging", "BATMON", MB_ICONWARNING);
  return msgboxID;
}

// int main(void) {
//   messagex();
//   return 0;
// }
