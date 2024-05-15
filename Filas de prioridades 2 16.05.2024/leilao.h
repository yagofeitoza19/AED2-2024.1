#ifndef LEILAO_H
#define LEILAO_H

typedef struct {
    char nome[20];
    int preco;
} Oferta;

typedef struct {
    Oferta *ofertas;
    int tamanho;
    int capacidade;
} FilaPrioridade;

FilaPrioridade* inicializarFila(int capacidade);
void inserirOferta(FilaPrioridade *fila, char *nome, int preco);
Oferta removerOferta(FilaPrioridade *fila);

#endif
