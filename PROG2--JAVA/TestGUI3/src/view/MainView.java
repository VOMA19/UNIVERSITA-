package view;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.layout.StackPane;
import java.util.ArrayList;
import item.Item;

public class MainView extends VBox {
    // Prima parte: Inventario
    private final HBox rigaComuni = new HBox(10);
    private final HBox rigaRari = new HBox(10);
    private final VBox sezioneInventario = new VBox(5); // Separazione di 5px tra righe [6]

    // Seconda parte: Equipaggiamento [6]
    private final Label lblOggettiRimanenti = new Label("Oggetti rimanenti: 5");
    private final HBox rigaEquipaggiamento = new HBox(10);
    private final VBox sezioneEquipaggiamento = new VBox(10);

    // Terza parte: Inserimento codici segreti [6]
    private final HBox rigaCodici = new HBox(10);
    private final Button btnStart = new Button("Start");
    private final Button btnW = new Button("W");
    private final Button btnA = new Button("A");
    private final Button btnS = new Button("S");
    private final Button btnD = new Button("D");
    private final Label lblCodiceSchermo = new Label("Sequenza inserita: ");

    public MainView() {
        super(20); // Separazione di 20px tra le tre parti principali [6]
        this.setPadding(new Insets(15));
        this.setAlignment(Pos.CENTER);

        // 1. Configurazione Inventario
        rigaComuni.setAlignment(Pos.CENTER);
        rigaRari.setAlignment(Pos.CENTER);
        sezioneInventario.getChildren().addAll(rigaComuni, rigaRari);
        sezioneInventario.setAlignment(Pos.CENTER);

        // 2. Configurazione Equipaggiamento
        lblOggettiRimanenti.setStyle("-fx-font-weight: bold; -fx-font-size: 13px;");
        rigaEquipaggiamento.setAlignment(Pos.CENTER);
        sezioneEquipaggiamento.getChildren().addAll(lblOggettiRimanenti, rigaEquipaggiamento);
        sezioneEquipaggiamento.setAlignment(Pos.CENTER);

        // 3. Configurazione Sezione Codici
        rigaCodici.getChildren().addAll(btnStart, btnW, btnA, btnS, btnD);
        rigaCodici.setAlignment(Pos.CENTER);
        lblCodiceSchermo.setStyle("-fx-font-size: 11px; -fx-text-fill: blue;");

        // Disabilitiamo le lettere all'inizio [3]
        setLettereDisabilitate(true);

        this.getChildren().addAll(sezioneInventario, sezioneEquipaggiamento, rigaCodici, lblCodiceSchermo);
    }

    public void setLettereDisabilitate(boolean disabilitate) {
        btnW.setDisable(disabilitate);
        btnA.setDisable(disabilitate);
        btnS.setDisable(disabilitate);
        btnD.setDisable(disabilitate);
    }

    public void popolaInventario(ArrayList<Item> comuni, ArrayList<Item> rari,
                                 javafx.event.EventHandler<javafx.scene.input.MouseEvent> clickHandler) {
        rigaComuni.getChildren().clear();
        rigaRari.getChildren().clear();

        for (Item item : comuni) {
            ItemView iv = new ItemView(item);
            iv.addEventHandler(javafx.scene.input.MouseEvent.MOUSE_CLICKED, clickHandler);
            rigaComuni.getChildren().add(iv);
        }

        for (Item item : rari) {
            ItemView iv = new ItemView(item);
            iv.addEventHandler(javafx.scene.input.MouseEvent.MOUSE_CLICKED, clickHandler);
            rigaRari.getChildren().add(iv);
        }
    }

    public void aggiornaEquipaggiamento(ArrayList<Item> equipaggiati, int spazioRimanente) {
        rigaEquipaggiamento.getChildren().clear();
        lblOggettiRimanenti.setText("Oggetti rimanenti: " + spazioRimanente);

        for (Item item : equipaggiati) {
            // Un oggetto equipaggiato si mostra senza ammontare sotto [6]
            Rectangle rect = new Rectangle(80, 80);
            rect.setStroke(Color.BLACK);
            rect.setStrokeWidth(3);
            rect.setFill(Color.LIGHTGRAY);
            Label lbl = new Label(item.getNome());
            lbl.setStyle("-fx-font-weight: bold; -fx-text-fill: black;");
            StackPane cella = new StackPane(rect, lbl);
            rigaEquipaggiamento.getChildren().add(cella);
        }
    }

    public void aggiornaCodiceSchermo(String sequenza) {
        lblCodiceSchermo.setText("Sequenza inserita: " + sequenza);
    }

    public Button getBtnStart() { return btnStart; }
    public Button getBtnW() { return btnW; }
    public Button getBtnA() { return btnA; }
    public Button getBtnS() { return btnS; }
    public Button getBtnD() { return btnD; }
}