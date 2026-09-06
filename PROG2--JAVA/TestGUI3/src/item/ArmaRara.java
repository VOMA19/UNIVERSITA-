package item;

public class ArmaRara extends Item {
    private final boolean unico;

    public ArmaRara(String nome, int ammontare, boolean unico) {
        // Gli oggetti rari partono bloccati. Massimo = 1 se unico, altrimenti 3 [4]
        super(nome, ammontare, unico ? 1 : 3, false);
        this.unico = unico;
    }

    public boolean isUnico() {
        return unico;
    }
}
