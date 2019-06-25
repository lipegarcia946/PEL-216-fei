#include<stdio.h>
#include<cstdlib>

int const MAX =10;
class Fila{
public:
    int vetFila[MAX];
    int inicio, fim, quantidade;
    void inicializaFila();
    void enfileira(int* ,int);
    void desenfileira(int*);
};
void Fila::inicializaFila(){
    this->inicio =-1;
    this->fim =-1;
    this->quantidade =0;
}
void Fila::enfileira(int vetFila[],int num){
    if(fim!=MAX){
        if(inicio== -1){
            inicio = 0;
        }
        fim++;
        vetFila[fim]= num;
        quantidade++;
        printf("o numero %d  inserido na %da. posicao \n", num, this->fim);
    }
    else{
        printf("fila cheia");
    }
}
void Fila:: desenfileira(int vetFila[]){
int s= this->inicio, aux;
if(inicio!= -1 && fim !=-1 && s <= this->fim){
    if(this->fim == this->inicio){
            inicializaFila();

    }else{
        inicio++;
        aux= vetFila[inicio];
        printf("O elemento desenfileirado foi: %d\n",aux);
        }
    }
    else
            printf("Fila vazia\n");

}
int main(void){
    Fila*q;
    int num;
    for(int i=0; i<MAX; i++){
            printf("%do- numero: ", i+1);
            scanf("%d",&num);
            q->enfileira(&q->vetFila[i], num);
            printf("retirando da fila\n");
            q->desenfileira(&q->vetFila[i]);
            }




    return 0;
}
