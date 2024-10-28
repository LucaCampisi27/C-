#include<iostream>
using namespace std;
int main(){
int a=0, valor=0;
int op;
do{
cout<<"\t\tEjemplo de menu"<<endl;
cout<<"menu 1 ........[1]"<<endl;
cout<<"menu 2 ........[2]"<<endl;
cout<<"menu 3 ........[3]"<<endl;
cout<<"Salir ........[4]"<<endl;
cout<<"indique su opcion:";
cin>>op;
switch (op){
case 1:
    cout<<"presionaste la opcion 1"<<endl;
    a = 1 + rand() % 3; // Genera un valor entre 0 y 9
    cout<<a<<endl;
    break;
case 2:
    cout<<"presionaste la opcion 2"<<endl;
    break;
    case 3:
    cout<<"presionaste la opcion 3"<<endl;
    break;
    case 4:
    cout<<"Saliendo"<<endl;
    break;
default:
cout<<"Opcion incorrecta"<<endl;
    break;
}

}while (op != 4);
return 0;
}

    








    
