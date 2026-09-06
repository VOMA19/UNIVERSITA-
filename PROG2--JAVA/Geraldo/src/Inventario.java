package src;

import java.util.ArrayList;
import src.oggetto.Oggetto;
import src.eccezioni.PesoEccessivoException;

public class Inventario {
    private ArrayList<Oggetto> listaOggetti = new ArrayList<>();
    private final double pesoMax = 50.0; // Costante fissa di capacità

    // Calcola dinamicamente il peso totale corrente dello zaino
    public double getPesoAttuale() {
        double pesoTotale = 0.0;
        for (Oggetto o : listaOggetti) {
            pesoTotale += o.getPeso();
        }
        return pesoTotale;
    }

    public void aggiungiOggetto(Oggetto item) throws PesoEccessivoException {
        double pesoAttuale = getPesoAttuale();
        if (pesoAttuale + item.getPeso() <= pesoMax) {
            listaOggetti.add(item);
            System.out.println(item.getNome() + " aggiunto all'inventario.");
        } else {
            // Un messaggio molto più dettagliato e utile per il debugging!
            double spazioRimasto = pesoMax - pesoAttuale;
            throw new PesoEccessivoException(
                "Impossibile aggiungere '" + item.getNome() +
                "' (Peso: " + item.getPeso() + "kg). Spazio residuo nello zaino: " + spazioRimasto + "kg."
            );
        }
    }

    // Risolto con il Dynamic Dispatch: nessuna riga di instanceof!
    public void ripara(Oggetto item) {
        item.ripara();
    }
}
