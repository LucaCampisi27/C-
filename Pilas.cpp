#include<iostream>
using namespace std;
struct nodo{
    int dato;
    nodo *siguiente;
};
void agregarPila(nodo *&,int);
void sacarPila(nodo *&,int &);
int main(){
nodo *pila=NULL;
char rta;
int dato;
do{ 

    cout<<"Digite un numero";
    cin>>dato;
    agregarPila(pila,dato);
    cout<<"\nDesea agregar otro elemento (S/N):";
    cin>>rta;
}while ((rta=='s')||(rta=='S'));
cout<<"\nSacando los elementos de pila:";





}