import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import controller.GearController;
import inventario.Inventario;
import item.*;
import view.MainView;
import java.util.ArrayList;

public class MainApp extends Application {

    @Override
    public void start(Stage primaryStage) {
        // 1. Inizializziamo il modello di dati dell'inventario
        Inventario zaino = new Inventario(10);
        ArrayList<Item> listaElementi = new ArrayList<>();

        // Oggetti di prova iniziali
        listaElementi.add(new StrumentoComune("Shuriken", 1, 2, 2));
        listaElementi.add(new ArmaRara("Rampino d'Acciaio", 3, 0.8, 50));

        // 2. Prepariamo l'interfaccia grafica (View)
        MainView gui = new MainView();

        // 3. Colleghiamo il Controller per mediare tra grafica e dati
        new GearController(zaino, gui, listaElementi);

        // 4. Colleghiamo la scena al nostro layout principale
        Scene scena = new Scene(gui, 600, 400); // Finestra 600x400 pixel

        primaryStage.setTitle("Tenchu Ninja Gear - Simulazione Esame");
        primaryStage.setScene(scena);
        primaryStage.show(); // Mostra la finestra a schermo
    }
}
