fun is_lower_than5 x = 
    case (x < 5) of 
        true => 1
      | false => 2;

(* --- TEST --- *)
val test1 = is_lower_than5 10;
val test2 = is_lower_than5 2;
val test3 = is_lower_than5 0;  (* Testiamo anche lo zero! *)
val test4 = is_lower_than5 ~3; (* Testiamo un numero negativo! (~ è il meno in SML) *)

val _ = print ("Risultato con 10: " ^ Int.toString(test1) ^ "\n");
val _ = print ("Risultato con 2:  " ^ Int.toString(test2) ^ "\n");
val _ = print ("Risultato con 0:  " ^ Int.toString(test3) ^ "\n");
val _ = print ("Risultato con ~3: " ^ Int.toString(test4) ^ "\n");