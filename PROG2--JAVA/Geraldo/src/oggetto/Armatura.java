package src.oggetto;

public class Armatura extends Oggetto implements Riparabile {
    private int difesa;
    private int durability;

    public Armatura(String nome, double peso, int difesa, int durability) {
        super(nome, peso);
        this.difesa = difesa;
        this.durability = durability;
    }

    @Override
    public void ripara() {
        this.durability = 10;
        System.out.println("L'armatura " + getNome() + " è stata riparata al massimo (10)!");
    }

    public int getDurability() {
        return durability;
    }
}
