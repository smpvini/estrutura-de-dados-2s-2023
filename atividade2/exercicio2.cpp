#include <stdio.h>

void menor_maior_array(int arr[], int size, int *menor, int *maior) {
    if (size <= 0) {
        printf("O array está vazio.\n");
        return;
    }
    
    *menor = arr[0];
    *maior = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < *menor) {
            *menor = arr[i];
        }
        if (arr[i] > *maior) {
            *maior = arr[i];
        }
    }
}

int main() {
    int arr[] = {5, 7, 9, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int menor, maior;

    menor_maior_array(arr, size, &menor, &maior);
    printf("Menor elemento: %d\n", menor);
    printf("Maior elemento: %d\n", maior);

    return 0;
}

