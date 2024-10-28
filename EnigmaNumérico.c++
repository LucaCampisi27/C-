#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

void jugarAdivinanza(int maxIntentos, int rangoMax);
void mostrarInstrucciones();
void mostrarCreditos();
void establecerColor(int color);
void nivelDificultad();
void mostrarBarraProgreso(int intentos, int maxIntentos);

int main() {
    srand(time(0)); // Inicialización del generador de números aleatorios
    int opcion;

    while (true) {
        // Mostrar menú
        establecerColor(14); // Color amarillo
        cout << "\n--- Menú Principal ---" << endl;
        establecerColor(7); // Color blanco
        cout << "1. Jugar" << endl;
        cout << "2. Instrucciones" << endl;
        cout << "3. Créditos" << endl;
        cout << "4. Salir" << endl;
        establecerColor(11); // Color cian
        cout << "Selecciona una opción: ";
        cin >> opcion;

        // Procesar la opción seleccionada
        switch (opcion) {
            case 1:
                nivelDificultad();
                break;
            case 2:
                mostrarInstrucciones();
                break;
            case 3:
                mostrarCreditos();
                break;
            case 4:
                establecerColor(10); // Color verde
                cout << "¡Gracias por jugar! Hasta luego." << endl;
                return 0;
            default:
                establecerColor(12); // Color rojo
                cout << "Opción no válida, por favor intenta de nuevo." << endl;
        }
    }

    return 0;
}

void jugarAdivinanza(int maxIntentos, int rangoMax) {
    int numeroAleatorio = rand() % rangoMax + 1; // Genera un número aleatorio
    int intentos = 0;
    int intentoUsuario;

    // Mensaje de bienvenida
    establecerColor(13); // Color magenta
    cout << "\n--- Juego de Adivinanza ---" << endl;
    cout << "He pensado en un número entre 1 y " << rangoMax << ". ¡Intenta adivinar cuál es!" << endl;

    // Bucle para que el usuario adivine el número
    while (intentos < maxIntentos) {
        // Solicitar al usuario que ingrese un número
        establecerColor(11); // Color cian
        cout << "Introduce un número: ";
        cin >> intentoUsuario;
        intentos++;

        // Comprobar si el número ingresado es correcto, mayor o menor
        if (intentoUsuario == numeroAleatorio) {
            establecerColor(10); // Color verde
            cout << "¡Felicitaciones! Has adivinado el número en " << intentos << " intentos." << endl;
            break; // Terminar el juego
        } else if (intentoUsuario < numeroAleatorio) {
            establecerColor(14); // Color amarillo
            cout << "El número que buscas es mayor. ¡Sigue intentando!" << endl;
        } else {
            establecerColor(14); // Color amarillo
            cout << "El número que buscas es menor. ¡Sigue intentando!" << endl;
        }

        mostrarBarraProgreso(intentos, maxIntentos);

        if (intentos == maxIntentos) {
            establecerColor(12); // Color rojo
            cout << "¡Lo siento! Has alcanzado el máximo de intentos. El número era " << numeroAleatorio << "." << endl;
        }
    }
}

void mostrarInstrucciones() {
    establecerColor(13); // Color magenta
    cout << "\n--- Instrucciones ---" << endl;
    establecerColor(14); // Color blanco
    cout << "1. Selecciona la opción 'Jugar' en el menú principal." << endl;
    cout << "2. Elige un nivel de dificultad." << endl;
    cout << "3. Se generará un número aleatorio en el rango seleccionado." << endl;
    cout << "4. Intenta adivinar el número ingresando un número y presionando Enter." << endl;
    cout << "5. Recibirás pistas para saber si el número es mayor o menor al que ingresaste." << endl;
    cout << "6. El juego termina cuando adivinas el número o alcanzas el límite de intentos." << endl;
}

void mostrarCreditos() {
    establecerColor(13); // Color magenta
    cout << "\n--- Créditos ---" << endl;
    establecerColor(7); // Color blanco
    cout << "Juego desarrollado por [Campisi Luca Giovanni]." << endl;
    cout << "Gracias por jugar. ¡Diviértete!" << endl;
}

void establecerColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void nivelDificultad() {
    int opcion;
    establecerColor(14); // Color amarillo
    cout << "\n--- Selección de Dificultad ---" << endl;
    establecerColor(7); // Color blanco
    cout << "1. Fácil (1-50, 10 intentos)" << endl;
    cout << "2. Medio (1-100, 7 intentos)" << endl;
    cout << "3. Difícil (1-200, 5 intentos)" << endl;
    establecerColor(11); // Color cian
    cout << "Selecciona una opción: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            jugarAdivinanza(10, 50);
            break;
        case 2:
            jugarAdivinanza(7, 100);
            break;
        case 3:
            jugarAdivinanza(5, 200);
            break;
        default:
            establecerColor(12); // Color rojo
            cout << "Opción no válida, regresando al menú principal." << endl;
    }
}

void mostrarBarraProgreso(int intentos, int maxIntentos) {
    establecerColor(7); // Color blanco
    cout << "Intentos: [";
    for (int i = 0; i < maxIntentos; i++) {
        if (i < intentos) {
            establecerColor(12); // Color rojo
            cout << "#";
        } else {
            establecerColor(8); // Color gris
            cout << "-";
        }
    }
    establecerColor(7); // Color blanco
    cout << "] " << intentos << "/" << maxIntentos << " intentos" << endl;
}
/*Los colores en Windows se pueden especificar con los siguientes códigos:
0 = Negro
1 = Azul
2 = Verde
3 = Aqua
4 = Rojo
5 = Púrpura
6 = Amarillo
7 = Blanco
8 = Gris
9 = Azul claro
10 = Verde claro
11 = Aqua claro
12 = Rojo claro
13 = Púrpura claro
14 = Amarillo claro
15 = Blanco brillante 

chcp 65001 Permite el uso de tildes , ñ y caracteres especiales en consola

*/