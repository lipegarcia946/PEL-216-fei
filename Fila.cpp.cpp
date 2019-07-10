#include<stdio.h>
#include<cstdlib>
// constante que é o tamanho maximo do vetor
int const MAX =10;
class Fila{ // a classe fila contem:
public:
    int vetFila[MAX]; // vetor de tamanho max
    int inicio, fim, quantidade; // variaveis p/ controle
    // do inicio, da quantidade, e o fim
    void inicializaFila(); // construtor
    void enfileira(int* ,int);// insere na fila
    void desenfileira(int*); //retira da fila
};
// construtor
void Fila::inicializaFila(){
    this->inicio =-1;// inicio começa em -1
    this->fim =-1;//inicio começa em -1
    this->quantidade =0; // quantidade coomeça em 0
}
// insere na fila pelo fim
void Fila::enfileira(int vetFila[],int num){
    if(fim!=MAX){ // inserindo na 1a. posição
        if(inicio== -1){
            inicio = 0;
        }
        fim++; // inserindo nas demais posições
        vetFila[fim]= num;
        quantidade++;
        printf("o numero %d  inserido na %da. posicao \n", num, this->fim);
    }
    else{
        printf("fila cheia");
    }
}
//retirando da fila pelo inicio
void Fila:: desenfileira(int vetFila[]){
int s= this->inicio, aux;
if(inicio!= -1 && fim !=-1 && s <= this->fim){
    if(this->fim == this->inicio){ //se a fila estiver vazia
            inicializaFila();

    }else{
        inicio++; // retirando da fila
        aux= vetFila[inicio];
        printf("O elemento desenfileirado foi: %d\n",aux);
        }
    }
    else
            printf("Fila vazia\n");

}
// função principal
int main(void){
    Fila*q;
    int num;
    for(int i=0; i<MAX; i++){// inserindo
            printf("%do- numero: ", i+1);
            scanf("%d",&num);
            q->enfileira(&q->vetFila[i], num);
            printf("retirando da fila\n");// retirando
            q->desenfileira(&q->vetFila[i]);
            }




    return 0;
}
