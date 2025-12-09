#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Nodo {
    int valore;
    Nodo* sinistro;
    Nodo* destro;
};

// IMPLEMENTAZIONI LISTA
int listLengthRec(Node* head) {
    if (head == nullptr) return 0;
    return 1 + listLengthRec(head->next);
}

int sumListRec(Node* head) {
    if (head == nullptr) return 0;
    return head->data + sumListRec(head->next);
}

int maxListRec(Node* head) {
    if (head->next == nullptr) return head->data;
    int maxRest = maxListRec(head->next);
    return (head->data > maxRest) ? head->data : maxRest;
}

bool searchListRec(Node* head, int x) {
    if (head == nullptr) return false;
    if (head->data == x) return true;
    return searchListRec(head->next, x);
}

void printListRec(Node* head) {
    if (head == nullptr) return;
    cout << head->data << " ";
    printListRec(head->next);
}

Node* insertAtTailRec(Node* head, int value) {
    if (head == nullptr) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }
    head->next = insertAtTailRec(head->next, value);
    return head;
}

Node* deleteValueRec(Node* head, int value) {
    if (head == nullptr) return nullptr;
    if (head->data == value) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    head->next = deleteValueRec(head->next, value);
    return head;
}

void deleteListRec(Node* head) {
    if (head == nullptr) return;
    deleteListRec(head->next);
    delete head;
}

// IMPLEMENTAZIONI NUMERI
int fattorialeRec(int n) {
    if (n <= 1) return 1;
    return n * fattorialeRec(n - 1);
}

int fibonacciRec(int n) {
    if (n <= 1) return n;
    return fibonacciRec(n - 1) + fibonacciRec(n - 2);
}

int contaCifreRec(int n) {
    if (n < 10) return 1;
    return 1 + contaCifreRec(n / 10);
}

int sommaCifreRec(int n) {
    if (n < 10) return n;
    return (n % 10) + sommaCifreRec(n / 10);
}

bool isPrimeRec(int n, int d) {
    if (d * d > n) return true;
    if (n % d == 0) return false;
    return isPrimeRec(n, d + 1);
}

// IMPLEMENTAZIONI ALBERO
Nodo* insertBSTRec(Nodo* radice, int val) {
    if (radice == nullptr) {
        Nodo* newNode = new Nodo;
        newNode->valore = val;
        newNode->sinistro = newNode->destro = nullptr;
        return newNode;
    }
    if (val < radice->valore)
        radice->sinistro = insertBSTRec(radice->sinistro, val);
    else if (val > radice->valore)
        radice->destro = insertBSTRec(radice->destro, val);
    return radice;
}

void printInOrderRec(Nodo* radice) {
    if (radice == nullptr) return;
    printInOrderRec(radice->sinistro);
    cout << radice->valore << " ";
    printInOrderRec(radice->destro);
}

int altezzaAlberoRec(Nodo* radice) {
    if (radice == nullptr) return 0;
    int leftHeight = altezzaAlberoRec(radice->sinistro);
    int rightHeight = altezzaAlberoRec(radice->destro);
    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

int contaNodiRec(Nodo* radice) {
    if (radice == nullptr) return 0;
    return 1 + contaNodiRec(radice->sinistro) + contaNodiRec(radice->destro);
}

int sommaValoriRec(Nodo* radice) {
    if (radice == nullptr) return 0;
    return radice->valore + sommaValoriRec(radice->sinistro) + sommaValoriRec(radice->destro);
}

bool searchBSTRec(Nodo* radice, int x) {
    if (radice == nullptr) return false;
    if (radice->valore == x) return true;
    if (x < radice->valore)
        return searchBSTRec(radice->sinistro, x);
    else
        return searchBSTRec(radice->destro, x);
}

void deleteTreeRec(Nodo* radice) {
    if (radice == nullptr) return;
    deleteTreeRec(radice->sinistro);
    deleteTreeRec(radice->destro);
    delete radice;
}

void menu() {
    cout << "\n=== MENU PRINCIPALE ===\n";
    cout << "1 - Operazioni sulla LISTA\n";
    cout << "2 - Operazioni sui NUMERI\n";
    cout << "3 - Operazioni sull'ALBERO BST\n";
    cout << "0 - Esci\n";
}

void menuLista() {
    cout << "\n--- MENU LISTA ---\n";
    cout << "1 - Inserisci in coda\n";
    cout << "2 - Stampa lista\n";
    cout << "3 - Lunghezza lista\n";
    cout << "4 - Somma elementi\n";
    cout << "5 - Massimo elemento\n";
    cout << "6 - Cerca valore\n";
    cout << "7 - Cancella primo nodo con valore dato\n";
    cout << "8 - Distruggi lista\n";
    cout << "0 - Torna al menu principale\n";
}

void menuNumeri() {
    cout << "\n--- MENU NUMERI ---\n";
    cout << "1 - Fattoriale\n";
    cout << "2 - Fibonacci\n";
    cout << "3 - Conta cifre\n";
    cout << "4 - Somma cifre\n";
    cout << "5 - Verifica se primo\n";
    cout << "0 - Torna al menu principale\n";
}

void menuAlbero() {
    cout << "\n--- MENU ALBERO BST ---\n";
    cout << "1 - Inserisci valore\n";
    cout << "2 - Stampa in-order\n";
    cout << "3 - Altezza albero\n";
    cout << "4 - Conta nodi\n";
    cout << "5 - Somma valori\n";
    cout << "6 - Cerca valore\n";
    cout << "7 - Distruggi albero\n";
    cout << "0 - Torna al menu principale\n";
}

int main() {
    Node* head = nullptr;   // lista
    Nodo* radice = nullptr; // albero

    int scelta;

    do {
        menu();
        cout << "Scelta: ";
        cin >> scelta;

        if (scelta == 1) {
            int scL;
            do {
                menuLista();
                cout << "Scelta lista: ";
                cin >> scL;

                switch (scL) {
                    case 1: {
                        int v;
                        cout << "Valore da inserire: ";
                        cin >> v;
                        head = insertAtTailRec(head, v);
                        break;
                    }
                    case 2:
                        cout << "Lista: ";
                        printListRec(head);
                        cout << endl;
                        break;
                    case 3:
                        cout << "Lunghezza: " << listLengthRec(head) << endl;
                        break;
                    case 4:
                        cout << "Somma: " << sumListRec(head) << endl;
                        break;
                    case 5:
                        if (head == nullptr) cout << "Lista vuota.\n";
                        else cout << "Massimo: " << maxListRec(head) << endl;
                        break;
                    case 6: {
                        int x;
                        cout << "Valore da cercare: ";
                        cin >> x;
                        if (searchListRec(head, x))
                            cout << x << " trovato.\n";
                        else
                            cout << x << " NON trovato.\n";
                        break;
                    }
                    case 7: {
                        int x;
                        cout << "Valore da cancellare: ";
                        cin >> x;
                        head = deleteValueRec(head, x);
                        break;
                    }
                    case 8:
                        deleteListRec(head);
                        head = nullptr;
                        cout << "Lista distrutta.\n";
                        break;
                }
            } while (scL != 0);
        }

        else if (scelta == 2) {
            int scN;
            do {
                menuNumeri();
                cout << "Scelta numeri: ";
                cin >> scN;

                switch (scN) {
                    case 1: {
                        int n;
                        cout << "n: ";
                        cin >> n;
                        cout << "Fattoriale: " << fattorialeRec(n) << endl;
                        break;
                    }
                    case 2: {
                        int n;
                        cout << "n: ";
                        cin >> n;
                        cout << "Fibonacci: " << fibonacciRec(n) << endl;
                        break;
                    }
                    case 3: {
                        int n;
                        cout << "Numero: ";
                        cin >> n;
                        cout << "Cifre: " << contaCifreRec(n) << endl;
                        break;
                    }
                    case 4: {
                        int n;
                        cout << "Numero: ";
                        cin >> n;
                        cout << "Somma cifre: " << sommaCifreRec(n) << endl;
                        break;
                    }
                    case 5: {
                        int n;
                        cout << "Numero: ";
                        cin >> n;
                        if (n <= 1) cout << "NON primo.\n";
                        else if (isPrimeRec(n, 2)) cout << "Primo.\n";
                        else cout << "NON primo.\n";
                        break;
                    }
                }
            } while (scN != 0);
        }

        else if (scelta == 3) {
            int scA;
            do {
                menuAlbero();
                cout << "Scelta albero: ";
                cin >> scA;

                switch (scA) {
                    case 1: {
                        int v;
                        cout << "Valore da inserire: ";
                        cin >> v;
                        radice = insertBSTRec(radice, v);
                        break;
                    }
                    case 2:
                        cout << "In-order: ";
                        printInOrderRec(radice);
                        cout << endl;
                        break;
                    case 3:
                        cout << "Altezza: " << altezzaAlberoRec(radice) << endl;
                        break;
                    case 4:
                        cout << "Numero nodi: " << contaNodiRec(radice) << endl;
                        break;
                    case 5:
                        cout << "Somma valori: " << sommaValoriRec(radice) << endl;
                        break;
                    case 6: {
                        int x;
                        cout << "Valore da cercare: ";
                        cin >> x;
                        if (searchBSTRec(radice, x))
                            cout << x << " trovato.\n";
                        else
                            cout << x << " NON trovato.\n";
                        break;
                    }
                    case 7:
                        deleteTreeRec(radice);
                        radice = nullptr;
                        cout << "Albero distrutto.\n";
                        break;
                }
            } while (scA != 0);
        }

    } while (scelta != 0);

    // cleanup finale
    deleteListRec(head);
    deleteTreeRec(radice);
    return 0;
}
