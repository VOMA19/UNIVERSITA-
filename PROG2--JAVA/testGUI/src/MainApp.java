import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

public class MainApp extends Application {

    @Override
    public void start(Stage primaryStage) {
        // --- 1. CREAZIONE COMPONENTI (Mattoncini Grafici) ---

        // Strumento 1: Spada di Ferro (Rettangolo sotto + Scritta sopra)
        Rectangle rettangolo1 = new Rectangle(150, 40);
        rettangolo1.setStroke(Color.BLACK);
        rettangolo1.setFill(Color.LIGHTGRAY); // Colore iniziale grigio
        Label label1 = new Label("Spada di Ferro");

        // Lo StackPane sovrappone: il primo elemento va sotto, il secondo sopra
        StackPane cellaSpada = new StackPane(rettangolo1, label1);

        // Strumento 2: Scudo di Legno
        Rectangle rettangolo2 = new Rectangle(150, 40);
        rettangolo2.setStroke(Color.BLACK);
        rettangolo2.setFill(Color.LIGHTGRAY);
        Label label2 = new Label("Scudo di Legno");

        StackPane cellaScudo = new StackPane(rettangolo2, label2);

        // Zona Dettagli (Centro dello schermo)
        Label dettagliCentro = new Label("Nessun elemento selezionato");
        dettagliCentro.setStyle("-fx-font-size: 14px; -fx-font-weight: bold;");


        // --- 2. DEFINIZIONE DELLE AZIONI (Event Handling) ---

        // Gestiamo il click del mouse direttamente sullo StackPane della Spada
        cellaSpada.setOnMouseClicked(e -> {
            // Usiamo le parentesi graffe { } per eseguire più azioni insieme!
            dettagliCentro.setText("Hai selezionato: Spada di Ferro");
            rettangolo1.setFill(Color.LIGHTBLUE); // Diventa azzurro (selezionato)
            rettangolo2.setFill(Color.LIGHTGRAY); // Lo scudo torna grigio
        });

        // Gestiamo il click del mouse sullo StackPane dello Scudo
        cellaScudo.setOnMouseClicked(e -> {
            dettagliCentro.setText("Hai selezionato: Scudo di Legno");
            rettangolo2.setFill(Color.LIGHTBLUE); // Diventa azzurro (selezionato)
            rettangolo1.setFill(Color.LIGHTGRAY); // La spada torna grigio
        });


        // --- 3. CREAZIONE LAYOUT E POSIZIONAMENTO ---

        // Creiamo la colonna di sinistra e ci infiliamo solo i due mattoncini
        VBox menuSinistra = new VBox(10);
        menuSinistra.setPadding(new Insets(15)); // Un po' di margine interno
        menuSinistra.getChildren().addAll(cellaSpada, cellaScudo);

        // Creiamo il BorderPane globale
        BorderPane layoutPrincipale = new BorderPane();

        // Posizioniamo la colonna a sinistra e la label dei dettagli al centro
        layoutPrincipale.setLeft(menuSinistra);
        layoutPrincipale.setCenter(dettagliCentro);


        // --- 4. ACCENSIONE SCHERMO ---

        // Passiamo il BorderPane (layoutPrincipale) come radice della scena
        Scene scena = new Scene(layoutPrincipale, 500, 300); // Finestra 500x300 pixel

        primaryStage.setTitle("Playground JavaFX - Sfida 1 Superata!");
        primaryStage.setScene(scena);
        primaryStage.show();
    }
}