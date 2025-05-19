#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água (valor 0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Coordenadas iniciais do navio horizontal
    int linha_h = 2;
    int coluna_h = 4;

    // Coordenadas iniciais do navio vertical
    int linha_v = 5;
    int coluna_v = 6;

    // Validação simples para garantir que os navios cabem no tabuleiro
    if (coluna_h + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linha_v + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // Posiciona navio horizontal na linha_h
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_h][coluna_h + i] = VALOR_NAVIO;
        }

        // Posiciona navio vertical na coluna_v
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se já existe um navio nessa posição (evita sobreposição)
            if (tabuleiro[linha_v + i][coluna_v] == VALOR_NAVIO) {
                printf("Erro: sobreposição de navios detectada.\n");
                return 1;
            }
            tabuleiro[linha_v + i][coluna_v] = VALOR_NAVIO;
        }

    } else {
        printf("Erro: coordenadas inválidas para posicionar navios.\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}