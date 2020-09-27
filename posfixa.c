#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 100
#define CHAR_MIN '\0'


int precedencia(char op) {
    switch (op) {

    case '(': 
      return 0;
      break;

    case '+': 
    case '-':
      return 1;
      break;

    case '*': 
    case '/': 
      return 2;
      break;
  }
}

void empilha(int *t, char P[MAX], char y){
  if (*t != MAX - 1) {
    (*t)++;
    P[*t] = y;
    }
  else
    printf("Pilha cheia!\n");
}

char desempilha(int *t, char P[MAX]){
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
  
  char posfixa[MAX],pilhaAux[MAX] , aux;
 
  int topoPosfixa,topoAux;

  topoPosfixa = -1;
  topoAux = -1;


  char expression[MAX];
  int i;

  printf("\nDigite a expressao:");
  scanf("%[^\n]", expression);


  for (i = 0; expression[i] != '\0'; i++){

      if ('0' <= expression[i] && expression[i] <= '9'){
        empilha(&topoPosfixa, posfixa, expression[i]); 
      }else{
        switch ( expression[i] )
        {
          case '(' :
            empilha(&topoAux, pilhaAux, expression[i]);
          break;

          case ')' :
            do{
              aux = desempilha(&topoAux, pilhaAux);
              if(aux != '(')
              empilha(&topoPosfixa, posfixa, aux);
            }while(aux != '(');
          break;
          
          default : 
            while(topoAux != -1 &&  precedencia(expression[i]) <= precedencia(pilhaAux[topoAux])){
                aux = desempilha(&topoAux, pilhaAux);
                empilha(&topoPosfixa, posfixa, aux);
            };
            empilha(&topoAux, pilhaAux, expression[i]);
          break;
        }
      }
  }
  while (topoAux != -1)
     empilha(&topoPosfixa, posfixa, desempilha(&topoAux, pilhaAux));

  printf("Expressao Infixa: %s\n", expression);
  printf("Expressao Posfixa: %s\n", posfixa); 

  return 0;

}