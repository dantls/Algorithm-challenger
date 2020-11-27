#include <stdio.h>
#include "t2.h"

int main (int argc, char* argv[]){
  int value ,*baseValue , *current;

  if(argc != 2){
    fprintf(stderr, "Modo de uso: \n");
    return 0;
  }

  value = atoi(argv[1]);

  baseValue = allocate(value);



  return 0;
}