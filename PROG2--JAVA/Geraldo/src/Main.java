package src;

import src.oggetto.Spada;
import src.eccezioni.PesoEccessivoException;

public class Main {
    public static void main(String[] args) {
        Inventario zaino = new Inventario();

        // Creiamo una spada incredibilmente pesante
        Spada spadaGigante = new Spada("Spada di Ferro Colato", 60.0, 50, 10);

        try {
            zaino.aggiungiOggetto(spadaGigante); // Questo metodo può lanciare l'eccezione!
            System.out.println("Oggeto aggiunto con successo!");
        } catch (PesoEccessivoException e) {
            // Questo blocco cattura l'errore e lo gestisce senza far crashare il programma
            System.err.println("ATTENZIONE: " + e.getMessage());
            // All'esame, qui scriverai il codice JavaFX per mostrare una finestra di Alert!
        }
    }
}
