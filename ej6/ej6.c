#include "stdio.h"
#include "math.h"
#include "mpi.h"

int main(int argc, char *argv[]){
	int proc,nroProc,n,i;
	
	n=pow(10,4);
	double r1,r2,r3;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &proc); //rank
  	MPI_Comm_size(MPI_COMM_WORLD, &nroProc); //size 

 	if(proc==0){
 		MPI_Recv(&r1,1,MPI_INT,1,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  		MPI_Recv(&r2,1,MPI_INT,2,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  		MPI_Recv(&r3,1,MPI_INT,3,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  		double s=0;
		s=r1+r2+r3;
		s=3+4*(s);
		printf("Pi: %f \n",s);
  	}
  	if(proc==1){
  		r1=0;
  		for(i=0;i<n;i++){
 			r1=r1+(pow((-1),(i+1)/((2*i)*(2*i+1)*(2*i+2))));
 		}
 		MPI_Send(&r1,1,MPI_INT,0,0,MPI_COMM_WORLD);
  	}
  	if(proc==2){
  		r2=0;
  		for(i=n;i<n*2;i++){
 			r2=r2+(pow((-1),(i+1)/((2*i)*(2*i+1)*(2*i+2))));
 		}
 		MPI_Send(&r2,1,MPI_INT,0,0,MPI_COMM_WORLD);
  	}
  	if(proc==3){
  		r3=0;
  		for(i=n*2;i<n*3;i++){
 			r3=r3+(pow((-1),(i+1)/((2*i)*(2*i+1)*(2*i+2))));
 		}
 		MPI_Send(&r3,1,MPI_INT,0,0,MPI_COMM_WORLD);
  	}
  	MPI_Finalize();
}
/*
"Símbolo del sistema de Developer Command Prompt"-visual studio
cl /I"C:\Program Files (x86)\Microsoft MPI\SDK\Include" ej6.c /link /LIBPATH:"C:\Program Files (x86)\Microsoft MPI\SDK\Lib\x86" msmpi.lib -o ej6
mpiexec -n 4 ej6.exe
*/