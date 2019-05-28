#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>
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

int multiplicarOMP(int **mat_a, int **mat_b, int **mat_c, int N, int L, int M, int n_threads);
int multiplicarOMPBlocos(matriz_bloco_t **mat_a, matriz_bloco_t **mat_b, matriz_bloco_t **mat_c, int **matFim, int divisor, int n_threads);
