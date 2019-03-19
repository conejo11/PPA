#include "matriz.h"
#include <time.h>

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% MATRIZ %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int gerar_matriz(int **matriz, int linha, int coluna, int valor){
  #TODO
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int zerar_matriz (int **matriz, int linha, int coluna){
	return gerar_matriz(matriz,linha,coluna,0);
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int imprimir_matriz (int **matriz, int linha, int coluna){
	for (int j =0; j < coluna; j++)
		printf("\t(%d)", j);
	printf("\n");
	for (int i=0; i < linha; i++) {
		printf("(%d)", i);
	  for (int j=0; j < coluna; j++){
			printf("\t%d", matriz[i][j]);
		}
		printf("\n");
	}
	return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int comparar_matriz (int **matriza, int **matrizb, int linha, int coluna){
	for (int j =0; j < coluna; j++)
	for (int i=0; i < linha; i++) {
	  for (int j=0; j < coluna; j++){
			if (matriza[i][j] != matrizb[i][j]) {
				printf("O elemento [%d,%d] é diferente nas matrizes analisadas!", i,j);
				return 1;
			}
		}

	}
	printf("VERIFICADO: Matrizes identicas\n");
	return 0;
}


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int **liberar_matriz (int **matriz, int linha, int coluna) {
        #TODO
	return NULL;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int **alocar_matriz (int linha, int coluna) {
        #TODO
	return nova_a;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int gerar_submatriz (int **mat_origem, matriz_bloco_t *submatriz, bloco_t *bloco) {
        #TODO
  return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int imprimir_submatriz (matriz_bloco_t *submatriz){
        #TODO
	return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int imprimir_bloco (matriz_bloco_t *submatriz) {
        #TODO
	return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// orientacao, 0 corte horizontal, 1 para corte vertical
matriz_bloco_t **particionar_matriz (int **matriz, int mat_lin, int mat_col, int orientacao) {
        #TODO
  return NULL;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
matriz_bloco_t **constroi_submatriz (int **matriz, int mat_lin, int mat_col, int divisor) {
        #TODO
	return NULL;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
matriz_bloco_t **liberar_submatriz (matriz_bloco_t **submatriz) {
        #TODO
  return NULL;
}
