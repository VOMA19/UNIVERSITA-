(* Versione usando hd e tl *)
fun fourth L = hd(tl(tl(tl L)));

fun fourthPM (_::_::_::x::_) = x;

