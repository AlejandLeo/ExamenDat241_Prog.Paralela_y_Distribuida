#include <iostream>

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


int main(){
    int x, y, z;
    std::cout << "x: "<< std::endl;
    std::cin >> x;
    std::cout << "y: "<< std::endl;
    std::cin >> y;

    suma(x,y,&z);
    std::cout << "x+y: "<< z << std::endl;
    
    resta(x,y,&z);
    std::cout << "x-y: " << z << std::endl;
    
    multiplicacion(x,y,&z);
    std::cout << "x*y: " << z << std::endl;
    
    division(x,y,&z);
    std::cout << "x/y: " << z << std::endl;

    return 0;
}
/*  g++ ej2.cpp -o ej2
    ej2
*/