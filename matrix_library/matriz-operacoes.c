#include "matriz-operacoes.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% MATRIZ %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int somarIJ (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
  if(!mat_a || !mat_b || !mat_c){
		printf("ERROR: Out of memory\n");
		return 1;
	}

	int i,j;
	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			mat_c[i][j] = mat_a[i][j] + mat_b[i][j];
		}
	}

  return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int somarJI (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
	if(!mat_a || !mat_b || !mat_c){
		printf("ERROR: Out of memory\n");
		return 1;
	}

	int i,j;
	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			mat_c[j][i] = mat_a[j][i] + mat_b[j][i];
		}
	}
  return 0;
}


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarIJK (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
	if(!mat_a || !mat_b || !mat_c){
		printf("ERROR: Out of memory\n");
		return 1;
	}

	int i,j,k;
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			for(k = 0; k < L; k++){
				mat_c[i][j] += mat_a[i][k] * mat_b[k][j];
			}
		}
	}

	return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarIKJ (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
	if(!mat_a || !mat_b || !mat_c){
		printf("ERROR: Out of memory\n");
		return 1;
	}

	int i,j,k;
	for(i = 0; i < N; i++){
		for(k = 0; k < L; k++){
			for(j = 0; j < M; j++){
				mat_c[i][j] += mat_a[i][k] * mat_b[k][j];
			}
		}
	}

	return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarKIJ (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
	if(!mat_a || !mat_b || !mat_c){
		printf("ERROR: Out of memory\n");
		return 1;
	}

	int i,j,k;
	for(k = 0; k < L; k++){
		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				mat_c[i][j] += mat_a[i][k] * mat_b[k][j];
			}
		}
	}

  return 0;
}


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarKJI (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
	if(!mat_a || !mat_b || !mat_c){
		printf("ERROR: Out of memory\n");
		return 1;
	}

  int i,j,k;
	for(k = 0; k < L; k++){
		for(j = 0; j < M; j++){
			for(i = 0; i < N; i++){
				mat_c[i][j] += mat_a[i][k] * mat_b[k][j];
			}
		}
	}

  return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarJIK (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
	if(!mat_a || !mat_b || !mat_c){
		printf("ERROR: Out of memory\n");
		return 1;
	}

	int i,j,k;
	for(j = 0; j < M; j++){
		for(i = 0; i < N; i++){
			for(k = 0; k < L; k++){
				mat_c[i][j] += mat_a[i][k] * mat_b[k][j];
			}
		}
	}

  return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarJKI (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
	if(!mat_a || !mat_b || !mat_c){
		printf("ERROR: Out of memory\n");
		return 1;
	}

	int i,j,k;
	for(j = 0; j < M; j++){
		for(k = 0; k < L; k++){
			for(i = 0; i < N; i++){
				mat_c[i][j] += mat_a[i][k] * mat_b[k][j];
			}
		}
	}

  return 0;
}


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicar_submatriz (matriz_bloco_t *mat_suba, matriz_bloco_t *mat_subb, matriz_bloco_t *mat_subc) {
  if(!mat_suba || !mat_subb || !mat_subc){
		printf("ERROR: Out of memory\n");
		return 1;
	}

  int i,j,k;
  for(i = mat_suba->bloco->lin_inicio; i < mat_suba->bloco->lin_fim; i++){
  	for(k = mat_suba->bloco->col_inicio; k < mat_suba->bloco->col_fim; k++){
  		for(j = mat_subb->bloco->col_inicio; j < mat_subb->bloco->col_fim; j++){
  			mat_subc->matriz[i][j] += mat_suba->matriz[i][k] * mat_subb->matriz[k][j];
  		}
  	}
  }
	return 0;
}
