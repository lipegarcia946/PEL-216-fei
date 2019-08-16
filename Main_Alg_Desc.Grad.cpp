#include <stdio.h>
#include<stdlib.h>
#include<math.h>
class Funcao{ // A classe funcao possue atributo e dois m�todos
public:
    int x0;
    int CalcFunc(int xi);
    int CalcDerivada(int xi);
};
// calcula o valor da  fun��o no ponto xi
int Funcao::CalcFunc(int xi){
    return pow(xi,2);
}
// calcula a derivada da fun��o no ponto xi
int Funcao::CalcDerivada(int xi){
return 2*xi;
}
int main(){
    Funcao f;
    int resp,i= resp, n;// variveis de controle
    float beta,Grad; // variaveis para obter os resultados
    printf("programa que execulta o Algoritmo de Desc. de Grad p/ calcular digite os parametros:\n");
    fflush(stdin);
    printf("digite a quantidade de execucoes: ");// parte do codigo que faz repeti��o
    scanf("%d",&n);// no. de repeti��es definido pelo usuario
    for(int j=0; j<n; j++){ //la�o que faz as n- repeti��es
            printf("%da execucao:\n",j+1);
            printf("digite um valor para xi(ponto inicial):");/*parametros fornecidos pelo usuario
        valor de x0, beta*/
        scanf("%d",&f.x0); //L� o valor de xi (ou x0)
        resp=f.CalcFunc(f.x0);
        printf("digite um valor para servir como taxa de aprendizado (beta):\n");
        scanf("%f",&beta);
        printf("O valor do ponto xi da funcao eh: =%d\n", resp);
        do {//la�o para calculo do gradiente
            int s= f.CalcDerivada(f.x0); // pega o valor da derivada
            Grad=abs(Grad-beta* s); // fun��o que calcula o gradiente
            printf("O gradiente da funcao eh: = %.2f\n", Grad);// resposta do gradiente
        i++;// itera��o para calculuar o gradienet
        }while(i>beta && i< 0); // fim la�o do-while
    } //fim do la�o for
    return 0;


} // fim do programa
