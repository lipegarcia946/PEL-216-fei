#include<stdio.h>
#include<stdlib.h>
#include"../JogoV1.h"
int main(){
    int *grafo;
    grafo= (int *)malloc(sizeof(int));
    int tab;
    JogoV1 j;
    j.inicialiarJogo();
    tab=j.criaTabuleiro(grafo);
    j.moverTabuleiro();
    printf("-------------->BFS\n");
    j.BuscaEmlargura(grafo, tab);
    printf("-------------->DFS\n");
    j.BuscaEmProfundidade(grafo, tab);
    system("Pause");
    return 0;
}
