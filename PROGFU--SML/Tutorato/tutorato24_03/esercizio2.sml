(*Scrivi una funzione che data una stringa in input, restituisca una stringa composta dagli
elementi originali seguiti dagli stessi elementi disposti in ordine inverso cosi da creare una
stringa palindroma.
esempio:
> palindromoStringa("abc");
val it = "abccba": string
> palindromoStringa("add");
val it = "adddda": string*)

fun palindromoStringa s = s ^ implode (rev (explode s));

val test1 = palindromoStringa "abc";
val test2 = palindromoStringa "add";

val _ = print("Risultato 1: " ^ test1 ^ "\n");
val _ = print("Risultato 2: " ^ test2 ^ "\n");