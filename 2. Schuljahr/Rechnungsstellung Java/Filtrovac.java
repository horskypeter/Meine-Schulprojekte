import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Filtrovac {
    public static void main(String[] args) {

            File myObj =  new File(args[0]);                                     //Nacitanie prveho vstupneho argumentu a otvorenie suboru
        if (myObj.exists()) {                                                    //Overenie
            System.out.println("Subor je pripraveny ");

            BufferedReader br;
            FileReader fr;
            try
            {
                fr =  new FileReader(myObj);
                br = new BufferedReader(fr);
                String line;

                line = br.readLine();                                            //Nacitnie po riadku
                ArrayList<Filter> mojizakaznici = new ArrayList<>();             //Vytvorenie zoznamu
                while(line !=null)                                               //Nacitavam v cykle pokial nie je prazdny riadok
                {
                    String[] parameter = line.split(";");
                    if (parameter[0].length()!=20)                               //Ukladanie 20 znakov koli rozdielnosti dlzky mien
                    {
                        while(parameter[0].length()!=20)
                            parameter[0] = parameter[0] + " ";
                    }
                    if(parameter[1].length()!=12)                                //Ak nenacita tel. cislo tak vypise 12 prazdnych znakov
                    {
                        while(parameter[1].length()!=12)
                            parameter[1] = parameter[1] + " ";
                    }
                    Filter zakaznik = new Filter(parameter[0],parameter[1],parameter[2],parameter[3],parameter[4]);

                    mojizakaznici.add(zakaznik);                                 //Tu ukladam udaje do zoznamu
                    line = br.readLine();
                }

                char entryParam = args[1].charAt(0);                             //Nacitanie druheho vstupneho argumentu
            switch (entryParam)                                                  //Prepinac
            {
                case 'p':                                                        //Filter plyn
                    int i=0;
                    while (i < mojizakaznici.size())
                    {
                        String P = mojizakaznici.get(i).Plyn(mojizakaznici.get(i).plyn);
                        if (P!="")
                        {
                            System.out.println(P);
                        }
                        i++;
                    }
                    break;
                case 'e':                                                          //Filter elektrika
                    i=0;
                    while (i < mojizakaznici.size())
                    {
                        String E = mojizakaznici.get(i).Elektrika(mojizakaznici.get(i).elektrika);
                        if (E!="")
                        {
                            System.out.println(E);
                        }
                        i++;
                    }
                    break;
                case 'f':                                                          //Filter fakturacia
                    i=0;
                    while (i < mojizakaznici.size())
                    {
                        String F = mojizakaznici.get(i).Fakturacia(mojizakaznici.get(i).fakturacia);
                        if (F!="")
                        {
                            System.out.println(F);
                        }
                        i++;
                    }
                    break;
                case 'm':                                                          //Filter mobilny kontakt
                    i=0;
                    while (i < mojizakaznici.size())
                    {
                        String T = mojizakaznici.get(i).Telcislo(mojizakaznici.get(i).telcislo);
                        if (T!="")
                        {
                            System.out.println(T);
                        }
                        i++;
                    }
                    break;
                default:                                                         //Pre zle zadanu volbu
                    System.out.println("Zadal si neplatnu volbu");
            }
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
        }
        else                                                                     //Ak nacitanie suboru nebolo uspesne
        {
            System.out.println("Subor sa nepodarilo nacitat");
        }
    }
}