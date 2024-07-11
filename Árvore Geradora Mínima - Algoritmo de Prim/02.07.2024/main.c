#include "c.h"

int main(){
    GRAFO*gr = inicializa_grafo(7);

    // Primeiro exemplo
    inserir_aresta(gr,0,2,28);
    inserir_aresta(gr,0,5,10);
    
    inserir_aresta(gr,1,0,28);
    inserir_aresta(gr,1,6,14);
    inserir_aresta(gr,1,2,16);
    
    inserir_aresta(gr,2,1,16);
    inserir_aresta(gr,2,3,12);
    
    inserir_aresta(gr,3,6,18);
    inserir_aresta(gr,3,2,12);
    inserir_aresta(gr,3,4,22);
    
    inserir_aresta(gr,4,3,22);
    inserir_aresta(gr,4,5,25);
    inserir_aresta(gr,4,6,24);
   
    inserir_aresta(gr,5,0,10);
    inserir_aresta(gr,5,4,25);
   
    inserir_aresta(gr,6,1,14);
    inserir_aresta(gr,6,3,18);
    inserir_aresta(gr,6,7,24);

    // Segundo exemplo
    inserir_aresta(gr,0,1,6);
    inserir_aresta(gr,0,2,1);
    inserir_aresta(gr,0,3,5);
    
    inserir_aresta(gr,1,0,6);
    inserir_aresta(gr,1,2,2);
    inserir_aresta(gr,1,4,5);
    
    inserir_aresta(gr,2,0,1);
    inserir_aresta(gr,2,1,2);
    inserir_aresta(gr,2,3,2);
    inserir_aresta(gr,2,4,6);
    inserir_aresta(gr,2,5,4);
    
    inserir_aresta(gr,3,0,5);
    inserir_aresta(gr,3,2,2);
    inserir_aresta(gr,3,5,4);
   
    inserir_aresta(gr,4,1,5);
    inserir_aresta(gr,4,2,6);
    inserir_aresta(gr,4,5,3);
   
    inserir_aresta(gr,5,4,3);
    inserir_aresta(gr,5,2,4);
    inserir_aresta(gr,5,3,4);

    imprimir(gr);
    imprimir_aresta(gr);
    printf("\narvore geradora minima: %d",algoritmoPrim(gr,0));
    int valor = algoritmoPrim(gr,0);
    printf("\nValor arvore espassa: %d",valor);
    return 0;
}
