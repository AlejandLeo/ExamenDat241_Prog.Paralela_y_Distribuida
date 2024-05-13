#include "stdio.h"
#include "omp.h"

void suma(int a,int b,int *c){
	*c=a+b;
}
void resta(int a,int b,int *c){
	*c=a-b;
}
int multiplicacion(int a,int b,int *c){
	int i;
	*c=0;
	for(i=1;i<=b;i++){
		suma(a,*c,c);
	}
	return *c;
}
int division(int a,int b,int *c){
	*c=0;
	int i=0;
	while(a>=b){
		resta(a,b,c);
		i++;
		a=*c;
	}
	*c=i;
}

void main(){
	int activo,cantidadOperaciones;
	int x,y,z,i=0;
	printf("x:\n");
	scanf("%d",&x);
	printf("y:\n");
	scanf("%d",&y);

	cantidadOperaciones=4;
	omp_set_num_threads(cantidadOperaciones);

	#pragma omp parallel
	{
		activo =omp_get_thread_num();
		if(activo==0){
		suma(x,y,&z);
		printf("x+y: %d\n",z);
		}
		else if(activo ==1){
		resta(x,y,&z);
		printf("x-y: %d\n",z);
		}
		else if(activo==2){
			multiplicacion(x,y,&z);
		printf("x*y: %d\n",z);
		}
		else if(activo==3){
			division(x,y,&z);
			printf("x/y: %d\n",z);
		}		
	}		
}	
/*
	gcc -fopenmp ej3.c -o ej3
	ej3
*/