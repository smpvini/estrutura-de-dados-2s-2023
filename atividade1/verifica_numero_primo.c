#include <stdio.h>
#include <stdlib.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0; 
    }

    int i = 2;
    int limit = i * i; 

    while (limit <= num) {
        if (num % i == 0) {
            return 0; 
        }

        i++;
        limit = i * i; 
    }

    return 1; 
}

int main() {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (is_prime(numero)) {
        printf("1 - O numero %d e primo.\n", numero);
    } else {
        printf("0 - O numero %d nao e primo.\n", numero);
    }

    return 0;
}

