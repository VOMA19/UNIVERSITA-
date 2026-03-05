void main() {

    TNT tnt1 = new TNT(100);
    TNT tnt3 = new TNT();

    TNT tnt2 = new TNT(50);
    Random rand = new Random();

    int numeroCasuale = rand.nextInt(11);

    if(numeroCasuale%2 == 0)
        tnt1.explode();
    else
        tnt2.explode();

    if(tnt1.exploded) {
        System.out.println("Riko?");
        System.out.println("hai distrutto: " + tnt1.range*4 + " blocchi");
    }else
        System.out.println("nope");

    if(tnt2.exploded) {
        System.out.println("Giovanni");
        System.out.println("hai distrutto: " + tnt2.range*4 + " blocchi");
    }else
        System.out.println("Puf");
}
