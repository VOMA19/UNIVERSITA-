import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

import java.util.ArrayList;

public class MainApp extends Application {

    @Override
    public void start(Stage primaryStage) {

        // --- 0. LISTA DI SUPPORTO PER IL RESET DINAMICO ---
        // Questa lista tiene traccia di tutti i rettangoli presenti a schermo
        ArrayList<Rectangle> tuttiIRettangoli = new ArrayList<>();


        // --- 1. CREAZIONE COMPONENTI INIZIALI (Mattoncini Grafici) ---

        // Strumento 1: Spada di Ferro
        Rectangle rettangolo1 = new Rectangle(150, 40);
        rettangolo1.setStroke(Color.BLACK);
        rettangolo1.setFill(Color.LIGHTGRAY);
        tuttiIRettangoli.add(rettangolo1); // REGISTRIAMO IL RETTANGOLO
        Label label1 = new Label("Spada di Ferro");
        StackPane cellaSpada = new StackPane(rettangolo1, label1);

        // Strumento 2: Scudo di Legno
        Rectangle rettangolo2 = new Rectangle(150, 40);
        rettangolo2.setStroke(Color.BLACK);
        rettangolo2.setFill(Color.LIGHTGRAY);
        tuttiIRettangoli.add(rettangolo2); // REGISTRIAMO IL RETTANGOLO
        Label label2 = new Label("Scudo di Legno");
        StackPane cellaScudo = new StackPane(rettangolo2, label2);

        // Zona Dettagli (Centro dello schermo)
        Label dettagliCentro = new Label("Nessun elemento selezionato");
        dettagliCentro.setStyle("-fx-font-size: 14px; -fx-font-weight: bold;");

        // Barra di Inserimento (In fondo allo schermo)
        HBox barraBottom = new HBox(10); // Spazio di 10px tra TextField e Bottone
        barraBottom.setPadding(new Insets(10));
        barraBottom.setAlignment(Pos.CENTER);

        TextField aggiuntaArma = new TextField();
        aggiuntaArma.setPromptText("Nome nuova arma...");
        Button btnAggiungi = new Button("AGGIUNGI ARMA");

        barraBottom.getChildren().addAll(aggiuntaArma, btnAggiungi);


        // --- 2. DEFINIZIONE DELLE AZIONI DEI COMPONENTI INIZIALI ---

        // Click sulla Spada di Ferro
        cellaSpada.setOnMouseClicked(e -> {
            dettagliCentro.setText("Hai selezionato: Spada di Ferro");
            dettagliCentro.setTextFill(Color.BLACK); // Reset colore a nero (in caso di precedenti errori)

            // Ciclo per spegnere TUTTI i rettangoli registrati
            for (Rectangle r : tuttiIRettangoli) {
                r.setFill(Color.LIGHTGRAY);
            }
            // Accendiamo solo quello cliccato
            rettangolo1.setFill(Color.LIGHTBLUE);
        });

        // Click sullo Scudo di Legno
        cellaScudo.setOnMouseClicked(e -> {
            dettagliCentro.setText("Hai selezionato: Scudo di Legno");
            dettagliCentro.setTextFill(Color.BLACK);

            // Spegniamo tutti i rettangoli
            for (Rectangle r : tuttiIRettangoli) {
                r.setFill(Color.LIGHTGRAY);
            }
            // Accendiamo solo questo
            rettangolo2.setFill(Color.LIGHTBLUE);
        });


        // --- 3. CREAZIONE LAYOUT E POSIZIONAMENTO ---

        // Colonna di sinistra (conterrà i nostri mattoncini grafici)
        VBox menuSinistra = new VBox(10);
        menuSinistra.setPadding(new Insets(15));
        menuSinistra.getChildren().addAll(cellaSpada, cellaScudo);

        // BorderPane globale
        BorderPane layoutPrincipale = new BorderPane();
        layoutPrincipale.setLeft(menuSinistra);
        layoutPrincipale.setCenter(dettagliCentro);
        layoutPrincipale.setBottom(barraBottom);


        // --- 4. AZIONE DI AGGIUNTA DINAMICA (IL BOTTONE) ---

        btnAggiungi.setOnAction(e -> {
            String nomeInput = aggiuntaArma.getText().trim();

            if (nomeInput.isEmpty()) {
                // Gestione Errore: testo rosso
                dettagliCentro.setText("ERRORE: Inserisci un nome valido!");
                dettagliCentro.setTextFill(Color.RED);
            } else {
                // Creiamo il nuovo mattoncino grafico
                Rectangle rettangoloNuovo = new Rectangle(150, 40);
                rettangoloNuovo.setStroke(Color.BLACK);
                rettangoloNuovo.setFill(Color.LIGHTGRAY);

                // Registriamo il nuovo rettangolo nella lista globale!
                tuttiIRettangoli.add(rettangoloNuovo);

                Label labelNuova = new Label(nomeInput);
                StackPane cellaNuova = new StackPane(rettangoloNuovo, labelNuova);

                // Aggiungiamo SOLO la nuova cella alla colonna di sinistra (Nessun duplicato!)
                menuSinistra.getChildren().add(cellaNuova);

                // Definiamo il comportamento del click sul nuovo elemento a runtime
                cellaNuova.setOnMouseClicked(e2 -> {
                    dettagliCentro.setText("Hai selezionato: " + labelNuova.getText());
                    dettagliCentro.setTextFill(Color.BLACK);

                    // Spegniamo TUTTI i rettangoli (anche questo nuovo e quelli futuri!)
                    for (Rectangle r : tuttiIRettangoli) {
                        r.setFill(Color.LIGHTGRAY);
                    }
                    // Accendiamo questo specifico rettangolo appena cliccato
                    rettangoloNuovo.setFill(Color.LIGHTBLUE);
                });
            }
            // Svuotiamo il campo di testo per l'inserimento successivo
            aggiuntaArma.clear();
        });


        // --- 5. ACCENSIONE FINESTRA ---
        Scene scena = new Scene(layoutPrincipale, 550, 350); // Risoluzione comoda
        primaryStage.setTitle("Playground JavaFX - Sfida 2 Superata!");
        primaryStage.setScene(scena);
        primaryStage.show();
    }
}