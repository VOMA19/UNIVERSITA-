package item;

import eccezioni.GeraldoException;

public interface Riparabile {
    void ripara() throws GeraldoException;
    int getIntegrita();
}