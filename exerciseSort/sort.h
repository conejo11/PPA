#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void quick_sort(int *vetor, int indice_esq, int indice_dir);
void bubblesort(int *vetor, int tamanho);
void mergesort(int *vetor, int l, int r);
void merge(int *vetor, int l, int m, int r);
