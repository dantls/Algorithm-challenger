#include <stdio.h>

int main(int argc , char *argv[]){
  int num , qtd;
  FILE *entrada;

  if(argc != 2){
    fprintf(stderr, "Modo de uso: ./listas arquivo.bin \n");
    return 0;
  }
  entrada = fopen(argv[1], "rb");

  if(entrada == NULL){
    fprintf(stderr, "Erro ao abrir o arquivo %s\n", argv[1]);
    return 0;
  }

  qtd = 0;

  while(fread(&num, sizeof(int),1,entrada)){
    qtd++;
    printf("%d",num);
  }

  printf("\n %d numeros\n",qtd);
  fclose(entrada);
}