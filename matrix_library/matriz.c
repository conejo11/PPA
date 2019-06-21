#include "matriz.h"
#include <time.h>

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% MATRIZ %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int gerar_matriz(int **matriz, int linha, int coluna, int valor){
  if (!matriz) {
    printf("ERROR: Out of memory\n");
    return 1;
  }
  srand( (unsigned)time(NULL) );

  for(int i = 0; i < linha; i++){
    for(int j = 0; j < coluna; j++){
      if (valor == -9999) {
        matriz[i][j] = rand() % 10;
      }

      if (valor == -8888) {
        matriz[i][j] = i;
      }

      if (valor == -7777) {
        matriz[i][j] = linha - i;
      }

      if (valor == 0) {
        matriz[i][j] = valor;
      }
    }
  }
  return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int zerar_matriz (int **matriz, int linha, int coluna){
  if (!matriz) {
    printf("ERROR: Out of memory\n");
    return 1;
  }
	return gerar_matriz(matriz,linha,coluna,0);
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int imprimir_matriz (int **matriz, int linha, int coluna){
  if (!matriz) {
    printf("ERROR: Out of memory\n");
    return 1;
  }
	for (int j = 0; j < coluna; j++)
		printf("\t(%d)", j);
	printf("\n");
	for (int i = 0; i < linha; i++) {
		printf("(%d)", i);
	  for (int j = 0; j < coluna; j++){
			printf("\t%d", matriz[i][j]);
		}
		printf("\n");
	}
	return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int comparar_matriz (int **matriza, int **matrizb, int linha, int coluna){
  if (!matriza || !matrizb) {
    printf("ERROR: Out of memory (Nao foi inicializada possivelmente pois a soma ou multiplicacao nao atenderam os criterios)\n");
    return 1;
  }
	for (int i=0; i < linha; i++) {
	  for (int j=0; j < coluna; j++){
			if (matriza[i][j] != matrizb[i][j]) {
				printf("O elemento [%d,%d] é diferente nas matrizes analisadas! %d != %d\n", i,j,matriza[i][j], matrizb[i][j]);
				return 1;
			}
		}
	}
	printf("VERIFICADO: Matrizes identicas\n\n");
	return 0;
}


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int **liberar_matriz (int **matriz, int linha, int coluna) {
  for(int i = 0; i < linha; i++){
    free(matriz[i]);
  }
  free(matriz);
	return NULL;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int **alocar_matriz (int linha, int coluna) {
  int i;
  int **mat = NULL;
  mat = (int **) calloc(linha, sizeof(int*));
  for(i = 0; i < linha; i++){
    mat[i] = (int *) calloc(coluna, sizeof(int));
  }
  if (!mat) {
    printf("ERROR: Out of memory\n");
    return NULL;
  }
  // printf("alocou\n");
	return mat;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// orientacao, 0 corte horizontal, 1 para corte vertical
matriz_bloco_t **particionar_matriz (int **matriz, int mat_lin, int mat_col, int orientacao, int divisor) {
  matriz_bloco_t **block = NULL;
  block = (matriz_bloco_t **) calloc(divisor, sizeof(matriz_bloco_t*));
  if (!block || !matriz) {
    printf("ERROR: Out of memory\n");
    return NULL;
  }
  for(int i = 0; i< divisor; i++){
    block[i] = (matriz_bloco_t *) malloc(sizeof(matriz_bloco_t));
    block[i]->bloco = (bloco_t *) malloc(sizeof(bloco_t));
  }

  if(orientacao == 0){
    int desloc = mat_lin/divisor;
    for(int i=0; i<divisor; i++){
      block[i]->matriz = matriz;
      block[i]->bloco->lin_inicio = i * desloc;
      block[i]->bloco->lin_fim = (i+1) * desloc;
      block[i]->bloco->col_inicio = 0;
      block[i]->bloco->col_fim = mat_col;

    }
    block[divisor-1]->bloco->lin_fim = mat_lin;
  } else {
    int desloc = mat_col/divisor;
    for(int i=0; i<divisor; i++){
      block[i]->matriz = matriz;
      block[i]->bloco->lin_inicio = 0;
      block[i]->bloco->lin_fim = mat_lin;
      block[i]->bloco->col_inicio = i * desloc;
      block[i]->bloco->col_fim = (i+1) * desloc;
    }
    block[divisor-1]->bloco->col_fim = mat_col;
  }
  return block;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
matriz_bloco_t **constroi_submatrizv2 (int mat_lin, int mat_col, int divisor) {
  matriz_bloco_t **block = NULL;
  block = (matriz_bloco_t **) calloc(divisor, sizeof(matriz_bloco_t*));
  if (!block) {
    printf("ERROR: Out of memory\n");
    return NULL;
  }
  for(int i = 0; i< divisor; i++){
    block[i] = (matriz_bloco_t *) malloc(sizeof(matriz_bloco_t));
    block[i]->bloco = (bloco_t *) malloc(sizeof(bloco_t));
  }
  for(int i=0; i<divisor; i++){
    int **matBl = alocar_matriz(mat_lin, mat_col);
    block[i]->matriz = matBl;
    block[i]->bloco->lin_inicio = 0;
    block[i]->bloco->lin_fim = mat_lin;
    block[i]->bloco->col_inicio = 0;
    block[i]->bloco->col_fim = mat_col;
  }
	return block;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
matriz_bloco_t **liberar_submatriz (matriz_bloco_t **submatriz, int divisor) {
    for(int i = 0; i<divisor; i++){
      free(submatriz[i]->bloco);
      free(submatriz[i]);
    }
    free(submatriz);
  return NULL;
}
