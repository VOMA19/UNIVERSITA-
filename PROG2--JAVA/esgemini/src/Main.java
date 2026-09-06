package src;

import java.util.ArrayList;
import java.util.Collections;
import src.eccezioni.GearException;
import src.eccezioni.InventarioPienoException;
import src.inventario.Inventario;
import src.item.*;
import src.ordinamento.OrdinatoreEfficienza;

public class Main {
    public static void main(String[] args) {
        Inventario zaino = new Inventario(5); // Zaino piccolo da 5 slot

        StrumentoComune shuriken = new StrumentoComune("Shuriken", 1, 2, 2); // 1 slot, 2 cariche
        ArmaRara rampino = new ArmaRara("Rampino d'Acciaio", 3, 0.15, 50);   // 3 slot, durabilità 15%
        StrumentoComune fumogeno = new StrumentoComune("Fumogeno", 2, 1, 1); // 2 slot (Supererebbe la portata!)

        System.out.println("--- 1. TEST INSERIMENTO & INVARIANTI ---");
        try {
            zaino.aggiungiItem(shuriken); // Libero: 1/5 slot
            zaino.aggiungiItem(rampino);  // Libero: 4/5 slot
            zaino.aggiungiItem(fumogeno); // Errore! Richiede 2 slot ma ne rimane solo 1.
        } catch (InventarioPienoException e) {
            System.err.println("ERRORE: " + e.getMessage());
        }

        System.out.println("\n--- 2. TEST ATTIVAZIONE & ECCEZIONI LOGICHE ---");
        try {
            zaino.attivaStrumento(rampino); // scende a 5% (0.05)
            zaino.attivaStrumento(rampino); // scende a -5% -> Errore!
        } catch (GearException e) {
            System.err.println("ERRORE: " + e.getMessage());
        }

        System.out.println("\n--- 3. TEST ORDINAMENTO ALTERNATIVO (EFFICIENZA) ---");
        ArrayList<Item> listaOrdinamento = new ArrayList<>();
        listaOrdinamento.add(shuriken); // Efficienza: 2/2 = 1.0 (100%)
        listaOrdinamento.add(rampino);  // Efficienza: 0.05 (5%)

        System.out.println("Prima: " + listaOrdinamento.get(0).getNome() + " (Eff: " + listaOrdinamento.get(0).getEfficienza() + "), " +
                           listaOrdinamento.get(1).getNome() + " (Eff: " + listaOrdinamento.get(1).getEfficienza() + ")");

        // Ordiniamo usando il Comparator esterno
        Collections.sort(listaOrdinamento, new OrdinatoreEfficienza());

        System.out.println("Dopo: " + listaOrdinamento.get(0).getNome() + " (Eff: " + listaOrdinamento.get(0).getEfficienza() + "), " +
                           listaOrdinamento.get(1).getNome() + " (Eff: " + listaOrdinamento.get(1).getEfficienza() + ")");
    }
}
