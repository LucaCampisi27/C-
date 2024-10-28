//3.	Realice un programa que solicite de la entrada estándar un entero del 1 al 10 y muestre en la salida estándar su tabla de multiplicar//
//cout<<num<<"*"<<i<<"="<<num*i<<endl;//
#include <iostream>
using namespace std;

int main() {
    int num, tabla = 0;

    
    do {
        cout << "Ingrese un numero del 1 al 10: ";
        cin >> num;

        if (num < 1 || num > 10) {
            cout << "Numero fuera del rango permitido. Intente nuevamente." << endl;
        }
    } while (num < 1 || num > 10);

    
    for (int i = 1; i <= 10; i++) {
        tabla = num * i;
        cout << "La tabla de " << num << " ---> " << num << " * " << i << " = " << tabla << endl;
    }

    return 0;
}
