import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Zakaznik implements CreditCard {

    private String meno;
    private String cisloKarty;
    private String bezpecnostnyKod;
    private int stavUctu;
    private String typKarty;

    Zakaznik() {
    }

    Zakaznik(String meno, String cisloKarty, String bezpecnostnyKod, int stavUctu, String typKarty) {
        this.meno = meno;
        this.cisloKarty = cisloKarty;
        this.bezpecnostnyKod = bezpecnostnyKod;
        this.stavUctu = stavUctu;
        this.typKarty = typKarty;
    }

    public ArrayList<Zakaznik> nacitajVstup(String args) {                           //dostanem vstupny argument
        File vstup = new File(args);                                                 //otvorim subor
        ArrayList<Zakaznik> mojzakaznik = new ArrayList<>();                         //vytvorim ArrayList
        if (vstup.exists()) {
            BufferedReader br;
            FileReader fr;
            try {
                fr = new FileReader(vstup);
                br = new BufferedReader(fr);
                String line;
                line = br.readLine();                                                //nacitavam riadok
                System.out.println("Nacitane zo vstupneho suboru");
                while (line != null) {                                               //opakujem pokial neprecitam cely subor
                    String[] parameter = line.split(";");                      //rozdelujem pokial nie je bodkociarka
                    Zakaznik zakaznik = new Zakaznik(parameter[0], parameter[1], parameter[2], Integer.parseInt(parameter[3]), parameter[4]);
                    mojzakaznik.add(zakaznik);                                       //pridavam do ArrayList
                    line = br.readLine();                                            //nacitavam riadok
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {                                                                     //osetrenie ak nemam vstupny subor
            System.out.println("Neexistuje vstupny subor");
        }
        return mojzakaznik;
    }

    public void vytlacMeno() {                                                       //tlacim meno

        while (meno.length() < 15) {
            meno = meno + " ";
        }
        System.out.println(getMeno() + " **** **** **** " + getCisloKarty().substring(getCisloKarty().length() - 4)
                + "\t" + getBezpecnostnyKod() + "\t" + getStavUctu() + "\t" + getTypKarty());
    }

    public void zistiKredit(Zakaznik zakaznik) {
        System.out.println(zakaznik.stavUctu);
    }

    public void vykonajPlatbu(Zakaznik zakaznik, Transakcia transakcia) {
        if (zakaznik.getCisloKarty().equals(transakcia.getCisloKarty()) &&
                zakaznik.getBezpecnostnyKod().equals(transakcia.getBezpecnostnyKod())) {
            zakaznik.setStavUctu(zakaznik.getStavUctu() + transakcia.getObrat());     //overujem ci je splnena podmienka
            String y = ("Odratavam z uctu");
            while (y.length() < 20) {
                y =y +" ";
            }
            System.out.println(String.format(y+" **** **** **** %s sumu \t%s",
                    zakaznik.getCisloKarty().substring(zakaznik.getCisloKarty().length() - 4), transakcia.getObrat()));
        }
    }

    public void uhradKredit(Zakaznik zakaznik, Transakcia transakcia) {
        if (zakaznik.getCisloKarty().equals(transakcia.getCisloKarty()) &&
                zakaznik.getBezpecnostnyKod().equals(transakcia.getBezpecnostnyKod())) {
            zakaznik.setStavUctu(zakaznik.getStavUctu() + transakcia.getObrat());     //overujem ci je splnena podmienka
            String z = ("Priratavam na ucet");
            while (z.length() < 20) {
                z = z + " ";
            }
            System.out.println(String.format(z + " **** **** **** %s sumu \t%s",
                    zakaznik.getCisloKarty().substring(zakaznik.getCisloKarty().length() - 4), transakcia.getObrat()));
        }
    }

    public String getMeno() {
        return meno;
    }

    public void setMeno(String meno) {
        this.meno = meno;
    }

    public String getCisloKarty() {
        return cisloKarty;
    }

    public void setCisloKarty(String cisloKarty) {
        this.cisloKarty = cisloKarty;
    }

    public String getBezpecnostnyKod() {
        return bezpecnostnyKod;
    }

    public void setBezpecnostnyKod(String bezpecnostnyKod) {
        this.bezpecnostnyKod = bezpecnostnyKod;
    }

    public int getStavUctu() {
        return stavUctu;
    }

    public void setStavUctu(int stavUctu) {
        this.stavUctu = stavUctu;
    }

    public String getTypKarty() {
        return typKarty;
    }

    public void setTypKarty(String typKarty) {
        this.typKarty = typKarty;
    }
}

