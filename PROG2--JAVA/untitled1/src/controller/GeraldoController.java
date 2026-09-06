package controller;

import eccezioni.GeraldoException;
import eccezioni.KitEsauritiException;
import eccezioni.PesoMassimoSuperatoException;
import inventario.InventarioGeraldo;
import item.Arma;
import item.Item;
import item.KitRiparazione;
import item.Riparabile;
import javafx.scene.control.Alert;
import javafx.scene.input.MouseEvent;
import view.ItemView;
import view.MainView;

import java.util.ArrayList;
import java.util.Collections;

public class GeraldoController {
    private final InventarioGeraldo model; // I dati logici
    private final MainView view;           // La finestra grafica
    private final ArrayList<Item> baule;   // La lista degli oggetti nel baule a sinistra

    // Variabili di stato: teniamo traccia di quale oggetto è attualmente cliccato
    private Item itemSelezionatoBaule = null;
    private Item itemSelezionatoEquip = null;

    public GeraldoController(InventarioGeraldo model, MainView view, ArrayList<Item> bauleIniziale) {
        this.model = model;
        this.view = view;
        this.baule = bauleIniziale;

        // --- COLLEGAMENTO DEGLI EVENTI ---
        // 1. Chiediamo alla View i suoi bottoni (tramite i getter) e gli colleghiamo un'azione
        this.view.getBtnEquipaggia().setOnAction(e -> gestisciEquipaggia());
        this.view.getBtnRipara().setOnAction(e -> gestisciRipara());
        this.view.getBtnOrdina().setOnAction(e -> gestisciOrdina());

        // 2. Disegniamo per la prima volta l'interfaccia con i dati iniziali
        aggiornaGrafica();
    }

    /**
     * Viene eseguito quando l'utente clicca su un oggetto nel Baule di sinistra
     */
    private void gestisciClickBaule(MouseEvent event) {
        // Recuperiamo la cella grafica che ha subito il click
        ItemView cellaCliccata = (ItemView) event.getSource();

        // Estraiamo l'oggetto logico associato a quella cella
        this.itemSelezionatoBaule = cellaCliccata.getModelItem();

        // Se sto selezionando a sinistra, deseleziono quello al centro per chiarezza
        this.itemSelezionatoEquip = null;

        // Ridisegnamo lo schermo per mostrare il bordo di selezione blu!
        aggiornaGrafica();
    }

    /**
     * Viene eseguito quando l'utente clicca su un oggetto già equipaggiato al centro
     */
    private void gestisciClickEquip(MouseEvent event) {
        ItemView cellaCliccata = (ItemView) event.getSource();
        this.itemSelezionatoEquip = cellaCliccata.getModelItem();

        // Deseleziono a sinistra
        this.itemSelezionatoBaule = null;

        aggiornaGrafica();
    }

    /**
     * AZIONE: EQUIPAGGIA L'OGGETTO SELEZIONATO
     */
    private void gestisciEquipaggia() {
        if (itemSelezionatoBaule == null) {
            mostraAlert(Alert.AlertType.WARNING, "Selezione mancante", "Attenzione", "Seleziona prima un oggetto dal baule!");
            return;
        }

        try {
            // Chiediamo al Model (InventarioGeraldo) di equipaggiare l'oggetto
            model.equipaggia(itemSelezionatoBaule);

            // Se il Model NON lancia eccezioni, l'azione è andata a buon fine:
            // Rimuoviamo l'oggetto dal baule di sinistra e svuotiamo la selezione
            baule.remove(itemSelezionatoBaule);
            itemSelezionatoBaule = null;

            // Diciamo alla View di aggiornare la schermata
            aggiornaGrafica();

        } catch (PesoMassimoSuperatoException ex) {
            // Se Geraldo supera il peso, il Model spara l'eccezione checked.
            // Il Controller la cattura e la trasforma in un popup di errore grafico!
            mostraAlert(Alert.AlertType.ERROR, "Errore Peso", "Geraldo non ce la fa!", ex.getMessage());
        }
    }

    /**
     * AZIONE: RIPARA L'ARMA SELEZIONATA AL CENTRO
     */
    private void gestisciRipara() {
        if (itemSelezionatoEquip == null) {
            mostraAlert(Alert.AlertType.WARNING, "Selezione mancante", "Attenzione", "Seleziona un'arma equipaggiata per ripararla!");
            return;
        }

        // Controllo di sicurezza: l'oggetto selezionato è un'Arma (implementa Riparabile)?
        if (!(itemSelezionatoEquip instanceof Riparabile)) {
            mostraAlert(Alert.AlertType.ERROR, "Impossibile Riparare", "Oggetto non valido", "Solo le armi possono essere riparate!");
            return;
        }

        Riparabile arma = (Riparabile) itemSelezionatoEquip;

        try {
            // 1. Chiediamo al Model di cercare un kit con cariche libere nell'equipaggiamento
            KitRiparazione kit = model.trovaKitDisponibile();

            // 2. Se lo trova, consumiamo una carica del kit
            kit.usaCarica();

            // 3. Ripariamo l'arma
            arma.ripara();

            // 4. Mostriamo un popup informativo di successo
            mostraAlert(Alert.AlertType.INFORMATION, "Successo", "Arma riparata!", "L'integrità è aumentata del 30%!");

            aggiornaGrafica();

        } catch (GeraldoException ex) {
            // Catturiamo gli errori del backend (es. kit finiti o arma già al 100%) e li mostriamo a schermo
            mostraAlert(Alert.AlertType.ERROR, "Errore Riparazione", "Riparazione annullata", ex.getMessage());
        }
    }

    /**
     * AZIONE: ORDINA IL BAULE
     */
    private void gestisciOrdina() {
        // Sfrutta il compareTo implementato nel Model (Item.java) per ordinare alfabeticamente
        Collections.sort(baule);
        aggiornaGrafica();
    }

    /**
     * IL SINCRONIZZATORE: Svuota e ridisegna tutto basandosi sullo stato attuale del Model
     */
    private void aggiornaGrafica() {
        // Diciamo alla View di ridisegnare la lista del baule
        view.aggiornaListaBaule(this.baule, this.itemSelezionatoBaule, this::gestisciClickBaule);

        // Diciamo alla View di ridisegnare la lista dell'equipaggiamento
        view.aggiornaListaEquipaggiamento(model.getEquipaggiamento(), this.itemSelezionatoEquip, this::gestisciClickEquip);

        // Chiediamo alla View di aggiornare la scritta del peso
        view.aggiornaScrittaPeso(model.getPesoAttuale(), model.getPesoMassimo());
    }

    /**
     * Funzione comoda per aprire al volo un Alert di JavaFX
     */
    private void mostraAlert(Alert.AlertType tipo, String titolo, String intestazione, String contenuto) {
        Alert alert = new Alert(tipo);
        alert.setTitle(titolo);
        alert.setHeaderText(intestazione);
        alert.setContentText(contenuto);
        alert.showAndWait();
    }
}