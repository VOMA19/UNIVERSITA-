
int main() {
    // Creazione di un albero binario di esempio
    Node* root = createNodeV(1,
                        createNodeV(7,
                            createNode(7),
                            createNode(-8)),
                        createNode(0));
    cout << "Stampa dell'albero:" << endl;
    int sommarichiesta, livello;
    printTreeDepth(root);
    calcola(root, sommarichiesta, livello);
    if (livello != -1) {
        cout << "Somma richiesta: " << sommarichiesta << " al livello: " << livello << endl;
    } else {
        cout << "L'albero e' vuoto." << endl;
    }
    // Pulizia della memoria
    deleteTree(root);
    std::cout << "---------------------------------" << std::endl;
    root = nullptr;
    printTreeDepth(root);
    calcola(root, sommarichiesta, livello);
    if (livello != -1) {
        cout << "Somma richiesta: " << sommarichiesta << " al livello: " << livello << endl;
    } else {
        cout << "L'albero e' vuoto." << endl;
    }
    // Pulizia della memoria
    deleteTree(root);
    std::cout << "---------------------------------" << std::endl;
    root = createNodeV(1,
                        createNodeV(7,
                            createNode(7),
                            createNode(-8)),
                        createNode(-6));
    printTreeDepth(root);
    calcola(root, sommarichiesta, livello);
    if (livello != -1) {
        cout << "Somma richiesta: " << sommarichiesta << " al livello: " << livello << endl;
    } else {
        cout << "L'albero e' vuoto." << endl;
    }
    // Pulizia della memoria
    deleteTree(root);
    std::cout << "---------------------------------" << std::endl;
    root = createNodeV(1,
                        createNodeV(7,
                            createNode(7),
                            createNode(-8)),
                        createNode(-8));
    printTreeDepth(root);
    calcola(root, sommarichiesta, livello);
    if (livello != -1) {
        cout << "Somma richiesta: " << sommarichiesta << " al livello: " << livello << endl;
    } else {
        cout << "L'albero e' vuoto." << endl;
    }
    // Pulizia della memoria
    deleteTree(root);
    return 0;
}