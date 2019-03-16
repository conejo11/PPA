# ALGORITMOS DE ORDENAÇÃO
Primeiro exercício, este arquivo documenta como executá-lo.

# COMPILAR
Para compilar o arquivo utilize o comando no terminal:
  - make (compila todos os arquivos)
  - make sort (compila os arquivos da biblioteca de ordenação)
  - make gera_vector (compila os arquivos da bibliotaca que gera o arquivo)
  - make help (irá gerar um arquivo de tamanho 10 e apresentar informações na tela)
  - make clean (remove arquivos de compilação)

É recomendado utilizar apenas o comando "make" para que tudo seja compilado. Para recompilar
é necessário primeiro utilizar o comando "make clean" para depois utilizar "make" novamente.

# GERAR ARQUIVO/VETORES
Para gerar um arquivo de tamanho diferente de 10 utilize o comando
 - ./gera_vector <tamanho vetor> -9999

Exemplo para vetor de tamanho 100:
 - ./gera_vector 100 -9999

# EXECUTAR APLICAÇÃO
Para executar a aplicação utilize o comando:
 - ./sort vector-<tamanho>.map

Exemplo para vetor de tamanho 10:
 - ./sort vector-10.map

# DENTRO DA APLICAÇÃO
Será impresso em tela o vetor desordenado e um número de 1 à 3 será solicitado:
 - 1: Quicksort
 - 2: Bubblesort
 - 3: Mergesort

Após isso se o número correto for inserido, o vetor ordenado utilizando o algoritmo solicitado
será impresso junto ao tempo de execução. Para utilizar outro algoritmo o programa deverá ser executado novamente. 
