import java.util.Random;

public class Main {
    public static void main(String[] args) {
        int pocetPokusov = 0;
        int vyherne;
        int nevyherne;
        int zmena;
        int zozmenou = 0, bezzmeny = 0;
        double i = 0, j = 0;
        Random rand = new Random();
        System.out.println("Vitaj v hre kde mozes vyhrat auto");
        while (pocetPokusov != 100000) {
            int volba = rand.nextInt(3) + 1;
            if ((volba == 1) || (volba == 2) || (volba == 3)) {
                vyherne = rand.nextInt(3) + 1;
                nevyherne = rand.nextInt(3) + 1;
                while ((nevyherne == vyherne) || (nevyherne == volba)) {
                    nevyherne = rand.nextInt(3) + 1;
                }
                int znak = rand.nextInt(2) + 1;
                if (znak == 1) {
                    zmena = rand.nextInt(3) + 1;
                    while ((zmena == nevyherne) || (zmena == volba)) {
                        zmena = rand.nextInt(3) + 1;
                    }
                    volba = zmena;
                    zozmenou++;
                    if (zmena == vyherne) {
                        i++;
                    }
                }
                if (znak == 2) {
                    if (volba == vyherne) {
                        j++;
                    }
                    bezzmeny++;
                }
                pocetPokusov++;
            } else {
                System.out.println("Zadal si zlu volbu");
            }
        }
        double vysledok = (i / zozmenou) * 100;
        double vysledok2 = (j / bezzmeny) * 100;
        System.out.println("Ak si zmenil volbu mal si uspesnost : " + vysledok + " %");
        System.out.println("Ak si nemenil volbu mal si uspesnost : " + vysledok2 + " %");
    }
}