#include <stdio.h>
#include <stdlib.h>

const MAX = 5;

int main(){
  int values[MAX];
  int i;
  /* leitura das valores */
  for (i = 0; i < 5; i++)
  {
    printf("Digite os valores: ");
    scanf("%d", &values[i]);
  }
  printf("%d", maximum(5 , values));
}

 int maximum(int index, int arr[MAX]){
   int aux = 0;

   if(index == 1){
     return arr[0];
   }else {
     aux = maximum(index -1 , arr);
     if(aux > arr[index-1]){
       return aux;
     }else{
       return arr[index-1];
     }
   }
 };
 