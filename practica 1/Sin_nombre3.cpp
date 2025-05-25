#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    string buscar;
    string respuesta;

    do {
        ifstream archivo("archivo.txt");
        if (!archivo) {
            cout << "No se pudo abrir el archivo." << endl;
            return 1;
        }

        do {
            cout << "Ingrese la palabra o carácter a buscar: ";
            getline(cin, buscar);
        } while (buscar.empty());

        string linea;
        int total = 0;

        while (getline(archivo, linea)) {
            string lineaOriginal = linea;
            string lineaMin = toLower(linea);
            string buscarMin = toLower(buscar);

            size_t pos = 0;
            while ((pos = lineaMin.find(buscarMin, pos)) != string::npos) {
                total++;
                pos += buscarMin.length();
            }

            cout << lineaOriginal << endl;
        }

        cout << "\nTotal de coincidencias: " << total << endl;

        archivo.close();

        cout << "\n¿Desea buscar otra palabra? (S/N): ";
        getline(cin, respuesta);

    } while (respuesta == "S" || respuesta == "s");

    return 0;
}
