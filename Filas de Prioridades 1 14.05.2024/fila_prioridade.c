#include "fila_prioridade.h"
#include <stdio.h>
#include <string.h>

void trocarPacientes(Paciente *a, Paciente *b) {
    Paciente temp = *a;
    *a = *b;
    *b = temp;
}

void ajustarHeap(FilaPrioridade *fila, int indice) {
    int maior = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    if (esquerda < fila->tamanho && fila->pacientes[esquerda].urgencia > fila->pacientes[maior].urgencia)
        maior = esquerda;

    if (direita < fila->tamanho && fila->pacientes[direita].urgencia > fila->pacientes[maior].urgencia)
        maior = direita;

    if (maior != indice) {
        trocarPacientes(&fila->pacientes[indice], &fila->pacientes[maior]);
        ajustarHeap(fila, maior);
    }
}

void inicializarFila(FilaPrioridade *fila) {
    fila->tamanho = 0;
}

void inserirPaciente(FilaPrioridade *fila, char nome[], char telefone[], int urgencia) {
    if (fila->tamanho == MAX_PACIENTES) {
        printf("A fila está cheia. Não é possível adicionar mais pacientes.\n");
        return;
    }

    strcpy(fila->pacientes[fila->tamanho].nome, nome);
    strcpy(fila->pacientes[fila->tamanho].telefone, telefone);
    fila->pacientes[fila->tamanho].urgencia = urgencia;

    int indice = fila->tamanho;
    while (indice > 0 && fila->pacientes[(indice - 1) / 2].urgencia < fila->pacientes[indice].urgencia) {
        trocarPacientes(&fila->pacientes[(indice - 1) / 2], &fila->pacientes[indice]);
        indice = (indice - 1) / 2;
    }

    fila->tamanho++;
}

void excluirPaciente(FilaPrioridade *fila) {
    if (fila->tamanho == 0) {
        printf("A fila está vazia. Não há pacientes para remover.\n");
        return;
    }

    printf("Paciente %s, telefone %s, chamado para transplante.\n", fila->pacientes[0].nome, fila->pacientes[0].telefone);

    fila->pacientes[0] = fila->pacientes[fila->tamanho - 1];
    fila->tamanho--;

    ajustarHeap(fila, 0);
}

void imprimirFila(FilaPrioridade *fila) {
    if (fila->tamanho == 0) {
        printf("A fila está vazia.\n");
        return;
    }

    printf("Fila de espera de pacientes para transplante:\n");
    for (int i = 0; i < fila->tamanho; i++) {
        printf("Nome: %s, Telefone: %s, Urgência: %d\n", fila->pacientes[i].nome, fila->pacientes[i].telefone, fila->pacientes[i].urgencia);
    }
}
