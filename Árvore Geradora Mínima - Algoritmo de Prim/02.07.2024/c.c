#include "c.h"

GRAFO* inicializa_grafo(int v){
    GRAFO *g = malloc(sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;

    g->adj = malloc(sizeof(int *[v]));
    for(int i = 0; i < v; i++){
        g->adj[i] = malloc(sizeof(int[v]));
    }
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            g->adj[i][j] = 0;
        }
    }
    return g;
}
bool inserir_aresta(GRAFO *gr, int vi,int vf,int peso){
    if(!gr) return false;
    if(vf<0 || vf>= gr->vertices) return false;
    if(vi<0 || vi>= gr->vertices) return false;
    if(gr->adj[vi][vf] == 0){
        gr->adj[vi][vf] = peso;
        gr->arestas ++;
    }
    return true;
}
bool apagar_aresta(GRAFO *gr, int vi,int vf){
    if(!gr) return false;
    if(vf<0 ||vf >= gr->vertices) return false;
    if(vi<0 || vi>= gr->vertices) return false;
    if(gr->adj[vi][vf] ==1){
        gr->adj[vi][vf] = 0;
        gr->arestas --;
    }
    return true;
}
void imprimir(GRAFO *gr){
    for(int i = 0; i < gr->vertices;i++){
        printf("\nVertice %d:",i);
        for(int j = 0; j < gr->vertices;j++){
            printf("%d ",gr->adj[i][j]);
        }
    }
}
void imprimir_aresta(GRAFO *gr){
    for(int i = 0; i < gr->vertices; i ++){
        printf("\n");
        for(int j = 0; j < gr->vertices;j++){
            printf("(%d %d)",i,j);
        }
    }
}
// algoritmo de prim seleciona semrpe o menor caminho para ambos os lados.
// realiza um somatorio do trajeto total.
// o mesmo vertice nao pode ser visitado, pois isso gera um ciclo
int buscarMenorValor(GRAFO *gr, int lista[],bool visitados[])
{
    int menor_valor = __INT_MAX__;
    int index;
    for(int i = 0; i < gr->vertices; i++)
    {
        if((lista[i] < menor_valor && lista[i] > 0) &&visitados[i] != true)
        {
            if(visitados[i]!= true)
            {
                menor_valor = lista[i];
                index = i; 
            }
        }
    }
    visitados[index] = true;
    return index;
}
bool validarVisitado(GRAFO *gr, bool visitados[])
{
    for(int i = 0; i < gr->vertices; i ++)
    {
        if(visitados[i] == false)
        {
            return false;
        }
    }
    return true;
}

int algoritmoPrim(GRAFO *gr,int vi)
{
    int valor = 0;
    int lista[gr->vertices];
    bool visitado[gr->vertices];
    for(int i = 0; i < gr->vertices; i++)
    {
        if(i == vi)
        {
            lista[i] = 0;
            visitado[i] = true; 
        }
        else{
            lista[i] = __INT_MAX__;
            visitado[i] = false; 
        }
    }
    while(!validarVisitado(gr,visitado))
    {
        for(int i = 0 ; i < gr->vertices; i++)
        {
            if(gr->adj[vi][i] > 0 && lista[i] == __INT_MAX__)
            {
                lista[i] = gr->adj[vi][i];
            }
            else if(gr->adj[vi][i] > 0 && lista[i] != __INT_MAX__){
                if(gr->adj[vi][i] < lista[i])
                {
                    lista[i] = gr->adj[vi][i];
                }else{
                    continue;
                }
            }
        }
        vi = buscarMenorValor(gr,lista,visitado);
        visitado[vi] = true;
        printf("\nvalor cada iteracao: %d",lista[vi]);
        valor+= lista[vi];
    }
    return valor;
}
