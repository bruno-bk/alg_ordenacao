#include <stdio.h>
#include <stdlib.h>

#include "improved_bubblesort.h"

void improved_bubble_sort(int *A, int n, long results[]){
    int ordenado = 1;
    long comparisons = 0;
    long swap = 0;

    for(long i = 0; i < n; i++){
        for(long j = 0; j < n - i - 1; j++){
            comparisons++;
            if (A[j] > A[j + 1]){
                ordenado = 0;
                swap++;
                int aux = A[j];
                swap++;
                A[j] = A[j + 1];
                swap++;
                A[j + 1] = aux;
            }
        }
        comparisons++;
        if (ordenado == 1) {
            results[0] = comparisons;
            results[1] = swap;
            return;
        }
    }

    results[0] = comparisons;
    results[1] = swap;
    return;
}