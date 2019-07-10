#include<stdio.h>
#include<cstdlib>
class Node{ // classe nó contem o valor e um ponteiro
public:
    int valor; // valor que será inserido na lista
    Node *proximo;//ponteiro p/ o prox nó
};
//classe ListaLigada herda os atributos da classe nó
class ListaLigada: public Node{ // a classe ListaLigada possue:
    /*dois ponteiros um para o inicio e outro pra o final da lista
    um inteiro para a qtd de itens da lista
    um inteiro para o topo da lista   */
public:
    ListaLigada *inicio;
    ListaLigada*fim;
    int quantidade;
    int topo;
    /*os segueintes metodos:
    inicializa => construtor
    inserirNoinicio => insere no inicio da lista como se fosse uma fila
    removerNoinicio => remove do inicio da lista como se fosse fila
    inserirNofim => insere no fim da lista como se fosse uma pilha
    removerNofim => remove do inicio da lista como se fosse pilha*/
    void inicializa();
    void insereComoFila(ListaLigada*l,int);
    void removerComoFila(ListaLigada *l,int, int);
    void insereComoPilha(ListaLigada *l,int);
    void removerComoPilha(ListaLigada *l,int, int);

}; // construtor
  void ListaLigada::inicializa(){
    this-> proximo = NULL; // aponta p/ valor nulo
    this->inicio = NULL;// aponta p/ valor nulo
    this->fim = NULL; // aponta p/ valor nulo
    this->quantidade=0; // inicializa c/ valor 0
    this-> topo=-1;// inicializa c/ valor -1
}
    //insereComoFila => insere no inicio da lista como se fosse uma fila

void ListaLigada::insereComoFila(ListaLigada*l, int num){
    ListaLigada * novo_no= NULL;// ponteiro auxiliar
    if(l->inicio== NULL && l->fim == NULL){ // se a lista no inicio estiver vazia, insere na primeira posição
        printf("lista vazia, inserindo na 1a. pos\n");
        l->proximo= l->inicio;
        l->proximo = l->fim;
        l->quantidade++;// atualiza a quantidade incrementando
    }
    else if(l->inicio!=NULL && l->fim == NULL){//se a lista no inicio não estiver vazia, insere nas demais posições
            novo_no= l->inicio;
            l->proximo= novo_no;
            l->fim = novo_no;
            l->quantidade++;// atualiza a quantidade incrementando
    }

}


// insereComoPilha => insere no fim da lista como se fosse pilha
void ListaLigada::insereComoPilha(ListaLigada *l,int){
    ListaLigada * novo_no = NULL; // ponteiro auxiliar
        if(l->fim== NULL && l->inicio==NULL){ // se a lista fim estiver vazia,insere  na primeira posição
       printf("a lista esta vazia, inserindo na 1a. pos...:\n");
        novo_no=l->inicio;
        l->proximo= l->inicio;
        l->proximo=l->fim;
        l->quantidade++;// atualiza a quantidade incrementando
        this->topo++; // aqui atualiza-se o topo
        //printf("topo =%d\n",topo);
    }else if(l->fim!= NULL &&l->inicio!=NULL){
        novo_no= l-> inicio;
        l->proximo= l->inicio;
        l->proximo= novo_no;
        l->fim = novo_no;
        l->quantidade++; // atualiza a quantidade incrementando
        this->topo++; // aqui atualiza-se o topo
        //printf("topo =%d\n", topo);// ficou comentado pois esta mostrando endereço de memoria
    }
}
void ListaLigada::removerComoFila(ListaLigada*l, int num, int v){
    ListaLigada*anterior= NULL;
     ListaLigada*ant_anterior= NULL;
     ListaLigada*atual= NULL;
        if(l->inicio== NULL && l->fim== NULL){
        anterior= l->inicio;
        l->quantidade--;
        anterior= NULL;
        l->proximo= NULL;
        l->fim= NULL;
    }
    else if(l->inicio!=NULL && l->fim!=NULL){
        ant_anterior= l->inicio;
        anterior = atual;
        l->proximo = atual;
    }
        else{
            printf("Impossivel remover lista vazia!");
        }
}
//removerComoPilha=> remove do fim da lista como se fosse uma pilha
void ListaLigada::removerComoPilha(ListaLigada*l, int num, int x){
    ListaLigada* atual = NULL;// ponteiro auxilar
    ListaLigada* ant = NULL;// ponteiro auxilar
    if(l->fim == NULL && l->inicio){ // remove da 1a. posição do fim
        atual = l->inicio;
        l->proximo = atual;
        l->fim = atual;
        l->fim = NULL; // apos retirar o elemento ele aponta p/ nulo
        this->topo--;
        l->quantidade--; //atualiza a quantidade decrementando
        //printf("topo = %d", l->topo); // ficou comentado pois esta mostrando endereço de memoria
    }
    else if(l->fim!= NULL && l->inicio!=NULL){ // remove das demais posiçãções do fim
        ant= atual;
        l->proximo = atual;
        l->quantidade--; //atualiza a quantidade decrementando
        l->fim = ant;
        l->fim = NULL;// apos retirar o elemento ele aponta p/ nulo
        this->topo--;
       // printf("topo = %d", topo); // ficou comentado pois esta mostrando endereço de memoria
    }
}


int main(void){
    int num, v, x, a=0,b=0, f=0;
    printf("digite um valor para alocar memoria....:\n");
    scanf("%d",&num);
    ListaLigada *Lista;
    Lista= (ListaLigada*)malloc(num*sizeof(Lista)); //alocação din. de memoria
    Lista->valor = v;// a variavel valor recebe v
     if(Lista== NULL){
            f=1;
    throw "limite de memoria atingido";
    }

    printf("*****Inserindo como fila**********\n");
    printf("adicionando a lista:\n ");
    for(int i=0; i<num; i++){ //laço p/ inserir como fila

        scanf("%d",&v); // valor lido pelo usuario
        printf("valor:%d, inserido na [%da.] pos\n ", v, i+1);
        Lista->insereComoFila(&Lista[i], num);
                do{ //laço p/ remover como fila

                    Lista->removerComoFila(&Lista[a], num, v);
                    printf("O valor %d, foi removido e esta na pos %da\n",v, a+1);
                } while(a!=i);
                a++;
            }
        printf("*****Inserindo no fim da lista**********\n");
        for(int j=0; j<num;j++){ //laço p/ inserir como pilha

        scanf("%d",&x); // laço p/ remover como pilha
        printf("valor, eh:%d inserido na [%da.] pos\n ", x, j+1);
        Lista->insereComoPilha(&Lista[j],num);
        do{
                    Lista->removerComoPilha(&Lista[b], num, x);
                    printf("O valor %d, foi removido e esta na pos %da\n",x, b+1);
                    fflush(stdin);
                } while(b!=j);
                b++;

    }
    free(Lista);// liberação da memoria alocada
    /*try{ //o bloco try- catch esta comentado pois a ideia era lançar uma exeção quando a lista estiver cheia
    pedindo a realocação de memoria mas não funcionou
       if(f==1){
            printf("Um erro ocorreu:", &f);
        } catch(int f);
        printf("realoque memoria \n");*/

    return 0;

    }
//}

