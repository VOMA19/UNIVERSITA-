package view;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import java.util.ArrayList;
import item.Item;

public class MainView extends BorderPane {
    private final VBox listaSinistra = new VBox(10);
    private final VBox zonaCentrale = new VBox(10);
    private final Button btnAttiva = new Button("Attiva Strumento");
    private final Button btnOrdina = new Button("Ordina per Efficienza");

    public MainView() {
        this.setPadding(new Insets(15));

        // 1. Zona Sinistra: Titolo + Lista di ItemView
        Label lblLista = new Label("Ninja Gear:");
        listaSinistra.getChildren().add(lblLista);
        this.setLeft(listaSinistra);

        // 2. Zona Centrale: Dettagli dell'oggetto selezionato
        zonaCentrale.setAlignment(Pos.CENTER);
        zonaCentrale.getChildren().add(new Label("Seleziona uno strumento a sinistra"));
        this.setCenter(zonaCentrale);

        // 3. Zona Inferiore: Pulsantiera
        HBox pulsantiera = new HBox(15);
        pulsantiera.getChildren().addAll(btnAttiva, btnOrdina);
        this.setBottom(pulsantiera);
    }

    // Ricostruisce la lista di ItemView a sinistra ogni volta che i dati cambiano
    public void popolaLista(ArrayList<Item> items, javafx.event.EventHandler<javafx.scene.input.MouseEvent> clickHandler) {
        listaSinistra.getChildren().clear();
        listaSinistra.getChildren().add(new Label("Ninja Gear:"));

        for (Item item : items) {
            ItemView itemView = new ItemView(item);
            // Registriamo il click handler passato dal controller
            itemView.addEventHandler(javafx.scene.input.MouseEvent.MOUSE_CLICKED, clickHandler);
            listaSinistra.getChildren().add(itemView);
        }
    }

    // Mostra i dettagli dell'oggetto selezionato nella schermata centrale
    public void mostraDettagli(Item item) {
        zonaCentrale.getChildren().clear();
        if (item != null) {
            zonaCentrale.getChildren().addAll(
                    new Label("NOME: " + item.getNome()),
                    new Label("INGOMBRO: " + item.getIngombro() + " slot"),
                    new Label("EFFICIENZA: " + (int)(item.getEfficienza() * 100) + "%")
            );
        } else {
            zonaCentrale.getChildren().add(new Label("Nessuno strumento selezionato"));
        }
    }

    public Button getBtnAttiva() { return btnAttiva; }
    public Button getBtnOrdina() { return btnOrdina; }
}