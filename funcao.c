#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int value;
 
    printf("Digite valor:");
    scanf("%d", &value);

    printf("Resultado: %d", funcao(value));
}

int funcao(int value){
   if(value < 2){
     return value;
   }
     else {
     return funcao(value-1) + funcao(value-2);
   }
}
