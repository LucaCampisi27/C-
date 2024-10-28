#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Estudiante {
    string nombre;
    vector<int> calificaciones;
};

void guardarCalificaciones(const string& archivo, const vector<Estudiante>& estudiantes) {
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
    cout << "Datos guardados exitosamente." << endl;
}

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

void mostrarCalificaciones(const vector<Estudiante>& estudiantes) {
    for (const auto& estudiante : estudiantes) {
        cout << "Estudiante: " << estudiante.nombre << " - Calificaciones: ";
        for (int cal : estudiante.calificaciones) {
            cout << cal << " ";
        }
        cout << endl;
    }
}

int main() {
    string archivo = "calificaciones.txt";
    vector<Estudiante> estudiantes;
    int opcion;
    do {
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
                break;
            }
            case 2:
                estudiantes = leerCalificaciones(archivo);
                mostrarCalificaciones(estudiantes);
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
    } while (opcion != 4);

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Estudiante {
    string nombre;
    vector<int> calificaciones;
};

void guardarCalificaciones(const string& archivo, const vector<Estudiante>& estudiantes) {
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
    cout << "Datos guardados exitosamente." << endl;
}

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

void mostrarCalificaciones(const vector<Estudiante>& estudiantes) {
    for (const auto& estudiante : estudiantes) {
        cout << "Estudiante: " << estudiante.nombre << " - Calificaciones: ";
        for (int cal : estudiante.calificaciones) {
            cout << cal << " ";
        }
        cout << endl;
    }
}

int main() {
    string archivo = "calificaciones.txt";
    vector<Estudiante> estudiantes;
    int opcion;
    do {
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
                break;
            }
            case 2:
                estudiantes = leerCalificaciones(archivo);
                mostrarCalificaciones(estudiantes);
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
    } while (opcion != 4);

    return 0;
}
