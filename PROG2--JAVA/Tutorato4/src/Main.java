void main(String[] args) {
    // 1. Creiamo 4 punti 3D
    Punto3D p1 = new Punto3D(0, 0, 0);
    Punto3D p2 = new Punto3D(5, 10, -3);
    Punto3D p3 = new Punto3D(7, 2, 8);
    Punto3D p4 = new Punto3D(-1, -5, 12);

    // 2. Stampiamo il numero totale di punti invocando il metodo statico sulla classe
    System.out.println("Numero totale di punti istanziati: " + Punto3D.getNumeroPunti());

    // 3. Testiamo l'override del metodo toString()
    System.out.println("\nStampa dei singoli punti:");
    // Quando passi un oggetto a System.out.println, Java chiama in automatico il suo metodo toString()
    System.out.println("Punto 1 -> " + p1);
    System.out.println("Punto 2 -> " + p2);
    System.out.println("Punto 3 -> " + p3);
    System.out.println("Punto 4 -> " + p4);
}