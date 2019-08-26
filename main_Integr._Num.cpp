#include<stdio.h>
#include<stdlib.h>
#include<math.h>
class FuncIntegr{ // a classe FuncIntegr possui 3 atributos e 8 metodos
public:
    int a;
    int b;
    int n;
    //protótipo dos metodos
int DescFunc(int, int);
int calcfunc(int,int,int,int);
float RegraDosRetangulos(int,int, int,int,int);
float RegraDoTrapezio(int,int,int,int,int);
float RegraDeSimpson(int,int, int,int,int);
float ErroRegraDosRetangulos(int,int ,int, int);
float ErroRegraDoTrapezio(int,int ,int, int);
float ErroRegraDeSimpson(int,int ,int, int);

};
//apica a função no ponto de acordo com o tipo
int FuncIntegr::DescFunc(int tipo, int x){
    if (tipo == 1){
        return pow(2.718, x);
    }
    if(tipo==2){
        return sqrt(1-(pow(x,2)));
    }
    if(tipo== 3){
        return (2.718*pow(-x,2));
    }

}
// calcula a df/dx de acordo com o tipo da função e a regra
int FuncIntegr::calcfunc(int reg, int tipo, int x, int y){
    float eqa, eqb;
    eqa= (1-(pow(x,2)));
    eqb= (1-(pow(x,2)));
    if((reg== 1 || reg==2)&& (tipo==1)){
        return pow(2.718,x)*y;
    }
    if((reg== 1 ||reg==2) && (tipo==2)){
        return -1/(sqrt(eqa)* pow(x,3/2))*y;
    }
    if((reg== 1 || reg== 2) && (tipo == 3)){
        return (2.718*pow(-x,2))*(4*pow(x,2)-2)*y;
    }
    if(reg== 3 && tipo ==1){
        return pow(2.718, x);
    }
    if(reg==3 && tipo==2){
        return (((1/sqrt(eqb)*pow(x,7/2))));
    }
    if(reg==3 && tipo==3){
        return (((2.718*pow(-x,2))*(4*pow(x,2)-2)));
    }
} // realiza o calculo da regra dos retangulos
float FuncIntegr::RegraDosRetangulos(int tipo, int a ,int b, int fa, int fb){
    return (b-a)*(fa+fb)/2;
}
// realiza o calculo da regra do trapezio
float FuncIntegr::RegraDoTrapezio(int tipo, int a ,int b, int fa,int fb){
    return (b-a)*(fa/2+fb/2);
}
// realiza o calculo da regra de Simpson
float FuncIntegr::RegraDeSimpson(int tipo, int a ,int b, int fa,int fb){
    return (b-a)*(fa+4*(fa+fb)/2+fb)/6;
}
// realiza o calculo do erro de aproximação da regra dos retangulos
float FuncIntegr::ErroRegraDosRetangulos(int tipo, int a ,int b, int y){
    return (1/24*pow((b-a),3)* y);
}
// realiza o calculo do erro de aproximação da regra do trapezio
float FuncIntegr::ErroRegraDoTrapezio(int tipo,int a,int b, int y){
    return (1/12*pow((b-a),3)* y);
}
// realiza o calculo do erro de aproximação da regra de Simpson
float FuncIntegr::ErroRegraDeSimpson(int tipo, int a ,int b, int y){
    return (1/2800*pow((b-a),5)* y);
}

int main(){// função principal
    FuncIntegr Fi;// objeto da classe FuncIntegr
    float RR, RDT, RS;// variaveis que recebem o valor do ponto
    int fxa,fxb,k, tipo;// variaveis de controle
    float Epa1,Epb1, Epa2,Epb2;// variaveis p/ calcular o erro
    float Epa3,Epb3;// variaveis p/ calcular o erro
    int f_xa1,f_xa2,f_xa3, f_xb1,f_xb2, f_xb3;// variaveis p/ calcular df/dx
    printf("programa que Calcula a integral numerica, para comecar digite alguns parametros:\n "); //introdução p/ o usuario
    printf("A quantida de execucoes: ");// idem
    scanf("%d",&k);//lê o no. de execuções
    for(int i=0;i<k;i++){//laço para executar as k execuções
        printf("[%da.] execucao\n",i+1); // controle das execuções
        printf("escolha um tipo de funcao: \n");
        printf("1- exponecial: (e^x)dx, 2- raiz:sqrt(1-(x^2))dx, 3- exp. neg: (e^-(x^2))dx \n");
        //mostra as opções de tipos de função
        scanf("%d",&tipo); //Lê o tipo de função escolida pelo usuario
        printf("digite um valor para o limite inferior a: ");//captura o a dado pelo usuario
        scanf("%d",&Fi.a);// Lê o valor de a
        printf("digite um valor para o limite superior b (b>a): "); //captura o b dado pelo usuario
        scanf("%d",&Fi.b); //Lê o valor de b
        fxa=Fi.DescFunc(tipo, Fi.a);//mostra na tela o valor de fx em a
        printf("O valor da funcao calculado em a: %d\n",fxa);//mostra na tela o valor de fx em a
        fxb=Fi.DescFunc(tipo, Fi.b);//Calcula o valor de fx em b
        printf("O valor da funcao calculado em b: %d\n",fxb);//mostra na tela o valor de fx em b
        printf("a Integral da funcao no intervalo[%d,%d]  de acordo com as regras:\n", Fi.a,Fi.b);//mostra na tela o valor de a e b
        RR=Fi.RegraDosRetangulos(tipo,Fi.a,Fi.b,fxa,fxb);//Calcula o valor de fx pela regra do trapezio
        printf("pela Regra do Retangulo eh: %.2f\n ",RR);//mostra na tela o valor de fx pela regra dos retangulos
        RDT=Fi.RegraDoTrapezio(tipo, Fi.a,Fi.b,fxa,fxb);//Calcula o valor de fx pela regra do trapezio
        printf("pela Regra do Trapezio eh: %.2f\n ",RDT); //mostra na tela o valor de fx pela regra do trapezio
        RS=Fi.RegraDeSimpson(tipo,Fi.a,Fi.b,fxa,fxb);// Calcula o valor de fx pela regra de simpson
        printf("pela Regra De Simpson eh: %.2f\n",RS);//mostra na tela o valor de fx pela regra de simpson
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");//mostra na tela
        printf("calculando as derivadas das funcoes....\n");//mostra na tela
        printf("O valor da derivada da funcao calculado em a:%d e b:%d\n",Fi.a, Fi.b); //mostra na tela
        printf("para a Regra Dos Retangulos:\n");//mostra na tela
        f_xa1=Fi.calcfunc(1,tipo,Fi.a,fxa); // calc df/dx no ponto a
        f_xb1=Fi.calcfunc(1,tipo,Fi.b,fxb);// calc df/dx no ponto b
       //mostra na tela
        printf ("A derivada da funcao em a:%d e b:%d eh: f'(xa)= %d e f'(xb)= %d\n\n",Fi.a, Fi.b, f_xa1,f_xb1);
        //mostra na tela
        printf("para a Regra Dos Trapezios:\n");//mostra na tela
        f_xa2=Fi.calcfunc(2,tipo,Fi.a,fxa); // calc df/dx no ponto a
        f_xb2=Fi.calcfunc(2,tipo,Fi.b,fxb);// calc df/dx no ponto b
        printf ("A derivada da funcao em a:%d e b:%d eh: f'(xa)= %d e f'(xb)= %d\n\n",Fi.a, Fi.b, abs(f_xa2),abs(f_xb2));
        //mostra na tela
        printf("para a Regra De Simpson:\n"); //mostra na tela
        f_xa3=Fi.calcfunc(3,tipo,Fi.a,fxa);// calc df/dx no ponto a
        f_xb3=Fi.calcfunc(3,tipo,Fi.b,fxb);// calc df/dx no ponto b
        printf ("A derivada da funcao em a:%d e b:%d eh: f'(xa)= %d e f'(xb)= %d\n\n",Fi.a, Fi.b,abs(f_xa1),abs(f_xb1));
        //mostra na tela
        printf("___________________________________________________________________________\n");//mostra na tela
        //variaveis para calculo do erro
        float Er_RR, Er_RDT, Er_RS;
        printf("O valor do erro a aproximado da funcao...\n");//mostra na tela
        printf("para a Regra Dos Retangulos:\n");
        Epa1=Fi.ErroRegraDosRetangulos(tipo,Fi.a,Fi.b,f_xa1); // parcial em a
        Epb1=Fi.ErroRegraDosRetangulos(tipo,Fi.a,Fi.b,f_xb1); // parcial em b
        Er_RR=(1/2*(Epb1+Epa1)*(f_xa1+f_xb1)+ RR); //calculo do erro pela regra dos retangulos
        printf("O erro apximado da funcao eh: E= (%.2f) por cento\n", Er_RR); //imprime na tela
        printf("para a Regra Dos Trapezios:\n");// imprime na tela
        Epa2=Fi.ErroRegraDoTrapezio(tipo,Fi.a,Fi.b,f_xa2);//parcial em a
        Epb2=Fi.ErroRegraDoTrapezio(tipo,Fi.a,Fi.b,f_xb2); // parcial em b
        Er_RDT=(1/2*(Epb2+Epa2)*(Fi.a+Fi.b)+ RDT);// calculo do erro para a regra do trapezio
        printf("O erro apximado da funcao eh: E= (%.2f) por cento\n", Er_RDT);// imprime na tela
        Fi.n= abs(Er_RDT-1- RR);// calculo do erro  para regra dos retangulos
        printf("no. maximo de particoes p/ formar trapezios eh: N= (%d) divisoes \n", Fi.n);//no. divisoes do da area
        printf("para a Regra De Simpson:\n");
        Epa3=Fi.ErroRegraDeSimpson(tipo,Fi.a,Fi.b,f_xa3);//  parcial em a
        Epb3=Fi.ErroRegraDeSimpson(tipo,Fi.a,Fi.b,f_xb3);//  parcial em b
        Er_RS=(1/6*(Epb3+Epa3)+(Fi.b+ 4*f_xb3+f_xb3)+ RS); // calculo do Erro para Regra de simpson
        printf("O erro apximado da funcao eh: E= (%.2f) por cento\n", abs(Er_RS));// imprime na tela


    } //fim do for
    return 0;
}// fim do programa
