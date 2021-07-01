#include "message.h"
#include <iostream>
#include <windows.h>
#include <pthread.h>

using namespace std;

int alertx(void);
void * __cdecl messagex(void *number);
void * __cdecl playsound(void *filename);

// int main(void) {
//   alertx();
//   return 0;
// }

int alertx(void) {
  // do some error handling
  // Now threads
  pthread_t thread1, thread2;

  int f1 = pthread_create(&thread1, NULL, playsound, (void *)"/media/evac.wav");
  int f2 = pthread_create(&thread2, NULL, messagex, NULL);
  pthread_join(thread1, NULL);
  printf("%i\n", f1);
  return 0;
}

void * __cdecl messagex(void *number) {
  std::cout << "some variable" << IDCANCEL <<'\n';
  int msgboxID = MessageBox(NULL, "Something up with your charging", "BATMON", MB_ICONWARNING);
  return (void *)msgboxID;
}

void * __cdecl playsound(void* filename) {
  printf("Im Thread: %s\n", (char *)filename);
  PlaySound((char *)filename, NULL, 0);
  // fflush(stdout);
  return NULL;
}
