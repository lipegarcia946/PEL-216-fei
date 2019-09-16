/*codigo testado no linux*/
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// biblotecas 1 e 2 p/ rodar o MPI
#include<time.h> //1
#include<mpi.h>//2

#define MASTER 0 //define o processso mastre como como 0
class Fig_Integr{ // esta classe possui 6 variavis 2 metodo
public:
    int x1,x2,z1,z2;
    int y1, y2;
    float CalcVolumeFig(int, int, float);
    float CalcErroVolumeFig(float, float, int);
};
 //função que calcula o volume da figura
float Fig_Integr::CalcVolumeFig(int NpontosCirc,int qtd_pontos, float C ){
    int i= 0;
    float v;
    while(i<qtd_pontos){
        v= C*(1/NpontosCirc+(qtd_pontos*i));
        i++;
    }
    return v;
}
float Fig_Integr::CalcErroVolumeFig(float f1,float f2, int qtd_pontos){
    return (sqrt(pow(f1,2))-pow(f2,2)/qtd_pontos);

}
int main(int argc, char *argv[]){
    int qP,vRI; //variaveis de controle
    double Vol;
    double numX;
    double numY;
    double numZ;
    double ERRMC, ERRMCt;
    const float PI= 3.14;
    Fig_Integr F;
    F.x1= 1, F.x2=4, F.y1=-1, F.y2=-4,F.z1=1,F.z2=-1;
    printf("Programa que calcula o volume do Toroide, para comecar diga note alguns parametros e diga: \n");
    printf("os limites inferior e superior em x sao a: %d b:%d\n", F.x1, F.x2);
    printf("os limites inferior e superior em z sao a: %d b:%d\n", F.z1, F.z2);
    //printf("diga a quantidade de pontos: ");
    //scanf("%d",&qP);
    qP=1000;
      int PinRT=0,PoutRT=0, ex, ey, i=0, k;
    double Vx, Vy, Vz;
	int   numtasks, taskid, len, rc;
	// inicializa o MPI
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD,&taskid);


	//variaveis para guardar o tempo de execução
	double startime, stoptime, time;

	//contagem de do tempo
	startime = MPI_Wtime();

	//MPI -  divindindo a quantidade de pontos pela  quantide NUMTASKS
	k = qP/numtasks;
//laço de repeticão
  do{
      //escolhendo pontos aleatoriamente mostra na tela
        printf("escolhendo os pontos aleatorios....\n");
        numX= 1 + (rand()/(float)RAND_MAX)*3;
        numY= -3 + (rand()/(float)RAND_MAX)*7;
        numZ = -1 + (rand()/(float)RAND_MAX)*2;
        //calcula o toroide
        printf("Os pontos escolidos foram: %.2f,%.2f,%.2f\n",numX,numY,numZ);
        Vx= numX;
        Vy= numY;
        ex= pow(numX,2);
        ey= pow(numY,2);
        Vz= (pow(numZ,2)+pow(sqrt(pow(ex,2)+pow(ey,2))-3,2));
        // verifica se os pontos estão na RI(regiao de interesse)
        if(numZ <=-1.0){
            if(numY>=-3.0){
                 if(numZ>1.0){

            }
        }
        PoutRT++; //contador de pontos fora da RI

    }
    else{
        PinRT++; //contador de pontos da RI
    }
    i++;
   } while(i<qP);
   //fim do laço de repetição
 // reduce do MPI
  rc = MPI_Reduce(&Vol, &numX, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
   rc = MPI_Reduce(&ex, &numY, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
   rc = MPI_Reduce(&ey, &Vz, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
   rc = MPI_Reduce(&ERRMC, &ERRMCt, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
   // se a tarefa é o processo mestre retorna os valores
  if(taskid==MASTER){
	printf("a quantidade de pontos que estao na RI eh: %d\n", PinRT);
   	printf("a quantidade de pontos que estao fora da RI eh: %d\n", PoutRT);
  	Vol= F.CalcVolumeFig(vRI,qP,PI);
    	printf("O volume do Toroide eh: %f u.v\n ",Vol);
    	ERRMC= F.CalcErroVolumeFig(Vol-1, Vol,qP);
   	 ERRMCt=sqrt(ERRMC*-1);
    	printf("O erro da aproximacao da funcao eh: %.2f\n",ERRMCt);
	}

 return 0;
}
