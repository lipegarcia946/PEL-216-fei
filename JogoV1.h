//arquivo de Cabeçalho(head file)
#ifndef JOGOV1_H_INCLUDED
#define JOGOV1_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
class Node{ // A classe Node possue os atributos necessarios para poder funcionar o jogo dos 8
public:
    Node *proximo;// guarda o proximo registro do grafo
    int valor;// valor a ser inserido
    int *grafo;//ponteiro que responsavel na criação do grafo, através da alocação dinamica
    int fila[8];//vetor auxiliar usado na BFS(Busca em Largura)
    int pilha[8];// vetor auxiliar usado na DFS(Busca em Profundidade)
    int topo;// variavel que marca o topo na DFS(Busca em Profundidade)
};
class JogoV1: public Node{ /*A classe JogoV1 herda os atributos da classe NODE,a classe JogoV1 faz
    a implementação do jogo dos 8, e tem outros 2 atributos*/
 public:
    bool visitados[8];// vetor de boleanos que marca os vertices com verdadeiro (true) ou falso (false)
    int quantidade;/* Variavel que controla quantos valores foram inserido
    (nesse caso a quantidade de peças no tabuleiro do jogo)*/
// Prototipo das funções
void inicialiarJogo();
int criaTabuleiro(int*);
void moverTabuleiro ();
void BuscaEmlargura(int*,int);
void BuscaEmProfundidade(int*,int );
};
// Declação do metodo construtor
void JogoV1:: inicialiarJogo(){
this-> quantidade= 0;
this->topo= -1;
this->grafo= NULL;
this->proximo =NULL;
}
//Declaração do metodo de inserção (cria tabuleiro)
int JogoV1::criaTabuleiro(int * grafo){
 int valor,gr;

    printf("criando o tabuleiro...\n");
    int i=0, a=-1;
    Node* novo= NULL;//ponteiro auxiliar
    do{
            if(grafo== NULL){ //inserindo na 1a. posição
                printf("digite um valor:\n");
                 scanf("%d",&valor);
                 grafo = &valor;
                 novo= NULL;
                 proximo= NULL;
                 a++;
                printf("Peca:%d na %da.posicao\n",grafo[a],a+1);
                quantidade++;
                this->topo++;
                printf("quantidade de pecas = 1 e topo= %d\n",this->topo);
            } else if(grafo!=NULL){ //inserindo nas demais posições
                printf("digite um valor:\n");
                scanf("%d",&valor);
                 grafo = &valor;
                proximo= novo;
                a++;
                printf("peca %d posicao:%d\n",*grafo,a+1);
                quantidade++;
                this->topo++;
                printf("quantidade de pecas = %d e topo= %d\n", quantidade, this->topo);
        }

    } while(i< quantidade && quantidade<8);
    i++;
    return gr;
}
/* Função que mostra os movimentos permitido no tabuleiro,
( mas inicialmente está função seria responsável por realizar a movimentação das peças porém não foi possível
 realizar a implementação inicial desejada)*/
void JogoV1::moverTabuleiro(){
    printf("***************//**********************\n");
    printf("a Movimentacao permitida no tabuleiro eh:\n");
    printf("direcao para cima (UP):\n");
    printf("direcao para baixo (DOWN):\n");
    printf("direcao para esquerda (LEFT):\n");
    printf("direcao para direita (RIGHT):\n");
    fflush(stdin);
      //esboço da tentativa de realizar a movimentação das peças
      /* if(c== 'u'){
    printf("direcao para cima\n");
   }
   else if(c== 'd'){
    printf("direcao para baixo\n");
   }
   else if(c== 'l'){
    printf("direcao para esquerda\n");
   }
   else if(c== 'r'){
    printf("direcao para direira\n");
   }
   else{
    printf("opcao invalida\n");
   }*/


/*Função que realiza a Busca em Largura -BFS*/
}
void JogoV1::BuscaEmlargura(int * grafo,int valor){
    int inicio =0, fim=8;
    Node*novo= NULL; //ponteiro auxiliar
       // setando os vetores fila com 0 e visitados com false
        for(int i=0; i<8;i++){
            visitados[i]= false;
            fila[i]= 0;
        }

            int a=0;
            while (inicio<fim-1){//visistando o 1o. Vertice
            if(a== inicio){
            grafo =&valor;
            fila[inicio] = *(grafo+inicio);
            proximo=novo;
            visitados[inicio]= true; //marcando o vertice com verdadeiro, ou seja, ele já foi visitado
           printf("visitando a raiz do grafo: (o vertice: %d)\n", inicio+1);
        }
                if(a+1<fim){ //Visitando os demais vertices
                    grafo= &valor;
                    fila[inicio+1] =*(grafo+inicio);
                    proximo = novo;
                    visitados[inicio+1] = true; //marcando o vertice com verdadeiro, ou seja, ele já foi visitado
                    printf("visitando o %do vertice\n",inicio+2);

            }
            inicio++;

            }
            //removendo da fila
            int aux[8];
            for(int i= 8; i<fim;i++){
                    if(visitados[i]==true){
                        aux[i]=fila[a];
                        printf("retirando da fila o vertice: %d",aux[i]);

            }
        }
}
/*Função que realiza a Busca em Profundidade -DFS*/
void JogoV1::BuscaEmProfundidade(int*grafo, int valor){
    int a=8;
     // setando os vetores pilha com 0 e visitados com false
    for(int i=0; i<8; i++){
        pilha[i]=0;
        visitados[i]= false;
    }
    while(a!=0){
            if(a==8){// Visitando o 1o. Vertice
                topo=a;
                visitados[a]= true; //marcando o vertice com verdadeiro, ou seja, ele já foi visitado
                pilha[a]= topo;
                printf("visitando a raiz do grafo (o vertice %d)\n",topo);
                }
                else{ //Visitando os demais vertices
                    topo=a;
                    visitados[a]= true; //marcando o vertice com verdadeiro, ou seja, ele já foi visitado
                    pilha[a]= topo;
                    topo--;
                    printf("visitando o vertice %d\n",topo+1);

                    }
            // Removendo da pilha
            a--;
            int aux[8];
                    for(int i= 8; i<0;i--){
                            if(visitados[i]==true){
                                aux[i]=pilha[a];
                                printf("retirando da pilha o vertice: %d",aux[i]);
            }

        }

    }
}

#endif // JOGOV1_H_INCLUDED
