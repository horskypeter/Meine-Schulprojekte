public class ZasobnikFIFO {
    Object fifo[];
    int pop;
    int dlzka;
    int ukazovatel;

    ZasobnikFIFO(int pocetPoloziek)
    {
        this.fifo = new Object[pocetPoloziek];
        pop = 0;
        dlzka = this.fifo.length;
        ukazovatel=0;
    }

    void push(int preco) {
        if (pop < dlzka) {

            fifo[pop] = preco;
            pop = pop + 1;


        } else {
            System.out.println("Zasobnik je plny");
        }
    }
    Object pop() {
        if (pop >= 0) {

            pop = pop - 1;
            return fifo[pop];

        } else {
            System.out.println("Zasobnik je prazdny");
            return -1;
        }
    }
}
