#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#define MAX_PACIENTES 100

typedef struct {
    char nome[50];
    char telefone[15];
    int urgencia;
} Paciente;

typedef struct {
    Paciente pacientes[MAX_PACIENTES];
    int tamanho;
} FilaPrioridade;

void inicializarFila(FilaPrioridade *fila);
void inserirPaciente(FilaPrioridade *fila, char nome[], char telefone[], int urgencia);
void excluirPaciente(FilaPrioridade *fila);
void imprimirFila(FilaPrioridade *fila);

#endif
