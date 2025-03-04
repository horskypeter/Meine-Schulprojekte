using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Minizadanie_1
{
    public class Stvorec : Objekt                       //dedenie z Objekt triedy
    {
        public Stvorec(int x, int y) : base(x, y)       
        {
        }
        public override void chod()                       //prepisanie metody 
        {
            Console.Write("\n");
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    Console.Write("* ");
                }
                Console.Write("\n");
            }
        } 
    }
}
