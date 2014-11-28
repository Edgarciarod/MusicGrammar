#include <iostream>
#include "Generador.h"
#include "Musico.h"

using std::cout;
using std::endl;
using std::cin;

int main() {
    Generador compositor("/home/edgar/Documentos/MusicGrammar/gramatica.in");

    cout << "Ingrese la profundidad máxima deseada: " << endl;
    int complejidad;
    cin >> complejidad ;
    string partitura = compositor.genera(complejidad);

    cout << partitura << endl;

    Musico musico(partitura);
    musico.toca();

    return 0;
}