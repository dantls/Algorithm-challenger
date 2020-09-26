#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

  char answer[argc];
  float sum = 0;
  int total = argc-2;
  float average = 0;
  FILE *arquivo;


  if (argc>2){
    
    int i;
    for(i=2; i<argc ; i++){
       strcat(answer,argv[i]);
       strcat(answer," ");
       sum +=  atof(argv[i]);
    }

    average = sum/total;

    arquivo = fopen(argv[1], "w");

    if(arquivo != NULL){
      fprintf(arquivo,"Valores informados: %s \n", answer);
      fprintf(arquivo,"Quantidade de valores: %d \n", total);
      fprintf(arquivo,"Soma total: %.2f \n", sum);
      fprintf(arquivo,"Media: %.2f \n", average);

      fclose(arquivo);
    }
    
  }else {
    arquivo = fopen(argv[1], "w");

    if(arquivo != NULL){
      fprintf(arquivo,"Valores informados: %s \n", answer);
      fprintf(arquivo,"Quantidade de valores: %d \n", total);
      fprintf(arquivo,"Soma total: %.2f \n", sum);
      fprintf(arquivo,"Media: %.2f \n", average);

      fclose(arquivo);
    }
  }
  return 0;
}


