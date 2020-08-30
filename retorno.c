#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int valueA;
  int valueB;
 
    printf("Digite valor A:");
    scanf("%d", &valueA);
    printf("Digite valor B:");
    scanf("%d", &valueB);

    printf("Resultado: %d", retorno(valueA, valueB));
}

int retorno(int valueA , int valueB){
   if(valueB == 0){
     return valueA;
   }
     else {
     return retorno(valueB, (valueA % valueB)) ;
   }
}
