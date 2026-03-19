public class ArenaMain {
    public static void main(String[] args) {
        // Creazione di un array di tipo Combattente (Superclasse)
        Combattente[] arena = new Combattente[3];

        // UPCASTING: Inseriamo oggetti di tipo Cavaliere in reference di tipo Combattente
        arena[0] = new Combattente("Milizia Semplice", 50);
        arena[1] = new Cavaliere("Ser Lancillotto", 50, 5);  // Riduce il danno di 5
        arena[2] = new Cavaliere("Re Artù", 50, 10);         // Riduce il danno di 10

        System.out.println("--- INIZIO DEL COMBATTIMENTO ---");
        System.out.println("Ogni combattente subisce 15 danni.\n");

        // Iterazione sull'array
        for (int i = 0; i < arena.length; i++) {

            // POLIMORFISMO: a runtime Java capisce se chiamare il metodo
            // della superclasse (Combattente) o quello overridato (Cavaliere)
            arena[i].subisciDanno(15);

            System.out.println(arena[i].getNome() + " ha " + arena[i].getSalute() + " punti salute rimanenti.");
        }
    }
}