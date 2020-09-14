#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 100
#define CHAR_MIN '-'

void empilha(int *t, char P[MAX], int y){
  if (*t != MAX - 1) {
    (*t)++;
    P[*t] = y;
    printf("\n push(%c) \n", y);
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
    printf("\n pop(%c) \n", r);

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
   int malFormada;

   t = -1;
   malFormada = 0;

  char word[MAX];
  int i;

  printf("Digite a expressão: ");

  scanf("%s",word);
  fflush(stdin);

  for (i = 0; word[i] != '\0' && malFormada == 0 ; i++){
    if(word[i] == '[' || word[i] == '(' ){
      empilha(&t, P, word[i]);
    }
    
    if( word[i] == ']'){
      if(desempilha(&t, P) != '['){      
        malFormada=1;
      };
    }
    else if( word[i] == ')'){
      if(desempilha(&t, P) == '('){
        malFormada=1;
      };
    }
    
  }
  if(malFormada || t != -1){
    printf("Expressão mal formada \n");
  }else{
    printf("Expressão bem formada \n");
  }  
  return 0;

}

