#include<stdio.h>
#include<stdlib.h>
#include"../JogoV1.h"
int main(){ //Fun��o Principal
    int *grafo;
    grafo= (int *)malloc(sizeof(int));// aloca��o dinamica
    int tab;
    JogoV1 j;
    j.inicialiarJogo(); //chamada do construtor
    tab=j.criaTabuleiro(grafo);// chamada da fun��o cria tabuleiro
    j.moverTabuleiro();// chamada da fun��o que mostra a movimenta��o do Tabuleiro
    printf("-------------->BFS\n");
    j.BuscaEmlargura(grafo, tab);//chamada da fun��o que faz a BFS
    printf("-------------->DFS\n");
    j.BuscaEmProfundidade(grafo, tab);//chamada da fun��o que faz a DFS
    system("Pause");
    return 0;
}
