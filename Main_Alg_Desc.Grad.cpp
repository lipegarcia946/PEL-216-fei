#include <stdio.h>
#include<stdlib.h>
#include<math.h>
class Funcao{ // A classe funcao possue atributo e dois métodos
public:
    int x0;
    int CalcFunc(int xi);
    int CalcDerivada(int xi);
};
// calcula o valor da  função no ponto xi
int Funcao::CalcFunc(int xi){
    return pow(xi,2);
}
// calcula a derivada da função no ponto xi
int Funcao::CalcDerivada(int xi){
return 2*xi;
}
int main(){
    Funcao f;
    int resp,i= resp, n;// variveis de controle
    float beta,Grad; // variaveis para obter os resultados
    printf("programa que execulta o Algoritmo de Desc. de Grad p/ calcular digite os parametros:\n");
    fflush(stdin);
    printf("digite a quantidade de execucoes: ");// parte do codigo que faz repetição
    scanf("%d",&n);// no. de repetições definido pelo usuario
    for(int j=0; j<n; j++){ //laço que faz as n- repetições
            printf("%da execucao:\n",j+1);
            printf("digite um valor para xi(ponto inicial):");/*parametros fornecidos pelo usuario
        valor de x0, beta*/
        scanf("%d",&f.x0); //Lê o valor de xi (ou x0)
        resp=f.CalcFunc(f.x0);
        printf("digite um valor para servir como taxa de aprendizado (beta):\n");
        scanf("%f",&beta);
        printf("O valor do ponto xi da funcao eh: =%d\n", resp);
        do {//laço para calculo do gradiente
            int s= f.CalcDerivada(f.x0); // pega o valor da derivada
            Grad=abs(Grad-beta* s); // função que calcula o gradiente
            printf("O gradiente da funcao eh: = %.2f\n", Grad);// resposta do gradiente
        i++;// iteração para calculuar o gradienet
        }while(i>beta && i< 0); // fim laço do-while
    } //fim do laço for
    return 0;


} // fim do programa
