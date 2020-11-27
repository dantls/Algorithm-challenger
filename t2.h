#include <stdio.h>

void show(int *vet , int n);

void write_archive(int *vet, int n , const char *name_archive );

void fillInOrder(int *vet, int n);

void change(int *valueA , int *valueB);

void read(int *vet, int n);

int *allocate(int n);

void liberate(int *vet);

void copyK(int k, int *vetA, int *vetB);

void revertK(int k, int *vetA , int *vetB);

int *clone( int *vet , int n);

void shuffle (int *vet, int n, int lenght);

int checkOrdem(int *vet , int n);