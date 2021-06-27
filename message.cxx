#include "message.h"
#include <iostream>
#include <windows.h>
#include <pthread.h>
#include <_ptw32.h>
using namespace std;

void playsound(void *soundfile);
int alertx(void);
int messagex(void);

void * __cdecl play(void *filename) {
  printf("Im Thread\n");
  return filename;
}


int main(void) {
  alertx();
  return 0;
}

int alertx(void) {
  // do some error handling
  // Now threads
  pthread_t thread1;

  int f1 = pthread_create(&thread1, NULL, play, NULL);
  printf("%i\n", f1);
  return 0;
}

int messagex(void) {
  std::cout << "some variable" << IDCANCEL <<'\n';
  int msgboxID = MessageBox(NULL, "Something up with your charging", "BATMON", MB_ICONWARNING);
  return msgboxID;
}

void playsound(void *soundfile) {
  printf("%s\n", soundfile);
}
