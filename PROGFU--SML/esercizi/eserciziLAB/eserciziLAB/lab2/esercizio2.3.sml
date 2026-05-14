(* ==========================================================================
    LABORATORIO 2 - ESERCIZIO 2.3
    Scrivi una funzione 'min3real' che restituisca il minimo di tre reali.
    Esempio: min3real 10.5 5.2 8.1 = 5.2
========================================================================== *)

(* SML capisce che a, b, c sono reali perché usiamo Real.min *)
fun min3real a b c = Real.min(a, Real.min(b, c));

(* Test *)
val res_minReal = min3real 10.5 5.2 8.1;
print ("Il minimo reale e': " ^ Real.toString(res_minReal) ^ "\n");