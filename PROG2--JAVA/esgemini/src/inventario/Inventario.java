package src.inventario;

import java.util.ArrayList;
import src.eccezioni.GearException;
import src.eccezioni.InventarioPienoException;
import src.item.Item;

public class Inventario {
    private ArrayList<Item> listaGear = new ArrayList<>();
    private final int maxSlot;

    public Inventario(int maxSlot) {
        this.maxSlot = maxSlot;
    }

    // Calcola la somma dell'ingombro di tutti gli oggetti presenti
    public int getIngombroAttuale() {
        int somma = 0;
        for (Item i : listaGear) {
            somma += i.getIngombro();
        }
        return somma;
    }

    public void aggiungiItem(Item item) throws InventarioPienoException {
        // Invariante: lo spazio occupato + lo spazio del nuovo oggetto non deve superare il massimo
        if (getIngombroAttuale() + item.getIngombro() <= maxSlot) {
            listaGear.add(item);
            System.out.println(item.getNome() + " inserito nello zaino.");
        } else {
            throw new InventarioPienoException(
                "Spazio insufficiente! Richiesti: " + item.getIngombro() +
                " slot. Disponibili: " + (maxSlot - getIngombroAttuale()) + " slot."
            );
        }
    }

    // Polimorfismo puro: non sappiamo se è raro o comune, chiamiamo e basta!
    public void attivaStrumento(Item item) throws GearException {
        item.attiva();
    }
}
