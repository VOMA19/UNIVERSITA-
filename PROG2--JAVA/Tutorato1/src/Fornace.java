public class Fornace {
    private int carbone;
    private int temperatura;

    public Fornace(){
        this.carbone = 0;
        this.temperatura = 0;
    }

    public void aggiungiCarbone(int quantita){
        if(quantita < 0){
            System.out.println("Avviso: la quantità di carbone passata è negativa.");
        } else {
            // Usiamo += per aggiungere al carbone esistente
            this.carbone += quantita;
        }
    }

    public void accendi(){
        // Usiamo >= 1 per assicurarci che si accenda anche con esattamente 1 di carbone
        if(this.carbone >= 1){
            this.carbone -= 1;
            this.temperatura = 100;
        } else {
            System.out.println("Nessun combustibile!");
        }
    }

    public void tick(){
        if(this.temperatura > 0){
            this.temperatura -= 10;
            System.out.println("La temperatura attuale della fornace è: " + this.temperatura);

            // Controlliamo subito se, scendendo, ha raggiunto lo 0
            if(this.temperatura == 0){
                System.out.println("Fornace spenta");
            }
        }
    }
}