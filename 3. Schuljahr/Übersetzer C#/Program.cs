class Program
{
    static void Main()
    {
        var SKslovnik = new Dictionary<string, string>();
        var AJslovnik = new Dictionary<string, string>();
        Console.WriteLine("Vitaj v aplikacii slovnik ");
        Console.WriteLine("Vyber si z nasledovného menu: ");
        char volba = ' ';
        while (volba != 'q')
        {                                                                                   // hlavne menu
            Console.WriteLine("a nacitanie   b pridanie    c preklad    d odstranenie   " +
                " e pocet sloviciek   f vypisanie vsetkych    q ukoncenie");
            volba = Convert.ToChar(Console.ReadLine());
            if (volba == 'a')                                                               // vkladam slovicka do slovnikov
            {
                SKslovnik = new Dictionary<string, string>()
                {
                    {"macka","cat"},    {"pes","dog"},  {"kon","horse"},    {"mys","mouse"}
                };
                AJslovnik = new Dictionary<string, string>()
                {
                    {"cat","macka"},    {"dog","pes"},  {"horse","kon"},    {"mouse","mys"}
                };
                Console.WriteLine("Vlozil som neake zakladne slovicka do slovnika");
            }
            else if (volba == 'b')                                                          // pridanie slovicka do slovnika 
            {
                string? SKpridanie;
                string? AJpridanie;
                int cislo2;
                Console.WriteLine("Ake slovicko chces pridat?   1.Slovenske     2.Anglicke");
                cislo2 = Convert.ToInt32(Console.ReadLine());
                if (cislo2 == 1)                                                            // pridavam slovenske slovicko
                {
                    Console.WriteLine("Pridanie slovicka po slovensky");
                    SKpridanie = Console.ReadLine();
                    if (!SKslovnik.ContainsKey(SKpridanie))                                 // ak sa nenachadza tak sa spytam na preklad
                    {
                        Console.WriteLine("Preklad slovicka po anglicky");
                        AJpridanie = Console.ReadLine();
                        SKslovnik.Add(SKpridanie, AJpridanie);
                        Console.WriteLine("Pridal som slovicko " + SKpridanie + " v preklade " + AJpridanie + " do slovenskeho slovnika");
                    }
                    else
                    {
                        Console.WriteLine("Slovicko sa nachadza v slovniku");
                    }
                }
                else if (cislo2 == 2)                                                       // pridavam anglicke slovicko
                {
                    Console.WriteLine("Pridanie slovicka po anglicky");
                    AJpridanie = Console.ReadLine();
                    if (!AJslovnik.ContainsKey(AJpridanie))                                 // ak sa nenachadza tak sa spytam na preklad
                    {
                        Console.WriteLine("Preklad slovicka po slovensky");
                        SKpridanie = Console.ReadLine();
                        AJslovnik.Add(AJpridanie, SKpridanie);
                        Console.WriteLine("Pridal som slovicko " + AJpridanie + " v preklade " + SKpridanie + " do anglickeho slovnika");
                    }
                    else
                    {
                        Console.WriteLine("Slovicko sa nachadza v slovniku");
                    }
                }
                else
                {
                    Console.WriteLine("Takuto moznost neponukam");
                }
            }
            else if (volba == 'c')                                                          // preklad slovicka
            {
                string? SKhladam;
                string? AJhladam;
                int cislo;
                Console.WriteLine("Aky slovnik chcem?   1.SK-AJ     2.AJ-SK ");
                cislo = Convert.ToInt32(Console.ReadLine());
                if (cislo == 1)                                                             // prekladam slovenske slovicko
                {
                    Console.WriteLine("Ake slovenske slovicko chcem prelozit?");
                    SKhladam = Console.ReadLine();
                    if (SKslovnik.ContainsKey(SKhladam))                                    // podmienka musi sa nachadzat v slovniku
                    {
                        Console.WriteLine("Preklad slovicka " + SKhladam + " je " + SKslovnik.GetValueOrDefault(SKhladam));
                    }
                    else
                    {
                        Console.WriteLine("Slovicko " + SKhladam + " sa nenachadza v slovniku");
                    }
                }
                else if (cislo == 2)                                                        // prekladam anglicke slovicko
                {
                    Console.WriteLine("Ake anglicke slovicko chcem prelozit?");
                    AJhladam = Console.ReadLine();
                    if (AJslovnik.ContainsKey(AJhladam))                                    // podmienka musi sa nachadzat v slovniku
                    {
                        Console.WriteLine("Preklad slovicka " + AJhladam + " je " + AJslovnik.GetValueOrDefault(AJhladam));
                    }
                    else
                    {
                        Console.WriteLine("Slovicko " + AJhladam + " sa nenachadza v slovniku");
                    }
                }
                else
                {
                    Console.WriteLine("Takuto moznost neponukam");
                }
            }
            else if (volba == 'd')                                                          // volba na vymazanie slovicka
            {
                string? SKvymazem;
                string? AJvymazem;
                Console.WriteLine("Z akeho slovnika chcem vymazavat?   1.SK-AJ     2.AJ-SK ");
                int cislo1;
                cislo1 = Convert.ToInt32(Console.ReadLine());
                if (cislo1 == 1)                                                            // vymazavam zo slovenskeho slovnika
                {
                    Console.WriteLine("Ake slovenske slovicko chcem vymazat?");
                    SKvymazem = Console.ReadLine();
                    if (SKslovnik.ContainsKey(SKvymazem))                                   // ak sa nachadza tak vymazem
                    {
                        SKslovnik.Remove(SKvymazem);
                        Console.WriteLine("Slovicko " + SKvymazem + " som vymazal zo slovnika");
                    }
                    else
                    {
                        Console.WriteLine("Slovicko " + SKvymazem + " sa nenachadza v slovniku");
                    }
                }
                else if (cislo1 == 2)                                                       // vymazavam z anglickeho slovnika
                {
                    Console.WriteLine("Ake anglicke slovicko chcem vymazat?");
                    AJvymazem = Console.ReadLine();
                    if (AJslovnik.ContainsKey(AJvymazem))                                   // ak sa nachadza tak vymazem
                    {
                        AJslovnik.Remove(AJvymazem);
                        Console.WriteLine("Slovicko " + AJvymazem + " som vymazal zo slovnika");
                    }
                    else
                    {
                        Console.WriteLine("Slovicko " + AJvymazem + " sa nenachadza v slovniku");
                    }
                }
                else
                {
                    Console.WriteLine("Takuto moznost neponukam");
                }
            }
            else if (volba == 'e')                                                          // vypisanie vsetkych slovicok
            {
                Console.WriteLine("Pocet slovicok v slovenskom slovniku " + SKslovnik.Count());
                Console.WriteLine("Pocet slovicok v anglickom slovniku " + AJslovnik.Count());
            }
            else if (volba == 'f')                                                          // vypisanie vsetkych slovicok
            {
                Console.WriteLine("Vsetky slovicka");
                foreach (string key in SKslovnik.Keys)
                {
                    Console.WriteLine("Slovicka v SK slovniku " + key);
                }
                foreach (string key in AJslovnik.Keys)
                {
                    Console.WriteLine("Slovicka v AJ slovniku " + key);
                }
            }
        }
    }
}

