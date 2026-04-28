(*
Scrivi una funzione calcola_polinomio che prende in input un numero intero x e deve calcolare la seguente formula matematica:
(Esempio: calcola_polinomio 3 calcolerà 9 una sola volta, e poi farà (9 * 9) + 9, restituendo 90).
*)

fun calcola_polinomio (a: int) = 
    let 
        (* Calcolo e salvo il quadrato *)
        val x_quad = a * a
    in 
        (* Restituisco direttamente il calcolo finale *)
        (x_quad * x_quad) + x_quad
    end;

(* --- TEST --- *)
val test1 = calcola_polinomio 3; (* Risultato: 90 *)
val test2 = calcola_polinomio 2; (* Risultato: 20 (cioe' 16 + 4) *)