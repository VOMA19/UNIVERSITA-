(* Caso base: quando n arriva a 0, abbiamo finito di stampare. Restituiamo () *)
fun tabulate (a: real, delta: real, 0, F) = ()

(* Caso ricorsivo: stampiamo la riga corrente, poi andiamo al passo successivo *)
    | tabulate (a: real, delta: real, n: int, F) =
(
(* 1. Stampa il valore di 'a' e il valore di 'F(a)' separati da uno spazio *)
        print (Real.toString a ^ " " ^ Real.toString (F a) ^ "\n");

(* 2. Chiamata ricorsiva: 'a' aumenta di 'delta', 'n' diminuisce di 1 *)
        tabulate (a + delta, delta, n - 1, F)
);

(* --- TEST COME DA PDF --- *)
val _ = print "Inizio test tabulate:\n";
val _ = tabulate (1.0, 0.1, 9, fn x => x * x);