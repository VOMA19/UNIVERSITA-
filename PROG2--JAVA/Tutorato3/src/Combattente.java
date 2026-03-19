class Combattente {
    protected int salute;
    protected String nome;

    public Combattente(String nome, int salute) {
        this.nome = nome;
        this.salute = salute;
    }

    public void subisciDanno(int danno) {
        this.salute -= danno;
        // Evitiamo che la salute scenda sotto lo zero (opzionale, ma buona pratica)
        if (this.salute < 0) {
            this.salute = 0;
        }
    }

    public String getNome() {
        return nome;
    }

    public int getSalute() {
        return salute;
    }
}

// Sottoclasse

