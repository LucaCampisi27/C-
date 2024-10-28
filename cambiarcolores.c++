#include <iostream>
#include<conio.h>
#include <string>
using namespace std;
int main(){
    int numeros[] = {1,2,3,4,5};
    int inf,sup,mitad,dato;
    char bandera='f';

    dato = 8; //dato que no esta en el arreglo

    inf = 0;
    sup = 4;

    while(inf <=sup){
        cout<<inf;
    mitad = (inf+sup)/2;

if(numeros[mitad] == dato){
    bandera = 'v';
break;
    }

if (numeros[mitad]> dato){
sup = mitad;
mitad = (inf+sup)/2;
}
if(numeros[mitad] < dato){
    inf = mitad;
    mitad = (inf+sup)/2;
}
}

if(bandera=='v'){
        cout<<"el numero ha sido encontrado en la posicion: "<<mitad<<endl;
}else{
cout<<"el numero no ha sido encontrado";
}
getch();
return 0;
}