#include <string.h>
#include "bubble_sort.h"

// função para trocar duas palavras
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// função para ordenar o array de palavras usando o algoritmo Bubble Sort
void bubbleSort(char *arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                // troca as palavras se estiverem fora de ordem
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
