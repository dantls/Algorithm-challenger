#include <stdio.h>
#include <stdlib.h>

struct celula{
  int chave;
  struct celula *prox;
};

typedef struct celula celula;

celula *aloca(int x) {
  celula * novo;

  novo = (celula*) malloc (sizeof(celula));

  if (novo != NULL){
    novo->prox = NULL;
    novo->chave = x;
  }else {
    fprintf(stderr, "Erro ao alocar memoria\n");
  }
  return novo;
}

void insere_fim(celula ** lista, int x){
  celula *aux, *novo;
  if(*lista == NULL){
    *lista = aloca(x);
  }else{
    aux = *lista;
    while(aux->prox != NULL){
      aux= aux->prox;
    }
    novo = aloca(x);
    aux->prox = novo;
  }
}

int contem_valor(celula *lista , int chave){
  celula *aux;
  aux = lista;
  while(aux != NULL && aux->chave != chave){
    aux = aux->prox;
  }
  if(aux == NULL){
    return 0;
  }else {
    return 1;
  }
}


void libera(celula *lista){
  celula *aux;

  while(lista != NULL){
    aux = lista -> prox;
    free(lista);
    lista = aux;
  }
}

int count(celula *lista, int x){
  if(lista == NULL){
    return 0;
  }
  if(lista ->chave == x){
    return 1 + count(lista->prox, x);
  }else{
    return count(lista->prox, x);
  }
}

void show(celula *lista , FILE *stream){
  celula *aux, *shows;

  fprint(stream, "Quantidade: %d\n", list_size(lista));
  fprint(stream, "Elementos: ");

  aux = lista;
  while(aux != NULL){
    fprintf(stream, "%d", aux->chave);
    aux = aux->prox;
  }
  fprint(stream, "\n");

  aux = lista;
  shows = NULL;

  while(aux != NULL){
    if(contem_valor(shows, aux->chave) == 0){
      fprintf(stream, "%s %d \n", aux->chave , count(lista, aux->chave));
      insere_fim(shows, aux->chave);
    }
    aux = aux->prox;
  }
  libera(shows);




}


int main(int argc , char *argv[]){
  int num;
  FILE *entrada, *saida;
  celula *todos;

  if(argc != 2){
    fprintf(stderr,"Modo de uso: /listas arquivo.bin\n");
    return 0;
  }

  todos = NULL;

  entrada = fopen(argv[1], "rb");
  if(entrada == NULL){
    fprintf(stderr, "Erro ao abrir o arquivo %s\n", argv[1]);
    return 0;
  }

  fread(&num, sizeof(int), 1, entrada);

  while(!feof(entrada)){
    insere_fim(&todos, num);
    fread(&num, sizeof(int),1,entrada);
  }
  fclose(entrada);

  show(todos, stdout);
  saida = open_file("todos.txt");
  show_list(todos, saida);
  fclose(saida);
  libera(todos);

  return 0;
}