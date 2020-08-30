#include <stdio.h>
#include <stdlib.h>

int main(){
  int value = 0;
  /* leitura das valores */
    printf("Digite os valores: ");
    scanf("%d", &value);
  
  printf("O valor de fibonacci: %d", fibonacci(value));
}

 int fibonacci(int value){
   if( (value == 1 ) || (value == 2 )){
      return 1;
   }else {
     return fibonacci(value-1) + fibonacci(value-2); 
   }
 };
 