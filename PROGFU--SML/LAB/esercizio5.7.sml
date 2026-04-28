(*Write an efficient program doubleExp that, given as input a
real 𝑥 and nonnegative 𝑖, computes 𝑥2𝑖, making only one
recursive call*)

fun doubleExp (x: real, 0) = x                         (* Caso base: x^(2^0) = x^1 = x *)
  | doubleExp (x: real, i: int) =                      (* Caso ricorsivo *)
      let
          (* 1. Faccio UN'UNICA chiamata ricorsiva per calcolare il livello precedente *)
          val risultato_prec = doubleExp (x, i - 1)
      in
          (* 2. Moltiplico il risultato per se stesso (Elevo al quadrato) *)
          risultato_prec * risultato_prec
      end;

(* --- TEST --- *)
(* doubleExp(2.0, 3) calcolera' 2^(2^3) = 2^8 = 256.0 *)
val test1 = doubleExp (2.0, 3);
val test2 = doubleExp (1.1, 10); (* 1.1 alla 1024! *)

val _ = print ("Risultato di 2.0 con i=3 : " ^ Real.toString test1 ^ "\n");
val _ = print ("Risultato di 1.1 con i=10: " ^ Real.toString test2 ^ "\n");