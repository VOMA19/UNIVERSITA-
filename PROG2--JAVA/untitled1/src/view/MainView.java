package view;

import item.Item;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;

import java.util.ArrayList;

public class MainView extends BorderPane {
    // 1. Scatole vuote strutturali
    private final VBox colonnaBaule = new VBox(8);         // Conterrà gli elementi a sinistra
    private final VBox colonnaEquipaggiamento = new VBox(8); // Conterrà gli elementi al centro
    private final HBox barraBottoni = new HBox(15);         // Conterrà i 3 bottoni in basso

    // 2. Elementi grafici reali
    private final Label lblPeso = new Label();
    private final Button btnEquipaggia = new Button("EQUIPAGGIA");
    private final Button btnRipara = new Button("RIPARA");
    private final Button btnOrdina = new Button("ORDINA BAULE");

    public MainView() {
        // Spaziatura interna generale della finestra
        this.setPadding(new Insets(15));

        // --- SEZIONE TOP: Il Peso ---
        lblPeso.setStyle("-fx-font-size: 15px; -fx-font-weight: bold; -fx-text-fill: #2c3e50;");
        HBox contenitorePeso = new HBox(lblPeso);
        contenitorePeso.setAlignment(Pos.CENTER);
        contenitorePeso.setPadding(new Insets(0, 0, 15, 0));
        this.setTop(contenitorePeso); // Agganciamo la scritta in alto!

        // --- SEZIONE LEFT: Il Baule di partenza ---
        colonnaBaule.setPadding(new Insets(10));
        colonnaBaule.setPrefWidth(180);
        colonnaBaule.setStyle("-fx-border-color: #bdc3c7; -fx-border-width: 2px; -fx-border-radius: 5px;");

        VBox layoutBauleCompleto = new VBox(5, new Label("🎒 BAULE DI PARTENZA"), colonnaBaule);
        layoutBauleCompleto.setAlignment(Pos.TOP_CENTER);
        this.setLeft(layoutBauleCompleto); // Incastriamo a sinistra!

        // --- SEZIONE CENTER: L'Equipaggiamento ---
        colonnaEquipaggiamento.setPadding(new Insets(10));
        colonnaEquipaggiamento.setPrefWidth(180);
        colonnaEquipaggiamento.setStyle("-fx-border-color: #bdc3c7; -fx-border-width: 2px; -fx-border-radius: 5px;");

        VBox layoutEquipCompleto = new VBox(5, new Label("⚔️ EQUIPAGGIATO"), colonnaEquipaggiamento);
        layoutEquipCompleto.setAlignment(Pos.TOP_CENTER);
        this.setCenter(layoutEquipCompleto); // Incastriamo al centro!

        // --- SEZIONE BOTTOM: La Pulsantiera ---
        barraBottoni.setAlignment(Pos.CENTER);
        barraBottoni.setPadding(new Insets(15, 0, 0, 0));
        barraBottoni.getChildren().addAll(btnEquipaggia, btnRipara, btnOrdina);
        this.setBottom(barraBottoni); // Incastriamo in basso!
    }

    /**
     * Chiamato dal Controller per ridisegnare la colonna di sinistra (Baule)
     */
    public void aggiornaListaBaule(ArrayList<Item> elementi, Item selezionato, javafx.event.EventHandler<MouseEvent> clickHandler) {
        colonnaBaule.getChildren().clear(); // Svuotiamo il vecchio disegno!

        for (Item item : elementi) {
            // Controlliamo se questo specifico oggetto è quello cliccato
            boolean isSelected = (item == selezionato);

            // Creiamo il mattoncino grafico
            ItemView cella = new ItemView(item, isSelected);

            // Gli appiccichiamo la capacità di sentire il click gestito dal Controller
            cella.setOnMouseClicked(clickHandler);

            // Lo infiliamo nella colonna visibile
            colonnaBaule.getChildren().add(cella);
        }
    }

    /**
     * Chiamato dal Controller per ridisegnare la colonna centrale (Equipaggiamento)
     */
    public void aggiornaListaEquipaggiamento(ArrayList<Item> elementi, Item selezionato, javafx.event.EventHandler<MouseEvent> clickHandler) {
        colonnaEquipaggiamento.getChildren().clear(); // Svuotiamo!

        for (Item item : elementi) {
            boolean isSelected = (item == selezionato);
            ItemView cella = new ItemView(item, isSelected);
            cella.setOnMouseClicked(clickHandler);
            colonnaEquipaggiamento.getChildren().add(cella);
        }
    }

    /**
     * Chiamato dal Controller per aggiornare i numeri del peso in cima
     */
    public void aggiornaScrittaPeso(double attuale, double massimo) {
        lblPeso.setText(String.format("Peso Geraldo: %.1f / %.1f Kg", attuale, massimo));
    }

    // --- I GETTER PER IL CONTROLLER ---
    // Ricorda: il Controller non può accedere direttamente alle variabili private della View, usa questi!
    public Button getBtnEquipaggia() { return btnEquipaggia; }
    public Button getBtnRipara() { return btnRipara; }
    public Button getBtnOrdina() { return btnOrdina; }
}
