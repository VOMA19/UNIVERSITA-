#include <iostream>
using namespace std;

struct NodoHuffman {
    char carattere;
    NodoHuffman* sinistro;
    NodoHuffman* destro;
};

// Funzione di supporto che decodifica i bit a partire da un certo nodo
void DecodificaCarattere(NodoHuffman* nodo, const char* codice, int& indice, char* parolaRisultato, int& pos) {
    if (!nodo) return; // sicurezza
    if (pos >= 99) return; // sicurezza

    // Se siamo in una foglia → carattere trovato
    if (!nodo->sinistro && !nodo->destro) {
        parolaRisultato[pos++] = nodo->carattere;
        return;
    }
    
    // Leggo il bit corrente e avanzo
    char bit = codice[indice++];
    if (bit == '0')
        DecodificaCarattere(nodo->sinistro, codice, indice, parolaRisultato, pos);
    else if (bit == '1')
        DecodificaCarattere(nodo->destro, codice, indice, parolaRisultato, pos);

}


// Funzione principale: decodifica l'intera parola
void DecodificaParola(NodoHuffman* radice, const char* codiceBinario, char* parolaRisultato) {
    int indice = 0; // posizione nella stringa di bit
    int pos = 0;    // posizione nella parola decodificata

    while (codiceBinario[indice] != '\0') {
        DecodificaCarattere(radice, codiceBinario, indice, parolaRisultato, pos);
    }

    // Chiudo la stringa risultante
    parolaRisultato[pos] = '\0';
}

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
