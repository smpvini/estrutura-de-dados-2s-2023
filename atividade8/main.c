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

    exit(0);
}