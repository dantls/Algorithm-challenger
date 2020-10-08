#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 100
#define CHAR_MIN '\0'

#define NUMBER_OF_STRING 100
#define MAX_STRING_SIZE 300

int precedencia(char op) {
    switch (op) {

    case ';': 
      return -1;
      break;
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

    case '^': 
      return 3;
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

void posfixa(char * expression){

  char posfixa[MAX] = {},pilhaAux[MAX] = {} , aux;

  int topoPosfixa,topoAux, i;

  topoPosfixa = -1;
  topoAux = -1;

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

  printf("%s\n", posfixa); 

}

void imprime(int lenght, char iMatriz[][MAX_STRING_SIZE]) 
{
   int i;
   for (i=0; i < lenght; i++)
   {
      printf("%s\n", iMatriz[i]);
   }
}

int main(){
  setlocale(LC_ALL, "portuguese");

    FILE *ptArq;
    ptArq = fopen("entrada.txt", "r");

    int quantity ,i;
  
    fscanf(ptArq,"%d", &quantity);

    char expressions[quantity][MAX_STRING_SIZE];
    
    if(ptArq == NULL){
        printf("Ocorreu um problema ao abrir o arquivo.\n");
    }else{
        int t, j = 0 ;
        char linha[300];
        while(fgets(linha, 300, ptArq) != NULL){
          if (j == 0 ){
          }else{
            linha[strcspn(linha, "\n")] = 0;
            t = j-1;
            strcpy(expressions[t] , linha);
          }
          j++;

       }
        fclose(ptArq);
    }
    
    //imprime(quantity, expressions);

    int y;
    for (y= 0; y < 7; y++)
    {
     posfixa(expressions[y]);
    }

    //posfixa(expressions[0]);
    //posfixa(expressions[1]);
    //posfixa(expressions[2]);
    //posfixa(expressions[4]);
    
  return 0;

}


