#include <iostream>
using namespace std;

const int MAXN = 100;

void stampaArray(int a[], int n){
    if (n == 0) return;
    stampaArray(a, n-1);
    cout << a[n-1] << " ";
}
int sommaArray(int a[], int n){
    if(n == 0) return 0;
    return a[n-1] + sommaArray(a, n-1);
}
int maxArray(int a[], int n){
    if(n == 1) return a[0];
    int maxRest = maxArray(a, n-1);
    return (a[n-1] > maxRest) ? a[n-1] : maxRest;
}
int minArray(int a[], int n){
    if(n == 1) return a[0];
    int minRest = minArray(a, n-1);
    return (a[n-1] <= minRest) ? a[n-1] : minRest;
}
bool arrayOrdinato(int a[], int n){
    if (n <= 1) return true;
    if (a[n-2] > a[n-1]) return false;
    return arrayOrdinato(a, n-1);
}
int contaPari(int a[], int n){
    if(n == 0) return 0;
    if(a[n-1]%2 == 0) return 1+ contaPari(a, n-1);
    else return contaPari(a, n-1);
}
bool cercaValore(int a[], int n, int x){
    if (n == 0) return false;
    if (a[n-1] == x) return true;
    return cercaValore(a, n-1, x);
}
int potenza(int base, int exp){
    if(exp == 0) return 1;
    return base * potenza(base,exp-1);
}
int mcd(int a, int b){
    if(b == 0) return a;
    return mcd(b, a % b);
}
void invertiArray(int a[], int n){
    if(n <= 1) return;
    
    // Scambia primo e ultimo elemento
    int temp = a[0];
    a[0] = a[n-1];
    a[n-1] = temp;
    
    // Ricorsione sul sottovettore centrale
    invertiArray(a + 1, n - 2);
}

void menu() {
    cout << "\n=== MENU RICORSIONE ===\n";
    cout << "1 - Stampa array\n";
    cout << "2 - Somma elementi array\n";
    cout << "3 - Massimo dell'array\n";
    cout << "4 - Minimo dell'array\n";
    cout << "5 - Verifica se array e' ordinato crescente\n";
    cout << "6 - Conta quanti pari ci sono\n";
    cout << "7 - Cerca un valore x nell'array\n";
    cout << "8 - Calcola potenza(base, exp)\n";
    cout << "9 - Calcola MCD(a, b)\n";
    cout << "10 - Inverti l'array\n";
    cout << "0 - Esci\n";
}

int main() {
    int n;
    int a[MAXN];

    cout << "Inserisci n (1-" << MAXN << "): ";
    cin >> n;
    if (n <= 0 || n > MAXN) {
        cout << "n non valido.\n";
        return 1;
    }

    cout << "Inserisci " << n << " interi:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int scelta;
    do {
        menu();
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1:
                cout << "Array: ";
                stampaArray(a, n);
                cout << endl;
                break;

            case 2:
                cout << "Somma: " << sommaArray(a, n) << endl;
                break;

            case 3:
                cout << "Massimo: " << maxArray(a, n) << endl;
                break;

            case 4:
                cout << "Minimo: " << minArray(a, n) << endl;
                break;

            case 5:
                if (arrayOrdinato(a, n))
                    cout << "L'array e' ordinato crescente.\n";
                else
                    cout << "L'array NON e' ordinato.\n";
                break;

            case 6:
                cout << "Numero di pari: " << contaPari(a, n) << endl;
                break;

            case 7: {
                int x;
                cout << "Valore da cercare: ";
                cin >> x;
                if (cercaValore(a, n, x))
                    cout << x << " e' presente.\n";
                else
                    cout << x << " NON e' presente.\n";
                break;
            }

            case 8: {
                int base, exp;
                cout << "Base: ";
                cin >> base;
                cout << "Esponente (>=0): ";
                cin >> exp;
                cout << "Risultato: " << potenza(base, exp) << endl;
                break;
            }

            case 9: {
                int x, y;
                cout << "a: ";
                cin >> x;
                cout << "b: ";
                cin >> y;
                cout << "MCD: " << mcd(x, y) << endl;
                break;
            }

            case 10:
                invertiArray(a, n);
                cout << "Array invertito: ";
                stampaArray(a, n);
                cout << endl;
                break;

            case 0:
                cout << "Arrivederci.\n";
                break;

            default:
                cout << "Scelta non valida.\n";
        }

    } while (scelta != 0);

    return 0;
}
