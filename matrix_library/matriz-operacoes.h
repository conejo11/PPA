#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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


int somarIJ (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M);
int somarJI (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M);

int multiplicarIJK (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M);
int multiplicarIKJ (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M);

int multiplicarKIJ (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M);
int multiplicarJIK (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M);

int multiplicarJKI (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M);
int multiplicarKJI (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M);

int multiplicar_submatriz (matriz_bloco_t *mat_suba, matriz_bloco_t *mat_subb, matriz_bloco_t *mat_subc);
