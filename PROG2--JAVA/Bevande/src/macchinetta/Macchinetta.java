package Bevande.src.macchinetta;

import Bevande.src.bevande.Bevanda;
import Bevande.src.metodi.Metodi;

public class Macchinetta {
    private Bevanda bevandaSelezionata;
    private Metodi metodoSelezionato;

    // Modificato in public e aggiunti i controlli di robustezza
    public void ordina(int sugar) {
        // 1. Controllo robustezza: impediamo il NullPointerException
        if (bevandaSelezionata == null || metodoSelezionato == null) {
            System.out.println("Errore: impossibile procedere. Seleziona bevanda e pagamento.");
            return;
        }

        // 2. Logica di pagamento ed erogazione
        if (metodoSelezionato.paga(bevandaSelezionata.getCosto())) {
            bevandaSelezionata.prepara(sugar);
        } else {
            System.out.println("Impossibile completare l'ordine: transazione fallita.");
        }

        // 3. Reset dello stato (usa i setter o imposta direttamente a null)
        this.bevandaSelezionata = null;
        this.metodoSelezionato = null;
    }

    public Metodi getMetodi() {
        return metodoSelezionato;
    }

    public Bevanda getBevanda() {
        return bevandaSelezionata;
    }

    public void setMetodo(Metodi metodoSelezionato) {
        this.metodoSelezionato = metodoSelezionato;
    }

    public void setBevanda(Bevanda bevandaSelezionata) {
        this.bevandaSelezionata = bevandaSelezionata;
    }
}
