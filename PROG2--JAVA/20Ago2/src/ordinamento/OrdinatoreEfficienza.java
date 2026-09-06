package ordinamento;

import java.util.Comparator;
import item.Item;

public class OrdinatoreEfficienza implements Comparator<Item> {
    @Override
    public int compare(Item i1, Item i2) {
        // Double.compare gestisce correttamente i valori decimali
        return Double.compare(i1.getEfficienza(), i2.getEfficienza());
    }
}