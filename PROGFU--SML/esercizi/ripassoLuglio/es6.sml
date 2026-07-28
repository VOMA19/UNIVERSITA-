datatype lambda_expr = Var of string 
                     | Lambda of string * lambda_expr 
                     | Apply of lambda_expr * lambda_expr;

fun is_free s (Var v) = (s = v)
    | is_free s (Lambda(v, e)) = if s = v then false else is_free s e
    | is_free s (Apply(e1, e2)) = (is_free s e1) orelse (is_free s e2);


fun verifica (a,b) = a > b


fun vowel [] = false
    | vowel (#"a"::xs) = true
    | vowel (#"e"::xs) = true
    | vowel (#"i"::xs) = true
    | vowel (#"o"::xs) = true
    | vowel (#"u"::xs) = true
    | vowel (_::xs) = false;

fun elementi_pari [] = []
    | elementi_pari [x] = []
    | elementi_pari (x::y::xs) = y :: elementi_pari xs;


fun max_List [x] = x
    | max_List (x::y::xs) = 
        if x > y then max_List (x::xs) 
        else max_List (y::xs);

fun max_List_con_let [x] = x
    | max_List_con_let (x::xs) =
        let 
            val max_del_resto = max_List_con_let xs 
        in 
            if x > max_del_resto then x else max_del_resto 
        end;

fun sum_list [] = (0,0)
    | sum_list [x] = (x,0) 
    | sum_list (x::y::xs) = 
        (*Facciamo un'unica chiamata sul resto della lista e *)
        (*spacchettiamo subito la tupla risultante due variabili*)
        let        
            val (sumDisp_resto, sumPari_resto) = sum_list(xs)
        in
            (* Nel blocco in...end, sommiamo gli elementi correnti ai rispettivi totali *)
            (x + sumDisp_resto, y + sumPari_resto)
        end;

fun split [] = ([], [])
    | split [x] = ([x], [])
    | split (x::y::xs) = 
        let
            val (splitPari, splitDispari) = split(xs)
        in
            (x::splitPari, y::splitDispari)
        end;


fun doubleExp (x:real, 0) = x
    | doubleExp (x:real, i) = 
        let
            val y = doubleExp(x, i-1) 
        in
            y * y
        end;


datatype Expr = X 
                | Y 
                | Avg of Expr * Expr 
                | Mul of Expr * Expr;

fun compute X x y = x
    | compute Y x y = y
    | compute (Avg(e1, e2)) x y = ((compute e1 x y) + (compute e2 x y)) div 2
    | compute (Mul(e1, e2)) x y = (compute e1 x y) * (compute e2 x y);


datatype 'a btree = Empty 
                  | Node of 'a * 'a btree * 'a btree;

fun inOrder Empty = nil
    | inOrder (Node(valore, sx, dx)) = 
        inOrder(sx) @ [valore] @ inOrder(dx);

datatype 'a tree = Node of 'a * 'a tree list;


(* Caso base: il nodo non ha figli (la lista è nil) *)
fun isOn x (Node(valore, nil)) = (valore = x)
(* Caso ricorsivo: il nodo ha almeno un figlio 't' e il resto dei figli 'ts' *)
    | isOn x (Node(valore, t::ts)) = 
        (valore = x) orelse 
        isOn x t orelse 
        isOn x (Node(valore, ts));

datatype 'a btree = Empty | Node of 'a * 'a btree * 'a btree

fun contaNodi Empty = 0
    |contaNodi (Node(valore, sx, dx)) = 1 + contaNodi(sx) + contaNodi(dx);

fun dictionary s [] = 0
    | dictionary s ((stringT, n)::xs) = 
        if s = stringT then n else dictionary s xs;

datatype naturale = zero | successivo of naturale;

fun sommaPeano zero y = y
    | sommaPeano (successivo x) y = successivo (sommaPeano x y);

datatype 'a btree = Empty | Node of 'a * 'a btree * 'a btree

fun intLT (a, b) = a < b;

fun lookup lt Empty x = false
    | lookup lt (Node(y, left, right)) x =
        if lt(x, y) then lookup lt left x    (* Usa la funzione 'lt' passata come parametro! *)
        else if lt(y, x) then lookup lt right x 
        else true;

datatype 'a tree = Node of 'a * 'a tree list;

fun sumTree (Node(a, nil)) = a
    |sumTree (Node(a, t::ts)) = sumTree(t) + sumTree(Node(a, ts));