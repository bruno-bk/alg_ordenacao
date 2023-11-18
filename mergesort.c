#include <stdio.h>
#include <stdlib.h>

#include "mergesort.h"

long comparisons = 0;
long swap = 0;

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    
    int L[n1], M[n2];
    
    for (int i = 0; i < n1; i++) {
        swap++;
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        swap++;
        M[j] = arr[q + 1 + j];
    }
    
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= M[j]) {
            swap++;
            arr[k] = L[i];
            i++;
        } else {
            swap++;
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        swap++;
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        swap++;
        arr[k] = M[j];
        j++;
        k++;
    }
}

void merge_loop(int arr[], int l, int r) {
    comparisons++;
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_loop(arr, l, m);
        merge_loop(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void merge_sort(int *A, int n, long results[]) {
    merge_loop(A, 0, n-1);

    results[0] = comparisons;
    results[1] = swap;
}
