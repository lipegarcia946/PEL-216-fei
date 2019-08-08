#include<stdio.h>
#include<stdlib.h>
#include"../JogoV1.h"
int main(){ //Função Principal
    int *grafo;
    grafo= (int *)malloc(sizeof(int));// alocação dinamica
    int tab;
    JogoV1 j;
    j.inicialiarJogo(); //chamada do construtor
    tab=j.criaTabuleiro(grafo);// chamada da função cria tabuleiro
    j.moverTabuleiro();// chamada da função que mostra a movimentação do Tabuleiro
    printf("-------------->BFS\n");
    j.BuscaEmlargura(grafo, tab);//chamada da função que faz a BFS
    printf("-------------->DFS\n");
    j.BuscaEmProfundidade(grafo, tab);//chamada da função que faz a DFS
    system("Pause");
    return 0;
}
