#include "matriz-operacoes-omp.h"
#include "matriz-operacoes.h"

int multiplicarOMP(int **mat_a, int **mat_b, int **mat_c, int N, int L, int M, int n_threads){
  if(!mat_a || !mat_b || !mat_c){
    printf("ERROR: Out of memory\n");
    return 1;
  }
  int i,j,k;

  #pragma omp parallel shared (mat_a, mat_b, mat_c, N, L, M) \
  num_threads(n_threads)

  #pragma omp for schedule(static)

  for(i = 0; i < N; i++){
    for(k = 0; k < L; k++){
      for(j = 0; j < M; j++){
        mat_c[i][j] += mat_a[i][k] * mat_b[k][j];
      }
    }
  }

  return 0;
}

int multiplicarOMPBlocos(matriz_bloco_t **mat_a, matriz_bloco_t **mat_b, matriz_bloco_t **mat_c, int **matFim, int divisor, int n_threads){
  if(!mat_a || !mat_b || !mat_c){
    printf("ERROR: Out of memory\n");
    return 1;
  }

  int j,x;

  #pragma omp parallel shared (mat_a, mat_b, mat_c, matFim, divisor) \
  num_threads(n_threads)
  #pragma omp for schedule(static)
    for( x =0; x<divisor; x++){
      multiplicar_submatriz(mat_a[x], mat_b[x], mat_c[x]);
    }

  for (j=0;j<divisor;j++){
    somarIJ(mat_c[j]->matriz, matFim, matFim, mat_c[j]->bloco->lin_fim, mat_c[j]->bloco->lin_fim, mat_c[j]->bloco->col_fim);
  }

  return 0;
}
