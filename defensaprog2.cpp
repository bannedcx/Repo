#include <iostream>
#include <fstream> 
#include <string> 
#include <algorithm> 

using namespace std;

string toLowerCase(const string &str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

int main() {
    char option;  

    do {
        // se reinician las variables en cada iteracion
        string word;
        int totalEncontradas = 0;
        bool encontrada = false;

        cout << "Ingrese la palabra a buscar: ";
        cin >> word;
        word = toLowerCase(word);

        ifstream archivo("Archivo.txt.txt");  // se abre el archivo en cada iteracionn
        if (!archivo) {
            cout << "Error al abrir el archivo." << endl;
            return 1;
        }

        cout << "Contenido del archivo:\n";

        string linea;
        while (getline(archivo, linea)) {
            string lowerLinea = toLowerCase(linea);
            size_t pos = lowerLinea.find(word);
            size_t lastPos = 0;
            bool found = false;

            //se imprime la linea resaltando solo la palabra o letra buscada
            while (pos != string::npos) {
                found = true;
                totalEncontradas++;

                // imprime la parte antes de la coincidencia
                cout << linea.substr(lastPos, pos - lastPos);

                // imprime lo buscado en amarillo
                cout << "\033[33m" << linea.substr(pos, word.length()) << "\033[0m";

                // mueve la posicion despues de encontrar una palabra o letra
                lastPos = pos + word.length();
                pos = lowerLinea.find(word, lastPos);
            }

            // imprime el resto de la linea
            cout << linea.substr(lastPos) << endl;

            if (found) {
                encontrada = true;
            }
        }

        archivo.close();  // se cierra el archivo despues de la busqueda

        if (!encontrada) {
            cout << "La palabra no se encuentra en el archivo." << endl;
        } else {
            cout << "total de coincidencisd encontradas para '" << word << "': " << totalEncontradas << endl;
        }

        cout << "¿deseas buscar mas palabras? (S/N): ";
        cin >> option;

    } while (option == 'S' || option == 's');
	
	cout<< "Vuelve cuando el barcelona gane la sexta" << endl;     
    return 0;
}
