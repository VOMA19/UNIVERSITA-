package eccezioni;

public class NotEnoughAmtInInventoryException extends GearException {
    public NotEnoughAmtInInventoryException(String message) {
        super(message);
    }
}