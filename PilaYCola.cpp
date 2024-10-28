#include <iostream>
#include <windows.h>
#include <string>  // Para usar std::string
using namespace std;

// Función para establecer el color del texto en la consola
void establecerColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Función para mostrar el membrete
void mostrarMembrete() {
    establecerColor(11);  // Color cyan claro
    cout << "*********************************************" << endl;
    cout << "*        GESTIÓN DE ENVÍOS Y DEVOLUCIONES    *" << endl;
    cout << "*              Empresa de Logística          *" << endl;
    cout << "*           Autor: LUCA CAMPISI              *" << endl;
    cout << "*********************************************" << endl;
    establecerColor(7);  // Restaurar color por defecto (blanco)
}

const int MAX = 100;  // Tamaño máximo de la cola y la pila

// Funciones para manejar la cola (FIFO)
void encolar(string cola[], int &fin, string paquete) {
    if (fin < MAX) {
        cola[fin] = paquete;
        fin++;
    } else {
        establecerColor(12);  // Color rojo para error
        cout << "Cola llena, no se pueden agregar más paquetes." << endl;
        establecerColor(7);  // Restaurar color
    }
}

void desencolar(string cola[], int &inicio, int fin) {
    if (inicio < fin) {
        inicio++;
    }
}

string frente(string cola[], int inicio) {
    return cola[inicio];
}

// Funciones para manejar la pila (LIFO)
void apilar(string pila[], int &tope, string paquete) {
    if (tope < MAX) {
        pila[tope] = paquete;
        tope++;
    }
}

void desapilar(int &tope) {
    if (tope > 0) {
        tope--;
    }
}

string obtenerTope(string pila[], int tope) {
    return pila[tope - 1];
}

// Función para enviar un paquete desde la pila de devoluciones
void enviarPaqueteFallido(string pila[], int &tope, string cola[], int &finCola) {
    if (tope > 0) {
        string paqueteFallido = obtenerTope(pila, tope);
        establecerColor(10);  // Color verde para el envío
        cout << "Reintentando el envío de " << paqueteFallido << "..." << endl;

        // Simulación de fallos en el envío
        if (paqueteFallido == "Paquete 2" || paqueteFallido == "Paquete 3") {
            establecerColor(12);  // Color rojo para fallos
            cout << "Fallo en el envío de " << paqueteFallido << ". Guardando en la pila de devoluciones." << endl;
            // Volver a apilar el paquete fallido
            apilar(pila, tope, paqueteFallido);
        } else {
            establecerColor(10);  // Color verde para éxito
            cout << "Envío exitoso de " << paqueteFallido << "." << endl;
        }

        desapilar(tope);  // Eliminar de la pila
    } else {
        establecerColor(12);  // Color rojo para error
        cout << "No hay paquetes fallidos en la pila." << endl;
        establecerColor(7);  // Restaurar color
    }
}

int main() {
      SetConsoleCP(65001);          // Entrada de consola en UTF-8
    SetConsoleOutputCP(65001);    // Salida de consola en UTF-8
    string colaEnvios[MAX];       // Cola para envíos
    string pilaDevoluciones[MAX]; // Pila para devoluciones
    int inicioCola = 0, finCola = 0; // Índices para la cola
    int topePila = 0;             // Índice para la pila

    // Mostrar el membrete
    mostrarMembrete();

    int opcion;
    do {
        establecerColor(14);  // Color amarillo para el menú
        cout << "\n--- MENÚ ---\n";
        cout << "1. Agregar paquete a la cola de envíos\n";
        cout << "2. Enviar paquetes (con posibilidad de fallo)\n";
        cout << "3. Reintentar el envío de paquetes fallidos\n";
        cout << "4. Enviar paquete fallido desde la pila\n";
        cout << "5. Mostrar estado de cola y pila\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        establecerColor(7);  // Restaurar color

        if (opcion == 1) {
            string paquete;
            cout << "Ingrese el nombre del paquete: ";
            cin.ignore();  // Ignorar el salto de línea restante
            getline(cin, paquete);  // Usar getline para permitir espacios
            encolar(colaEnvios, finCola, paquete);
            cout << "Paquete \"" << paquete << "\" agregado a la cola." << endl;
        }

        else if (opcion == 2) {
            if (inicioCola < finCola) {
                string paqueteActual = frente(colaEnvios, inicioCola);
                establecerColor(10);  // Color verde para el envío
                cout << "Enviando " << paqueteActual << "..." << endl;

                // Simulación de fallos en el envío
                if (paqueteActual == "Paquete 2" || paqueteActual == "Paquete 3") {
                    establecerColor(12);  // Color rojo para fallos
                    cout << "Fallo en el envío de " << paqueteActual << ". Guardando en la pila de devoluciones." << endl;
                    apilar(pilaDevoluciones, topePila, paqueteActual);  // Guardar en la pila
                } else {
                    establecerColor(10);  // Color verde para éxito
                    cout << "Envío exitoso de " << paqueteActual << "." << endl;
                }

                desencolar(colaEnvios, inicioCola, finCola);
            } else {
                establecerColor(12);  // Color rojo para error
                cout << "No hay paquetes en la cola para enviar." << endl;
                establecerColor(7);  // Restaurar color
            }
        }

        else if (opcion == 3) {
            while (topePila > 0) {
                string paqueteDevuelto = obtenerTope(pilaDevoluciones, topePila);
                establecerColor(13);  // Color morado para reintentos
                cout << "Reintentando el envío de " << paqueteDevuelto << "..." << endl;
                encolar(colaEnvios, finCola, paqueteDevuelto);  // Volver a encolar
                desapilar(topePila);  // Eliminar de la pila
            }
            establecerColor(10);  // Color verde para éxito
            cout << "Todos los paquetes devueltos han sido reintentados." << endl;
            establecerColor(7);  // Restaurar color
        }

        else if (opcion == 4) {
            enviarPaqueteFallido(pilaDevoluciones, topePila, colaEnvios, finCola);
        }

        else if (opcion == 5) {
            cout << "Paquetes en la cola de envíos: " << (finCola - inicioCola) << endl;
            cout << "Paquetes en la pila de devoluciones: " << topePila << endl;
        }

    } while (opcion != 6);  // Salir del menú

    establecerColor(11);  // Color cyan claro
    cout << "Gracias por usar el sistema de gestión de envíos y devoluciones." << endl;
    establecerColor(7);  // Restaurar color
    return 0;
}
