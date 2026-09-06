package item;

public abstract class Item implements Comparable<Item> {
    private final String nome;
    private final double peso; // in kg

    public Item(String nome, double peso) {
        this.nome = nome;
        this.peso = peso;
    }

    public String getNome() { return nome; }
    public double getPeso() { return peso; }

    @Override
    public int compareTo(Item o) {
        // Ordinamento naturale alfabetico
        return this.nome.compareTo(o.nome);
    }
}