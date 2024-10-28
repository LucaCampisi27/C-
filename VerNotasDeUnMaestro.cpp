#include <iostream>

using namespace std;

int busquedaBinaria(int arreglo[], int izquierda, int derecha, int valorBuscado) {
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arreglo[medio] == valorBuscado)
            return medio;

        if (arreglo[medio] < valorBuscado)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }

    return -1; // Valor no encontrado
}

int main() {
    int n;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    int arreglo[n];
    cout << "Ingrese los elementos del arreglo en orden ascendente: ";
    for (int i = 0; i < n; i++) {
        cin >> arreglo[i];
    }

    cout << "Tamaño del arreglo en bytes: " << sizeof(arreglo) << endl;

    int valorBuscado;
    cout << "Ingrese el valor a buscar: ";
    cin >> valorBuscado;

    int resultado = busquedaBinaria(arreglo, 0, n - 1, valorBuscado);

    if (resultado != -1) {
        cout << "El valor " << valorBuscado << " se encuentra en el índice " << resultado << endl;
    } else {
        cout << "El valor " << valorBuscado << " no se encuentra en el arreglo" << endl;
    }

    return 0;
}