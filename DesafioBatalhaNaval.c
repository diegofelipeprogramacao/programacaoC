
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define NAVIOS 3

void inicializarTabuleiro(char tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = '~';
}

void posicionarNavios(int navios[NAVIOS][2]) {
    srand(time(NULL));
    for (int i = 0; i < NAVIOS; i++) {
        navios[i][0] = rand() % TAM;
        navios[i][1] = rand() % TAM;

        // Evita duplicados
        for (int j = 0; j < i; j++) {
            if (navios[i][0] == navios[j][0] && navios[i][1] == navios[j][1]) {
                i--; // Reposiciona
                break;
            }
        }
    }
}

int verificarAcerto(int linha, int coluna, int navios[NAVIOS][2]) {
    for (int i = 0; i < NAVIOS; i++)
        if (navios[i][0] == linha && navios[i][1] == coluna)
            return 1;
    return 0;
}

int main() {
    char tabuleiro[TAM][TAM];
    int navios[NAVIOS][2];
    int tiros = 0, acertos = 0;

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(navios);

    printf("🚢 BATALHA NAVAL - C VERSION\n");

    while (acertos < NAVIOS) {
        int x, y;
        printf("\nDigite a linha e a coluna (0-4): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= TAM || y < 0 || y >= TAM) {
            printf("❌ Coordenadas inválidas!\n");
            continue;
        }

        tiros++;

        if (verificarAcerto(x, y, navios)) {
            printf("🎯 Acertou!\n");
            tabuleiro[x][y] = 'X';
            acertos++;
        } else {
            printf("💦 Água!\n");
            tabuleiro[x][y] = 'O';
        }

        // Mostra tabuleiro
        printf("Tabuleiro:\n");
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                printf(" %c ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    }

    printf("\n✅ Você afundou todos os navios em %d tentativas!\n", tiros);
    return 0;
}


