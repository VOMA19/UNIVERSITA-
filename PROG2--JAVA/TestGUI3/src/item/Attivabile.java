package item;

import eccezioni.GearException;

/**
 * Interfaccia di comportamento.
 * Rappresenta la capacità di un oggetto dell'inventario di essere "attivato"
 * o consumato per produrre un effetto a runtime.
 */
public interface Attivabile {

    /**
     * Esegue l'azione speciale associata allo strumento.
     *
     * @throws GearException se l'attivazione non è possibile
     *                       (es. se l'oggetto è esaurito, bloccato o rotto).
     */
    void attiva() throws GearException;
}
