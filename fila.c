#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 5
#define INT_MIN -999

void enfileira(int *i, int *f, int F[MAX], int y){
  if (*f != *i || *f == -1) {
      if (*f == -1) {
      *i = 0;
      *f = 0;
    }
    F[*f] = y;
    *f = (*f + 1) % MAX;
  }
  else
    printf("Fila cheia!\n");
}


int desenfileira(int *i, int *f, int F[MAX]){
  int r = INT_MIN;
    if (*i != -1) {
     r = F[*i];
     *i = (*i + 1) % MAX;
    if (*i == *f) {
      *i = -1;
      *f = -1;
    }
  }
  else
    printf("Fila vazia!\n");
  return r;
}

int main(){
  setlocale(LC_ALL, "portuguese");

  int *ini, *fim, F[MAX] , input,count,value,option;
  ini = 0;
  fim = 0;
  count = 0;
  input = 0;
  value = 0;
  option = 0;
  

  while(input != 5 ){
    fflush(stdin);
    printf("1 - Enfileira \n");
    printf("2 - Desenfileira \n");
    printf("3 - Mostrar \n");
    printf("5 - Sair \n");

    printf("Digite a opção: ");
    scanf("%d", &input);

    if (input == 1)
    {
      printf("Digite a fila: ");
      scanf("%d", &value);
        enfileira(ini, fim, F, value);
      printf("\n enfileira(%d) \n", value);
    }else if (input == 2) {
        printf("\n desenfileira(%d) \n", desenfileira(ini,fim, F));

    }else if (input == 3) {
      // while(*i == *f && *f != 1 ){
      //   printf("%d \n", desenfileira(i,f, F));
      //   *f = (*f + 1) % MAX;
      // }
    }
    else {
      input = 5;
    }
      
  }
  return 0;
}

