package item;

import eccezioni.GeraldoException;

public class Arma extends Item implements Riparabile {
    private int integrita; // da 0 a 100

    public Arma(String nome, double peso, int integrita) {
        super(nome, peso);
        this.integrita = integrita;
    }

    @Override
    public int getIntegrita() { return integrita; }

    @Override
    public void ripara() throws GeraldoException {
        if (this.integrita >= 100) {
            throw new GeraldoException(this.getNome() + " è già al massimo dell'integrità!");
        }
        this.integrita = Math.min(100, this.integrita + 30); // Ripara del 30%
    }
}