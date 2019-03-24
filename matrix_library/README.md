# FUNÇÕES PARA ALOCAÇÃO, LIBERAÇÃO, COMPARAÇÃO, GERAÇÃO E IMPRESSÃO DE MATRIZES
Segundo exercício, este arquivo documenta como executá-lo.

# COMPILAR
Para compilar o arquivo utilize o comando no terminal:
  - make (compila todos os arquivos)
  - make main_matriz (compila os arquivos da função main)
  - make gera_matriz2 (compila os arquivos da bibliotaca que gera a matriz)
  - make help (irá apresentar um exemplo de comando para execução)
  - make clean (remove arquivos de compilação)

É recomendado utilizar apenas o comando "make" para que tudo seja compilado.

# GERAR ARQUIVO/MATRIZES
Para gerar uma matriz aleatória:
 - ./gera_matriz2 (linhas) (colunas)

para gerar uma matriz em ordem crescente:
  - Entre no arquivo gera_matriz2.c e substitua a linha 35:
    - gerar_matriz(mat0, linha, coluna, -9999) => gerar_matriz(mat0, linha, coluna, -8888);

para gerar uma matriz em ordem decrescente:
  - Entre no arquivo gera_matriz2.c e substitua a linha 35:
    - gerar_matriz(mat0, linha, coluna, -9999) => gerar_matriz(mat0, linha, coluna, -7777);

Exemplo para matriz 50 x 100:
 - ./gera_matriz2 50 100

# EXECUTAR APLICAÇÃO
Para executar a aplicação utilize o comando:
 - ./main_matriz (dimensões)-mat.map (dimensões)-mat.map

Exemplo para matriz 50x100 e 100x50:
 - ./main_matriz 50x100-mat.map 100x50-mat.map

# DENTRO DA APLICAÇÃO
As duas matrizes serão lidas, alocadas e uma terceira matriz NxM será criada e preenchida com zeros.

As três matrizes serão impressas em tela.

Uma comparação da matriz A com a matriz B será realizada (Muito provavelmente serão diferentes devido a aaleatoriedade).

Uma comparação da matriz A será feita com ela mesma (precisa mostrar que são identicas).

O arquivo "out*.map-result" ainda não é gerado nesta versão inicial.

Os ponteiros serão desalocados e os arquivos fechados.

# INFORMAÇÕES ADICIONAIS
o arquivo main_matriz.c apresenta um código simples comentado em seu início para realizar um teste mais direto das funções implementadas. Caso queira utilizálo comente todo o código das linhas 42 até 202 e descomente todo o código da linha 1 até 41. Após isso compile novamente. Para executar a versão mais simples da main é necessário apenas um arquivo de matriz.
