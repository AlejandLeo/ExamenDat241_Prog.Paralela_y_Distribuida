#include "stdio.h"

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
	int x,y,z;
	printf("x:\n");
	scanf("%d",&x);
	printf("y:\n");
	scanf("%d",&y);

	suma(x,y,&z);
	printf("x+y: %d\n",z);
	
	resta(x,y,&z);
	printf("x-y: %d\n",z);
	
	multiplicacion(x,y,&z);
	printf("x*y: %d\n",z);
	
	division(x,y,&z);
	printf("x/y: %d\n",z);
}
/*  gcc ej1.c -o ej1
    ej1
*/