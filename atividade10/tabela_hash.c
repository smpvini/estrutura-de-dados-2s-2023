#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct {
    char* chave;
    char* dado;
} HashEntry;

HashEntry* tabela[TABLE_SIZE];

void hash_table_init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela[i] = NULL;
    }
}

int hash(char* chave) {
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i];
    }
    return hash % TABLE_SIZE;
}

char* hash_table_get(char* chave) {
    int index = hash(chave);
    if (tabela[index] != NULL) {
        return tabela[index]->dado;
    } else {
        return NULL;
    }
}

void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);
    HashEntry* entry = malloc(sizeof(HashEntry));
    entry->chave = strdup(chave);
    entry->dado = strdup(dado);
    tabela[index] = entry;
}

int hash_table_contains(char* chave) {
    int index = hash(chave);
    return tabela[index] != NULL;
}

void hash_table_remove(char* chave) {
    int index = hash(chave);
    if (tabela[index] != NULL) {
        free(tabela[index]->chave);
        free(tabela[index]->dado);
        free(tabela[index]);
        tabela[index] = NULL;
    }
}

void hash_table_destroy() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (tabela[i] != NULL) {
            free(tabela[i]->chave);
            free(tabela[i]->dado);
            free(tabela[i]);
        }
    }
}

#endif
