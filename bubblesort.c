#include <stdio.h>
#include <stdlib.h>

#include "bubblesort.h"

void bubble_sort(int *A, int n, long results[]) {
    long comparisons = 0;
    long swap = 0;

    for (long i = 0; i < n; i++) {
        for (long j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (A[j] > A[j + 1]) {
                swap++;
                int aux = A[j];
                swap++;
                A[j] = A[j + 1];
                swap++;
                A[j + 1] = aux;
            }
        }
    }

    results[0] = comparisons;
    results[1] = swap;
}
