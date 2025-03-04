namespace Minizadanie_1
{
     class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Aky objekt mam zobrazit mam moznosti stvorec obdlznik a trojuholnik: ");
            string meno = Console.ReadLine();                       //nacitavam objekt
            Console.WriteLine("Kolko riadkov: ");
            int y = Convert.ToInt32(Console.ReadLine());            //nacitavam rozmer y
            Console.WriteLine("Kolko stplcov: ");
            int z = Convert.ToInt32(Console.ReadLine());            //nacitavam rozmer x
            switch (meno)                                           //prepinac
            {
                case ("Stvorec" or "stvorec"):                      //objekt stvorec
                    if (y != z)
                    {
                        Console.WriteLine("Zadal si obdlznik"); 
                    }
                    else
                    {
                        Objekt p1 = new Stvorec(y, z);
                        p1.chod();
                    }
                    break;
                case ("Obdlznik" or "obdlznik"):                    // objekt obdlznik
                    if (y == z)
                    {
                        Console.WriteLine("Zadal si stvorec");
                    }
                    else
                    {
                        Objekt p2 = new Obdlznik(y, z);
                        p2.chod();
                    }
                    break;
                case ("Trojuholnik" or "trojuholnik"):                  //objekt trojuholnik
                    Console.WriteLine("Na zostrojenie trojuholnika potrebujem len pocet stlpcov resp. riadkov");
                        y = 1;
                        Objekt p3 = new Trojuholnik(y, z);
                        p3.chod();
                    break;
                default:                                                // vsetko ostatne
                    Console.WriteLine("Objekt nemam ulozeny v pamati");
                    break;
            }
        }
    }
}