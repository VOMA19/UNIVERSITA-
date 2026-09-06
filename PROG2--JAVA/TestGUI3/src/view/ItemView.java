package view;

import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import item.Item;

public class ItemView extends StackPane {
    private final Item modelItem;

    public ItemView(Item item) {
        this.modelItem = item;
        this.setAlignment(Pos.CENTER);

        // Rettangolo di lato 80px con un bordo di 3px BLACK [3]
        Rectangle sfondo = new Rectangle(80, 80);
        sfondo.setStroke(Color.BLACK);
        sfondo.setStrokeWidth(3);

        // Se sbloccato LIGHTGRAY, altrimenti DARKGRAY [3]
        if (item.isSbloccato()) {
            sfondo.setFill(Color.LIGHTGRAY);
        } else {
            sfondo.setFill(Color.DARKGRAY);
        }

        // Testo centrale: Nome dell'oggetto + ammontare [3]
        Label etichetta = new Label(item.getNome() + "\n" + item.getAmmontare());
        etichetta.setStyle("-fx-text-alignment: center; -fx-font-weight: bold; -fx-text-fill: black;");

        this.getChildren().addAll(sfondo, etichetta);
    }

    public Item getModelItem() {
        return modelItem;
    }
}