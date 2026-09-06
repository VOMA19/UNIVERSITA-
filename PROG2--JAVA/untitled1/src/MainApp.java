import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import controller.GeraldoController;
import inventario.InventarioGeraldo;
import item.*;
import view.MainView;

import java.util.ArrayList;

public class MainApp extends Application {

    @Override
    public void start(Stage primaryStage) {
        // 1. Creiamo il Modello (Geraldo ha un limite di 30.0 Kg)
        InventarioGeraldo model = new InventarioGeraldo(30.0);

        // 2. Creiamo una lista fittizia di oggetti presenti nel baule all'inizio del gioco
        ArrayList<Item> baulePartenza = new ArrayList<>();

        baulePartenza.add(new Arma("Spada dell'Orso", 12.0, 45));       // Gialla (integrità 45)
        baulePartenza.add(new Arma("Spada d'Argento", 8.5, 95));        // Verde (integrità 95)
        baulePartenza.add(new Arma("Daga Arrugginita", 4.0, 0));        // Rossa (rotta, integrità 0)
        baulePartenza.add(new Armatura("Gabbana Leggera", 14.5, 30));   // Celeste
        baulePartenza.add(new KitRiparazione("Kit dello Strigo", 3.0, 3)); // Arancione (3 usi)
        baulePartenza.add(new KitRiparazione("Olio Lubrificante", 1.5, 1)); // Arancione (1 uso)

        // 3. Creiamo la Scenografia Grafica (View) vuota
        MainView view = new MainView();

        // 4. Creiamo il Controller passandogli Model, View e la lista di partenza
        GeraldoController controller = new GeraldoController(model, view, baulePartenza);

        // 5. Inseriamo la View nella scena e mostriamo la finestra a schermo
        Scene scena = new Scene(view, 450, 520);
        primaryStage.setTitle("Equip Geraldo - Witcher Inventory Management");
        primaryStage.setScene(scena);
        primaryStage.show();
    }
}