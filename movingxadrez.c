#include <stdio.h>

int main() {

    // ==============================
    // 1️⃣ TORRE - usando estrutura FOR
    // ==============================
    // A torre move-se em linha reta, neste caso 5 casas para a direita.
    int casasTorre = 5;

    printf("=== Movimento da TORRE ===\n");
    for (int i = 1; i <= casasTorre; i++) {
        printf("Casa %d: Direita\n", i);
    }

    // ==============================
    // 2️⃣ BISPO - usando estrutura WHILE
    // ==============================
    // O bispo move-se na diagonal, neste caso 5 casas para cima e à direita.
    int casasBispo = 5;
    int i = 1;

    printf("\n=== Movimento do BISPO ===\n");
    while (i <= casasBispo) {
        printf("Casa %d: Cima, Direita\n", i);
        i++;
    }

    // ==============================
    // 3️⃣ RAINHA - usando estrutura DO-WHILE
    // ==============================
    // A rainha move-se em qualquer direção, neste caso 8 casas para a esquerda.
    int casasRainha = 8;
    int j = 1;

    printf("\n=== Movimento da RAINHA ===\n");
    do {
        printf("Casa %d: Esquerda\n", j);
        j++;
    } while (j <= casasRainha);

    // ==============================
    // FIM DO PROGRAMA
    // ==============================
    printf("\nSimulação finalizada com sucesso!\n");

    return 0;
}