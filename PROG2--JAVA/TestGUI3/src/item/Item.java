package item;

public abstract class Item implements Comparable<Item> {
    private final String nome; // Nome immutabile [4]
    private int ammontare;
    private final int massimo; // Massimo consentito nell'inventario [4]
    private boolean sbloccato;

    public Item(String nome, int ammontare, int massimo, boolean sbloccato) {
        this.nome = nome;
        this.ammontare = ammontare;
        this.massimo = massimo;
        this.sbloccato = sbloccato;
    }

    public String getNome() {
        return nome;
    }

    public int getAmmontare() {
        return ammontare;
    }

    public void setAmmontare(int ammontare) {
        if (ammontare < 0) {
            this.ammontare = 0;
        } else if (ammontare > massimo) {
            this.ammontare = massimo;
        } else {
            this.ammontare = ammontare;
        }
    }

    public int getMassimo() {
        return massimo;
    }

    public boolean isSbloccato() {
        return sbloccato;
    }

    public void setSbloccato(boolean sbloccato) {
        this.sbloccato = sbloccato;
    }

    @Override
    public int compareTo(Item o) {
        // Ordinamento naturale alfabetico per nome [1]
        return this.nome.compareTo(o.nome);
    }
}
