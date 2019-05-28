#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include "toolsv2.h"
#include "matriz.h"
#include "matriz-operacoes.h"
#include "matriz-operacoes-threads.h"
#include "matriz-operacoes-omp.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int main(int argc, char *argv[]) {

	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	// DECLARAÇÃO de VARIÁVEIS
	int **mat_a = NULL;
	int **mat_b = NULL;
	int **mat_c = NULL;
	int **mat_d =NULL;
	double mediaSeqNor = 0, mediaThNor = 0, mediaSeqBlock = 0, mediaThBlock = 0;
	int **matFim =NULL;
	int **matFim2 =NULL;
	FILE *fmat_a, *fmat_b, *fmat_c;
	int nr_line;
	int *vet_line = NULL;
	int N, M, La, Lb;
	double start_time, end_time;

	matriz_bloco_t **Vsubmat_a = NULL;
	matriz_bloco_t **Vsubmat_b = NULL;
	matriz_bloco_t **Vsubmat_c = NULL;
	int divisor, n_threads;
	// int **mat_bloco_final = NULL;
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	if (argc != 5){
		printf ("ERRO: Numero de parametros %s <matriz_a> <matriz_b>\n", argv[0]);
		exit (1);
	}

  // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	fmat_a = fopen(argv[1],"r");
	fmat_b = fopen(argv[2],"r");
	divisor = atoi(argv[3]);
	n_threads = atoi(argv[4]);
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

	mat_d = alocar_matriz(N, M);
	zerar_matriz(mat_d, N, M);

	matFim = alocar_matriz(N, M);
	zerar_matriz(matFim, N, M);

	matFim2 = alocar_matriz(N, M);
	zerar_matriz(matFim2, N, M);

	if ((mat_c == NULL) || (mat_b == NULL) || (mat_a == NULL)) {
		printf("ERROR: Out of memory\n");
	}
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%

	if(La != Lb){
		printf("Coluna de A diferente de Linha de B, não é possível multiplicar\n");
		return 1;
	} else {
  	// Multiplicação IKJ Normal sequencial
		for(int i=0; i<10; i++){
			zerar_matriz(mat_c, N, M);
			start_time = wtime();
			multiplicarIKJ(mat_a,mat_b,mat_c, N, La, M);
			end_time = wtime();
			mediaSeqNor += end_time - start_time;
			fmat_c= fopen("outIJK_sequencial.map-result","w");
			fileout_matriz(mat_c, N, M, fmat_c);
		}
		mediaSeqNor = mediaSeqNor/10;

		// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

		// Multiplicacao IJK Bloco Sequencial
		for (int i =0; i<10; i++){
			zerar_matriz(matFim, N, M);
			start_time = wtime();
			Vsubmat_a = particionar_matriz (mat_a, N, La, 1, divisor);
			Vsubmat_b = particionar_matriz (mat_b, Lb, M, 0, divisor);
			Vsubmat_c = constroi_submatrizv2 (N, M, divisor);
			for(int j=0; j<divisor; j++){
				multiplicar_submatriz(Vsubmat_a[j], Vsubmat_b[j], Vsubmat_c[j]);
			}
			for(int k = 0; k<divisor; k++){
				somarIJ(Vsubmat_c[k]->matriz, matFim, matFim, N, La, M);
			}
			end_time = wtime();
			mediaSeqBlock += end_time - start_time;
			fmat_c= fopen("outIJK_Bloco_Sequencial.map-result","w");
			fileout_matriz(matFim, N, M, fmat_c);
		}
		mediaSeqBlock = mediaSeqBlock/10;

		// Multiplicacao IKJ Normal OMP
		for(int i=0; i<10; i++){
			zerar_matriz(mat_d, N, M);
			start_time = wtime();
			multiplicarOMP(mat_a,mat_b,mat_d, N, La, M, n_threads);
			end_time = wtime();
			mediaThNor += end_time - start_time;
			fmat_c= fopen("outIJK_Thread.map-result","w");
			fileout_matriz(mat_d, N, M, fmat_c);
		}
		mediaThNor = mediaThNor/10;

		// Multiplicacao IJK Bloco OMP
		for(int i=0; i<10; i++){
			zerar_matriz(matFim2, N, M);
			start_time = wtime();
			Vsubmat_a = particionar_matriz (mat_a, N, La, 1, divisor);
			Vsubmat_b = particionar_matriz (mat_b, Lb, M, 0, divisor);
			Vsubmat_c = constroi_submatrizv2 (N, M, divisor);
			multiplicarOMPBlocos(Vsubmat_a, Vsubmat_b, Vsubmat_c, matFim2, divisor, n_threads);
			end_time = wtime();
			mediaThBlock += end_time - start_time;
			fmat_c= fopen("outIJK_Bloco_Thread.map-result","w");
			fileout_matriz(matFim2, N, M, fmat_c);
		}
		mediaThBlock = mediaThBlock/10;





		printf("Comparar Matrizes\n\n");
		printf("Sequencial Normal/Sequencial Bloco\n");
		comparar_matriz (mat_c, matFim, N, M);
		printf("Sequencial Normal/OMP Normal\n");
		comparar_matriz (mat_c, mat_d, N, M);
		printf("Sequencial Normal/OMP Bloco\n");
		comparar_matriz (mat_c, matFim2, N, M);
		printf("\n\n\n");

		printf("Medias de Tempo\n\n");
		printf("Tempo Medio - Normal Sequencial: %f\n\n", mediaSeqNor);
		printf("Tempo Medio - Bloco Sequencial: %f\n\n", mediaSeqBlock);
		printf("Tempo Medio - Normal OMP: %f\n\n", mediaThNor);
		printf("Tempo Medio - Bloco OMP %f\n\n", mediaThBlock);
		printf("\n\n\n");

		printf("Speedup\n\n");
		printf("Speedup Multiplicação Normal: %f\n\n", mediaSeqNor/mediaThNor);
		printf("Speedup Multiplicação Blocos: %f\n\n", mediaSeqBlock/mediaThBlock);
		printf("Resultados individuais encontram-se nos arquivos <out*.map-result>.\n");


		//test zone

		//finished

	  // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
		// LIBERAR MEMÓRIA
		liberar_submatriz (Vsubmat_a,divisor);
		liberar_submatriz (Vsubmat_b,divisor);
		liberar_submatriz (Vsubmat_c,divisor);

		liberar_matriz(mat_a,N,La);
		liberar_matriz(mat_b,Lb,M);
		liberar_matriz(mat_c,N,M);
		liberar_matriz(mat_d,N,M);
		liberar_matriz(matFim,N,M);
		liberar_matriz(matFim2,N,M);

		fclose(fmat_a);
		fclose(fmat_b);
		fclose(fmat_c);
	}
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	return 0;
}
