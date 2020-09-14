#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 10
#define CHAR_MIN '\0'

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
  
  char P[MAX];
  int t;
  int palindromo;

  t = -1;
  palindromo = 1;

  char word[MAX], aux;
  int i;

  fflush(stdin);
  printf("\n Digite uma palavra:");
  gets(word);


  for (i = 0; word[i] != '\0'; i++)
  {
    empilha(&t, P, word[i]);
  }
  for (i = 0; word[i] != '\0' && palindromo == 1; i++)
  {
    aux = desempilha(&t, P);
    if(word[i] != aux){
      printf("Não é palindromo");
      palindromo = 0;
    }
  }
  if(palindromo){
    printf("É palindromo");
  }

  return 0;

}