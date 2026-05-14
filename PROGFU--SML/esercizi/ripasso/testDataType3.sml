(* ==========================================================================
ESERCIZIO: La Casa Intelligente

Parte 1: Definire un datatype `statoLuce` con 3 costruttori:
- Spenta
- Regolata (int per la luminosità)
- Colorata (tupla string * int per colore e luminosità)

Parte 2: Scrivere una funzione `leggiStato` che prenda uno 
stato e restituisca una stringa descrittiva.
========================================================================== *)

(* --- PARTE 1: Definizione del tipo di dato --- *)
datatype statoLuce = 
    Spenta 
    | Regolata of int 
    | Colorata of string * int;

(* --- PARTE 2: La funzione con Pattern Matching --- *)
fun leggiStato Spenta = 
        "La luce e' spenta."
    
    | leggiStato (Regolata valore) =  
        "La luce e' accesa al: " ^ Int.toString(valore) ^ "%"
    
    | leggiStato (Colorata (colore, valore)) = 
        "La luce e' " ^ colore ^ " e al " ^ Int.toString(valore) ^ "%";


(* ==========================================================================
    TEST E STAMPE A SCHERMO
   ========================================================================== *)
val test_spenta = leggiStato Spenta;
val test_regolata = leggiStato (Regolata 50);
val test_colorata = leggiStato (Colorata ("Blu", 75));

print ("\n--- STATO LUCI SMART HOME ---\n");
print (test_spenta ^ "\n");
print (test_regolata ^ "\n");
print (test_colorata ^ "\n");