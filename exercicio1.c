#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc , char *argv[]){
  int i, num, n;
  FILE *saida;

  if(argc != 3){
    fprintf(stderr, "Modo de uso: ./aleat n arquivo.bin \n");
    return 0;
  }

  n = atoi(argv[1]);

  saida = fopen(argv[2], "wb");

  if(saida == NULL){
    fprintf(stderr, "Erro ao abrir o arquivo %s\n", argv[2]);
    return 0;
  }

  srand(time(NULL));

  for(i=0 ; i < n ; i++){
    num = rand() % 100;
    fwrite(&num , sizeof(int),1 , saida);
  }

  fclose(saida);

  return 0;
}