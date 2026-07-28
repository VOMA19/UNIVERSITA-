datatype battlefield = 
    Empty 
  | Creature of string * int 
  | Zone of battlefield * battlefield;

fun total_power Empty = 0
    | total_power (Creature(tipo, valore)) = 
        if tipo = "Eldrazi" then valore else 0
    | total_power (Zone(sx, dx)) = 
        total_power sx + total_power dx;