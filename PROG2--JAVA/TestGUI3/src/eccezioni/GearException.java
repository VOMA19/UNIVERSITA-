package eccezioni;

// Eccezione checked padre di tutte le anomalie dell'inventario
public class GearException extends Exception {
    public GearException(String message) {
        super(message);
    }
}