package src.oggetto;

public class Spada extends Oggetto implements Riparabile {
    private int danno;
    private int durability;

    // Chiama super per nome e peso, poi inizializza i campi specifici
    public Spada(String nome, double peso, int danno, int durability) {
        super(nome, peso);
        this.danno = danno;
        this.durability = durability;
    }

    @Override
    public void ripara() {
        this.durability = 10; // Nel file armigeraldo.pdf il massimo è 10
        System.out.println("La spada " + getNome() + " è stata riparata al massimo (10)!");
    }

    public int getDurability() {
        return durability;
    }
}