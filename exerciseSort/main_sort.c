#include <stdio.h>
#include <stdlib.h>

// Bibliotecas pessoais
#include "vector.h"
#include "toolsvector.h"
#include "sort.h"

int main(int argc, char** argv) {
  int nlinhas;
  int x;
  int *vet = NULL;
  FILE *fvet;
  double start_time, end_time;

  if (argc != 2){
    printf ("ERRO: Numero de parametros %s <filename>", argv[0]);
    exit (1);
  }

  //nlinhas =  atoi(argv[1]);
  fvet = fopen(argv[1],"r");
  if (fvet == NULL) {
    printf("Error: Na abertura dos arquivos.");
    exit(1);
  }

  nlinhas = extrai_nroLine(fvet);
  vet = alocar_vetor(nlinhas);
  filein_vetor (vet, nlinhas, fvet);
  printf("\t\t**** PRINT vetor lido N(%d) **** \n", nlinhas);
  imprimir_vetor(vet, nlinhas);

  printf("Digite:\n1 - Quicksort\n2 - Bubblesort\n3 - Mergesort\n");
  scanf("%d",&x);

  switch(x){
    case 1:
      start_time = wtime();
      quick_sort(vet, 0, nlinhas - 1);
      end_time = wtime();

      printf("\t\t**** PRINT vetor Ordenado QUICKSORT N(%d) **** \n", nlinhas);
      imprimir_vetor(vet, nlinhas);
      printf("\tRuntime MERGE: %f\n", end_time - start_time);
      break;
    case 2:
      start_time = wtime();
      bubblesort(vet, nlinhas - 1);
      end_time = wtime();

      printf("\t\t**** PRINT vetor Ordenado BUBBLESORT N(%d) **** \n", nlinhas);
      imprimir_vetor(vet, nlinhas);
      printf("\tRuntime MERGE: %f\n", end_time - start_time);
      break;
    case 3:
      start_time = wtime();
      mergesort(vet, 0, nlinhas - 1);
      end_time = wtime();

      printf("\t\t**** PRINT vetor Ordenado MERGESORT N(%d) **** \n", nlinhas);
      imprimir_vetor(vet, nlinhas);
      printf("\tRuntime MERGE: %f\n", end_time - start_time);
      break;
    default:
      printf("Opcao escolhida inválida\n");
  }

  liberar_vetor (vet);
  fclose (fvet);
  return 0;
}
