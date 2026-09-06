package inventario;

import item.*;
import eccezioni.*;
import java.util.ArrayList;

public class InventarioGeraldo {
    private final ArrayList<Item> equipaggiamento = new ArrayList<>();
    private final double pesoMassimo; // Geraldo non può trasportare più di questo peso

    public InventarioGeraldo(double pesoMassimo) {
        this.pesoMassimo = pesoMassimo;
    }

    public ArrayList<Item> getEquipaggiamento() {
        return equipaggiamento;
    }

    public double getPesoMassimo() {
        return pesoMassimo;
    }

    // Calcola il peso attuale sommando i pesi degli oggetti equipaggiati
    public double getPesoAttuale() {
        double pesoTotale = 0;
        for (Item i : equipaggiamento) {
            pesoTotale += i.getPeso();
        }
        return pesoTotale;
    }

    // Tenta di equipaggiare un oggetto
    public void equipaggia(Item item) throws PesoMassimoSuperatoException {
        if (getPesoAttuale() + item.getPeso() > pesoMassimo) {
            throw new PesoMassimoSuperatoException("Geraldo non ha abbastanza forza! Peso limite superato.");
        }
        equipaggiamento.add(item);
    }

    // Cerca se nell'equipaggiamento c'è almeno un Kit di riparazione con cariche
    public KitRiparazione trovaKitDisponibile() throws KitEsauritiException {
        for (Item i : equipaggiamento) {
            if (i instanceof KitRiparazione) {
                KitRiparazione kit = (KitRiparazione) i;
                if (kit.getUsciteRimanenti() > 0) {
                    return kit;
                }
            }
        }
        throw new KitEsauritiException("Nessun kit di riparazione con cariche rimaste nell'equipaggiamento!");
    }
}
