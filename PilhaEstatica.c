#include <stdio.h>
#include<stdlib.h>
#define TAMANHO 10
typedef struct {
    int itens[TAMANHO];
    int topo;
} tPilha;

void iniciaPilha(tPilha *s)
{
    s->topo = -1;
}

int lerItem(void)
{
     int it;
     printf("\nInforme o dado: \n");
     scanf("%d", & it);
     return it;
}

void empilha(tPilha *s)
{
    int it;
    if(s->topo != TAMANHO-1)
    { /* tem espaco na pilha*/
        it = lerItem();
        s->topo++;
        s->itens[s->topo] = it;
        printf("\nItem:[%d] empilhado com sucesso!\n", it);
    }
    else /* pilha cheia*/
    {
        printf("\nPilha Cheia!\n");
    }
    system("pause");
}

int desempilha(tPilha *s)
{
    int it;
    if(s->topo != -1)
    { /* ha itens na pilha*/
        it = s->itens[s->topo];
        s->topo--;
    }
    else /* pilha vazia*/
    {
        printf("\nPilha Vazia!\n");
        system("pause");
    }
    return it;
}


int menu(void)
{
    int opc;
    system("cls");
    printf(" ---------------------------- \n");
    printf("   Exemplo de Pilha Estatica  \n");
    printf(" Escolha uma das opcoes abaixo\n");
    printf("       1 - Empilhar           \n");
    printf("       2 - Mostrar Pilha      \n");
    printf("       3 - Desempilhar        \n");
    printf("       4 - Sair               \n");
    printf("    ==>");
    scanf("%d", &opc);
    if(opc < 1 || opc > 4)
    {
        printf("\nOpcao %d invalida!\nEscolha uma opcao valida!\n", opc);
        system("pause");
        opc = menu();
    }
    return opc;
}

void mostra(tPilha s)
{
    int i;
    system("cls");
    if(s.topo != -1)
    {
        for(i=s.topo; i>=0; i--)
        {
            printf("\n%d", s.itens[i]);
        }
    }
    else
    {
         printf("\nNao eh possivel mostrar uma pilha vazia!\n");
    }
    printf("\n");
    system("pause");
}
int main(int argc, char *argv[])
{
tPilha pilha;
  int escolha;

  iniciaPilha(&pilha);

  do
  {
      escolha = menu();

      switch(escolha)
      {
            case 1:
                    empilha(&pilha);
                    break;
            case 2:
                    mostra(pilha);
                    break;
            case 3:
                    printf("Valor desempilhado: [%d]", desempilha(&pilha));
                    system("pause");
      }
  }while(escolha!=4);
  printf("\nTchau!!! :'(\n");
  system("PAUSE");
  return 0;
}
