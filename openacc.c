#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<omp.h>
class Fig_Integr{//A classe Fig_Integr possui 6 variaveis e 2 funções
public:
    int x1,x2,z1,z2;
    int y1, y2;
    float CalcVolumeFig(int, int, float);
    float CalcErroVolumeFig(float, float, int);
};
//a função calcula o volume da figura
float Fig_Integr::CalcVolumeFig(int NpontosCirc,int qtd_pontos, float C ){
    int i= 0;
    float v;
    while(i<qtd_pontos){
        v= C*(1/NpontosCirc+(qtd_pontos*i));
        i++;
    }
    return v;
}
// a função calcula o erro estimado
float Fig_Integr::CalcErroVolumeFig(float f1,float f2, int qtd_pontos){
    return (sqrt(pow(f1,2))-pow(f2,2)/qtd_pontos);

}
// função principal
int main(int argc, char *argv[]){
    int qP,vRI; // variveis de controle
    double Vol;
    double numX; //variavel p/ sortear um valor aleatório em x
    double numY;//variavel p/ sortear um valor aleatório em y
    double numZ;//variavel p/ sortear um valor aleatório em z
    double ERRMC, ERRMCt; //variaveis p/ calcular o erro
    const float PI= 3.14;// constante p/ calcular o volume
    Fig_Integr F;
    F.x1= 1, F.x2=4, F.y1=-1, F.y2=-4,F.z1=1,F.z2=-1;
    printf("Programa que calcula o volume do Toroide, para comecar diga note alguns parametros e diga: \n");
    printf("os limites inferior e superior em x sao a: %d b:%d\n", F.x1, F.x2);
    printf("os limites inferior e superior em z sao a: %d b:%d\n", F.z1, F.z2);
    qP=4000;// valor definido de 1000
      int PinRT=0,PoutRT=0, ex, ey, i; //variaveis de controle
    double Vx, Vy, Vz; //variaveis p/ o cálculo do toróide
//programação paralela com o for
#pragma for acc parallel private (i) reduction(+:PoutRT) reduction(+:PinRT)
 for(i=0; i<qP;i++){
	//sorteio dos pontos aleatorios
        printf("escolhendo os pontos aleatorios....\n");
        numX= 1 + (rand()/(float)RAND_MAX)*3;
        numY= -3 + (rand()/(float)RAND_MAX)*7;
        numZ = -1 + (rand()/(float)RAND_MAX)*2;

        printf("Os pontos escolidos foram: %.2f,%.2f,%.2f\n",numX,numY,numZ);
        Vx= numX;
        Vy= numY;
        ex= pow(numX,2);
        ey= pow(numY,2);
        Vz= (pow(numZ,2)+pow(sqrt(pow(ex,2)+pow(ey,2))-3,2));
        // verifica se os pontos estão ou não na RI
	if(numZ <=-1.0){
            if(numY>=-3.0){
                 if(numZ>1.0){

            }
        }
        PoutRT++; // conta os pontos fora da RI
    }
    else{
        PinRT++; // conta os pontos na RI
    }

}
	// mostra na tela
	printf("a quantidade de pontos que estao na RI eh: %d\n", PinRT);
   	printf("a quantidade de pontos que estao fora da RI eh: %d\n", PoutRT);
  	Vol= F.CalcVolumeFig(vRI,qP,PI);
    	printf("O volume do Toroide eh: %.2f u.v\n ",Vol);
    	ERRMC= F.CalcErroVolumeFig(Vol-1, Vol,qP);
   	ERRMCt=sqrt(ERRMC*-1);
    	printf("O erro da aproximacao da funcao eh: %.2f\n",ERRMCt);


 return 0;
}
