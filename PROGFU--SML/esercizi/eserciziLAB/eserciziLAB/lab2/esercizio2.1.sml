(* ==========================================================================
    LABORATORIO 2 - ESERCIZIO 1
    Scrivi una funzione 'cube' che calcola il cubo di un numero reale.
    Esempio: cube (2.9) = 24.389
   ========================================================================== *)

(* Dichiariamo la funzione 'cube'. 
    Usiamo (x: real) per forzare il compilatore a usare i numeri decimali,
    altrimenti SML userebbe gli 'int' di default per l'operatore * *)

fun cube (x: real) = x * x * x;

(* ==========================================================================
    TEST E STAMPE A SCHERMO
========================================================================== *)

val test_cube = cube 2.9;

(* Per stampare, convertiamo il risultato in stringa con Real.toString *)
print ("\n--- RISULTATO ESERCIZIO 1 ---\n");
print ("Il cubo di 2.9 e': " ^ Real.toString(test_cube) ^ "\n");