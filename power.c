#include <stdio.h>
#include <stdlib.h>

int main(){
  int base;
  int exponent;
    printf("Digite valor da Base: ");
    scanf("%d", &base);
    printf("Digite o valor do Expoente: ");
    scanf("%d", &exponent);

    printf("Resultado: %d",  power(base, exponent));
}

int power(int base, int exponent){
    if ((base == 1) || (exponent == 1 )){
      return base;
    }else {
      return base * (power(base,exponent-1));
    }
  
}