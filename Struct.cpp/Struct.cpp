#include <iostream>
#include <string>
#include <limits>
#include <windows.h>
#include <vector>
using namespace std;

struct info_direccion {
    string direccion;
    string ciudad;
    string provincia;
};

struct Empleado {
    string nombre;
    info_direccion dir_empleado;
    double salario;
};

struct Corredor {
    string nombre;
    int edad;
    string sexo;
    string club;
} C1;

struct promedio {
    float nota1;
    float nota2;
    float nota3;
};

struct alumno {
    string nombre;
    string sexo;
    int edad;
    promedio prom;
} alumno;

// Función para cambiar el color del texto
void establecerColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Función para imprimir el membrete del menú principal
void imprimirMembretePrincipal() {
    establecerColor(11); // Color azul claro
    cout << "-------------------------------------------\n";
    cout << "       Menú de Ejercicios con Estructuras  \n";
    cout << "-------------------------------------------\n";
    establecerColor(15); // Color blanco
}

// Función para imprimir el membrete específico para el ejercicio 1
void imprimirMembreteEmpleados() {
    establecerColor(10); // Color verde claro
    cout << "-------------------------------------------\n";
    cout << "   Empleados con Mayor y Menor Salario     \n";
    cout << "-------------------------------------------\n";
    establecerColor(15); // Color blanco
}

// Función para imprimir el membrete específico para el ejercicio 2
void imprimirMembreteCorredor() {
    establecerColor(14); // Color amarillo
    cout << "-------------------------------------------\n";
    cout << "           Datos de Corredores             \n";
    cout << "-------------------------------------------\n";
    establecerColor(15); // Color blanco
}

// Función para imprimir el membrete específico para el ejercicio 3
void imprimirMembreteAlumno() {
    establecerColor(13); // Color púrpura
    cout << "-------------------------------------------\n";
    cout << "        Calcular Promedio de Alumnos       \n";
    cout << "-------------------------------------------\n";
    establecerColor(15); // Color blanco
}

// Declaración de las funciones de los ejercicios
void ejercicio1();
void ejercicio2();
void ejercicio3();

int main() {
    SetConsoleCP(65001);          // Entrada de consola en UTF-8
    SetConsoleOutputCP(65001);    // Salida de consola en UTF-8
    int opcion;

    do {
        system("cls"); // Limpiar pantalla
        imprimirMembretePrincipal(); // Membrete principal

        cout << "1. Ingresar y mostrar datos de Empleados\n";
        cout << "2. Datos de un corredor\n";
        cout << "3. Calcular el promedio de un alumno\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer

        switch(opcion) {
            case 1:
                system("cls");
                imprimirMembreteEmpleados(); // Membrete específico
                ejercicio1();
                break;
            case 2:
                system("cls");
                imprimirMembreteCorredor(); // Membrete específico
                ejercicio2();
                break;
            case 3:
                system("cls");
                imprimirMembreteAlumno(); // Membrete específico
                ejercicio3();
                break;
            case 4:
            establecerColor(3);
                cout << "Saliendo del programa...\n";
                break;
            default:
            establecerColor(12);
                cout << "Opción no válida. Intente de nuevo.\n";
        }

        if(opcion != 4) {
            cout << "\nPresione Enter para volver al menú principal...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer
            cin.get(); // Esperar a que el usuario presione Enter
        }

    } while(opcion != 4);

    return 0;
}

// Ejercicio 1: Datos de empleados
void ejercicio1() {
    int n, posMayor = 0, posMenor = 0;
    float mayor = 0, menor = 9999999;
    cout << "Ingrese el número de empleados: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer
    vector<Empleado> Empleados(n);
    for (int i = 0; i < n; i++) {
        cout << "Ingrese los datos del Empleado " << i + 1 << ":\n";
        cout << "Nombre: ";
        getline(cin, Empleados[i].nombre);
        cout << "Dirección: ";
        getline(cin, Empleados[i].dir_empleado.direccion);
        cout << "Ciudad: ";
        getline(cin, Empleados[i].dir_empleado.ciudad);
        cout << "Provincia: ";
        getline(cin, Empleados[i].dir_empleado.provincia);
        cout << "Salario: ";
        cin >> Empleados[i].salario;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer

        if (Empleados[i].salario > mayor) {
            mayor = Empleados[i].salario;
            posMayor = i;
        }
        if (Empleados[i].salario < menor) {
            menor = Empleados[i].salario;
            posMenor = i;
        }

        cout << "------------------------------------------" << endl;
    }

    cout << "Empleado con mayor salario:\n";
    cout << "Nombre: " << Empleados[posMayor].nombre << endl;
    cout << "Dirección: " << Empleados[posMayor].dir_empleado.direccion << endl;
    cout << "Ciudad: " << Empleados[posMayor].dir_empleado.ciudad << endl;
    cout << "Provincia: " << Empleados[posMayor].dir_empleado.provincia << endl;
    cout << "Salario: " << Empleados[posMayor].salario << endl;
    cout << "------------------------------------------" << endl;

    cout << "Empleado con menor salario:\n";
    cout << "Nombre: " << Empleados[posMenor].nombre << endl;
    cout << "Dirección: " << Empleados[posMenor].dir_empleado.direccion << endl;
    cout << "Ciudad: " << Empleados[posMenor].dir_empleado.ciudad << endl;
    cout << "Provincia: " << Empleados[posMenor].dir_empleado.provincia << endl;
    cout << "Salario: " << Empleados[posMenor].salario << endl;
    cout << "------------------------------------------" << endl;
}

// Ejercicio 2: Datos de un corredor
void ejercicio2() {
    char categoria[20];
    cin.ignore();
    cout << "Ingrese el nombre del corredor: ";
    getline(cin, C1.nombre);
    cout << "Ingrese la edad del corredor: ";
    cin >> C1.edad;
    cin.ignore();
    cout << "Ingrese el sexo del corredor: ";
    getline(cin, C1.sexo);
    cout << "Club: ";
    getline(cin, C1.club);
    if (C1.edad <= 18) {
        strcpy(categoria, "Juvenil");
    } else if (C1.edad <= 40) {
        strcpy(categoria, "Senior");
    } else {
        strcpy(categoria, "Veterano");
    }
    cout << "------------------------------------------Datos del Corredor------------------------------------------\n";
    cout << "Nombre: " << C1.nombre << endl;
    cout << "Edad: " << C1.edad << endl;
    cout << "Categoría: " << categoria << endl;
    cout << "Sexo: " << C1.sexo << endl;
    cout << "Club: " << C1.club << endl;
}

// Ejercicio 3: Calcular promedio de un alumno
void ejercicio3() {
    float promedio_alumno;
    cin.ignore();
    cout << "Digite el nombre del alumno: ";
    getline(cin, alumno.nombre);
    cout << "Digite la edad del alumno: ";
    cin >> alumno.edad;
    cin.ignore();
    cout << "Digite el sexo del alumno: ";
    getline(cin, alumno.sexo);
    cout << "\n---------------------NOTAS------------------\n";
    cout << "Ingrese la primera nota: ";
    cin >> alumno.prom.nota1;
    cout << "Ingrese la segunda nota: ";
    cin >> alumno.prom.nota2;
    cout << "Ingrese la tercera nota: ";
    cin >> alumno.prom.nota3;
    cin.ignore(); // Limpiar buffer después de ingresar las notas
    promedio_alumno = (alumno.prom.nota1 + alumno.prom.nota2 + alumno.prom.nota3) / 3;
    cout << "\n----------------DATOS DEL ALUMNO---------------------\n";
    cout << "Nombre: " << alumno.nombre << endl;
    cout << "Edad: " << alumno.edad << endl;
    cout << "Sexo: " << alumno.sexo << endl;
    cout << "Promedio Final: " << promedio_alumno << endl;
}
