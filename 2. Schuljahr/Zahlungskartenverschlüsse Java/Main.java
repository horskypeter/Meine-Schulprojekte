import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        args[0] = args[0].toLowerCase();                                             //zmenim na male znaky
        Transakcia transakcia = new Transakcia();
        if (args.length == 1) {                                                      //osetrenie vstupu
            ArrayList<Zakaznik> zakaznikList = new Zakaznik().nacitajVstup(args[0]); //vytvorenie ArrayList a posielam vstupny argument
            int i=0;
            while (i < zakaznikList.size()) {                                        //citam co je ulozene v ArrayList
                zakaznikList.get(i).vytlacMeno();
                i++;
            }
            String volba = "";
            while (!volba.equals("exit")) {                                          //nacitavam pokial volba nie je "exit"
                System.out.println("Zadaj nazov suboru s transakciami: ");
                Scanner scan = new Scanner(System.in);
                volba = scan.next();
                volba = volba.toLowerCase();                                         //menim volbu na male znaky
                if (volba.equals("exit")) {                                          //ak je volba exit koncim program
                    break;
                }
                zakaznikList = transakcia.nacitajObrat(volba, zakaznikList);         //vykonam a ulozim zmeny
            }
            i = 0;
            System.out.println("Konecne stavy uctov");
            while (i < zakaznikList.size()) {                                        //tlacim koncove stavy uctov
                zakaznikList.get(i).vytlacMeno();
                i++;
            }
        } else {
            System.out.println("Na spustenie programu potrebujem 1 parametre a ty si zadal : " + args.length + " vstupny parameter");
        }
    }
}
