import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Transakcia {
    public Transakcia() {
    }

    private String cisloKarty;
    private String bezpecnostnyKod;
    private int obrat;

    public Transakcia(String cisloKarty, int obrat, String bezpecnostnyKod) {
        this.cisloKarty = cisloKarty;
        this.obrat = obrat;
        this.bezpecnostnyKod = bezpecnostnyKod;
    }

    public ArrayList<Zakaznik> nacitajObrat(String volba, ArrayList<Zakaznik> zakaznici) {      //dostanem vstup a ArrayList
        File obrat = new File(volba);                                                           //otvorim druhy subor
        if (obrat.exists()) {                                                                   //skontrolujem
            BufferedReader br;
            FileReader fr;
            try {
                fr = new FileReader(obrat);
                br = new BufferedReader(fr);
                String line;
                line = br.readLine();                                                          //nacitavam riadok
                while (line != null) {                                                         //opakujem pokial neprecitam cely subor
                    String[] parameter = line.split(";");                                //rozdelujem pokial nie je bodkociarka
                    Transakcia transakcia = new Transakcia(parameter[0], Integer.parseInt(parameter[1]), parameter[2]);
                        for (Zakaznik zakaznik :zakaznici)                                     //prechazdam cez vsetkych zakaznikov a overujem podmienky
                        {
                        if (zakaznik.getTypKarty().equals("blue") &&
                                (!(transakcia.getObrat() > -1000)
                                        || !(transakcia.getObrat() < 1000))) {
                            continue;
                        }
                        if (zakaznik.getTypKarty().equals("gold") &&
                                (!(transakcia.getObrat() > -5000)
                                        || !(transakcia.getObrat() < 5000))) {
                            continue;
                        }
                        if (transakcia.getObrat() < 0)
                        {
                            zakaznik.vykonajPlatbu(zakaznik, transakcia);
                        }
                        else
                        {
                            zakaznik.uhradKredit(zakaznik, transakcia);
                        }
                    }
                    line = br.readLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        else {
            System.out.println("Zadal si neexistujuci subor");
        }
        return zakaznici;
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

    public int getObrat() {
        return obrat;
    }

    public void setObrat(int obrat) {
        this.obrat = obrat;
    }

}
