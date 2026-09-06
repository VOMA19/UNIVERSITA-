package Bevande.src.metodi;

public class Carta implements Metodi {
    private double saldo;

    // Ottima pratica: un costruttore per impostare il saldo iniziale
    public Carta(double saldoIniziale) {
        if (saldoIniziale >= 0) {
            this.saldo = saldoIniziale;
        } else {
            this.saldo = 0.0; // Invariante: il saldo iniziale non può essere negativo
        }
    }

    @Override
    public boolean paga(double costo) {
        if (this.saldo >= costo) {
            this.saldo -= costo; // <--- SOTTRAZIONE DEL SALDO (Risolve il bug!)
            System.out.println("Pagamento di " + costo + "€ effettuato con successo.");
            System.out.println("Saldo residuo sulla carta: " + this.saldo + "€");
            return true;
        } else {
            System.out.println("Transazione negata: saldo insufficiente sulla carta (" + this.saldo + "€).");
            return false;
        }
    }

    public void setSaldo(double saldo) {
        if (saldo >= 0) { // Proteggiamo l'invariante anche nel setter
            this.saldo = saldo;
        }
    }

    public double getSaldo() {
        return this.saldo;
    }
}