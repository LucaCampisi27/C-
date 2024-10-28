#include <iostream>
#include <locale>
using namespace std;

int main() {
    // Configurar la localización para manejar caracteres especiales
    setlocale(LC_ALL, "es_ES.UTF-8");  // Para sistemas en español de España
    // setlocale(LC_ALL, "es_MX.UTF-8");  // Para sistemas en español de México

    string nombre = "José Ñandú";

    cout << "Nombre con caracteres especiales: " << nombre << endl;

    return 0;
}
