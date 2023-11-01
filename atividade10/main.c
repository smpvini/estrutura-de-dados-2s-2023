#include <stdio.h>
#include "tabela_hash.h"

int main() {
    hash_table_init();

    hash_table_put("chave1", "valor1");
    hash_table_put("chave2", "valor2");

    printf("Valor associado à chave1: %s\n", hash_table_get("chave1"));
    printf("Valor associado à chave2: %s\n", hash_table_get("chave2"));

    if (hash_table_contains("chave3")) {
        printf("A chave3 está na tabela.\n");
    } else {
        printf("A chave3 não está na tabela.\n");
    }

    hash_table_remove("chave1");
    printf("Valor associado à chave1 após remoção: %s\n", hash_table_get("chave1"));

    hash_table_destroy();

    return 0;
}
