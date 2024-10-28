#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0)); // Inicializar el generador de números aleatorios

    const int cantidadNumeros = 10; // Número de números aleatorios que deseas generar
    vector<int> numerosPosibles;

    // Llenar el vector con números del 1 al 100
    for (int i = 1; i <= 100; ++i) {
        numerosPosibles.push_back(i);
    }

    // Barajar el vector para obtener una secuencia aleatoria
    random_shuffle(numerosPosibles.begin(), numerosPosibles.end());

    // Mostrar los primeros 'cantidadNumeros' números aleatorios
    for (int i = 0; i < cantidadNumeros; ++i) {
        cout << "Número generado: " << numerosPosibles[i] << endl;
    }

    return 0;
}
