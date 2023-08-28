#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Ponto;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s dados.csv\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int numRegistros = 0;
    char ch;
    while ((ch = fgetc(arquivo)) != EOF) {
        if (ch == '\n') {
            numRegistros++;
        }
    }
    rewind(arquivo);

    Ponto *pontos = (Ponto *)malloc(numRegistros * sizeof(Ponto));
    if (!pontos) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    double somaX = 0.0, somaY = 0.0;
    for (int i = 0; i < numRegistros; i++) {
        fscanf(arquivo, "%lf,%lf", &pontos[i].x, &pontos[i].y);
        somaX += pontos[i].x;
        somaY += pontos[i].y;
    }
    fclose(arquivo);

    double mediaX = somaX / numRegistros;
    double mediaY = somaY / numRegistros;

    double somaXY = 0.0, somaXQuadrado = 0.0;
    for (int i = 0; i < numRegistros; i++) {
        somaXY += (pontos[i].x - mediaX) * (pontos[i].y - mediaY);
        somaXQuadrado += (pontos[i].x - mediaX) * (pontos[i].x - mediaX);
    }

    double coeficienteAngular = somaXY / somaXQuadrado;
    double coeficienteLinear = mediaY - coeficienteAngular * mediaX;

    printf("Equação da regressão linear: y = %.4f * x + %.4f\n", coeficienteAngular, coeficienteLinear);

    free(pontos);

    return 0;
}

