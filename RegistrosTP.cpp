#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib> // Para system
#include <windows.h>
#include <cstdio> // Para std::remove
using namespace std;

// Función para cambiar el color del texto
void establecerColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Estructura para almacenar datos del estudiante
struct Estudiante {
    string nombre;
    vector<int> calificaciones;
};

// Función para limpiar la pantalla
void limpiarPantalla() {
#ifdef _WIN32
    system("cls"); // Para Windows
#else
    system("clear"); // Para Linux/Mac
#endif
}

// Función para comprobar si el archivo existe
bool archivoExiste(const string& archivo) {
    ifstream f(archivo.c_str());
    return f.good();
}

// Función para guardar las calificaciones en un archivo
void guardarCalificaciones(const string& archivo, const vector<Estudiante>& estudiantes) {
    // Verifica si el archivo ya existe
    if (archivoExiste(archivo)) {
        establecerColor(12); // Color rojo
        cout << "El archivo ya existe. ¿Desea sobrescribirlo? (s/n): ";
        char respuesta;
        cin >> respuesta;
        if (respuesta != 's' && respuesta != 'S') {
            establecerColor(7); // Restablecer a blanco
            cout << "Guardado cancelado." << endl;
            return;
        }
    }

    ofstream archivoSalida(archivo, ios::out | ios::trunc);
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo para guardar los datos." << endl;
        return;
    }
    for (const auto& estudiante : estudiantes) {
        archivoSalida << estudiante.nombre;
        for (int cal : estudiante.calificaciones) {
            archivoSalida << " " << cal;
        }
        archivoSalida << endl;
    }
    archivoSalida.close();
    establecerColor(10); // Color verde
    cout << "Datos guardados exitosamente." << endl;
    establecerColor(7); // Restablecer a blanco
}

// Función para leer las calificaciones desde un archivo
vector<Estudiante> leerCalificaciones(const string& archivo) {
    vector<Estudiante> estudiantes;
    ifstream archivoEntrada(archivo);
    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir el archivo para leer los datos." << endl;
        return estudiantes;
    }
    string linea;
    while (getline(archivoEntrada, linea)) {
        istringstream iss(linea);
        Estudiante est;
        iss >> est.nombre;
        int calificacion;
        while (iss >> calificacion) {
            est.calificaciones.push_back(calificacion);
        }
        estudiantes.push_back(est);
    }
    archivoEntrada.close();
    return estudiantes;
}

// Función para mostrar las calificaciones de los estudiantes
void mostrarCalificaciones(const vector<Estudiante>& estudiantes) {
    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }
    for (const auto& estudiante : estudiantes) {
        cout << "Estudiante: " << estudiante.nombre << " - Calificaciones: ";
        for (int cal : estudiante.calificaciones) {
            cout << cal << " ";
        }
        cout << endl;
    }
}

// Función para mostrar el membrete
void mostrarMembrete() {
    establecerColor(14); // Color amarillo
    cout << "===============================" << endl;
    cout << "         REGISTRO DE NOTAS     " << endl;
    cout << "          LUCA CAMPISI         " << endl;
    cout << "===============================" << endl;
    establecerColor(7); // Restablecer a blanco
}

int main() {
    SetConsoleCP(65001);          // Entrada de consola en UTF-8
    SetConsoleOutputCP(65001);    // Salida de consola en UTF-8
    string archivo = "calificaciones.txt";  // Nombre del archivo
    vector<Estudiante> estudiantes;           // Vector para almacenar estudiantes
    int opcion;

    do {
        limpiarPantalla(); // Limpia la pantalla antes de mostrar el menú
        mostrarMembrete(); // Muestra el membrete
        cout << "Menú de Opciones:\n";
        cout << "1. Agregar Estudiante y Calificaciones\n";
        cout << "2. Mostrar Calificaciones\n";
        cout << "3. Guardar Calificaciones\n";
        cout << "4. Salir\n";
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Estudiante nuevoEstudiante;
                cout << "Ingrese el nombre del estudiante: ";
                cin >> nuevoEstudiante.nombre;
                int numCalificaciones, calificacion;
                cout << "Ingrese el número de calificaciones: ";
                cin >> numCalificaciones;
                for (int i = 0; i < numCalificaciones; ++i) {
                    cout << "Ingrese la calificación " << i + 1 << ": ";
                    cin >> calificacion;
                    nuevoEstudiante.calificaciones.push_back(calificacion);
                }
                estudiantes.push_back(nuevoEstudiante);
                cout << "Calificaciones ingresadas correctamente." << endl;
                mostrarCalificaciones(estudiantes); // Muestra las calificaciones inmediatamente
                break;
            }
            case 2:
                mostrarCalificaciones(estudiantes); // Muestra las calificaciones almacenadas en memoria
                break;
            case 3:
                guardarCalificaciones(archivo, estudiantes);
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
        cout << "\nPresione Enter para continuar..."; // Espera a que el usuario presione Enter
        cin.ignore(); // Ignora el newline pendiente
        cin.get(); // Espera a que el usuario presione Enter
    } while (opcion != 4);

    return 0;
}
