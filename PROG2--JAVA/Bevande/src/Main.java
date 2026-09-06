package Bevande.src;

import Bevande.src.bevande.Espresso;
import Bevande.src.macchinetta.Macchinetta;
import Bevande.src.metodi.Carta;
import Bevande.src.metodi.Metodi;

public class Main {
    public static void main(String[] args) {
        Macchinetta macchinetta1 = new Macchinetta();
        Carta carta1 = new Carta(5.0);
        Espresso espresso1 = new Espresso();
        macchinetta1.setBevanda(espresso1);
        macchinetta1.setMetodo(carta1);
        
        macchinetta1.ordina(3);
    }
}