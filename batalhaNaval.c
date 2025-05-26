#include <stdio.h>

#define TAM 10
#define TAM_HAB 5

// Função para inicializar o tabuleiro com 0
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para posicionar navio horizontal
void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
}

// Função para posicionar navio vertical
void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
}

// Função para posicionar navio diagonal principal
void posicionarNavioDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }
}

// Função para posicionar navio diagonal secundária
void posicionarNavioDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha + i][coluna - i] = 3;
    }
}

// Função para construir habilidade em forma de cone
void construirHabilidadeCone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            habilidade[i][j] = 0;
        }
    }
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = TAM_HAB / 2 - i; j <= TAM_HAB / 2 + i; j++) {
            if (j >= 0 && j < TAM_HAB) {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Função para construir habilidade em forma de cruz
void construirHabilidadeCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Função para construir habilidade em forma de octaedro
void construirHabilidadeOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Função para aplicar habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = origem_linha - TAM_HAB / 2 + i;
            int coluna = origem_coluna - TAM_HAB / 2 + j;

            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] == 0)
                    tabuleiro[linha][coluna] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int habilidade[TAM_HAB][TAM_HAB];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Posiciona os navios
    posicionarNavioHorizontal(tabuleiro, 1, 1);
    posicionarNavioVertical(tabuleiro, 4, 4);
    posicionarNavioDiagonalPrincipal(tabuleiro, 6, 0);
    posicionarNavioDiagonalSecundaria(tabuleiro, 6, 9);

    // Construir e aplicar habilidade Cone
    construirHabilidadeCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 2, 2);

    // Construir e aplicar habilidade Cruz
    construirHabilidadeCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 5, 5);

    // Construir e aplicar habilidade Octaedro
    construirHabilidadeOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 7, 7);

    // Imprimir tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
