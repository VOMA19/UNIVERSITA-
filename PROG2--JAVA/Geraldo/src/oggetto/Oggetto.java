package src.oggetto;

public abstract class Oggetto {
    private String nome;
    private double peso;

    // Costruttore fondamentale per inizializzare lo stato comune
    public Oggetto(String nome, double peso) {
        this.nome = nome;
        this.peso = peso;
    }

    public String getNome() {
        return nome;
    }

    public double getPeso() {
        return peso;
    }

    // Il trucco magico: comportamento di default vuoto (No-Op)
    public void ripara() {
        // Di default, un oggetto generico non fa nulla quando viene riparato
    }
}