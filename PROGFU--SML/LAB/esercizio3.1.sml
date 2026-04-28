fun factorial 0 = 1
    | factorial n = n * factorial (n - 1)

val fattoriale = factorial 10;
val messaggio = "il fattoriale del numero e': " ^ Int.toString fattoriale;

print(messaggio); 