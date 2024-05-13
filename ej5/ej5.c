#include "stdio.h"
#include "mpi.h"

int main(int argc, char *argv[]){
	int proc,nroProc,n,i,j,k;
	printf("N: \n");
	scanf("%d",&n);

	int m[n][n],v[n],vr[n];
	printf("Entrada-Matriz: \n");	
	for(k=0;k<n*n;k++){
		scanf("%d",&m[i][j]);
		j++;
		if(j==n){
			i++;
			j=0;
		}
	}
	printf("Entrada-Vector: \n");	
	for(i=0;i<n;i++){
		scanf("%d",&v[i]);
	}

	printf("\n---Matriz---\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}

	printf("\n---Vector---\n");
	for(i=0;i<n;i++){
		printf("%d ",v[i]);
	}
	printf("\n");
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &proc); //rank
  	MPI_Comm_size(MPI_COMM_WORLD, &nroProc); //size 

 	if(proc==0){
 		MPI_Recv(m,n,MPI_INT,1,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  		MPI_Recv(v,n,MPI_INT,2,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  		printf("\n---Vector Resultado---\n");
		for(i=0;i<n;i++){
			printf("%d ",vr[i]);
		}
		printf("\n");
  	}
  	if(proc==1){
  		for(i=0;i<n;i++){
 			for(j=0;j<n;j++){
 				m[i][j]=m[i][j]*v[i];
 			}
 		}
 		MPI_Send(m,n,MPI_INT,0,0,MPI_COMM_WORLD);
  	}
  	if(proc==2){
  		for(int i=0;i<n;i++){
  			int s=0;
 			for(int j=0;j<n;j++){
 				s=s+m[j][i];
 			}
 			vr[i]=s;
 		}
  		MPI_Send(v,n,MPI_INT,0,0,MPI_COMM_WORLD);
  	}
  	MPI_Finalize();
}
/*
"Símbolo del sistema de Developer Command Prompt"-visual studio
cl /I"C:\Program Files (x86)\Microsoft MPI\SDK\Include" ej5.c /link /LIBPATH:"C:\Program Files (x86)\Microsoft MPI\SDK\Lib\x86" msmpi.lib -o ej5
mpiexec -n 3 ej5.exe
*/