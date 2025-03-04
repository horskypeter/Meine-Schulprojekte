public interface CreditCard {
    void zistiKredit(Zakaznik zakaznik);
    void vykonajPlatbu(Zakaznik zakaznik,Transakcia transakcia);
    void uhradKredit(Zakaznik zakaznik, Transakcia transakcia);
}
