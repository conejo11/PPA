# FUNÇÕES PARA OPERAÇÕES COM MATRIZES
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
O código executado é o apresentado pelo professor no moodle para o teste desta atividade.

# INFORMAÇÕES ADICIONAIS
Testes foram adicionados para verificar se as matrizes atendem os critérios para soma e multiplicação.

Caso deixe dentro do código como o professor colocou no main de exemplo:
  - somarIJ(mat_a,mat_a,mat_somaIJ, N, N, N);
Não irá funcionar devido ao teste da propriedade de adição e multiplicação que compara as dimensões de A e B,
a soma e multiplicação devem ser sempre da matriz A com a matriz B, exemplo:
  - somarIJ(mat_a,mat_b,mat_somaIJ, N, N, N);

Para comparar a matriz A com ela mesma passe-a como parâmetro 2 vezes ao executar a aplicação:
  - ./main_matriz mat_a.map mat_a.map
