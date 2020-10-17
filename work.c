#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX 100
#define CHAR_MIN '\0'
#define NUMBER_OF_STRING 100
#define MAX_STRING_SIZE 300

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
void empilhaInt(int *t, int P[MAX], int y){
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
int desempilhaInt(int *t, int P[MAX]){
  int r;
  if (*t != -1) {
    r = P[*t];
    (*t)--;
  } else {
    r = CHAR_MIN;
    printf("Pilha vazia!\n");
  }
  return r;
}

char * posfixa(char *expression)
{

    char posfixa[MAX] = {}, pilhaAux[MAX] = {}, aux;

    int topoPosfixa, topoAux, i;

    topoPosfixa = -1;
    topoAux = -1;

    for (i = 0; expression[i] != '\0'; i++)
    {

        if (isdigit(expression[i]))
        {
            empilha(&topoPosfixa, posfixa, expression[i]);
        }
        else
        {
            empilha(&topoPosfixa, posfixa, ' ');
            switch (expression[i])
            {
            case '(':
                empilha(&topoAux, pilhaAux, expression[i]);
                break;
            case ')':
                do
                {
                    aux = desempilha(&topoAux, pilhaAux);
                    if (aux != '('){
                        empilha(&topoPosfixa, posfixa, aux);
                    }
                } while (aux != '(');
                break;
            default:
                while (topoAux != -1 && precedencia(expression[i]) <= precedencia(pilhaAux[topoAux]))
                {
                    aux = desempilha(&topoAux, pilhaAux);
                    empilha(&topoPosfixa, posfixa, aux);
                };
        

                empilha(&topoAux, pilhaAux, expression[i]);
                break;
            }
        }
    }
    while (topoAux != -1)
    {
        empilha(&topoPosfixa, posfixa, ' ');
        empilha(&topoPosfixa, posfixa, desempilha(&topoAux, pilhaAux));

    }
    
    strcpy(expression , posfixa);
    
    return expression; 
}


int calculaPosfixa(char expression[][MAX_STRING_SIZE]){

  printf("Expressao dentro da calcula: %s\n", expression[0]);
  printf("Expressao dentro da calcula: %s\n", expression[1]);
  printf("Expressao dentro da calcula: %s\n", expression[2]);

  int var1 , var2, i, j ,  result;

  char pilhaAux[MAX] = {};
  int pilhaAuxInt[MAX] = {};

  char ax2,ax1,teste;

  int topoAux,topoAuxInt,aux1,aux2;
        int resultado = 0;


  topoAux = -1;
  topoAuxInt = -1;
  var1 = 0;
  var2 = 0;
  result = 0;

    for (i = 0; strcmp(expression[i] ,"\0") != 0; i++){
      
            if (strcmp(expression[i] ,"*") == 0){

                  var1 = desempilhaInt(&topoAuxInt, pilhaAuxInt);
                  var2 = desempilhaInt(&topoAuxInt, pilhaAuxInt);
                  result = var1 * var2;
                  empilhaInt(&topoAuxInt,pilhaAuxInt,result);
            }
            // else if (strcmp(expression[i] ,"^") == 0){

            //       var1 = desempilhaInt(&topoAuxInt, pilhaAuxInt);
            //       var2 = desempilhaInt(&topoAuxInt, pilhaAuxInt);
            //       result = var1 * var2;
            //       empilhaInt(&topoAuxInt,pilhaAuxInt,result);

            //       printf("%d", result);
            // }
            else if (strcmp(expression[i] ,"-") == 0){
                  var1 = desempilhaInt(&topoAuxInt, pilhaAuxInt);
                  var2 = desempilhaInt(&topoAuxInt, pilhaAuxInt);
                  result =  var2 - var1;
                  empilhaInt(&topoAuxInt,pilhaAuxInt,result);
                 
            }else if (strcmp(expression[i] ,"+") == 0){

                  var1 = desempilhaInt(&topoAuxInt, pilhaAuxInt);
                  var2 = desempilhaInt(&topoAuxInt, pilhaAuxInt);
                  result =  var2 + var1;
                  empilhaInt(&topoAuxInt,pilhaAuxInt,result);
           
            }else if (strcmp(expression[i] ,"/") == 0){
                  var1 = desempilhaInt(&topoAuxInt, pilhaAuxInt);
                  var2 = desempilhaInt(&topoAuxInt, pilhaAuxInt);
                  result =  var2 / var1;
                  empilhaInt(&topoAuxInt,pilhaAuxInt,result);

            }else{
              empilhaInt(&topoAuxInt,pilhaAuxInt,atoi(expression[i]));
            } 
     
    }
    return desempilhaInt(&topoAuxInt, pilhaAuxInt);

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


  /* 
    Envia expressão lida do arquivo
  */

  printf("Expressao na main lida pelo arquivo : %s\n", expressions[0]);
  printf("Expressao na main lida pelo arquivo : %s\n", expressions[1]);
  printf("Expressao na main lida pelo arquivo : %s\n", expressions[2]);




  /* 
    Envia expressão para o calculaPosfixa e imprime resultado
  */

  char expression[NUMBER_OF_STRING][MAX_STRING_SIZE] = {"20","4","*","\0"};
  printf("Expressao na main : %s\n", expression[0]);
  printf("Expressao na main : %s\n", expression[1]);
  printf("Expressao na main : %s\n", expression[2]);
  printf("%d\n", calculaPosfixa(expression));


  /* 
    Gera Posfixa
  */

   char expressaoPosfixa[300];
   strcpy (expressaoPosfixa, posfixa(expressions[4]));
   printf("Resultado posfixa: %s", expressaoPosfixa);
   
  return 0;

}














































