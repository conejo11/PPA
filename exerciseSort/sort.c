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

void mergesort(int *vetor, int l, int r) {
   if(l < r){
     int m = l+(r-l)/2;
     mergesort(vetor, l, m);
     mergesort(vetor, m+1, r);
     merge(vetor, l, m, r);
   }
}

void merge(int *vetor, int l, int m, int r){
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int auxLeft[n1];
  int auxRight[n2];

  for(i=0; i<n1; i++)
    auxLeft[i] = vetor[l + i];
  for(j=0; j<n2; j++)
    auxRight[j] = vetor[m+1+j];

  i = j = 0;
  k = l;
  while(i<n1 && j<n2){
    if(auxLeft[i] <= auxRight[j]){
      vetor[k] = auxLeft[i];
      i++;
    } else {
      vetor[k] = auxRight[j];
      j++;
    }
    k++;
  }

  while(i<n1){
    vetor[k] = auxLeft[i];
    i++;
    k++;
  }

  while(j<n2){
    vetor[k] = auxRight[j];
    j++;
    k++;
  }
}
