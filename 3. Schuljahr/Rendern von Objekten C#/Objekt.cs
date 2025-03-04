using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Minizadanie_1
{
    public class Objekt
    {
        protected int x=0;
        protected int y=0; 
        protected string meno;
        public Objekt (int x, int y)               //konstruktor
        {
            this.x = x;
            this.y = y; 
        }
        public virtual void chod()   {              //metoda
        }
    }
}
