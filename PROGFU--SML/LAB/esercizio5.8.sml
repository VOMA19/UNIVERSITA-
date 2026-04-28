fun sumList [] = (0, 0)                             (* Caso base 1: lista vuota *)
  | sumList [x] = (x, 0)                            (* Caso base 2: un solo elemento (posizione pari) *)
  | sumList (x::y::xs) =                            (* Estraggo DUE elementi: x (pari) e y (dispari) *)
      let
          (* Faccio la ricorsione sul resto della lista e salvo la tupla *)
          val (sommaPariResto, sommaDispariResto) = sumList xs
      in
          (* Sommo x ai pari e y ai dispari *)
          (x + sommaPariResto, y + sommaDispariResto)
      end;

(* --- TEST --- *)
(* Posizioni pari:  1, 3, 5  (Somma = 9)  *)
(* Posizioni disp:  2, 4, 6  (Somma = 12) *)
val test_lista = sumList [1, 2, 3, 4, 5, 6];

val _ = print ("Somma Pari: " ^ Int.toString (#1 test_lista) ^ "\n");
val _ = print ("Somma Dispari: " ^ Int.toString (#2 test_lista) ^ "\n");