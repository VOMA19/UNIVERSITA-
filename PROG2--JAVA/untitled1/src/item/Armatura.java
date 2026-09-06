package item;

public class Armatura extends Item {
    private final int puntiDifesa;

    public Armatura(String nome, double peso, int puntiDifesa) {
        super(nome, peso);
        this.puntiDifesa = puntiDifesa;
    }

    public int getPuntiDifesa() { return puntiDifesa; }
}