(* ==========================================================================
    LABORATORIO 2 - ESERCIZIO 2.2
    Scrivi una funzione 'min3' che restituisca il minimo di tre interi.
    Esempio: min3 10 5 8 = 5
   ========================================================================== *)

(* Utilizziamo la funzione predefinita Int.min che accetta una tupla (x, y) 
   e restituisce il minore tra i due. La applichiamo ricorsivamente. *)

fun min3 a b c = Int.min(a, Int.min(b, c));

(* ==========================================================================
    TEST E STAMPE A SCHERMO
========================================================================== *)

val risultato_min3 = min3 10 5 8;

print ("\n--- RISULTATO ESERCIZIO 2.2 ---\n");
print ("Il minimo tra 10, 5 e 8 e': " ^ Int.toString(risultato_min3) ^ "\n");