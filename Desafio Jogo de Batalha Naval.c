#include <stdio.h>

#define TAMANHO 10     // Tamanho fixo do tabuleiro 10x10
#define NAVIO 3        // Valor que representa o navio
#define TAM_NAVIO 3    // Cada navio ocupa 3 posições

int main() {
    int tabuleiro[TAMANHO][TAMANHO]; // Matriz 10x10 que representa o tabuleiro
    int i, j;

    // --- 1. Inicializar o tabuleiro com 0 (água)
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // --- 2. Coordenadas iniciais dos navios ---
    // Definidas diretamente no código conforme o enunciado
    int linhaVertical = 2;   // Linha inicial do navio vertical
    int colunaVertical = 4;  // Coluna fixa do navio vertical
    int linhaHorizontal = 6; // Linha fixa do navio horizontal
    int colunaHorizontal = 1;// Coluna inicial do navio horizontal

    // --- 3. Validação simples para garantir que cabem no tabuleiro ---
    if (linhaVertical + TAM_NAVIO > TAMANHO || colunaVertical >= TAMANHO ||
        linhaHorizontal >= TAMANHO || colunaHorizontal + TAM_NAVIO > TAMANHO) {
        printf("Erro: as coordenadas dos navios ultrapassam o limite do tabuleiro.\n");
        return 1;
    }

    // --- 4. Posicionar o navio vertical ---
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = NAVIO;
    }

    // --- 5. Posicionar o navio horizontal (garantindo que não sobrepõe o outro) ---
    int sobreposicao = 0;
    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaHorizontal][colunaHorizontal + i] == NAVIO) {
            sobreposicao = 1;
        }
    }

    if (sobreposicao) {
        printf("Erro: os navios se sobrepõem!\n");
        return 1;
    }

    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = NAVIO;
    }

    // --- 6. Exibir o tabuleiro ---
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
