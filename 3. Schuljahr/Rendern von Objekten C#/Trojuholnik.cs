using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Minizadanie_1
{
    public class Trojuholnik : Objekt                        //dedenie z Objekt triedy
    {
        public Trojuholnik(int x, int y) : base(x,y)
        {
        }
        public override void chod()                     //prepisanie metody 
        {
            Console.Write("\n");
            for (int i = 0; i < y; i++)
            {
                for (int j = 0; j < x; j++)
                {
                    Console.Write("* ");
                }
                Console.Write("\n");
                x++;
            }
        }
    }
}