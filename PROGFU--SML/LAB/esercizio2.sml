(* 1. Definiamo la funzione ricorsiva che fa il lavoro *)
fun sommaLista [] = 0
  | sommaLista (x::xs) = x + sommaLista xs;

(* 2. Dichiariamo i nostri dati di partenza *)
val numeri = [15, 25, 10, 50];

(* 3. Elaboriamo i dati chiamando la funzione *)
val totale = sommaLista numeri;

(* 4. Prepariamo e stampiamo l'output *)
val messaggio = "La somma dei numeri nella lista e': " ^ Int.toString totale ^ "\n";
val _ = print messaggio;^ Int.toString totale ^