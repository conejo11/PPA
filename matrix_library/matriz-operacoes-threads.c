#include "matriz-operacoes-threads.h"
#include "matriz-operacoes.h"

void *multiplicaNormalTh (void *ptr){
  ArgsNormal *args = (ArgsNormal*) ptr;
  int i,j,k;
  for (i = args->linha; i<args->linA; i+=args->n_threads){
    for(j = 0; j< args->colB; j++){
      for(k = 0; k< args->colA; k++){
        args->mat_c[i][j] += args->mat_a[i][k] * args->mat_b[k][j];
      }
    }
  }
  return NULL;
}

void *multiplicaBlocoTh (void *ptr){
  ArgsBlock *args = (ArgsBlock*) ptr;
  int i;
  for( i =args->bloco; i<args->divisor; i+=args->n_threads){
    multiplicar_submatriz(args->mat_a[i], args->mat_b[i], args->mat_c[i]);
  }
  return NULL;
}

int multiplicarThBlocos (matriz_bloco_t **mat_a, matriz_bloco_t **mat_b, matriz_bloco_t **mat_c, int **matFim, int divisor, int n_threads){
  if(!mat_a || !mat_b || !mat_c){
    printf("ERROR: Out of memory\n");
    return 1;
  }

  int i;
  pthread_t *threads = NULL;
  threads = (pthread_t *) malloc (n_threads * sizeof(pthread_t));
  if (!threads){
    printf("ERROR: Out of memory\n");
    return 1;
  }

  ArgsBlock *args = (ArgsBlock *) malloc(n_threads * sizeof(ArgsBlock));
  if (!args){
    printf("ERROR: Out of memory\n");
    return 1;
  }

  for (i =0; i< n_threads; i++){
    args[i].mat_a = mat_a;
    args[i].mat_b = mat_b;
    args[i].mat_c = mat_c;
    args[i].divisor = divisor;
    args[i].matFim = matFim;
    args[i].bloco = i;
    args[i].n_threads = n_threads;
    pthread_create(&threads[i],NULL,multiplicaBlocoTh, (void *) &args[i]);
  }

  for (i=0; i<n_threads; i++){
    pthread_join(threads[i], NULL);
  }

  for (i=0; i<divisor; i++){
    somarIJ(args->mat_c[i]->matriz, args->matFim, args->matFim,args->mat_c[i]->bloco->lin_fim,args->mat_c[i]->bloco->lin_fim,args->mat_c[i]->bloco->col_fim);
  }

  free(args);
  free(threads);
  return 0;
}

int multiplicarTh (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M, int n_threads) {
  if(!mat_a || !mat_b || !mat_c){
    printf("ERROR: Out of memory\n");
    return 1;
  }

  int i;
  pthread_t *threads = NULL;

  threads = (pthread_t *) malloc (n_threads * sizeof(pthread_t));
  if (!threads){
    printf("ERROR: Out of memory\n");
    return 1;
  }

  ArgsNormal *args = (ArgsNormal *) malloc (n_threads * sizeof(ArgsNormal));
  if (!args){
    printf("ERROR: Out of memory\n");
    return 1;
  }

  for(i=0; i< n_threads; i++){
    args[i].mat_a = mat_a;
    args[i].linA = N;
    args[i].colA = L;
    args[i].mat_b = mat_b;
    args[i].colB = M;
    args[i].mat_c = mat_c;
    args[i].linha = i;
    args[i].n_threads = n_threads;
    pthread_create(&threads[i], NULL, multiplicaNormalTh, (void*)&args[i]);
  }

  for(i=0; i< n_threads; i++){
    pthread_join(threads[i], NULL);
  }
  free(args);
  free(threads);
  return 0;
}
