package item;

public class StrumentoComune extends Item {
    public StrumentoComune(String nome, int ammontare) {
        // Gli oggetti comuni sono sbloccati di default e hanno massimo = 8 [4]
        super(nome, ammontare, 8, true);
    }
}