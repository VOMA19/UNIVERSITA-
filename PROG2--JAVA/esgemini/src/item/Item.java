package src.item;

import java.util.Objects;

// Implementa Comparable per definire l'ordinamento naturale
// Implementa Attivabile così tutti gli Item sanno come attivarsi polimorficamente
public abstract class Item implements Attivabile, Comparable<Item> {
    private String nome;
    private int ingombro;

    public Item(String nome, int ingombro) {
        this.nome = nome;
        this.ingombro = ingombro;
    }

    public String getNome() {
        return nome;
    }

    public int getIngombro() {
        return ingombro;
    }

    // Metodo astratto che costringe i figli a dichiarare la propria efficienza
    public abstract double getEfficienza();

    // 1. ORDINAMENTO NATURALE: ingombro decrescente, poi nome alfabetico
    @Override
    public int compareTo(Item other) {
        int compIngombro = other.ingombro - this.ingombro; // decrescente
        if (compIngombro != 0) {
            return compIngombro;
        }
        return this.nome.compareTo(other.nome); // crescente (alfabetico)
    }

    // 2. CONTRATTO DI OBJECT (equals e hashCode impeccabili)
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || this.getClass() != obj.getClass()) return false;
        Item other = (Item) obj;
        return this.ingombro == other.ingombro && Objects.equals(this.nome, other.nome);
    }

    @Override
    public int hashCode() {
        return Objects.hash(nome, ingombro);
    }
}
