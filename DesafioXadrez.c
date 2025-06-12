#ifndef XADREZ_H
#define XADREZ_H

#define TAM 8

typedef struct {
    char tipo;   // P, T, C, B, Q, K
    char cor;    // b (branco), p (preto)
} Peca;

void iniciarTabuleiro(Peca tab[TAM][TAM]);
void exibirTabuleiro(Peca tab[TAM][TAM]);
int moverPeca(Peca tab[TAM][TAM], int x1, int y1, int x2, int y2);

#endif

#include <stdio.h>


void iniciarTabuleiro(Peca tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j].tipo = tab[i][j].cor = ' ';

    // Torres
    tab[0][0] = tab[0][7] = (Peca){'T', 'p'};
    tab[7][0] = tab[7][7] = (Peca){'T', 'b'};

    // Reis
    tab[0][4] = (Peca){'K', 'p'};
    tab[7][4] = (Peca){'K', 'b'};
}

void exibirTabuleiro(Peca tab[TAM][TAM]) {
    printf("   A B C D E F G H\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d  ", i+1);
        for (int j = 0; j < TAM; j++) {
            if (tab[i][j].tipo != ' ')
                printf("%c%c ", tab[i][j].tipo, tab[i][j].cor);
            else
                printf("-- ");
        }
        printf("\n");
    }
}

int moverPeca(Peca tab[TAM][TAM], int x1, int y1, int x2, int y2) {
    // Simples validação
    if (tab[x1][y1].tipo == ' ') return 0;

    // Mover
    tab[x2][y2] = tab[x1][y1];
    tab[x1][y1].tipo = tab[x1][y1].cor = ' ';
    return 1;
}
#include <stdio.h>


int main() {
    Peca tabuleiro[TAM][TAM];
    iniciarTabuleiro(tabuleiro);

    int x1, y1, x2, y2;
    char coluna1, coluna2;

    while (1) {
        exibirTabuleiro(tabuleiro);
        printf("Mover (ex: A2 A3): ");
        scanf(" %c%d %c%d", &coluna1, &y1, &coluna2, &y2);
        
        x1 = y1 - 1;
        y1 = coluna1 - 'A';
        x2 = y2 - 1;
        y2 = coluna2 - 'A';

        if (!moverPeca(tabuleiro, x1, y1, x2, y2)) {
            printf("Movimento inválido!\n");
        }
    }

    return 0;
}

