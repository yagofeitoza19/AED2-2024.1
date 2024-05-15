#include "leilao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FilaPrioridade* inicializarFila(int capacidade) {
    FilaPrioridade *fila = (FilaPrioridade*) malloc(sizeof(FilaPrioridade));
    fila->ofertas = (Oferta*) malloc(capacidade * sizeof(Oferta));
    fila->tamanho = 0;
    fila->capacidade = capacidade;
    return fila;
}

void inserirOferta(FilaPrioridade *fila, char *nome, int preco) {
    if (fila->tamanho == fila->capacidade) {
        printf("Erro: Capacidade excedida.\n");
        return;
    }

    int indice = fila->tamanho;
    strcpy(fila->ofertas[indice].nome, nome);
    fila->ofertas[indice].preco = preco;

    while (indice > 0 && fila->ofertas[(indice - 1) / 2].preco < fila->ofertas[indice].preco) {
        Oferta temp = fila->ofertas[(indice - 1) / 2];
        fila->ofertas[(indice - 1) / 2] = fila->ofertas[indice];
        fila->ofertas[indice] = temp;
        indice = (indice - 1) / 2;
    }

    fila->tamanho++;
}

Oferta removerOferta(FilaPrioridade *fila) {
    if (fila->tamanho == 0) {
        printf("Erro: Fila vazia.\n");
        exit(1);
    }

    Oferta melhorOferta = fila->ofertas[0];
    fila->tamanho--;

    fila->ofertas[0] = fila->ofertas[fila->tamanho];

    int indice = 0;
    while (1) {
        int filhoEsquerda = 2 * indice + 1;
        int filhoDireita = 2 * indice + 2;
        int indiceMaior = indice;

        if (filhoEsquerda < fila->tamanho && fila->ofertas[filhoEsquerda].preco > fila->ofertas[indiceMaior].preco)
            indiceMaior = filhoEsquerda;

        if (filhoDireita < fila->tamanho && fila->ofertas[filhoDireita].preco > fila->ofertas[indiceMaior].preco)
            indiceMaior = filhoDireita;

        if (indiceMaior != indice) {
            Oferta temp = fila->ofertas[indice];
            fila->ofertas[indice] = fila->ofertas[indiceMaior];
            fila->ofertas[indiceMaior] = temp;
            indice = indiceMaior;
        } else {
            break;
        }
    }

    return melhorOferta;
}
