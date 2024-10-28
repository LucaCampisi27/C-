#include <conio.h>
#include <iostream>

using namespace std;

void valNuevo(int&, int&);

int main() {
    int num1, num2;
    cout << "Digite un numero: ";
    cin >> num1;
    cout << "Digite otro numero: ";
    cin>>num2;
    valNuevo(num1, num2);
    getch();
    return 0;
}

void valNuevo(int& xnum, int& ynum) {
    int aux;
    cout << "El valor del primer numero es: " << xnum << endl;
    cout << "El valor del segundo numero es: " << ynum << endl;
    cout<<"------------------------------------------------\n";
    aux=xnum;
    xnum=ynum;
    ynum=aux;
    cout<<"El valor intercambiado del primer numero es:"<<xnum<<endl;
    cout<<"El valor intercambiado del segundo numero es:"<<ynum<<endl;

}