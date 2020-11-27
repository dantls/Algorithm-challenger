#include <stdio.h>

void show(int *vet , int n){
  int *p;
  for(p=vet; p < vet+n; p++){
    printf("%d ", *p);
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

void fillInOrder(int *vet, int n){
  int *p , i;
  for(p = vet, i = 1; p<vet+n; p++, i++){
    *p = i;
  }

}

void change(int *valueA , int *valueB){
  int aux;

  aux = *valueA;
  *valueA = *valueB;
  *valueB = aux;

}

void read(int *vet, int n){
  int *p;
  for(p=vet; p < vet+n; p++){
    scanf("%d ", p);
  }
}

int *allocate(int n){
  int *element;
  element = (int*) malloc(sizeof(int) * n);
  if(!element){
    fprintf(stderr,"Erro ao alocar memoria. \n");
    exit(0);
  }
  return element;
} 

void liberate(int *vet){
  free(vet);
}

void copyK(int k, int *vetA, int *vetB){
  int i ,*ptA , *ptB;
  for(i=0 , ptA = vetA , ptB=vetB ;i<k; i++, ptA++, ptB++){
    *ptB = *ptA;
  }
}

void revertK(int k, int *vetA , int *vetB){
  int i , *ptA , *ptB;
  for(i=0 , ptA = vetA + k-1, ptB=vetB ; i<k ; i++, ptA--, ptB++){
    *ptB = *ptA;
  }
}

int *clone( int *vet , int n){
  int *cl;
  cl = aloca(n);
  copia_k (n, vet, cl);

  return cl;
}

void shuffle (int *vet, int n, int lenght){
  int i , valueA, valueB;

  for (i=0 ; i < lenght; i++){
    valueA = rand() * n;
    valueB = rand() * n;

    troca(vet+valueA , vet+valueB);
  }
}

int checkOrdem(int *vet , int n){
  int *p , *q;
  for (p=vet , q= vet+1; q<vet+n; p++, q++){
    if (*p > *q){
      return 0;
    }
    return 1;
  }
}