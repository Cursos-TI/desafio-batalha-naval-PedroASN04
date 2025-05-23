#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializar o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posição inicial dos navios
    int linha_horizontal = 1, coluna_horizontal = 2; // horizontal
    int linha_vertical = 4, coluna_vertical = 5;     // vertical
    int linha_diagonal1 = 0, coluna_diagonal1 = 0;   // diagonal principal
    int linha_diagonal2 = 0, coluna_diagonal2 = 9;   // diagonal secundária

    // Posicionar navio horizontalmente (tamanho 3)
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }

    // Posicionar navio verticalmente (tamanho 3)
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
    }

    // Posicionar navio na diagonal principal (tamanho 3)
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] = 3;
    }

    // Posicionar navio na diagonal secundária (tamanho 3)
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha_diagonal2 + i][coluna_diagonal2 - i] = 3;
    }

    // Exibir o tabuleiro
    printf("Tabuleiro Batalha Naval:\\n\\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\\n");
    }

    return 0;
}
