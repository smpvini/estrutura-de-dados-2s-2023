#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void lista_inserir_no(No* L, No* no){
    if(L != NULL){
        if(L->proximo_no == NULL){
            L->proximo_no = no;
        }
        else{
            lista_inserir_no(L->proximo_no, no);
        }
    }
}

void lista_imprimir(No* L){
    if(L != NULL){
        printf("%c ", L->valor);
        lista_imprimir(L->proximo_no);
    }
}

int lista_quantidade_nos(No* L){
    if(L != NULL){
        return 1 + lista_quantidade_nos(L->proximo_no);
    }
    return 0;
}

No* lista_copiar(No* L){
    if(L != NULL){
        return no(L->valor, lista_copiar(L->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No* L, No* Lc){
    lista_inserir_no(L, Lc);
}

void lista_liberar(No* L){
    if(L != NULL){
        lista_liberar(L->proximo_no);
        free(L);
    }
}

No* lista_criar() {
    No* cabeca = (No*)malloc(sizeof(No));
    cabeca->proximo = NULL;
    return cabeca;
}

void lista_inserir_inicio(No* L, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = L->proximo;
    L->proximo = novo_no;
}

void lista_imprimir(No* L) {
    No* atual = L->proximo;
    while (atual != NULL) {
        printf("%c ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1; // Valor encontrado
        }
        atual = atual->proximo;
    }
    return 0; // Valor não encontrado
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int ocorrencias = 0;
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            ocorrencias++;
        }
        atual = atual->proximo;
    }
    return ocorrencias;
}

void lista_imprimir_inversa(No* L) {
    if (L->proximo == NULL) {
        return; // Lista vazia
    }
    No* atual = L->proximo;
    No* anterior = NULL;
    No* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    L->proximo = anterior;

    lista_imprimir(L);

    // Restaurar a ordem original da lista
    atual = anterior;
    anterior = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    L->proximo = anterior;
}

void lista_inserir_no_i(No* L, int i, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    No* atual = L;

    for (int j = 0; j < i; j++) {
        if (atual->proximo == NULL) {
            printf("Posição inválida.\n");
            free(novo_no);
            return;
        }
        atual = atual->proximo;
    }

    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
}

void lista_remover_no_i(No* L, int i) {
    No* atual = L;
    for (int j = 0; j < i; j++) {
        if (atual->proximo == NULL) {
            printf("Posição inválida.\n");
            return;
        }
        atual = atual->proximo;
    }

    if (atual->proximo != NULL) {
        No* no_remover = atual->proximo;
        atual->proximo = no_remover->proximo;
        free(no_remover);
    }
}

void lista_remover_no(No* L, char valor_busca) {
    No* atual = L;
    while (atual->proximo != NULL) {
        if (atual->proximo->valor == valor_busca) {
            No* no_remover = atual->proximo;
            atual->proximo = no_remover->proximo;
            free(no_remover);
        } else {
            atual = atual->proximo;
        }
    }
}

void lista_destruir(No* L) {
    No* atual = L->proximo;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(L);
}

#endif