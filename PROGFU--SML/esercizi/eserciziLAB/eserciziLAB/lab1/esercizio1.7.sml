(* ==========================================================================
    ESERCIZIO 1.7
    Fornire esempi di dati che corrispondono ai seguenti tipi complessi.
   ========================================================================== *)

(* 1. Tipo: ((int*int)*(bool list)*real)*(real*string) *)
val test_tipoAstruso1 : ((int*int)*(bool list)*real)*(real*string) = 
    (((1,2), [true, false], 3.5), (7.2, "ciao"));

(* 2. Tipo: (bool*int)*char *)
val test_tipoAstruso2 : (bool*int)*char = 
    ((true, 42), #"z");

(* 3. Tipo (corretto dalla slide): real * int list list list list *)
val test_tipoAstruso3 : real * int list list list list = 
    (3.14, [[[[1,2],[3]]]]);