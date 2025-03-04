public class Main {

    public static void main(String[] args) {
        System.out.println("Ahojky usmej sa na mna");

        ZasobnikLIFO mojZasobnik = new ZasobnikLIFO(10);
        mojZasobnik.push(4);
        mojZasobnik.push("ahoj");
        mojZasobnik.push(6);
        mojZasobnik.push('a');

//        System.out.println(mojZasobnik.pop());
//        System.out.println(mojZasobnik.pop());
//        System.out.println(mojZasobnik.pop());
//        System.out.println(mojZasobnik.pop());
//        System.out.println(mojZasobnik.pop());
        Zelenina mrkva = new Zelenina("mrkva", "slovensko");
        Zelenina banan = new Zelenina("banan", "kostarika");
        mojZasobnik.push(mrkva);
        mojZasobnik.push(banan);
//        System.out.println(mojZasobnik.pop());
//        System.out.println(mojZasobnik.pop());
        mojZasobnik.print();

//treba vytiahnut posledny prvok ako prvy
//        ZasobnikFIFO fifozasobnik = new ZasobnikFIFO( 5);
//        fifozasobnik.push(9);
//        fifozasobnik.push(10);
//        fifozasobnik.push(11);
//        fifozasobnik.push(12);
//        fifozasobnik.push(13);
//        fifozasobnik.push(14);
//        System.out.println(fifozasobnik.pop());
//        System.out.println(fifozasobnik.pop());
//        System.out.println(fifozasobnik.pop());
//        System.out.println(fifozasobnik.pop());


    }
}
