#include <stdio.h>
#include <stdlib.h>

#include "insertionsort.h"

void insertion_sort(int *a, int n, long results[]) {
    long comparisons = 0;
    long swap = 0;

    int i, chave, j;
    for (i = 1; i < n; i++) {
        swap++;
        chave = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > chave) {
            comparisons++;
            swap++;
            a[j + 1] = a[j];
            j--;
        }
        comparisons++;

        swap++;
        a[j + 1] = chave;
    }

    results[0] = comparisons;
    results[1] = swap;
}
