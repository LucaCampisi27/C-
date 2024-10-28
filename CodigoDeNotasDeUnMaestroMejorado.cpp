#include <iostream>
#include <windows.h>  // Solo en Windows
#include <algorithm>
#include <string>
using namespace std;

// Función para realizar búsqueda binaria en el arreglo de calificaciones
int busquedaBinaria(int calificaciones[], int n, int valor) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (calificaciones[medio] == valor)
            return medio;

        if (calificaciones[medio] < valor)
            inicio = medio + 1;
        else
            fin = medio - 1;
    }
    return -1;
}

// Función para establecer el color del texto
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    // Cambiar a UTF-8 en Windows
    SetConsoleCP(65001);          // Entrada de consola en UTF-8
    SetConsoleOutputCP(65001);    // Salida de consola en UTF-8

    // Definir colores
    const int COLOR_DEFAULT = 7;    // Blanco en fondo negro
    const int COLOR_GREEN = 10;      // Verde
    const int COLOR_RED = 12;        // Rojo
    const int COLOR_BLUE = 9;        // Azul
    const int COLOR_YELLOW = 14;     // Amarillo

    // Membrete
    setColor(COLOR_BLUE);
    cout << "============================================" << endl;
    cout << "            Sistema de Gestión de Notas       " << endl;
    cout << "                Instituto Educativo            " << endl;
    cout << "============================================" << endl;
    setColor(COLOR_DEFAULT);

    int n, calificacionABuscar, umbral;
    cout << "Ingrese el número de estudiantes: ";
    cin >> n;

    string nombres[n];         // Arreglo para los nombres de los estudiantes
    int calificaciones[n];      // Arreglo para las calificaciones

    // Registrar los nombres y las calificaciones
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin.ignore();  // Limpiar el buffer de entrada
        getline(cin, nombres[i]);
        cout << "Ingrese la calificación de " << nombres[i] << ": ";
        cin >> calificaciones[i];
    }

    // Ordenar ambos arreglos en base a las calificaciones usando sort y swap
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (calificaciones[i] > calificaciones[j]) {
                swap(calificaciones[i], calificaciones[j]);
                swap(nombres[i], nombres[j]);  // También intercambiamos los nombres
            }
        }
    }

    // Mostrar la lista ordenada de estudiantes
    setColor(COLOR_YELLOW);
    cout << "\nLista de estudiantes ordenada por calificación: \n";
    setColor(COLOR_DEFAULT);
    for (int i = 0; i < n; i++) {
        cout << nombres[i] << ": " << calificaciones[i] << endl;
    }

    // Buscar una calificación específica
    cout << "\nIngrese la calificación que desea buscar: ";
    cin >> calificacionABuscar;
    int resultado = busquedaBinaria(calificaciones, n, calificacionABuscar);

    if (resultado != -1) {
        setColor(COLOR_GREEN);
        cout << "El estudiante " << nombres[resultado] << " obtuvo una calificación de " << calificacionABuscar << endl;
    } else {
        setColor(COLOR_YELLOW);
        cout << "No se encontró ningún estudiante con esa calificación.\n";
    }
    setColor(COLOR_DEFAULT);

    // Calcular el promedio de la clase (entero)
    int sumaCalificaciones = 0;
    for (int i = 0; i < n; i++) {
        sumaCalificaciones += calificaciones[i];
    }
    double promedio = static_cast<double>(sumaCalificaciones) / n;
    cout << "El promedio de la clase es: " << promedio << endl;

    // Mostrar la calificación más alta y más baja
    cout << "La calificación más alta es: " << calificaciones[n - 1] << endl;
    cout << "La calificación más baja es: " << calificaciones[0] << endl;

    // Calcular el rango de calificaciones
    int rango = calificaciones[n - 1] - calificaciones[0];
    cout << "El rango de las calificaciones es: " << rango << endl;

    // Identificar estudiantes por debajo de un umbral
    cout << "\nIngrese el umbral de calificación para identificar a los estudiantes que necesitan mejorar: ";
    cin >> umbral;
    cout << "Estudiantes con calificaciones por debajo de " << umbral << ":\n";
    setColor(COLOR_RED);
    for (int i = 0; i < n; i++) {
        if (calificaciones[i] < umbral) {
            cout << nombres[i] << " con calificación de " << calificaciones[i] << endl;
        }
    }
    setColor(COLOR_DEFAULT);

    // Identificar estudiantes que aprobaron
    cout << "\nEstudiantes que aprobaron (calificaciones iguales o superiores al umbral):\n";
    setColor(COLOR_GREEN);
    for (int i = 0; i < n; i++) {
        if (calificaciones[i] >= umbral) {
            cout << nombres[i] << " con calificación de " << calificaciones[i] << endl;
        }
    }
    setColor(COLOR_DEFAULT);

    // Mensaje si el promedio es menor a 6
    if (promedio < 6.0) {
        setColor(COLOR_RED);
        cout << "\nEl promedio de la clase es menor a 6. Los estudiantes deberían esforzarse un poco más.\n";
        setColor(COLOR_DEFAULT);
    }

    return 0;
}
