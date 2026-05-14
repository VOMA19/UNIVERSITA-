exception shortList of int;

fun returnThird (L) =
    let
        (* 2. Funzione interna che tenta di prelevare il terzo elemento *)
        fun getThird (a::b::c::xs) = c 
            | getThird (_) = raise shortList (length L) 
    in
        (* 3. Chiamata alla funzione con gestione dell'errore *)
        getThird L handle shortList n => (print ("List too short.\nIt only contains " ^ Int.toString n ^ " elements.\n"); 0) 
    end;