#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
    int numVertices;
    int **adjMatrix;
} Graph;

Graph* createGraph(int numVertices);
void deleteGraph(Graph* graph);
void addEdge(Graph* graph, int src, int dest);
void removeEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);

#endif
