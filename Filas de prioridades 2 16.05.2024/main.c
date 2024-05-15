#include <stdio.h>
#include "leilao.h"

int main() {
    int N;
    scanf("%d", &N);

    FilaPrioridade *fila = inicializarFila(N);

    for (int i = 0; i < N; i++) {
        char tipo[10];
        scanf("%s", tipo);

        if (strcmp(tipo, "OFERTA") == 0) {
            char nome[20];
            int preco;
            scanf("%s %d", nome, &preco);
            inserirOferta(fila, nome, preco);
        } else if (strcmp(tipo, "VENDA") == 0) {
            Oferta melhorOferta = removerOferta(fila);
            printf("%d %s\n", melhorOferta.preco, melhorOferta.nome);
        }
    }

    free(fila->ofertas);
    free(fila);

    return 0;
}
