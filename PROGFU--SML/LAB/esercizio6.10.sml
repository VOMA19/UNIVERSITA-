(* Caso base: lista di funzioni vuota, restituisco lista vuota  *)
fun applyList [] x = [] 

(* Caso ricorsivo: smonto la testa (la funzione 'f') e il resto delle funzioni 'fs' *)
    | applyList (f::fs) x = 
        (f x) :: applyList fs x;

(*oppure*)

fun applyList fs x = 
    map (fn f => f x) fs;


(* Creiamo due funzioncine stupide *)
fun raddoppia n = n * 2;
fun quadrato n = n * n;
fun aggiungi_dieci n = n + 10;

(* Le mettiamo in una lista! *)
val mie_funzioni = [raddoppia, quadrato, aggiungi_dieci];

(* Usiamo applyList passando la lista di funzioni e il numero 5  *)
val test_risultato = applyList mie_funzioni 5;