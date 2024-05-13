#include "stdio.h"
#include "omp.h"

void main(){

	int n,k,i=0,j=0;

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
	for(k=0;k<n;k++){
		scanf("%d",&v[k]);
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
	
	i=0,j=0;
	int s=0;

	#pragma omp for private(k)
	for(int k=0;k<n*n;k++){
		s=s+m[i][j]*v[k%n];
		j++;
		if(j==n){
			vr[i]=s;
			i++;
			j=0;
			s=0;

		}
	}
	printf("\n---Vector Resultado---\n");
	for(i=0;i<n;i++){
		printf("%d ",vr[i]);
	}
	printf("\n");
}
/*
	gcc -fopenmp ej4.c -o ej4
	ej4
*/