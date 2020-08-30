#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int dividend;
  int divider;
    printf("Digite valor do dividendo: ");
    scanf("%d", &dividend);
    printf("Digite o valor do divisor: ");
    scanf("%d", &divider);

    printf("Resultado: %d", division(abs(dividend), abs(divider)));
}

int division(int dividend, int divider){
   if(divider == 0){
     return -1;
   }
   if(dividend < divider){
     return 0;
   }
   else if(dividend == divider){
     return 1;
   }
   else {
     return 1 + division(dividend - divider, divider);
   }
}
