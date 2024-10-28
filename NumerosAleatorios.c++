#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
 int a=0, valor=0;
    
    // De cero a RAND_MAX -----------------------------------------------------------------------
    
	a = rand(); // Genera un valor entre 0 y RAND_MAX
    cout<<a<<endl;
    cout<<"RAND_MAX para este equipo tiene un valor de:"<<RAND_MAX;
    
    cout<<endl<<endl<<endl;
    // De cero a 9, 19 , 999... -----------------------------------------------------------------------
    
    a = rand() % 10; // Genera un valor entre 0 y 9
    cout<<a<<endl;
    a = rand() % 20; // Genera un valor entre 0 y 19
    cout<<a<<endl;
    a = rand() % 1000; // Genera un valor entre 0 y 999
    cout<<a<<endl;
    
    cout<<endl<<endl<<endl;
    // Numero aleatorio con límite inferior... -----------------------------------------------------------------------
    
    valor = 10 + rand();		// Genera números aleatorios a partir del 10
    cout<<valor<<endl;
	valor = 65 + rand();		// Genera números aleatorios a partir del 65
	cout<<valor<<endl;
    
    cout<<endl<<endl<<endl;
    // Numero aleatorio con límites inferiores y superiores... -----------------------------------------------------------------------
    
    valor = 1 + rand() % 100; 	// Genera un valor entre 1 y 100. *El numero que ponemos al inicio se recorre, aquí como es 1, el 99 pasa a 100.
    cout<<valor<<endl;
	valor = 25 + rand() % 100; 	// Genera un valor entre 25 y 124 *El numero que ponemos al inicio se recorre, aquí como es 25, el 99 pasa a 124.
	cout<<valor<<endl;







    return 0;
}