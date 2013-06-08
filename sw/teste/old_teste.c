#include <stdio.h>
#define ADDR (10*1024*1024)

int count=1;

int main(int argc, char *argv[]){
  volatile int *lock=ADDR;
  while(*lock);
  printf("proc %d\n",count);
  count++;
  *lock=0;
  exit(0); // To avoid cross-compiler exit routine
  return 0; // Never executed, just for compatibility
}

