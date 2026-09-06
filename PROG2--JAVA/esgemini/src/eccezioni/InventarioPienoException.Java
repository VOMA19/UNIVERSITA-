package src.eccezioni;

public class InventarioPienoException extends Exception {
    public InventarioPienoException(String message) {
        super(message);
    }
}