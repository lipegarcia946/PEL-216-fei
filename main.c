#include "LDE.h"
//chamada do arquivo de declara��o e fun��o principal
int main(int argc, char *argv[])
{
    struct tLista lista;
    int opc;
    iniciaLista(&lista);
   // chamada da inicializa��o da lista e do menu
    do
    {
       opc = menu();
       switch(opc)
       {
            case 1: inserir(&lista);
                    break;
            case 2: listar(lista);
                    break;
            case 3: remover(&lista);
                    break;
            case 4: localizar(lista);
       }
    }while(opc != 5);

    printf("\nEntao vai!! Tchau!\n");
    system("PAUSE");
    return 0;
}
