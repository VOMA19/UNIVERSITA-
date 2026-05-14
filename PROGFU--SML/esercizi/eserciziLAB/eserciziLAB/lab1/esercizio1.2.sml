(* ==========================================================================
    ESERCIZIO 1.2
    Scrivi l'espressione per convertire:
    1. #"Y" in un intero.
    2. 120 in un carattere.
    3. 97.0 in un carattere.
    4. #"N" in un numero reale.
    5. #"Z" in una stringa.
========================================================================== *)

(* 1. #"Y" in un intero: usiamo ord per ottenere il codice ASCII *)
val y_to_int = ord(#"Y");
print ("1. Carattere #'Y' in intero: " ^ Int.toString(y_to_int) ^ "\n");

(* 2. 120 in un carattere: usiamo chr per convertire dal codice ASCII *)
val int_to_char = chr(120);
print ("2. Intero 120 in carattere: " ^ str(int_to_char) ^ "\n");

(* 3. 97.0 in un carattere: 
    Attenzione! chr vuole un int. Dobbiamo prima convertire il real in int 
    usando floor (o ceil/round) e poi chiamare chr. *)
val real_to_char = chr(floor(97.0));
print ("3. Reale 97.0 in carattere: " ^ str(real_to_char) ^ "\n");

(* 4. #"N" in un numero reale:
   Dobbiamo fare due passi: da char a int (ord) e poi da int a real (Real.fromInt). *)
val char_to_real = Real.fromInt(ord(#"N"));
print ("4. Carattere #'N' in reale: " ^ Real.toString(char_to_real) ^ "\n");

(* 5. #"Z" in una stringa: usiamo la funzione str *)
val char_to_string = str(#"Z");
print ("5. Carattere #'Z' in stringa: " ^ char_to_string ^ "\n");