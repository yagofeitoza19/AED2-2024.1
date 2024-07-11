#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    int numVertices, numEdges;
    printf("Digite o número de vértices: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    printf("Digite o número de arestas: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        printf("Digite a aresta %d (formato: src dest): ", i+1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Matriz de Adjacência:\n");
    printGraph(graph);

    deleteGraph(graph);

    return 0;
}
