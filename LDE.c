//arquivo de declaração das funções
#include "LDE.h"
/*função que inicializa a lista */
void iniciaLista(struct tLista *lista)
{
    lista->primeiro = NULL;// ponteiro para o primeiro registro da lista
    lista->quantidade = 0; // contador para a quantidade de registros da lista
}
/*função que inicializa inseta na lis */

void inserir(struct tLista *lista)
{
    struct tItem *novo = lerItem(); // ponteiro para o novo registro da lista
    struct tItem *atual = lista->primeiro; // ponteiro para que passa por toda lista
    struct tItem *anterior = NULL;

    int achei = NAO_LOCALIZADO;// variavel p/ controle

    if(lista->primeiro == NULL) // inserindo primeiro de uma lista vazia
    {
        lista->primeiro = novo;
        lista->quantidade ++;
    }
    else // inserindo em uma lista nao vazia
    {
        while(atual != NULL && achei == NAO_LOCALIZADO) // procurando a posicao a inserir
        {
            if(atual->chave >= novo->chave) // se entrar no if, encontrei a posicao ou um item repetido
            {
                if(atual->chave == novo->chave) // se for um item repetido
                {
                    printf("\nItem chave [%d] jah estah na lista!\n", novo->chave);
                    system("pause");
                    return;
                }
                else
                {
                    achei = LOCALIZADO;
                }
            }
            else
            {
                anterior = atual;
                atual = atual->proximo;
            }
        }
        if(achei == NAO_LOCALIZADO) // inserindo o ultimo item da lista
        {
            anterior->proximo = novo;
            lista->quantidade ++;
        }
        else // posicao de insercao foi localizada
        {
            if(anterior == NULL) // estah inserindo o primeiro item de uma lista nao vazia
            {
                lista->primeiro = novo;
                novo->proximo = atual;
                lista->quantidade ++;
            }
            else // estah inserindo no meio da lista
            {
                anterior->proximo = novo;
                novo->proximo = atual;
                lista->quantidade ++;
            }
        }
    }
    printf("\nItem: [%d] inserido com sucesso!\n", novo->chave);
    system("pause");
}

/*função que cria um item na lista */

struct tItem * criaItem()
{
    struct tItem *it = (struct tItem *) malloc(sizeof(struct tItem));// alocação de mem.
    if(it == NULL)
    {
        printf("\nNao foi possivel alocar memoria!\n");
        system("pause");
    }
    it->proximo = NULL;
    return it;
}
/*função que lê uma chave*/
struct tItem * lerItem()
{
    struct tItem *it = criaItem();
    if(it != NULL) //leitura da chave
    {
        printf("\nEntre a chave do item: \n");
        scanf("%d", &it->chave);
        return it;
    }
}
/*função que auxilia no gerenciamento da lista */

int menu()
{
    int opcao;
    system("cls");
    printf(" **************** LDE *************** \n");
    printf("        Escolha uma opcao abaixo      \n");
    printf("            1 - Inserir               \n");
    printf("            2 - Listar                \n");
    printf("            3 - Remover               \n");
    printf("            4 - Localizar             \n");
    printf("            5 - Sair                  \n");
    printf("           ==> ");
    scanf("%d", &opcao);
    if(opcao < 1 || opcao > 5)
    {
        printf("\nOpcao %d invalida!\nEntre uma opcao valida!\n", opcao);
        system("pause");
        opcao=menu();
    }
    return opcao;
}
/*função que mostra a lista na tela */

void listar(struct tLista lista)
{
    struct tItem *atual = lista.primeiro;

    system("cls");

    while(atual != NULL)
    {
        printf(" %d \n", atual->chave);
        atual = atual->proximo;
    }
    printf("\nHa %d itens na lista!\n", lista.quantidade);
    system("pause");
}
/*função que remove um item da lista*/
void remover(struct tLista *lista)
{
    struct tItem *anterior = NULL;
    struct tItem *atual = lista->primeiro;
    struct tItem *thechoosen;

    int achei = NAO_LOCALIZADO; // variavel de controle valor 0 ou 1

    if(lista->primeiro != NULL)
    {
        thechoosen = lerItem();
        while(atual != NULL && achei == NAO_LOCALIZADO)
        {
            if(atual->chave == thechoosen->chave)
            {
                achei = LOCALIZADO; // variavel de controle valor 0 ou 1
            }
            else
            {
                anterior = atual;
                atual = atual->proximo;
            }
        }
        if(achei == LOCALIZADO)
        {
            if(anterior == NULL) // estou exterminando o primeiro item da lista
            {
                lista->primeiro = atual->proximo;
            }
            else // estou removendo do meio ou do final
            {
                anterior->proximo = atual->proximo;
            }
            lista->quantidade--;
            free(atual);
            free(thechoosen);
            printf("\nItem removido com sucesso!\n");
            system("pause");
        }
        else
        {
            printf("\nItem thechoosen nao estah na lista!\n");
            system("pause");
        }
    }
    else
    {
        printf("\nHa %d elementos na lista!\n", lista->quantidade);
    }
}
/*função que realiza a busca na lista */
void localizar(struct tLista lista)
{
    struct tItem *thechoosen, *atual = lista.primeiro;

    int achei = NAO_LOCALIZADO;

    if(lista.primeiro != NULL)
    {
        thechoosen = lerItem();

        while(atual != NULL && !achei)
        {
            if(atual->chave == thechoosen->chave)
            {
                printf("\nLocalizado\n");
                printf("\nItem: chave: %d\n", atual->chave); // listar todos os campos da estrutura
                achei = LOCALIZADO;
            }
            else
            {
                atual = atual->proximo;
            }
        }
        if(!achei)
        {
            printf("\nNao achei!\n");
        }
    }
    else
    {
        printf("\nHa %d elementos na lista!\n", lista.quantidade);
    }
    system("pause");
    free(thechoosen);
}


