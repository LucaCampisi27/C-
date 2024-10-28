//2.	Determinar si un alumno reprueba o no un curso, sabiendo que aprobará si su promedio de 3 calificaciones es mayor o igual a 7; reprueba caso contrario.//
#include <iostream>
using namespace std;
int main(){
    float cal1,cal2,cal3,promedio;
    cout<<"Ingrese la calificacion 1: ";
cin>>cal1;
cout<<"Ingrese la calificacion 2:";
cin>>cal2;
cout<<"Ingrese la calificacion 3:";
cin>>cal3;
promedio=(cal1+cal2+cal3)/3;
if (promedio>=7)
{
    cout<<"Su Nota final es: "<<promedio<<" Aprobado Desocupado";
}else{
    cout<<"Su Nota final es: "<<promedio<<" Desaprobado a rendir";
}










return 0;
}