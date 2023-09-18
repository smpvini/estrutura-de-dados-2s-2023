#include "bubble_sort.h"

// função para trocar dois elementos de um array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// função para ordenar a lista usando o algoritmo Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // troca os elementos se estiverem fora de ordem
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
