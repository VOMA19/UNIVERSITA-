class Cavaliere extends Combattente {
    private int armatura;

    public Cavaliere(String nome, int salute, int armatura) {
        // Richiamo il costruttore della superclasse
        super(nome, salute);
        this.armatura = armatura;
    }

    @Override
    public void subisciDanno(int danno) {
        // Il danno viene ridotto dall'armatura
        int dannoEffettivo = danno - armatura;

        // Il danno finale non può essere negativo
        if (dannoEffettivo < 0) {
            dannoEffettivo = 0;
        }

        // Sottraiamo il danno effettivo alla salute
        this.salute -= dannoEffettivo;

        if (this.salute < 0) {
            this.salute = 0;
        }
    }
}
