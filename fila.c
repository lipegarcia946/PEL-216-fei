#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 10
typedef struct{
       int itens[TAMANHO];
       int fim, inicio, quantidade;
}tFila;

/*inicia uma fila vazia*/
void iniciaFila(tFila *q)
{
     q->inicio = -1;
     q->fim = -1;
     q->quantidade = 0;
}

void enfileira(tFila *q)
{
     int it;
     if(q->fim != TAMANHO-1)
     {  /* tem espaco na fila*/
          if(q->inicio == -1) // estah enfileirando o primeiro item
          {
               q->inicio = 0;
          }
          /*caso geral*/
          q->fim++;
          it = lerItem();
          q->itens[q->fim] = it;
          q->quantidade++;
          printf("\nItem [%d] enfileirado na %da. posicao\n", it, q->fim+1);
     }
     else /* nao tem mais espaco*/
     {
          printf("\nA fila esta cheia!\n");
     }
     system("pause");
}

int lerItem(){
    int it;
    printf("\nInforme um numero: \n");
    scanf("%d", &it);
    return it;
}

void desenfileira(tFila *q)
{
     int it;
     int inicio = q->inicio;

     if(q->inicio != -1 && q->fim != -1 && q->inicio <= q->fim)
     { /* Fila nao estah vazia*/
         if(q->fim == q->inicio)
         {
                   iniciaFila(q);
         }
         else
         {
             q->inicio++;
         }
         it = q->itens[inicio];
         printf("\n%d foi desenfileirado!\n", it);
     }
     else /* fila esta vazia*/
     {
         printf("\nImpossivel desenfileirar de uma fila vazia!\n");
     }
     system("pause");
}




void mostrarFila(tFila q)
{
     int itAtual=q.inicio;
     system("cls");

     if(q.inicio != -1 && q.fim != -1 && q.inicio <= q.fim)
     {
          printf("Itens na Fila!\n");
          while(itAtual <= q.fim)
          {
               printf(" %d ", q.itens[itAtual]);
               itAtual++;
          }
     }
     else
     {
         printf("Fila Vazia!");
     }
     system("pause");
}

int menu(void)
{
    int opc;
    system("cls");
    printf("Escolha uma opcao valida!\n");
    printf("      1 - Enfileirar     \n");
    printf("      2 - Mostrar Fila   \n");
    printf("      3 - Desenfileirar  \n");
    printf("      4 - Sair           \n");
    printf("      ==> ");
    scanf("%d", &opc);
    if(opc<1 || opc>4)
    {
        printf("\nOpcao %d invalida! Por favor!!!\nEscolha uma opcao valida!\n",opc);
        system("pause");
        return menu();
    }
    return opc;
}

void chamaFuncao(tFila *q)
{
     int opc;
     do
     {
         opc = menu();
         switch(opc)
         {
                case 1:
                           enfileira(q);
                           break;
                case 2:
                           mostrarFila(*q);
                           break;
                case 3:
                           desenfileira(q);
         }
     }while(opc!=4);
     printf("\nTchau!\n");
}

int main(int argc, char *argv[])
{
    tFila fila;
    iniciaFila(&fila);
    chamaFuncao(&fila);
    system("PAUSE");
    return 0;
}
