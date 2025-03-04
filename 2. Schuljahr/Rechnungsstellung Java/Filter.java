public class Filter
{
    public String meno;
    public String telcislo;
    public String plyn;
    public String elektrika;
    public String fakturacia;

    Filter(String meno, String telcislo, String plyn, String elektrika, String fakturacia)
    {
        this.meno = meno;
        this.telcislo = telcislo;
        this.plyn = plyn;
        this.elektrika = elektrika;
        this.fakturacia = fakturacia;
    }

    public String vytlacMeno()                                                   //vytlaci meno, tel.cislo a fakturaciu
    {
        String vystupneUdaje = meno + "\t" + telcislo + "\t" + fakturacia;
        return vystupneUdaje;
    }

    public String Plyn(String vstupP)
    {
        if (vstupP.equals("plyn"))                                               //podmienka ak 3 parameter je "plyn"
        {
            return vytlacMeno();
        }
        return "";
    }

    public String Elektrika(String vstupE)
    {
        if (vstupE.equals("elektrika"))                                          //podmienka ak 4 parameter je "elektrika"
        {
            return vytlacMeno();
        }
        return "";
    }

    public String Telcislo(String vstupM)                                        //podmienka ak 2 parameter zacina "09"
    {
        if (vstupM.startsWith("09"))
        {
            return vytlacMeno();
        }
        return "";
    }
    public String Fakturacia(String vstupF)
    {
        double cislo = Double.parseDouble(vstupF);                               //pretipovanie zo string na double

        if (cislo<0)                                                             //ak je cislo zaporne
        {
            return vytlacMeno();
        }
        return "";
    }
}