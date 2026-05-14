datatype 'a bltree = Empty | Leaf of 'a | Node of 'a * 'a bltree * 'a bltree;

fun doubleTree Empty = Empty
    | doubleTree (Leaf v) = Leaf (v * 2)
    | doubleTree (Node(v, left, right)) = 
        Node(v * 2, doubleTree left, doubleTree right);