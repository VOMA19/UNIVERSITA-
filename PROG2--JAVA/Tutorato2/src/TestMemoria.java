public class TestMemoria {
    public static void main(String[] args){
        Spada spadaGiocatore = new Spada(50);
        Spada spadaCassa = spadaGiocatore;
        spadaCassa.durabilita = 100;

        System.out.println(spadaGiocatore.durabilita);
        System.out.println(spadaCassa.durabilita);

    }
}
