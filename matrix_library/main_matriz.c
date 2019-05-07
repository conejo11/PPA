#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "toolsv2.h"
#include "matriz.h"
#include "matriz-operacoes.h"
#include "matriz-operacoes-threads.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int main(int argc, char *argv[]) {

	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	// DECLARAÇÃO de VARIÁVEIS
	int **mat_a = NULL;
	int **mat_b = NULL;
	int **mat_c = NULL;
	FILE *fmat_a, *fmat_b, *fmat_c, *fmatbloco_c;
	int nr_line;
	int *vet_line = NULL;
	int N, M, La, Lb;
	double start_time, end_time;

	matriz_bloco_t **Vsubmat_a = NULL;
	matriz_bloco_t **Vsubmat_b = NULL;
	matriz_bloco_t **Vsubmat_c = NULL;
	int nro_submatrizes=2;
	int **mat_bloco_final = NULL;
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	if (argc != 3){
		printf ("ERRO: Numero de parametros %s <matriz_a> <matriz_b>\n", argv[0]);
		exit (1);
	}

  // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	fmat_a = fopen(argv[1],"r");
	fmat_b = fopen(argv[2],"r");
  if ((fmat_a == NULL) || (fmat_b == NULL)) {
		printf("Error: Na abertura dos arquivos.");
		exit(1);
  }

  // matriz_a N (linha) x La (coluna)
	extrai_parametros_matriz(fmat_a, &N, &La, &vet_line, &nr_line);
	mat_a = alocar_matriz(N, La);
	filein_matriz (mat_a, N, La, fmat_a, vet_line, nr_line);

	// matriz_b Lb (linha) x M (coluna)
	extrai_parametros_matriz(fmat_b, &Lb, &M, &vet_line, &nr_line);
	mat_b = alocar_matriz(Lb, M);
	filein_matriz (mat_b, Lb, M, fmat_b, vet_line, nr_line);

	// matriz_c (resultante) = N (linha) x M(coluna)
	mat_c = alocar_matriz(N, M);
	zerar_matriz(mat_c, N, M);

	if ((mat_c == NULL) || (mat_b == NULL) || (mat_a == NULL)) {
		printf("ERROR: Out of memory\n");
	}
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%

	if(La != Lb){
		printf("Coluna de A diferente de Linha de B, não é possível multiplicar\n");
		return 1;
	} else {
  	// Multiplicação IJK
		zerar_matriz(mat_c, N, M);
		start_time = wtime();
		multiplicarIJK(mat_a,mat_b,mat_c, N, La, M);
		end_time = wtime();
		printf("\n ##### Multiplicação de Matrizes (IJK) #####\n");
		printf("\tRuntime: %f\n", end_time - start_time);
		fmat_c= fopen("outIJK.map-result","w");
		fileout_matriz(mat_c, N, M, fmat_c);
		// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

		// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	  // Multiplicação em Bloco v2
	  printf(" ##### Multiplicação de Matrizes (blocov2) #####\n");
		start_time = wtime();

		Vsubmat_a = particionar_matriz (mat_a, N, La, 1, 2);
		Vsubmat_b = particionar_matriz (mat_b, Lb, M, 0, 2);
		Vsubmat_c = constroi_submatrizv2 (N, M, nro_submatrizes);
		mat_bloco_final = alocar_matriz(N, M);
		zerar_matriz(mat_bloco_final, N, M);

		multiplicar_submatriz (Vsubmat_a[0], Vsubmat_b[0], Vsubmat_c[0]);
		multiplicar_submatriz (Vsubmat_a[1], Vsubmat_b[1], Vsubmat_c[1]);
		somarIJ(Vsubmat_c[0]->matriz,Vsubmat_c[1]->matriz,mat_bloco_final, N, La, M);

		end_time = wtime();

		printf("\tRuntime: %f\n\n", end_time - start_time);
		fmatbloco_c = fopen("outBlocov2.map-result","w");
		fileout_matriz(mat_bloco_final, N, M, fmatbloco_c);
		// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

		comparar_matriz (mat_c, mat_bloco_final, N, M);
		printf("Resultados individuais encontram-se nos arquivos <out*.map-result>.\n");

	  // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
		// LIBERAR MEMÓRIA
		liberar_submatriz (Vsubmat_a,2);
		liberar_submatriz (Vsubmat_b,2);
		liberar_submatriz (Vsubmat_c,2);

		liberar_matriz(mat_a,N,La);
		liberar_matriz(mat_b,Lb,M);
		liberar_matriz(mat_c,N,M);
		liberar_matriz(mat_bloco_final,N,M);

		fclose(fmat_a);
		fclose(fmat_b);
		fclose(fmat_c);
	}
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	return 0;
}
