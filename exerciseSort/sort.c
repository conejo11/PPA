#include "sort.h"

void quick_sort(int *vetor, int indice_esq, int indice_dir) {
  int r, l, pivot, aux;
  if (indice_esq < indice_dir){
    r = indice_dir;
    l = indice_esq;
    pivot = indice_esq;
    while (l < r){
      while(vetor[l] <= vetor[pivot] && l < indice_dir)
        l++;
      while(vetor[r] > vetor[pivot])
        r--;
      if(l < r){
        aux = vetor[l];
        vetor[l] = vetor[r];
        vetor[r] = aux;
      }
    }
    aux = vetor[pivot];
    vetor[pivot] = vetor[r];
    vetor[r] = aux;
    quick_sort(vetor, indice_esq, r - 1);
    quick_sort(vetor, r + 1, indice_dir);
  }
}

void bubblesort(int *vetor, int tamanho) {
  int i, j, aux;
  for(i = 1; i<tamanho; i++){
    for(j = 0; j < tamanho; j++){
      if(vetor[j] > vetor[j + 1]){
        aux = vetor[j];
        vetor[j] = vetor[j+1];
        vetor[j+1] = aux;
      }
    }
  }
}

void mergesort(int *vetor, int tamanho, int* vetortemp) {
   // Desenvolva o código do Quicksort
}
