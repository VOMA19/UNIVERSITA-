package inventario;

import item.Item;
import eccezioni.*;
import java.util.ArrayList;
import java.util.Collections;

public class Inventario {
    private final ArrayList<Item> comuni = new ArrayList<>();
    private final ArrayList<Item> rari = new ArrayList<>();
    private final ArrayList<Item> equipaggiamento = new ArrayList<>();
    private int capienzaEquipaggiamento = 5; // Limite iniziale di 5 oggetti [5]

    public void aggiungiComune(Item i) {
        comuni.add(i);
        Collections.sort(comuni); // Mantiene la lista ordinata alfabeticamente [1]
    }

    public void aggiungiRaro(Item i) {
        rari.add(i);
        Collections.sort(rari); // Mantiene la lista ordinata alfabeticamente [1]
    }

    public ArrayList<Item> getComuni() {
        return comuni;
    }

    public ArrayList<Item> getRari() {
        return rari;
    }

    public ArrayList<Item> getEquipaggiamento() {
        return equipaggiamento;
    }

    public int getSpazioRimanente() {
        return capienzaEquipaggiamento - equipaggiamento.size();
    }

    // Tenta di equipaggiare un oggetto dall'inventario al ninja [3]
    public void equipaggiaItem(Item item) throws GearException {
        if (!item.isSbloccato()) {
            throw new NotUnlockedException(item.getNome() + " caused NotUnlockedException");
        }
        if (item.getAmmontare() <= 0) {
            throw new NotEnoughAmtInInventoryException(item.getNome() + " caused NotEnoughAmtInInventoryException");
        }
        if (equipaggiamento.size() >= capienzaEquipaggiamento) {
            throw new InventarioPienoException(item.getNome() + " caused InventarioPienoException");
        }

        // Se tutti i controlli passano, aggiorniamo lo stato [3]
        item.setAmmontare(item.getAmmontare() - 1);
        equipaggiamento.add(item);
    }

    // CODE 1: DDA -> Aumenta il limite di equipaggiamento a 99 slot [5]
    public void cheatDDA() {
        this.capienzaEquipaggiamento = 99;
    }

    // CODE 2: DDS -> Aumenta di 1 l'ammontare di tutti gli oggetti sbloccati [5]
    public void cheatDDS() {
        for (Item i : comuni) {
            if (i.isSbloccato()) {
                i.setAmmontare(i.getAmmontare() + 1);
            }
        }
        for (Item i : rari) {
            if (i.isSbloccato()) {
                i.setAmmontare(i.getAmmontare() + 1);
            }
        }
    }

    // CODE 3: DWA -> Sblocca immediatamente tutti gli oggetti rari [5]
    public void cheatDWA() {
        for (Item i : rari) {
            i.setSbloccato(true);
        }
    }
}
