#include <stdio.h>

int soma_array(int arr[], int tamanho) {
    int soma = 0;
    int i;  
    for (i = 0; i < tamanho; i++) {
        soma += arr[i];
    }
    return soma;
}

int main() {
    int array_exemplo[] = {5, 7, 9, 6};
    int tamanho = sizeof(array_exemplo) / sizeof(array_exemplo[0]);
    
    int resultado = soma_array(array_exemplo, tamanho);
    printf("Resultado: %d\n", resultado);  
    
    return 0;
}

