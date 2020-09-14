#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 100
#define CHAR_MIN '-'

void empilha(int *t, char P[MAX], int y){
  if (*t != MAX - 1) {
    (*t)++;
    P[*t] = y;
    }
  else
    printf("Pilha cheia!\n");
}


char desempilha(int *t, char P[MAX])
{
  char r;
  if (*t != -1) {
    r = P[*t];
    (*t)--;
  } else {
    r = CHAR_MIN;
    printf("Pilha vazia!\n");
  }
  return r;
}

int main(){
  setlocale(LC_ALL, "portuguese");

   char G[MAX];
   int t;
  //  int malFormada;

   t = -1;
  // malFormada = 0;

  char word[MAX];
  int i;

  printf("Digite a expressao: ");

  scanf("%s",word);
  fflush(stdin);

  for (i = 0; word[i] != '\0'; i++){
    if(word[i] == '[' || word[i] == '(' ){
      empilha(&t, G, word[i]);
    }
  }

  for (i = 0; G[i] != '\0'; i++){
      printf("%c", G[i]);
  }
  return 0;

}
