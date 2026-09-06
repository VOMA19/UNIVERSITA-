import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import controller.GearController;
import inventario.Inventario;
import item.*;
import view.MainView;

public class MainApp extends Application {

    @Override
    public void start(Stage primaryStage) {
        // 1. Inizializziamo il Modello con i dati dell'esame [1]
        Inventario model = new Inventario();

        // Comuni sbloccati [1, 4]
        model.aggiungiComune(new StrumentoComune("Kunai", 7));
        model.aggiungiComune(new StrumentoComune("Riso", 2));
        model.aggiungiComune(new StrumentoComune("Fumo", 0));

        // Rari bloccati [1, 4]
        model.aggiungiRaro(new ArmaRara("Camicia", 0, false));
        model.aggiungiRaro(new ArmaRara("Armatura", 0, true)); // unica (max 1) [4]
        model.aggiungiRaro(new ArmaRara("Fuoco", 0, false));

        // 2. Prepariamo l'interfaccia grafica (View)
        MainView view = new MainView();

        // 3. Colleghiamo il Controller
        GearController controller = new GearController(model, view);

        // 4. Creiamo la scena
        Scene scena = new Scene(view, 400, 480);

        // Colleghiamo l'input da tastiera fisica per i codici segreti! [3]
        scena.setOnKeyPressed(controller::gestisciTastiera);

        primaryStage.setTitle("Tenchu 1 - Ninja Inventory");
        primaryStage.setScene(scena);
        primaryStage.show();
    }
}