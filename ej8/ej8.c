#include "stdio.h"

void seriePar(int n,int i,int *v){
	v[i]=(i+1)*2;
}
void mostrarV(int n,int *v){
	int i;
	for(i=0;i<n;i++){
		printf("%d,",v[i]);
	}
	printf("\n");
}
void main(){
	int i,n;
	printf("N:\n");
	scanf("%d",&n);
	int v[n] ;
	#pragma omp parallel for private(i)
	for(i=0;i<n;i++){
		seriePar(n,i,v);
	}
	printf("---Serie Par---\n");
	mostrarV(n,v);
}
/*
	gcc -fopenmp ej8.c -o ej8
	ej8
*/