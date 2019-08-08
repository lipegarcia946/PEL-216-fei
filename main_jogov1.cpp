#include<stdio.h>
#include<stdlib.h>
#include"../JogoV1.h"
int main(){ // função principal
    int *grafo;
    grafo= (int *)malloc(sizeof(int));//alocação dinamica
    int tab;
    JogoV1 j;
    j.inicialiarJogo(); //chamada da do construtor
    tab=j.criaTabuleiro(grafo);
    j.moverTabuleiro(); //chamada da função para mostrar movimentos
    printf("-------------->BFS\n");
    j.BuscaEmlargura(grafo, tab); // chamada da função BFS
    printf("-------------->DFS\n");
    j.BuscaEmProfundidade(grafo, tab);  // chamada da função DFS
    system("Pause");
    return 0;
}
