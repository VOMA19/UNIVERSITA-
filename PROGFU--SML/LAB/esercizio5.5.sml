fun sumPairs [] = (0, 0)
  | sumPairs ((x, y)::xs) =
      let
          val (sommaX, sommaY) = sumPairs xs
      in
          (x + sommaX, y + sommaY)
      end;

(* --- TEST --- *)
val test1 = sumPairs [(1,2), (3,4), (5,6)];
val test2 = sumPairs [(0,1), (3,6), (8,1), (10,9)];

(* Stampa veloce formattata come tupla *)
val _ = print ("Risultato test 1: (" ^ Int.toString (#1 test1) ^ ", " ^ Int.toString (#2 test1) ^ ")\n");
val _ = print ("Risultato test 2: (" ^ Int.toString (#1 test2) ^ ", " ^ Int.toString (#2 test2) ^ ")\n");