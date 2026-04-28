(* 1. Versione con 'fun' *)
fun is_one_fun 1 = "one"
  | is_one_fun _ = "anything else";

(* 2. Versione con 'case' *)
fun is_one_case x = 
    case x of
        1 => "one"
      | _ => "anything else";

(* 3. Versione con 'fn' *)
val is_one_fn = fn 1 => "one"
                 | _ => "anything else";

(* --- TEST E STAMPE --- *)

val test1 = is_one_fun 1;
val test2 = is_one_case 3;
val test3 = is_one_fn 10;

(* Nota: Nessun Int.toString necessario, i risultati sono gia' stringhe! *)
val _ = print ("Risultato con fun (passando 1): " ^ test1 ^ "\n");
val _ = print ("Risultato con case (passando 3): " ^ test2 ^ "\n");
val _ = print ("Risultato con fn (passando 10): " ^ test3 ^ "\n");