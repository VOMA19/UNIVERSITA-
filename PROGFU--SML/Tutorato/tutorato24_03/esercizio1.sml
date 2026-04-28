(*Scrivi una funzione che data una lista in input, restituisca una nuova lista composta dagli
elementi originali seguiti dagli stessi elementi disposti in ordine inverso cosi da creare una
lista palindroma.
esempio:
> palindromo[1,2,3] ;
val it = [1, 2, 3, 3, 2, 1]: int list
> palindromo["c","b","a"];
val it = ["c", "b", "a", "a", "b", "c"]: string list*)

fun reverse ([], acc) = acc
  | reverse (x::xs, acc) = reverse (xs, x :: acc);

fun palindromo xs = xs @ reverse (xs, []);

(* 1. Esplodiamo la stringa in lista *)
val lista_caratteri = explode "ciao";

(* 2. Applichiamo la TUA funzione palindromo *)
val lista_palindroma = palindromo lista_caratteri;

(* 3. Implodiamo la lista per farla tornare una stringa leggibile *)
val risultato_finale = implode lista_palindroma;

(* Stampa del risultato (nessun toString necessario, è già una stringa!) *)
val _ = print("Il valore inserito ritorna: " ^ risultato_finale ^ "\n");



