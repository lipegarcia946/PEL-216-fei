#include<stdio.h>
#include<cstdlib>
//tamanho definido do vetor pela cte MAX =10
int const MAX=10;
class Pilha{

public:
//declaração do vetor p/ pilha com tamanho MAX
//e um contador pro topo começando em -1
int vetpilha[MAX];
int topo=-1;
/*funções que são para genrenciamento da pilha*/
void CriaPilha(int vetpilha[],int);
void VerTopo();
int RemoverDaPilha(int vetpilha[]);

};
/*função que cria a pilha caso topo=MAX
exibe a msg pilha cheia*/

void Pilha::CriaPilha(int vetpilha[], int num){
     topo++;
    vetpilha[topo]=num;
     if(topo== MAX){
            printf("pilha cheia\n");
        }
}

/*função que mostra o topo da pilha enquanto topo!=MAX
exibe a msg pilha cheia*/

void Pilha::VerTopo(){
        if(topo+1!=MAX){
        printf("O topo eh: %d\n",topo);

        }
}
/*função que remove da pilha caso topo=MAX
aux= vetpilha[topo] */

int Pilha:: RemoverDaPilha(int vetpilha[]){
     int aux;
     if(topo+1== MAX){
            topo--;
     aux= vetpilha[topo];


    }
    return aux;
}


int main(void){
     Pilha p;
    int num, r, j=0;
    printf("digite 10 numeros: \n");
    for(int i=0;i<MAX; i++){
        printf("[%do.] numero:", i+1);
        scanf("%d",&num);
        p.CriaPilha(&p.vetpilha[i],num);
        p.VerTopo();
        if(p.topo==MAX){
            j=p.topo;
            do{
                printf("o elemento removido foi: %d \n",r);
                j--;
            }while(j!=-1);

        }
    }
        return 0;
    }






