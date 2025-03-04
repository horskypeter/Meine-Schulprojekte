import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in, "Windows-1250");

        System.out.println("Zadajte cislo:");
        long a = sc.nextLong();
        long b = a;
        long i = 0;


        long startTime;
        long endTime;
        long totalTime;
        while (b != 1) {
            startTime = System.nanoTime();
            while (b != 10000000) {
                while (a != 1) {
                    if (a % 2 == 1) {
                        a = a * 3 + 1;
                        i++;
                    }
                    if (a % 2 == 0) {
                        a = a / 2;
                        i++;
                    }
                    else {
                        System.out.println("Nasiel som " + b);
                    }
                }
                b++;
                a = b;
            }
            endTime = System.nanoTime();
            totalTime = endTime - startTime;
            double elapsedTimeInSecond = (double) totalTime / 1_000_000_000;

            System.out.println(elapsedTimeInSecond + " seconds " + i + " vypoctov");
            b = 3;
            i = 0;
        }
    }
}
