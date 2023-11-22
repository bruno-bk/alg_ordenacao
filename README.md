# Análise de Desempenho de Algoritmos de Ordenação

## Visão Geral

Este programa em C realiza uma análise comparativa de vários algoritmos de ordenação, incluindo Bubble Sort, Improved Bubble Sort, Insertion Sort, Selection Sort, Merge Sort, Quick Sort e Heap Sort. A análise abrange diferentes cenários, incluindo melhor caso, caso médio e pior caso.

## Pré-requisitos
Certifique-se de ter um compilador C instalado em seu sistema antes de executar este programa.

## Compilação
Para compilar o programa, use o seguinte comando:

```bash
gcc main.c bubblesort.c improved_bubblesort.c quicksort.c insertionsort.c selectionsort.c heapsort.c mergesort.c -lm -o sorting_analysis
```

## Execução
Execute o programa compilado com o seguinte comando:

```bash
./sorting_analysis
```

## Descrição

* O programa gera vetores de diversos tamanhos (variando de 10^3 a 10^5 elementos) preenchidos com valores aleatórios, já ordenados e ordenados inversamente.
* Mede o tempo de execução, o número de comparações e o número de trocas para cada algoritmo de ordenação em diferentes cenários (melhor caso, caso médio e pior caso).
* Os resultados são exibidos, mostrando o nome do algoritmo, tipo de complexidade, número de comparações, número de trocas e tempo de execução.

## Arquivos
* main.c: Contém a lógica principal do programa.
* bubblesort.h, improved_bubblesort.h, quicksort.h, insertionsort.h, selectionsort.h, heapsort.h, mergesort.h: Arquivos de cabeçalho para algoritmos de ordenação.
* bubblesort.c, improved_bubblesort.c, quicksort.c, insertionsort.c, selectionsort.c, heapsort.c, mergesort.c: Arquivos de implementação para algoritmos de ordenação.

## Customização
Você pode modificar o programa ajustando parâmetros como o intervalo de elementos do array, adicionando ou removendo algoritmos de ordenação ou alterando os tipos de cenários analisados.
Sinta-se à vontade para experimentar e adaptar o programa às suas necessidades específicas.
