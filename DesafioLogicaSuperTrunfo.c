
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

Carta cartas[] = {
    {"Leão", 8, 7, 5},
    {"Águia", 5, 9, 6},
    {"Elefante", 9, 4, 7},
    {"Tigre", 7, 8, 6},
    {"Coruja", 4, 5, 9},
    {"Cachorro", 6, 7, 6},
    {"Gato", 4, 8, 7},
    {"Cavalo", 7, 9, 5},
    {"Tubarão", 9, 6, 4},
    {"Urso", 8, 5, 6}
};

void exibirCarta(Carta c) {
    printf("Carta: %s\n", c.nome);
    printf("  Força: %d\n", c.forca);
    printf("  Velocidade: %d\n", c.velocidade);
    printf("  Inteligência: %d\n", c.inteligencia);
}

int main() {
    srand(time(NULL));

    Carta jogador = cartas[rand() % 10];
    Carta computador = cartas[rand() % 10];

    printf("Sua carta:\n");
    exibirCarta(jogador);

    int escolha;
    printf("\nEscolha um atributo:\n1 - Força\n2 - Velocidade\n3 - Inteligência\n> ");
    scanf("%d", &escolha);

    printf("\nCarta do computador:\n");
    exibirCarta(computador);

    int valorJogador, valorComputador;

    switch(escolha) {
        case 1:
            valorJogador = jogador.forca;
            valorComputador = computador.forca;
            break;
        case 2:
            valorJogador = jogador.velocidade;
            valorComputador = computador.velocidade;
            break;
        case 3:
            valorJogador = jogador.inteligencia;
            valorComputador = computador.inteligencia;
            break;
        default:
            printf("Escolha inválida!\n");
            return 1;
    }

    printf("\nResultado:\nVocê: %d vs Computador: %d\n", valorJogador, valorComputador);

    if (valorJogador > valorComputador)
        printf("✅ Você venceu!\n");
    else if (valorJogador < valorComputador)
        printf("❌ Você perdeu!\n");
    else
        printf("🤝 Empate!\n");

    return 0;
}


