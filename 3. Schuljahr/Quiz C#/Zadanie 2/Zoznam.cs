namespace Zadanie_2
{
    public class Zaznam
    {
        public int ID;
        public string Otazka;
        public string MoznostA;
        public string MoznostB;
        public string MoznostC;
        public string MoznostD;
        public string Spravna_odpoved;

        public Zaznam(int id ,string otazka, string moznostA, string moznostB, string moznostC, string moznostD, string spravnaOdpoved)
        {
            ID = id;
            Otazka = otazka;
            MoznostA = moznostA;
            MoznostB = moznostB;
            MoznostC = moznostC;
            MoznostD = moznostD;
            Spravna_odpoved = spravnaOdpoved;
        }
    }
}
