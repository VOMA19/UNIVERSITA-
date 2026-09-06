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

        // Disegniamo lo strumento come un rettangolo
        Rectangle sfondo = new Rectangle(150, 40);
        sfondo.setStroke(Color.BLACK);

        // Coloriamo lo sfondo del rettangolo in base all'efficienza
        if (item.getEfficienza() <= 0.0) {
            sfondo.setFill(Color.TOMATO); // Rosso se rotto/esaurito
        } else {
            sfondo.setFill(Color.LIGHTGREEN); // Verde se utilizzabile
        }

        // Testo con il nome e l'efficienza in percentuale
        Label etichetta = new Label(item.getNome() + " (" + (int)(item.getEfficienza() * 100) + "%)");
        etichetta.setTextFill(Color.BLACK);

        // Aggiungiamo sfondo e testo allo StackPane
        this.getChildren().addAll(sfondo, etichetta);
    }

    public Item getModelItem() {
        return modelItem;
    }
}
