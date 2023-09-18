#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_entrada>\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];

    // abrir o arquivo de entrada
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Erro ao abrir o arquivo de entrada '%s'.\n", inputFileName);
        return 1;
    }

    // ler as palavras do arquivo
    char **words = NULL;
    int numWords = 0;
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        // remove a quebra de linha do final
        buffer[strcspn(buffer, "\n")] = '\0';

        // aloca espaço para a palavra e a copia
        char *word = strdup(buffer);

        // adiciona a palavra ao array
        words = (char **)realloc(words, (numWords + 1) * sizeof(char *));
        words[numWords] = word;
        numWords++;
    }

    fclose(inputFile);

    // chama a função de ordenação
    bubbleSort(words, numWords);

    // cria o nome do arquivo de saída
    char *outputFileName = malloc(strlen(inputFileName) + 15);
    sprintf(outputFileName, "%s_ordenado.txt", inputFileName);

    // abrir o arquivo de saída
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Erro ao criar o arquivo de saída '%s'.\n", outputFileName);
        return 1;
    }

    // escreve as palavras ordenadas no arquivo de saída
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\n", words[i]);
        free(words[i]);
    }

    fclose(outputFile);
    free(words);
    free(outputFileName);

    printf("Palavras ordenadas com sucesso em '%s'.\n", outputFileName);

    return 0;
}
