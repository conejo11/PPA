# GNU Makefile

CC = mpicc
CCFLAGS = -Wall -O3 -pthread -fopenmp #-llikwid #-funroll-all-loops
LDFLAGS =
TARGET = main_matriz gera_matriz2 help
EXE = ./gera_matriz2

all: $(TARGET)

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

%: %.o
	$(CC) $(LDFLAGS) $^ -o $@

main_matriz: main_matriz.c matriz.o toolsv2.o matriz-operacoes.o matriz-operacoes-threads.o matriz-operacoes-omp.o multiplicarMPI.o
	$(CC) $(CCFLAGS) multiplicarMPI.o matriz-operacoes-omp.o matriz-operacoes-threads.o matriz-operacoes.o matriz.o toolsv2.o main_matriz.c -o $@ $(LDFLAGS)

gera_matriz2: matriz.o toolsv2.o gera_matriz2.c
	$(CC) $(CCFLAGS) matriz.o toolsv2.o gera_matriz2.c -o $@ $(LDFLAGS)


help:
	@echo
	@echo
	@echo "####### Exemplo de Geração de Matriz #######"
	@echo "./gera_matriz2 100 200"
	@echo
	@echo
	@echo "####### Exemplo de Execução #######"
	@echo "./main_matriz mat_a3x4.example mat_b4x3.example 20 4 "
	@echo
	@echo

clean:
	rm -f *.o *~ $(TARGET) *.map *.map-result
