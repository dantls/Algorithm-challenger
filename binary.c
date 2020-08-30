#include <stdio.h>
#include <stdlib.h>

int main(){
  int value;
  /* leitura das valores */
    printf("Digite os valor: ");
    scanf("%d", &value);
    binary(value);
}

void binary(int n)
  {
    if (n != 0) {
    binary(n / 2);
    printf("%c", '0' + n % 2);
  }
}
