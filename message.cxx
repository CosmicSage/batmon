#include "message.h"
#include <iostream>
#include <windows.h>
#include <pthread.h>

using namespace std;

int alertx(void);
int messagex(void);
void * __cdecl playsound(void* filename);

int main(void) {
  alertx();
  return 0;
}

int alertx(void) {
  // do some error handling
  // Now threads
  pthread_t thread1;

  int f1 = pthread_create(&thread1, NULL, playsound, (void *)"media/evac.wav");
  pthread_join(thread1, NULL);
  printf("%i\n", f1);
  return 0;
}

int messagex(void) {
  std::cout << "some variable" << IDCANCEL <<'\n';
  int msgboxID = MessageBox(NULL, "Something up with your charging", "BATMON", MB_ICONWARNING);
  return msgboxID;
}

void * __cdecl playsound(void* filename) {
  printf("Im Thread: %s\n", (char *)filename);
  PlaySound((char *)filename, NULL, 0);
  // fflush(stdout);
  return NULL;
}
