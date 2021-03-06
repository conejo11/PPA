#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <mpi.h>
#include "matriz.h"

#ifndef SOME_HEADER_FILE_H
#define SOME_HEADER_FILE_H

typedef struct {
  int lin_inicio;
  int lin_fim;
  int col_inicio;
  int col_fim;
} bloco_t;

typedef struct {
  int **matriz;
  bloco_t *bloco;
} matriz_bloco_t;
#endif

int multiplicarMPI(int**, int**, int**, int, int, int, int);

int *matrixToVector(int**, int, int);
void vectorToMatrix(int*, int**, int, int);
void somaVetor(int* vecA, int *vecB, int *res, int size);
