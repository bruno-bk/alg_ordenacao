#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"

long comparisons_q = 0;
long swap_q = 0;

long particao(int *A, long inicio, long fim){
    swap_q++;
    long pivo = A[fim];
    long i = inicio - 1;

    for (long j = inicio; j<fim; j++){
        comparisons_q++;
        if (A[j] < pivo){
            i++;
            swap_q++;
            long aux = A[i];
            swap_q++;
            A[i] = A[j];
            swap_q++;
            A[j] = aux; 
        }
    }
    swap_q++;
    long aux2 = A[i + 1];
    swap_q++;
    A[i + 1] = A[fim];
    swap_q++;
    A[fim] = aux2;

    return i + 1;
}

long particao_aleatoria(int *A, long inicio, long fim){
    long k = inicio + rand() % (fim - inicio);
    swap_q++;
    long aux = A[k];
    swap_q++;
    A[k] = A[fim];
    swap_q++;
    A[fim] = aux;

    return particao(A, inicio, fim);
}

void ordena(int *A, long inicio, long fim){
    comparisons_q++;
    if (inicio < fim){
        long pivo = particao_aleatoria(A, inicio, fim);
        ordena(A, inicio, pivo - 1);
        ordena(A, pivo + 1, fim);
    }
    return;
}

void quick_sort(int *A, long n, long results[]) {
    ordena(A, 0, n-1);

    results[0] = comparisons_q;
    results[1] = swap_q;
}
