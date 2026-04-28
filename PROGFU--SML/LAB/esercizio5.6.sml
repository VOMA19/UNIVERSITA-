exception ListaVuota;

fun maxList2 [] = raise ListaVuota 
    |maxList2 ([x:real]) = x                 (* Caso base: se c'e' un solo elemento, e' lui il massimo *)
    |maxList2 (x::xs) =                      (* Caso ricorsivo: estraggo l'elemento corrente 'x' e il resto 'xs' *)
      let 
          val max_resto = maxList2 xs
      in
          (* Confronto il mio elemento 'x' con il massimo del resto *)
          if x > max_resto then
              x
          else
              max_resto
      end;

(* --- TEST --- *)
val test_max = maxList2 [1.2, 5.5, 3.14, 9.9, 2.0];

val _ = print ("Il valore massimo e': " ^ Real.toString test_max ^ "\n");