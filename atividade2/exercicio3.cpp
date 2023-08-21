#include <stdio.h>
#include <string.h>

int busca_string(char *array[], int tamanho, char *busca) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(array[i], busca) == 0) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    char *array[] = {"texto", "J", "EDA"};
    char *busca = "EDO";
    int tamanho = sizeof(array) / sizeof(array[0]);

    int resultado = busca_string(array, tamanho, busca);
    printf("Saida: %d\n", resultado);

    return 0;
}

