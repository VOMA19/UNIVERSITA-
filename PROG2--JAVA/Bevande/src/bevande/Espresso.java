package Bevande.src.bevande;
public class Espresso implements Bevanda {
    // Possiamo definire il costo specifico dell'espresso come costante privata della classe
    private static final double COSTO_ESPRESSO = 0.80;

    @Override
    public void prepara(int zucchero) {
        System.out.println("Preparazione Espresso con " + zucchero + " cucchiaini di zucchero:");
        System.out.println("-> Trituro i chicchi di caffè...");
        System.out.println("-> Scaldo l'acqua ed erogo ad alta pressione...");
        System.out.println("-> Espresso pronto in tazza calda!");
    }

    @Override
    public double getCosto() {
        return COSTO_ESPRESSO; // Restituisce correttamente 0.80
    }
}