#include <iostream>
#include <fstream>

using namespace std;

const double gravity = 9.8;

// Inserire la soluzione qui sotto!

void simulate(double **, int, double, double);
bool save(const char *, double **, int);


int main()
{

   double s0, v0;
   int n;
   char *nomefile = new char[16];

   cout << "Inserire la quota di partenza, la velocita' iniziale, il numero di secondi di osservazione: ";
   cin >> s0 >> v0 >> n;

   if (s0 <= 0)
   {
      cout << "L'oggetto e' gia' a terra! Errore!" << endl;
      exit(1);
   }

   cout << "Inserisci ora il nome del file dove salvare i dati: ";
   cin >> nomefile;

   double *data[2];
   data[0] = new double[2 * n];
   data[1] = new double[2 * n];

   for (int i = 0; i < 2 * n; i++)
   {
      data[0][i] = 0;
      data[1][i] = 0;
   }

   simulate(data, 2 * n, v0, s0);
   if (save(nomefile, data, 2 * n) == false)
   {
      cout << "Errore durante il salvataggio dei dati!" << endl;
      delete[] data[0];
      delete[] data[1];
      exit(1);
   }

   if (data[1][2 * n - 1] > 0)
      cout << "Attenzione l'oggetto non ha ancora toccato terra!" << endl;

   delete[] data[0];
   delete[] data[1];

   return 0;
}

void simulate(double **d, int t, double vel0, double height)
{
   for (int i = 0; i < t; i++)
   {
      d[0][i] = i / 2.0;
      double s = -0.5 * gravity * (i / 2.0) * (i / 2.0) - (i / 2.0) * vel0 + height;

      if (s >= 0)
         d[1][i] = s;
      else
         break;
   }
   return;
}

bool save(const char *nomefile, double **d, int t)
{
   fstream fout;
   fout.open(nomefile, ios::out);
   if (fout.fail())
      return false;

   for (int i; i < t; i++)
   {
      fout << d[0][i] << "," << d[1][i] << endl;
   }

   fout.close();

   return true;
}
