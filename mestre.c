#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5 // Tamanho da matriz de habilidade (exemplo 5x5)

void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Inicializa o tabuleiro com água (0) e coloca navios (3) em posições específicas
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Água
        }
    }

    // Colocando alguns navios (valor 3)
    tabuleiro[2][3] = 3;
    tabuleiro[3][3] = 3;
    tabuleiro[4][3] = 3;
    tabuleiro[5][3] = 3;
    tabuleiro[6][3] = 3;
}

void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf("0 "); // Água
            else if (tabuleiro[i][j] == 3)
                printf("3 "); // Navio
            else if (tabuleiro[i][j] == 5)
                printf("5 "); // Área afetada pela habilidade
        }
        printf("\n");
    }
}

// Função para aplicar a habilidade Cone
void aplicarHabilidadeCone(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemX, int origemY) {
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // Definindo a matriz do cone
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j <= i; j++) {
            cone[i][j] = 1; // A parte do cone
        }
    }

    // Aplicando o cone no tabuleiro
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (cone[i][j] == 1) {
                int x = origemX + i - TAM_HABILIDADE / 2;
                int y = origemY + j - TAM_HABILIDADE / 2;
                if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO)
                    tabuleiro[x][y] = 5; // Marcando a área afetada
            }
        }
    }
}

// Função para aplicar a habilidade Cruz
void aplicarHabilidadeCruz(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemX, int origemY) {
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // Definindo a matriz da cruz
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        cruz[TAM_HABILIDADE / 2][i] = 1; // Linha central
        cruz[i][TAM_HABILIDADE / 2] = 1; // Coluna central
    }

    // Aplicando a cruz no tabuleiro
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (cruz[i][j] == 1) {
                int x = origemX + i - TAM_HABILIDADE / 2;
                int y = origemY + j - TAM_HABILIDADE / 2;
                if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO)
                    tabuleiro[x][y] = 5; // Marcando a área afetada
            }
        }
    }
}

// Função para aplicar a habilidade Octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemX, int origemY) {
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // Definindo a matriz do octaedro (losango)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i + j >= TAM_HABILIDADE / 2 && i - j <= TAM_HABILIDADE / 2 && j - i <= TAM_HABILIDADE / 2 && i + j <= TAM_HABILIDADE / 2 + TAM_HABILIDADE - 1) {
                octaedro[i][j] = 1; // A parte do octaedro
            }
        }
    }

    // Aplicando o octaedro no tabuleiro
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (octaedro[i][j] == 1) {
                int x = origemX + i - TAM_HABILIDADE / 2;
                int y = origemY + j - TAM_HABILIDADE / 2;
                if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO)
                    tabuleiro[x][y] = 5; // Marcando a área afetada
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Definindo os pontos de origem para as habilidades
    int origemConeX = 3, origemConeY = 3;
    int origemCruzX = 4, origemCruzY = 4;
    int origemOctaedroX = 5, origemOctaedroY = 5;

    // Exibindo o tabuleiro inicial
    printf("Tabuleiro Inicial:\n");
    exibirTabuleiro(tabuleiro);

    // Aplicando as habilidades
    aplicarHabilidadeCone(tabuleiro, origemConeX, origemConeY);
    printf("\nTabuleiro após Habilidade Cone:\n");
    exibirTabuleiro(tabuleiro);

    // Resetando o tabuleiro e aplicando a cruz
    inicializarTabuleiro(tabuleiro);
    aplicarHabilidadeCruz(tabuleiro, origemCruzX, origemCruzY);
    printf("\nTabuleiro após Habilidade Cruz:\n");
    exibirTabuleiro(tabuleiro);

    // Resetando o tabuleiro e aplicando o octaedro
    inicializarTabuleiro(tabuleiro);
    aplicarHabilidadeOctaedro(tabuleiro, origemOctaedroX, origemOctaedroY);
    printf("\nTabuleiro após Habilidade Octaedro:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
