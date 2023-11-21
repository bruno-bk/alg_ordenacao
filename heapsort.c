#include <stdio.h>
#include <stdlib.h>

#include "heapsort.h"

long comparisons_h = 0;
long swap_h = 0;

void heapify(int *A, int n, int i){
    int maior = i;
    int esquerda = (2*i) + 1; 
    int direita = (2*i) + 2;

    comparisons_h++;
    if (esquerda < n & A[esquerda] > A[maior]){
        maior = esquerda;
    }

    comparisons_h++;
    if (direita < n & A[direita] > A[maior]){
        maior = direita;
    }

    comparisons_h++;
    if(maior != i){
        swap_h++;
        int aux = A[i];
        swap_h++;
        A[i] = A[maior];
        swap_h++;
        A[maior] = aux; 

        heapify(A, n, maior);
    }
    
    return;
}

void heap_sort(int *A, int n, long results[]){
    for(long i = (n/2)-1; i>=0; i--){
        heapify(A, n, i);
    }

    for(long i = n-1; i>=1; i--){
        swap_h++;
        int aux = A[0];
        swap_h++;
        A[0] = A[i];
        swap_h++;
        A[i] = aux; 
        heapify(A, i, 0);
    }

    results[0] = comparisons_h;
    results[1] = swap_h;
}