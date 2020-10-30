#include <stdio.h>
#include <stdlib.h>

typedef struct IntList {
    int value;
    struct IntList *next;
} ListInt;
typedef ListInt *List;

void addListPrincipal(ListInt **listPrincipal, int value);   
void addOddList(ListInt **oddList, int value);      
void addPairList(ListInt **pairList, int value);    
void imprimeLista(ListInt *lst);

int main( int argc, char** argv ){

    FILE *fp;
    ListInt *listPrincipal, *oddList, *pairList;
    int value;
    
    listPrincipal = NULL; oddList = NULL; pairList = NULL;

    if( argc != 2 ){
        fprintf(stderr, "Informe o arquivo. Ex.: %s arquivo.bin\n", argv[0]);
        return 0;
    }else{
        fp = fopen(argv[1], "rb");

        while ( fread(&value, sizeof(int), 1, fp) ) {
            addListPrincipal(&listPrincipal, value);
            if (value % 2 == 0)
                addPairList(&pairList, value);
            else 
                addOddList(&oddList, value);
        }
        fclose(fp);

        printf("\nLista principal: ");
        imprimeLista(listPrincipal);
        printf("\nLista impar: ");
        imprimeLista(oddList);
        printf("\nLista par: ");
        imprimeLista(pairList);
        printf("\n\n");
    }

    return 0;
}

void addListPrincipal(ListInt **listPrincipal, int value) {
    ListInt *p, *q, *nova;
    p = NULL; q = *listPrincipal;
    
    while (q != NULL) {
        p = q; 
        q = q->next;
    }
    
    if(q == NULL){ 
        nova = (ListInt *) malloc(sizeof (ListInt));
        nova->value = value;
        nova->next = NULL;
        if(p!=NULL)
            p->next=nova;
        else
            *listPrincipal=nova;
    }
}

void addOddList(ListInt **oddList, int value) {
    ListInt *p, *q, *nova;
    p = NULL; 
    q = *oddList;
    while (q != NULL && q->value <= value) {
        p = q; 
        q = q->next;
    }
    if(q == NULL){ 
        nova = (ListInt *) malloc(sizeof (ListInt));
        nova->value = value;
        nova->next = NULL;
        if(p!=NULL){
            p->next=nova;
        }
        else{
            *oddList=nova;
        }
    }
    else {
        nova = (ListInt *) malloc(sizeof (ListInt));
        nova->value = value;
        nova->next = q;
        if(p!=NULL){
            p->next=nova;
        }
        else{
            *oddList=nova;
        }
    }
}

void addPairList(ListInt **pairList, int value) {
    ListInt *p, *q, *nova;
    p = NULL; q = *pairList;
    while (q != NULL && q->value >= value) {
        p = q; 
        q = q->next;
    }
    if(q == NULL){ 
        
        nova = (ListInt *) malloc(sizeof (ListInt));
        nova->value = value;
        nova->next = NULL;
        
        if(p!=NULL)
            p->next=nova;
        else
            *pairList=nova;
    }
    else {
        nova = (ListInt *) malloc(sizeof (ListInt));
        nova->value = value;
        nova->next = q;
        if(p!=NULL){
            p->next=nova;
        }
        else {
            *pairList=nova;
        }
    }
}

void imprimeLista(ListInt *lst) {
    ListInt *p;
    for (p = lst; p != NULL; p = p->next)
        printf("%d ", p->value);
}
