#include<iostream>
using namespace std;
int main (){
float hombres , mujeres , total , PH,PM ;
cout<<"Ingrese la cantidad de hombres:";
cin>> hombres;
cout<<"ingrese la cantidad de mujeres: ";
cin >>mujeres;
total = hombres + mujeres;
PH = (hombres*100)/total;
PM=(mujeres*100)/total;
cout<<"El porcentaje de hombres es de:"<<PH <<"%" <<"\nEl porcentaje de mujeres es de:"<<PM<<"%";

return 0;
}