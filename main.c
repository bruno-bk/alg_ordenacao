#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>

#include "bubblesort.h"
#include "improved_bubblesort.h"
#include "quicksort.h"
#include "insertionsort.h"
#include "selectionsort.h"
#include "heapsort.h"
#include "mergesort.h"

typedef void (*FunctionPointer)(int[], int, long[]);

int rand_number(int min, int max){
    return ((rand() % (max-1 - min + 1)) + min);
}

void print_vet(int vet[], int n){
    int i;
    if(n > 100){
        for (i = 0; i < 50; i++){
            printf("%d ",  vet[i]);
        }
        printf("... ");
        for (i=n-50; i<n; i++){
            printf("%d ",  vet[i]);
        }
    } else {
        for (i=0; i<n; i++){
            printf("%d ",  vet[i]);
        }
    }
    printf("\n");
}

float calcula_tempo(FunctionPointer ptr, int A[], int n, long results[]) {
    struct timeval tempo_ini, tempo_fim;
    gettimeofday(&tempo_ini, NULL);

    ptr(A,n, results);

    gettimeofday(&tempo_fim, NULL);

    uint32_t seconds = (tempo_fim.tv_sec - tempo_ini.tv_sec);
    uint32_t micros = ((seconds * 1000000) + tempo_fim.tv_usec) - (tempo_ini.tv_usec);
    return ((float)micros/1000000);
}

int main(void) {
    float tempo = 0;
    uint32_t elements = 0;

    time_t t;
    srand((unsigned) time(&t));

    char *complexidade[] = {"Melhor caso", "Caso medio", "Pior caso"};
    char *names[] = {"Bubble sort", "Improved Bubble sort", "Insertion sort", "Selection sort", "Merge sort", "Quick sort", "Heap sort"};
    void *functions[] = {bubble_sort, improved_bubble_sort, insertion_sort, selection_sort, merge_sort, quick_sort, heap_sort};

    for (int l = 3; l <= 5; l++){
        elements = (int)pow(10, l);

        printf("Conjunto com %d elementos\n\n", elements);
        uint32_t rand_values[elements];
        uint32_t dados[3][elements];

        for(int k = 0; k < elements; k++){
            rand_values[k] = rand_number(0, elements);
        }

        for (int i = 0; i < 7; i++) { //repetição dos algoritimos
            for(int k = 0; k < elements; k++) {
                dados[0][k] = k;
                dados[1][k] = rand_values[k];
                dados[2][k] = elements-k;
            }

            printf("Algoritimo: %s\n", names[i]);

            for (int j = 0; j < 3; j++) {
                long results[2] = {0 ,0};
                // print_vet(dados[j], elements);
                tempo = calcula_tempo(functions[i], dados[j], elements, results);
                // print_vet(dados[j], elements);
                printf("%s: Comp %ld | Trocas %ld | Tempo %fs\n", complexidade[j], results[0], results[1], tempo);
            }
            printf("\n");
        }
    }

    return 0;
}
