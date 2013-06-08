#include <stdio.h>
#define ADDR (10*1024*1024)
int main(int argc, char *argv[]){
  int i;
  volatile int *lock=ADDR;
  printf("comecou\n");
  for(i=0;i<10;i++)
    printf("Hi Marcus!\n");

  printf("fim\n");
  //*lock=0;
  if(*lock==0)
  {
	printf("lock livre\n");
  }else{
	printf("lock travado\n");
  }
  printf("tentando denovo\n");
  if(*lock==0)
  {
	printf("livre\n");
  }else{
	printf("lock travado\n");
  }
  printf("e se soltar ?\n");
  *lock=0;
  if(*lock==0)
  {
  	printf("lock livre\n");
  }else{
	printf("lock travado\n");
  }
  exit(0); // To avoid cross-compiler exit routine
  return 0; // Never executed, just for compatibility
}

