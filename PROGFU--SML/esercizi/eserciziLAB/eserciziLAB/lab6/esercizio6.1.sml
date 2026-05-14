val input = TextIO.openIn "file";
val chars5 = TextIO.inputN (input, 5);
val line = TextIO.inputLine input;
val nextChar = TextIO.lookahead input;
val everything = TextIO.inputAll input;
TextIO.closeIn input;