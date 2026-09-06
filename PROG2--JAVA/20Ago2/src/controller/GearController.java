package controller;

import javafx.scene.control.Alert;
import javafx.scene.input.MouseEvent;
import eccezioni.GearException;
import inventario.Inventario;
import item.Item;
import view.ItemView;
import view.MainView;
import ordinamento.OrdinatoreEfficienza;
import java.util.ArrayList;

public class GearController {
    private final Inventario model; // Reference al Model
    private final MainView view;    // Reference alla View
    private final ArrayList<Item> listaModello; // Lista di dati di appoggio
    private Item itemSelezionato = null;

    public GearController(Inventario model, MainView view, ArrayList<Item> listaModello) {
        this.model = model;
        this.view = view;
        this.listaModello = listaModello;

        // Inizializziamo la vista popolando la lista di sinistra
        aggiornaGrafica();

        // GESTIONE CLICK SUI BOTTONI (Action Events tramite Lambda!)
        this.view.getBtnAttiva().setOnAction(e -> attivaStrumentoSelezionato());
        this.view.getBtnOrdina().setOnAction(e -> ordinaListaPerEfficienza());
    }

    // GESTIONE CLICK SULL'ITEM (Mouse Event)
    private void gestisciSelezioneItem(MouseEvent event) {
        // Troviamo quale ItemView è stata cliccata tramite la sorgente dell'evento
        ItemView cliccata = (ItemView) event.getSource();
        this.itemSelezionato = cliccata.getModelItem();

        // Chiediamo alla View di mostrare i dettagli a schermo
        this.view.mostraDettagli(itemSelezionato);
    }

    private void attivaStrumentoSelezionato() {
        if (itemSelezionato == null) {
            mostraAlertErrore("Nessun oggetto selezionato!");
            return;
        }

        try {
            // Proviamo ad attivare l'oggetto sul modello!
            model.attivaStrumento(itemSelezionato);
            aggiornaGrafica(); // Se va a buon fine, ridisegniamo la View aggiornata
            view.mostraDettagli(itemSelezionato);
        } catch (GearException ex) {
            // CATTURA ECCEZIONE BACKEND: Mostriamo l'alert nativo di errore!
            mostraAlertErrore(ex.getMessage());
        }
    }

    private void ordinaListaPerEfficienza() {
        // Ordiniamo la lista usando il Comparator esterno
        listaModello.sort(new OrdinatoreEfficienza());
        aggiornaGrafica();
    }

    private void aggiornaGrafica() {
        // Ripopoliamo la lista passando il click handler per gli oggetti
        this.view.popolaLista(listaModello, this::gestisciSelezioneItem);
    }

    // STRUTTURA ALERT RICHIESTA ALL'ESAME
    private void mostraAlertErrore(String messaggio) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("Errore di Equipaggiamento");
        alert.setHeaderText("Azione non consentita");
        alert.setContentText(messaggio);
        alert.showAndWait(); // Blocca l'app finché l'utente non preme "OK"
    }
}