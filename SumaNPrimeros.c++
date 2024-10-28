//2.Calcular la suma de los “N” primeros números.//
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
int n,i,suma;
suma = 0;
cout<<"Ingrese el numero N para realizar la suma hasta ahi:"<<endl;
cin>>n;
for ( i = 1; i <= n; i++)
{
    suma = suma + i;
    
}


cout<<"La suma de los primeros  "<<n<<" Numeros es:"<<suma<<endl;

return 0;
}