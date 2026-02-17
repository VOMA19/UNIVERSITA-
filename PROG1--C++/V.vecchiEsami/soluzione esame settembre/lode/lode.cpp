#include <iostream>
using namespace std;

struct NodoHuffman {
    char carattere;
    NodoHuffman* sinistro;
    NodoHuffman* destro;
};

// Inserire qui sotto dichiarazione e definizione della funzione di DecodificaParola


// Inserire qui sopra dichiarazione e definizione della funzione di DecodificaParola

int main() {
    // Costruzione manuale dell'albero di esempio:
    //     (*)
    //    /   \
    //  'a'   (*)
    //       /   \
    //     'b'   'c'
    //
    // Codici:
    // 'a' → "0"
    // 'b' → "10"
    // 'c' → "11"

    NodoHuffman nodoA = {'a', nullptr, nullptr};
    NodoHuffman nodoB = {'b', nullptr, nullptr};
    NodoHuffman nodoC = {'c', nullptr, nullptr};

    NodoHuffman nodoInterno = {'*', &nodoB, &nodoC};  
    NodoHuffman radice = {'*', &nodoA, &nodoInterno}; 

    const char* codice = "01011";  // Testo codificato
    char parola[100];              // Array per la parola decodificata

    DecodificaParola(&radice, codice, parola);

    cout << "Codice Huffman: " << codice << endl;
    cout << "Parola decodificata: " << parola << endl;

    return 0;
}
