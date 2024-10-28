#include <iostream>
#include <cstdlib>
#include <ctime>
#include<locale.h>


using namespace std;

int main() {
    setlocale(LC_ALL, "spanish");
    srand(time(0)); // Inicialización del generador de numeros aleatorios

    // Variables
    int numeroAleatorio = rand() % 50 + 1; // Genera un numero aleatorio entre 1 y 50
    int intentos = 0;
    int intentoUsuario;

    // Mensaje de bienvenida
    cout << "Bienvenido al juego de adivinanza de numeros entre 1 y 50." << endl;

    // Bucle para que el usuario adivine el numero
    while (true) {
        // Solicitar al usuario que ingrese un numero
        cout << "Introduce un numero: ";
        cin >> intentoUsuario;
        intentos++;

        // Comprobar si el numero ingresado es correcto, mayor o menor
        if (intentoUsuario == numeroAleatorio) {
            cout << "¡Felicitaciones! Has adivinado el numero en " << intentos << " intentos." << endl;
            break; // Terminar el juego
        } else if (intentoUsuario < numeroAleatorio) {
            cout << "El numero que buscas es mayor." << endl;
        } else {
            cout << "El numero que buscas es menor." << endl;
        }
    }
system("pause");
    return 0;
}
