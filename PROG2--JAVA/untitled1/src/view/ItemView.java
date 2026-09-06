package view;

import item.Arma;
import item.Armatura;
import item.Item;
import item.KitRiparazione;
import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class ItemView extends StackPane {
    private final Item modelItem; // L'oggetto logico che stiamo disegnando

    public ItemView(Item item, boolean isSelected) {
        this.modelItem = item;
        this.setAlignment(Pos.CENTER);

        // 1. Creiamo lo sfondo rettangolare
        Rectangle sfondo = new Rectangle(150, 50);

        // Se l'oggetto è selezionato facciamo il bordo blu spesso, altrimenti nero sottile
        sfondo.setStroke(isSelected ? Color.BLUE : Color.BLACK);
        sfondo.setStrokeWidth(isSelected ? 3.5 : 1.5);

        // 2. LOGICA DEI COLORI (La richiesta specifica d'esame)
        String dettagliInformazione = "";

        if (item instanceof Arma) {
            Arma arma = (Arma) item;
            int integrita = arma.getIntegrita();
            dettagliInformazione = " [Int: " + integrita + "%]";

            // Regola d'esame per l'integrità
            if (integrita > 70) {
                sfondo.setFill(Color.LIGHTGREEN);
            } else if (integrita > 0) {
                sfondo.setFill(Color.YELLOW);
            } else {
                sfondo.setFill(Color.RED);
            }

        } else if (item instanceof Armatura) {
            Armatura armatura = (Armatura) item;
            dettagliInformazione = " [Dif: " + armatura.getPuntiDifesa() + "]";
            sfondo.setFill(Color.LIGHTBLUE); // Celeste per l'armatura

        } else if (item instanceof KitRiparazione) {
            KitRiparazione kit = (KitRiparazione) item;
            dettagliInformazione = " [Usi: " + kit.getUsciteRimanenti() + "]";
            sfondo.setFill(Color.ORANGE); // Arancione per i kit
        }

        // 3. Creiamo la scritta con Nome, Peso e dettagli specifici
        Label etichettaScritta = new Label(item.getNome() + "\n" + item.getPeso() + " Kg" + dettagliInformazione);
        etichettaScritta.setStyle("-fx-text-alignment: center; -fx-font-size: 10px; -fx-font-weight: bold; -fx-text-fill: black;");

        // 4. Sovrapponiamo lo sfondo e la scritta
        this.getChildren().addAll(sfondo, etichettaScritta);
    }

    public Item getModelItem() {
        return modelItem;
    }
}