package src.oggetto;

public class Pozione extends Oggetto {
    private int cura;

    public Pozione(String nome, double peso, int cura) {
        super(nome, peso);
        this.cura = cura;
    }
    // Eredita il metodo ripara() vuoto da Oggetto!
}