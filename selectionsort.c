#include <stdio.h>
#include <stdlib.h>

#include "selectionsort.h"

void selection_sort(int *a, int n, long results[]) {
    long comparisons = 0;
    long swap = 0;

    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            comparisons++;
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }

        swap++;
        int temp = a[i];
        swap++;
        a[i] = a[min_idx];
        swap++;
        a[min_idx] = temp;
    }

    results[0] = comparisons;
    results[1] = swap;
}

