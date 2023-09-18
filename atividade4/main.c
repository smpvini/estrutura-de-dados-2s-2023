#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <num1> <num2> <num3> ... <numN>\n", argv[0]);
        return 1;
    }

    int n = argc - 1; // número de elementos na lista
    int *arr = (int *)malloc(n * sizeof(int));

    // preenche o array com os números fornecidos como argumentos
    for (int i = 1; i <= n; i++) {
        arr[i - 1] = atoi(argv[i]);
    }

    // chama a função Bubble Sort para ordenar a lista
    bubbleSort(arr, n);

    // imprime a lista ordenada
    printf("Saída: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // libera a memória alocada para o array

    return 0;
}
