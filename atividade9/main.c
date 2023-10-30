#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]){

    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL)))));
    No* n3 = no('U', NULL);
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);
    lista_imprimir(n0);
    printf("\nqtd nos: %d", lista_quantidade_nos(n0));
    No* n_copia = lista_copiar(n0);
    printf("\n");
    lista_imprimir(n_copia);
    lista_concatenar(n0, n_copia);
    printf("\n");
    lista_imprimir(n0);
    lista_liberar(n0);
    n0 = NULL;
    lista_imprimir(n0);
    No* minhaLista = lista_criar();

    lista_inserir_inicio(minhaLista, 'A');
    lista_inserir_inicio(minhaLista, 'B');
    lista_inserir_inicio(minhaLista, 'A');
    lista_inserir_inicio(minhaLista, 'C');
    lista_inserir_inicio(minhaLista, 'A');

    printf("Lista original: ");
    lista_imprimir(minhaLista);

    char valor_busca = 'A';
    int existe = lista_verificar_existencia(minhaLista, valor_busca);
    int ocorrencias = lista_verificar_ocorrencias(minhaLista, valor_busca);

    printf("O valor '%c' existe na lista: %s\n", valor_busca, existe ? "Sim" : "Não");
    printf("Quantidade de ocorrencias de '%c': %d\n");

    int main(int argc, char* argv[]) {
    No* lista_nao_ordenada = lista_criar();
    No* lista_ordenada = lista_criar();

    FILE* arquivo = fopen("1kk_rand_float.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    char linha[20];
    clock_t start, end;
    double tempo_nao_ordenado = 0.0;
    double tempo_ordenado = 0.0;
    int contador = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        float valor;
        if (sscanf(linha, "%f", &valor) == 1) {
            No* novo_no = no((char)valor, NULL);

            start = clock();
            lista_inserir_no(lista_nao_ordenada, novo_no);
            end = clock();
            tempo_nao_ordenado += (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            lista_inserir_no_ordenado(lista_ordenada, novo_no);
            end = clock();
            tempo_ordenado += (double)(end - start) / CLOCKS_PER_SEC;

            contador++;
        }
    }

    fclose(arquivo);

    printf("Tempo médio de inserção em lista não ordenada: %f segundos\n", tempo_nao_ordenado / contador);
    printf("Tempo médio de inserção em lista ordenada: %f segundos\n", tempo_ordenado / contador);

    lista_liberar(lista_nao_ordenada);
    lista_liberar(lista_ordenada);

    return 0;
}

    exit(0);
}