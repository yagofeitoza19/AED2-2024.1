#include <stdio.h>
#include "graph.h"

int main() {
    int V;
    printf("Insira o número de vértices: ");
    scanf("%d", &V);

    Graph* graph = createGraph(V);

    int src, dest;
    while (1) {
        printf("Insira a origem e o destino da aresta (ou -1 -1 para sair): ");
        scanf("%d %d", &src, &dest);

        if (src == -1 && dest == -1) {
            break;
        }

        if (src >= V || dest >= V || src < 0 || dest < 0) {
            printf("Vértices inválidos! Tente novamente.\n");
            continue;
        }

        addEdge(graph, src, dest);
    }

    printGraph(graph);
    freeGraph(graph);

    return 0;
}
