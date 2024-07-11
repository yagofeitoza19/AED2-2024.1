#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{
    int vertices;
    int arestas;
    int **adj;
}GRAFO;

GRAFO* inicializa_grafo(int v);
bool inserir_aresta(GRAFO *gr, int vi,int vf,int peso);
bool apagar_aresta(GRAFO *gr, int vi,int vf);
void imprimir(GRAFO *gr);
void imprimir_aresta(GRAFO *gr);
int algoritmoPrim(GRAFO *gr, int vi);
