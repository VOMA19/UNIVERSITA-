package item;

public class KitRiparazione extends Item {
    private int usciteRimanenti;

    public KitRiparazione(String nome, double peso, int uscite) {
        super(nome, peso);
        this.usciteRimanenti = uscite;
    }

    public int getUsciteRimanenti() { return usciteRimanenti; }

    public void usaCarica() {
        if (usciteRimanenti > 0) {
            usciteRimanenti--;
        }
    }
}