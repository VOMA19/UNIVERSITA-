fun thousandthPower (x: real) =
    let
        (* 1. Costruiamo x^10 *)
        val x2  = x * x        (* x^2 *)
        val x4  = x2 * x2      (* x^4 *)
        val x8  = x4 * x4      (* x^8 *)
        val x10 = x8 * x2      (* x^8 * x^2 = x^10 *)

        (* 2. Costruiamo x^100 usando x^10 *)
        val x20  = x10 * x10
        val x40  = x20 * x20
        val x80  = x40 * x40
        val x100 = x80 * x20   (* x^80 * x^20 = x^100 *)

        (* 3. Costruiamo x^1000 usando x^100 *)
        val x200  = x100 * x100
        val x400  = x200 * x200
        val x800  = x400 * x400
        val x1000 = x800 * x200 (* x^800 * x^200 = x^1000 *)
    in
        x1000
    end;

(* --- TEST COME DA TRACCIA --- *)
val test1 = thousandthPower 1.0;
val test2 = thousandthPower 1.1;

val _ = print ("thousandthPower 1.0 = " ^ Real.toString test1 ^ "\n");
val _ = print ("thousandthPower 1.1 = " ^ Real.toString test2 ^ "\n");