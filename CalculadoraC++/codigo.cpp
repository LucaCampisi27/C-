#include <iostream>
#include <cmath> // Para funciones matematicas
#include <limits> // Para std::numeric_limits
#include <cstdlib> // Para system("cls")
#include <windows.h> // Para SetConsoleTextAttribute
#include <locale>
#include "membrete.h"
using namespace std;

// Prototipos de funciones
void membrete();
void sumar();
void restar();
void multiplicar();
void dividir();
void potencia();
void raiz();
void exponencial();
void logaritmo();
void valorAbsoluto();
void seno();
void coseno();
void tangente();
void establecerColor(int color);
template <typename T>
void obtenerEntrada(T &variable);
void alternarLocale();

// Funcion principal
int main() {
    int opcion;
    membrete();
    alternarLocale();
    while (true) {
        // Mostrar menu principal
        establecerColor(14); // Color amarillo
        cout << "\n--- Menu Principal ---" << endl;
        establecerColor(7); // Color blanco
        cout << "1. Funciones Basicas" << endl;
        cout << "2. Funciones Avanzadas" << endl;
        establecerColor(11); // Color cian
        cout << "3. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        system("cls"); // Limpiar la pantalla

        switch (opcion) {
            case 1: {
                // Menu de funciones basicas
                bool regresar = false;
                while (!regresar) {
                    establecerColor(14); // Color amarillo
                    cout << "\n--- Funciones Basicas ---" << endl;
                    establecerColor(7); // Color blanco
                    cout << "1. Suma" << endl;
                    cout << "2. Resta" << endl;
                    cout << "3. Multiplicacion" << endl;
                    cout << "4. Division" << endl;
                    establecerColor(11); // Color cian
                    cout << "5. Volver al menu principal" << endl;
                    establecerColor(2); // Color verde
                    cout << "Selecciona una opcion: ";
                    cin >> opcion;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
                    system("cls");

                    switch (opcion) {
                        case 1:
                            establecerColor(1); // Color rojo
                            membrete();
                            sumar();
                            break;
                        case 2:
                            establecerColor(5); // Color magenta
                            membrete();
                            restar();
                            break;
                        case 3:
                            establecerColor(8); // Color gris
                            membrete();
                            multiplicar();
                            break;
                        case 4:
                            establecerColor(10); // Color verde
                            membrete();
                            dividir();
                            break;
                        case 5:
                            regresar = true; // Volver al menu principal
                            break;
                        default:
                            establecerColor(12); // Color rojo
                            cout << "Opcion no valida, por favor intenta de nuevo." << endl;
                    }
                }
                break;
            }
            case 2: {
                // Menu de funciones avanzadas
                bool regresar = false;
                while (!regresar) {
                    establecerColor(14); // Color amarillo
                    cout << "\n--- Funciones Avanzadas ---" << endl;
                    establecerColor(7); // Color blanco
                    cout << "1. Potenciacion" << endl;
                    cout << "2. Raiz cuadrada" << endl;
                    cout << "3. Exponencial" << endl;
                    cout << "4. Logaritmo" << endl;
                    cout << "5. Valor absoluto" << endl;
                    cout << "6. Seno" << endl;
                    cout << "7. Coseno" << endl;
                    cout << "8. Tangente" << endl;
                    establecerColor(11); // Color cian
                    cout << "9. Volver al menu principal" << endl;
                    cout << "Selecciona una opcion: ";
                    cin >> opcion;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
                    system("cls");

                    switch (opcion) {
                        case 1:
                            establecerColor(1); // Color rojo
                            membrete();
                            potencia();
                            break;
                        case 2:
                            establecerColor(5); // Color magenta
                            membrete();
                            raiz();
                            break;
                        case 3:
                            establecerColor(8); // Color gris
                            membrete();
                            exponencial();
                            break;
                        case 4:
                            establecerColor(10); // Color verde
                            membrete();
                            logaritmo();
                            break;
                        case 5:
                            establecerColor(13); // Color purpura
                            membrete();
                            valorAbsoluto();
                            break;
                        case 6:
                            establecerColor(6); // Color amarillo oscuro
                            membrete();
                            seno();
                            break;
                        case 7:
                            establecerColor(9); // Color azul
                            membrete();
                            coseno();
                            break;
                        case 8:
                            establecerColor(11); // Color cian
                            membrete();
                            tangente();
                            break;
                        case 9:
                            regresar = true; // Volver al menu principal
                            break;
                        default:
                            establecerColor(12); // Color rojo
                            cout << "Opcion no valida, por favor intenta de nuevo." << endl;
                    }
                }
                break;
            }
            case 3:
                return 0; // Salir del programa
            default:
                establecerColor(12); // Color rojo
                cout << "Opcion no valida, por favor intenta de nuevo." << endl;
        }
    }

    return 0;
}

// Funcion para establecer el color del texto en la consola
void establecerColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Funcion para alternar entre el caracter ingles (predeterminado) y el español
void alternarLocale() {
    // Obtener la configuracion regional actual
    const char* localeActual = setlocale(LC_CTYPE, NULL);

    // Verificar la configuracion regional actual y alternar
    if (localeActual && strcmp(localeActual, "Spanish_Spain.1252") == 0) {
        setlocale(LC_CTYPE, "C");
    } else {
        setlocale(LC_CTYPE, "Spanish_Spain.1252");
    }
}

// Funcion para obtener una entrada valida del usuario
template <typename T>
void obtenerEntrada(T &variable) {
    while (true) {
        cin >> variable;
        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
            cout << "Entrada no valida. Por favor, ingrese un valor numerico: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
            break;
        }
    }
}

// Funciones basicas
void sumar() {
    double n1, n2;
    cout << "Ingrese el primer numero: ";
    obtenerEntrada(n1);
    cout << "Ingrese el segundo numero: ";
    obtenerEntrada(n2);
    cout << "El resultado de la suma es: " << (n1 + n2) << endl;
}

void restar() {
    double n1, n2;
    cout << "Ingrese el primer numero: ";
    obtenerEntrada(n1);
    cout << "Ingrese el segundo numero: ";
    obtenerEntrada(n2);
    cout << "El resultado de la resta es: " << (n1 - n2) << endl;
}

void multiplicar() {
    double n1, n2;
    cout << "Ingrese el primer numero: ";
    obtenerEntrada(n1);
    cout << "Ingrese el segundo numero: ";
    obtenerEntrada(n2);
    cout << "El resultado de la multiplicacion es: " << (n1 * n2) << endl;
}

void dividir() {
    double n1, n2;
    cout << "Ingrese el primer numero: ";
    obtenerEntrada(n1);
    cout << "Ingrese el segundo numero: ";
    obtenerEntrada(n2);
    if (n2 != 0) {
        cout << "El resultado de la division es: " << (n1 / n2) << endl;
    } else {
        cout << "Error: Division por cero no permitida." << endl;
    }
}

// Funciones avanzadas
void potencia() {
    double base, exponente;
    cout << "Ingrese la base: ";
    obtenerEntrada(base);
    cout << "Ingrese el exponente: ";
    obtenerEntrada(exponente);
    cout << "El resultado de la potenciacion es: " << pow(base, exponente) << endl;
}

void raiz() {
    double valor;
    cout << "Ingrese el valor: ";
    obtenerEntrada(valor);
    if (valor >= 0) {
        cout << "La raiz cuadrada es: " << sqrt(valor) << endl;
    } else {
        cout << "Error: No se puede calcular la raiz cuadrada de un numero negativo." << endl;
    }
}

void exponencial() {
    double valor;
    cout << "Ingrese el valor: ";
    obtenerEntrada(valor);
    cout << "El resultado de la exponencial es: " << exp(valor) << endl;
}

void logaritmo() {
    double valor;
    cout << "Ingrese el valor: ";
    obtenerEntrada(valor);
    if (valor > 0) {
        cout << "El logaritmo natural es: " << log(valor) << endl;
    } else {
        cout << "Error: No se puede calcular el logaritmo de un numero no positivo." << endl;
    }
}

void valorAbsoluto() {
    double valor;
    cout << "Ingrese el valor: ";
    obtenerEntrada(valor);
    cout << "El valor absoluto es: " << fabs(valor) << endl;
}

void seno() {
    double angulo;
    cout << "Ingrese el angulo en radianes: ";
    obtenerEntrada(angulo);
    cout << "El seno del angulo es: " << sin(angulo) << endl;
}

void coseno() {
    double angulo;
    cout << "Ingrese el angulo en radianes: ";
    obtenerEntrada(angulo);
    cout << "El coseno del angulo es: " << cos(angulo) << endl;
}
void tangente() {
    double angulo;
    cout << "Ingrese el angulo en radianes: ";
    obtenerEntrada(angulo);
    cout << "La tangente del angulo es: " << tan(angulo) << endl;
}
