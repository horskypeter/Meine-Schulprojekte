import java.util.Scanner;
public class Prvyprogram {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    
    System.out.print("Tvoje meno: ");
    String meno = input.next();

    System.out.print("Tvoje priezvisko: ");
    String priezvisko = input.next();
    String celemeno = meno +" "+ priezvisko;

    System.out.println("Tvoje meno je "+ meno +" "+ priezvisko);

    
    System.out.println("Tvoje meno je "+ celemeno);

    byte k=15;
    byte l=50;

    System.out.println(k+l);

  }
}