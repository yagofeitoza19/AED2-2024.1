#include <stdio.h>
#include "fila_prioridade.h"

int main() {
    FilaPrioridade fila;
    inicializarFila(&fila);

    int opcao;
    char nome[50], telefone[15];
    int urgencia;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Inserir novo paciente\n");
        printf("2. Excluir paciente chamado para transplante\n");
        printf("3. Imprimir fila de espera de pacientes\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Nome do paciente: ");
                scanf("%s", nome);
                printf("Telefone do paciente: ");
                scanf("%s", telefone);
                printf("Grau de urgencia (1 a 5): ");
                scanf("%d", &urgencia);
                inserirPaciente(&fila, nome, telefone, urgencia);
                break;
            case 2:
                excluirPaciente(&fila);
                break;
            case 3:
                imprimirFila(&fila);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
