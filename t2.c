#include <stdio.h>

void show(int *vet , int n){
  int *p;
  for(p=vet; p < vet+n; p++){
    print("%d ", *p);
  }
  printf("\n");
}

void write_archive(int *vet, int n , const char *name_archive ){
  int *p;
  FILE *arq;

  arq = fopen(name_archive, "w");

  if(!arq){
    fprintf(stderr,"Erro ao abrir arquivo %s\n", name_archive);
  }else {
    int *p;
    for(p=vet; p < vet+n; p++){
      fprint(arq,"%d", *p);
    }
    fprint(arq,"\n");
    fclose(arq);
  }
}

void read(int *vet, int n){
  int *p;
  for(p=vet; p < vet+n; p++){
    scanf("%d ", p);
  }

}
