package item;

import eccezioni.ArmaRottaException;

public class ArmaRara extends Item {
    private double durability; // da 0.0 a 1.0
    private int potenzaAttacco;

    public ArmaRara(String nome, int ingombro, double durability, int potenzaAttacco) {
        super(nome, ingombro);
        this.durability = durability;
        this.potenzaAttacco = potenzaAttacco;
    }

    @Override
    public void attiva() throws ArmaRottaException {
        // Controlliamo che l'arma non sia già rotta prima di usarla
        if (durability >= 0.10) {
            this.durability -= 0.10;
            // Arrotondamento per evitare errori di precisione dei double
            this.durability = Math.round(this.durability * 100.0) / 100.0;
            System.out.println(getNome() + " attivato! Durabilità rimanente: " + (durability * 100) + "%");
        } else {
            throw new ArmaRottaException("Impossibile usare " + getNome() + ": l'arma è rotta!");
        }
    }

    @Override
    public double getEfficienza() {
        return durability;
    }
}
