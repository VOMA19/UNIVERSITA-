public class Punto3D {
    // Campi di istanza (specifici per ogni singolo oggetto)
    private int x;
    private int y;
    private int z;

    // Campo statico (condiviso tra tutte le istanze della classe)
    private static int contatorePunti = 0;

    // Costruttore
    public Punto3D(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;

        // Ogni volta che viene chiamato il costruttore (nuovo oggetto),
        // incrementiamo il contatore globale
        contatorePunti++;
    }

    // Metodo statico per ottenere il numero di punti
    public static int getNumeroPunti() {
        return contatorePunti;
    }

    // Override del metodo toString() della classe Object
    @Override
    public String toString() {
        return "Punto: [" + x + ", " + y + ", " + z + "]";
    }


}