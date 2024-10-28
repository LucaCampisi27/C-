#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int eleccionUsuario;
    int eleccionComputadora;
    char jugarDeNuevo;

    // Inicializar el generador de números aleatorios
    srand(time(0));

    do {
        // Mostrar el menú de opciones
        cout << "\n--- Piedra, Papel o Tijera ---" << endl;
        cout << "1. Jugar" << endl;
        cout << "2. Salir" << endl;
        cout << "Elige una opción: ";
        cin >> eleccionUsuario;

        if (eleccionUsuario == 1) {
            // Mostrar las opciones del juego
            cout << "\nElige tu jugada:" << endl;
            cout << "1. Piedra" << endl;
            cout << "2. Papel" << endl;
            cout << "3. Tijera" << endl;
            cout << "Elige una opción: ";
            cin >> eleccionUsuario;

            // Generar la elección de la computadora
            eleccionComputadora = 1 + rand() % 3 ;

            // Mostrar la elección de la computadora
            cout << "La computadora eligió: ";
            if (eleccionComputadora == 1) {
                cout << "Piedra" << endl;
            } else if (eleccionComputadora == 2) {
                cout << "Papel" << endl;
            } else if (eleccionComputadora == 3) {
                cout << "Tijera" << endl;
            }

            // Determinar el resultado del juego
            if (eleccionUsuario == eleccionComputadora) {
                cout << "Es un empate!" << endl;
            } else if ((eleccionUsuario == 1 && eleccionComputadora == 3) ||
                       (eleccionUsuario == 2 && eleccionComputadora == 1) ||
                       (eleccionUsuario == 3 && eleccionComputadora == 2)) {
                cout << "¡Ganaste!" << endl;
            } else {
                cout << "La computadora gana!" << endl;
            }

            // Preguntar si el usuario quiere jugar de nuevo
            cout << "¿Quieres jugar de nuevo? (s/n): ";
            cin >> jugarDeNuevo;

        } else if (eleccionUsuario == 2) {
            cout << "Saliendo del juego." << endl;
            break;
        } else {
            cout << "Opción no válida. Por favor, elige una opción del menú." << endl;
        }

    // Estructura repetitiva para continuar mostrando el menú hasta que el usuario elija salir
    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');

    return 0;
}
