import java.util.Scanner;
public class Problem 
{
       public static void main(String[] args) 
       {
        Scanner sc = new Scanner(System.in, "Windows-1250");

        System.out.println("Zadajte cislo:");
        long a = sc.nextLong();
        long b=a;
        long i=0;
        while(b!=1)
        {
          System.out.println("Skumane cislo je " + b ); 

          while(a>1)
            {
              if (a%2==1) 
                {
                 // System.out.println("Cislo "+ a +" *3+1 ");
                  a=a*3+1;
                  i++;
                }  
               if (a%2==0) 
                {
                 // System.out.println("Cislo " + a + " /2");
                  a=a/2;
                  i++;
                 }
             }
             b++;
             if (a!=1)
                  {
                    b--;
                  System.out.println("Nasiel som " +b ); 
                  a=1;
                  b=1;
                  }

            a=b;
         } 
        System.out.println("Potreboval som len "+ i + " prechodov" ); 
      }
}