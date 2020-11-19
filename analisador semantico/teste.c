#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
  int ar[] ={5,1,1,1,1,1,1,1,1,1,1,1,1,1,-1}, i=0;
  int b[] = {2,2,2,2}, *t=ar+2;
  memcpy(t, b, 3*sizeof(int));
  while(ar[i]>0)
    printf("%d\n", ar[i++]);
 
  return 0;
}
/*
 (eepitch-shell)
 (eepitch-kill)
 (eepitch-shell)
gcc -o a teste.c
./a && rm a
  */
