#ifndef CARTAS_H
#define CARTAS_H

typedef struct {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

void exibirCarta(Carta c);
int compararAtributo(Carta c1, Carta c2, int atributo);

#endif

#include <stdio.h>


void exibirCarta(Carta c) {
    printf("Nome: %s\n", c.nome);
    printf("Força: %d\n", c.forca);
    printf("Velocidade: %d\n", c.velocidade);
    printf("Inteligência: %d\n", c.inteligencia);
}

int compararAtributo(Carta c1, Carta c2, int atributo) {
    switch(atributo) {
        case 1: return c1.forca - c2.forca;
        case 2: return c1.velocidade - c2.velocidade;
        case 3: return c1.inteligencia - c2.inteligencia;
        default: return 0;
    }
}

#include <stdio.h>


int main() {
    Carta jogador = {"Dragão", 90, 70, 60};
    Carta cpu = {"Grifo", 80, 80, 70};

    int atributo;
    
    printf("Sua carta:\n");
    exibirCarta(jogador);

    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - Força\n2 - Velocidade\n3 - Inteligência\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &atributo);

    int resultado = compararAtributo(jogador, cpu, atributo);

    printf("\nCarta do adversário:\n");
    exibirCarta(cpu);

    if (resultado > 0)
        printf("\nVocê venceu!\n");
    else if (resultado < 0)
        printf("\nVocê perdeu!\n");
    else
        printf("\nEmpate!\n");

    return 0;
}


