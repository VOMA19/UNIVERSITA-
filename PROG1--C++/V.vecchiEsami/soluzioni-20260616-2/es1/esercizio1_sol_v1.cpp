#include <iostream>
#include <fstream>

void calcola_straordinari(double[], double[], double, int);
int scrivi_append(char[], double[], int);

int main() 
{
    int curr_dim = 2;
    int noperai = 0;
    double* ore_lavorate = new (std::nothrow) double[curr_dim];
    
    if (ore_lavorate == nullptr){
                    std::cout<<"Problema di allocazione di memoria per le ore lavorate";
                    exit(-1);
                }

    double ore_inserite = 0.0;
    do {
        std::cout << "Inserire il numero di ore lavorate (-1.0 per terminare): ";
        std::cin >> ore_inserite;

        if (ore_inserite!=-1.0){
            
            if (ore_inserite < 0.0 || ore_inserite > 16.0) {
                std::cout << "Valore non valido inserito. Impostato a 1.0" << std::endl;
                ore_inserite = 1.0; 
            }

            noperai++;
               
            if (noperai > curr_dim) {
                int new_dim = 2 * curr_dim;
                double* new_array = new (std::nothrow) double[new_dim];

                if (new_array == nullptr){
                    std::cout<<"Memoria insufficiente per raddoppiare lo spazio di allocazione, non alloco altri e provo a calcolare straordinari";
                    noperai--;
                    break;
                 }

                for (int i = 0; i < curr_dim; i++)
                    new_array[i] = ore_lavorate[i];
                delete[] ore_lavorate;
                curr_dim = new_dim;
                ore_lavorate = new_array;
            }
            ore_lavorate[noperai - 1] = ore_inserite;
        }
    } while (ore_inserite != -1.0);

    double* ore_straordinario = new(std::nothrow) double[noperai];

    if (ore_straordinario == nullptr){
            std::cout<<"Memoria insufficiente per allocare array per straordinari";
            delete [] ore_lavorate;
            exit(-1);
                }

    calcola_straordinari(ore_lavorate, ore_straordinario, 8.0, noperai);

    
        
    char nome_file[32] = "registro_ore.txt";
    int res = scrivi_append(nome_file, ore_straordinario, noperai);

    if (res == 1)
        {  delete[] ore_lavorate;
           delete[] ore_straordinario;
	   return 1;
        }

    delete[] ore_straordinario;
    delete[] ore_lavorate;

    return 0;
}

void calcola_straordinari(double ore[], double straordinario[], double soglia, int dim) {
    for (int i = 0; i < dim; i++) {
        if (ore[i] > soglia)
            straordinario[i] = ore[i] - soglia;
        else
            straordinario[i] = 0.0;
    }
}

int scrivi_append(char nome_file[], double straordinario[], int dim) {
    std::fstream fout;

    fout.open(nome_file, std::ios::app);
    if (!fout)

      {
        std::cout << "Errore nell'apertura del file" << std::endl;
        return 1;
    }

    for (int i = 0; i < dim; i++)
        fout << straordinario[i] << std::endl;
    fout.close();

    return 0;
}
