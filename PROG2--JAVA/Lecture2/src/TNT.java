public class TNT {

    public boolean exploded = false;
    public double range;

    public TNT(double range){
        exploded = false;
        this.range = range;
    }

    public TNT(){
        this.range = 19;
    }


    public void explode(){
        exploded = true;
    }
}

