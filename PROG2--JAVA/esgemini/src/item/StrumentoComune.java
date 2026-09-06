package src.item;

import src.eccezioni.CaricheEsauriteException;

public class StrumentoComune extends Item {
    private int cariche;
    private int limiteCariche;

    public StrumentoComune(String nome, int ingombro, int cariche, int limiteCariche) {
        super(nome, ingombro);
        this.cariche = cariche;
        this.limiteCariche = limiteCariche;
    }

    @Override
    public void attiva() throws CaricheEsauriteException {
        // Attenzione: se cariche è 0, non possiamo attivare!
        if (cariche > 0) {
            this.cariche -= 1;
            System.out.println(getNome() + " attivato! Cariche rimanenti: " + cariche);
        } else {
            // Risolto il BUG del "new" mancante
            throw new CaricheEsauriteException("Impossibile usare " + getNome() + ": cariche esaurite!");
        }
    }

    @Override
    public double getEfficienza() {
        // Cast a double necessario per evitare la divisione intera!
        return (double) cariche / limiteCariche;
    }
}
