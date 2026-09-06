package controller;

import javafx.scene.control.Alert;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import eccezioni.*;
import inventario.Inventario;
import item.Item;
import view.ItemView;
import view.MainView;

public class GearController {
    private final Inventario model;
    private final MainView view;
    private final StringBuilder sequenzaCodice = new StringBuilder();
    private boolean inserimentoAttivo = false;

    public GearController(Inventario model, MainView view) {
        this.model = model;
        this.view = view;

        // Disegniamo l'inventario all'avvio
        aggiornaGrafica();

        // Colleghiamo i pulsanti fisici a schermo
        this.view.getBtnStart().setOnAction(e -> avviaCodice());
        this.view.getBtnW().setOnAction(e -> immettiLettera("W"));
        this.view.getBtnA().setOnAction(e -> immettiLettera("A"));
        this.view.getBtnS().setOnAction(e -> immettiLettera("S"));
        this.view.getBtnD().setOnAction(e -> immettiLettera("D"));
    }

    private void gestisciClickOggetto(MouseEvent event) {
        ItemView cellaCliccata = (ItemView) event.getSource();
        Item item = cellaCliccata.getModelItem();

        try {
            model.equipaggiaItem(item);
            aggiornaGrafica();
        } catch (GearException ex) {
            // Mostriamo l'Alert di tipo ERROR catturato dal backend! [3]
            mostraAlertErrore("Azione non consentita", "Impossibile equipaggiare l'oggetto", ex.getMessage());
        }
    }

    private void avviaCodice() {
        inserimentoAttivo = true;
        sequenzaCodice.setLength(0); // Pulisce
        view.aggiornaCodiceSchermo("");
        view.getBtnStart().setDisable(true); // Disabilita Start [3]
        view.setLettereDisabilitate(false);  // Abilita lettere [3]
    }

    private void immettiLettera(String lettera) {
        if (!inserimentoAttivo) return;

        sequenzaCodice.append(lettera);
        view.aggiornaCodiceSchermo(sequenzaCodice.toString());

        // Se abbiamo digitato 3 lettere, valutiamo il codice [5]
        if (sequenzaCodice.length() == 3) {
            applicaCheatCode(sequenzaCodice.toString());
        }
    }

    // Gestore per la tastiera fisica (richiesta dal testo d'esame!) [3]
    public void gestisciTastiera(KeyEvent event) {
        if (!inserimentoAttivo) return;

        KeyCode tasto = event.getCode();
        if (tasto == KeyCode.W) immettiLettera("W");
        else if (tasto == KeyCode.A) immettiLettera("A");
        else if (tasto == KeyCode.S) immettiLettera("S");
        else if (tasto == KeyCode.D) immettiLettera("D");
    }

    private void applicaCheatCode(String codice) {
        boolean codiceValido = false;

        if (codice.equals("DDA")) {
            model.cheatDDA();
            codiceValido = true;
        } else if (codice.equals("DDS")) {
            model.cheatDDS();
            codiceValido = true;
        } else if (codice.equals("DWA")) {
            model.cheatDWA();
            codiceValido = true;
        }

        if (codiceValido) {
            aggiornaGrafica();
        } else {
            // Se la sequenza di 3 lettere è errata, Alert! [3]
            mostraAlertErrore("Codice Errato", "Sequenza non riconosciuta", "Il codice " + codice + " non esiste!");
        }

        resettaStatoCodici();
    }

    private void resettaStatoCodici() {
        inserimentoAttivo = false;
        sequenzaCodice.setLength(0);
        view.aggiornaCodiceSchermo("");
        view.getBtnStart().setDisable(false);
        view.setLettereDisabilitate(true);
    }

    private void aggiornaGrafica() {
        this.view.popolaInventario(model.getComuni(), model.getRari(), this::gestisciClickOggetto);
        this.view.aggiornaEquipaggiamento(model.getEquipaggiamento(), model.getSpazioRimanente());
    }

    private void mostraAlertErrore(String titolo, String intestazione, String messaggio) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle(titolo);
        alert.setHeaderText(intestazione);
        alert.setContentText(messaggio);
        alert.showAndWait();
    }
}