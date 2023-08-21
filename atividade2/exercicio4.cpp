#include <stdio.h>

int conta_int_array(int array[], int tamanho, int numeroBusca) {
    int contagem = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == numeroBusca) {
            contagem++;
        }
    }
    
    return contagem;
}

int main() {
    int numeros[] = {5, 7, 9, 6, 7, 11, 6, 5};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int numeroBusca = 7;
    
    int resultado = conta_int_array(numeros, tamanho, numeroBusca);
    
    printf("O numero %d aparece %d vezes no array.\n", numeroBusca, resultado);
    
    return 0;
}

