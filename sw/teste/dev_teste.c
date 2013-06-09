#include <stdio.h>
#define ADDR (10*1024*1024)
#define DEV_ADDR (20*1024*1024)
int count=1;

int main(int argc, char *argv[]){
  volatile int *lock=ADDR;
  volatile int *dev=DEV_ADDR;
  if(*lock==0)
  {
	printf("proc %d\n",count);
	*dev=4;
	*dev=4;
	*dev=8;
	//*dev=5; //se nao colocar nada é 0
	printf("dev %d\n",*dev);
	count++;
	*lock=0;
	exit(0);
  }
  while(*lock);
  printf("proc %d\n",count);
  count++;
  *lock=0;
  exit(0); // To avoid cross-compiler exit routine
  return 0; // Never executed, just for compatibility
}

