// Arquivo de declaração
#include <stdio.h>
#include <stdlib.h>
//  declaração das variaveis de controle
#define LOCALIZADO 1
#define NAO_LOCALIZADO 0
//  declaração das estruturas
struct tItem
{
   int chave; // struct tDados
   struct tItem *proximo;
};

struct tLista
{
    struct tItem *primeiro;    
    int quantidade;
};
// prototipos das funçõees
void iniciaLista(struct tLista *);
void inserir(struct tLista *);
void remover(struct tLista *);
void listar(struct tLista);
void localizar(struct tLista);

struct tItem * lerItem();
struct tItem * criaItem();

int menu();







