import java.io.File;
import java.io.IOException;
import java.nio.file.Paths;
import java.util.Scanner;
import java.io.FileWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.attribute.BasicFileAttributes;

public class Main {

    public static void main(String[] args) {
        try {
            System.out.println("Zdravim ta pozri co som pre teba pripravil");
            System.out.println("----------------------------");
            System.out.println("Vyber si z nasledovneho menu");
            System.out.println("a........Vytvorit subor");
            System.out.println("b........Vlozit nieco");
            System.out.println("c........Precitat obsah suboru");
            System.out.println("d........Zisti velkost suboru");
            System.out.println("e........Kopiruj subor");
            System.out.println("f........Vypise cas vzniku suboru ");
            System.out.println("g........Vsetko o subore");
            System.out.println("y........Vymazat subor");
            System.out.println("x........Opustenie programu");
            System.out.println("Tvoja volba: ");


            Scanner reader = new Scanner(System.in);
            char entryParam = reader.next().charAt(0);
            while (entryParam != 'x') {
                switch (entryParam) {
                    case 'a':
                        File myObj1 = new File("filename.txt");
                        if (myObj1.createNewFile()) {
                            System.out.println("Subor vytvoreny: " + myObj1.getName());
                        } else {
                            System.out.println("Subor uz existuje");
                        }
                        break;
                    case 'b':
                        File myobj2 = new File("filename.txt");
                        if (myobj2.exists()) {
                            FileWriter myWriter = new FileWriter("filename.txt");
                            myWriter.write("Vkladam neaky zabavny text\n");
                            myWriter.write("Isla babka z kopecka vrzgali jej kolecka\n");
                            myWriter.close();
                            System.out.println("Uspesny zapis do suboru.");
                        } else {
                            System.out.println("Subor neexistuje");
                        }
                        break;
                    case 'c':
                        File myObj3 = new File("filename.txt");
                        if (myObj3.exists()) {
                            Scanner myReader = new Scanner(myObj3);
                            while (myReader.hasNextLine()) {
                                String data = myReader.nextLine();
                                System.out.println(data);
                            }
                            myReader.close();
                        } else {
                            System.out.println("Subor som nenasiel");
                        }
                        break;
                    case 'd':
                        File myObj4 = new File("filename.txt");
                        long size = myObj4.length();
                        System.out.println("Velkost suboru je : " + size);
                        break;
                    case 'e':
                        File myObj5 = new File("filename.txt");
                        if (myObj5.exists()) {
                            FileInputStream original = new FileInputStream("filename.txt");
                            FileOutputStream kopia = new FileOutputStream("newFile.txt");
                            byte[] array = new byte[70];
                            original.read(array);
                            kopia.write(array);
                            System.out.println("Subor input.txt sa skopiruje do newFile.");
                            original.close();
                            kopia.close();
                        } else {
                            System.out.println("Subor na kopirovanie nie je k dispozicii");
                        }
                        break;
                    case 'f':
                        File myObj6 = new File("filename.txt");
                        if (myObj6.exists()) {
                            Path file = Paths.get("filename.txt");
                            BasicFileAttributes attr = Files.readAttributes(file, BasicFileAttributes.class);
                            System.out.println("Cas vytvorenia: " + attr.creationTime());
                        } else {
                            System.out.println("Subor nie je k dispozicii");
                        }

                        break;
                    case 'g':
                        File myObj7 = new File("filename.txt");

                        System.out.println("existuje: " + myObj7.exists());
                        System.out.println("string: " + myObj7.toString());
                        System.out.println("meno: " + myObj7.getName());
                        System.out.println("rodic: " + myObj7.getParent());
                        System.out.println("cesta: " + myObj7.getPath());
                        System.out.println("abs. cesta: " + myObj7.getAbsolutePath());
                        System.out.println("can. cesta: " + myObj7.getCanonicalPath());
                        System.out.println("je subor: " + myObj7.isFile());
                        System.out.println("je adresar: " + myObj7.isDirectory());
                        System.out.println("vie citat: " + myObj7.canRead());
                        System.out.println("vie zapisovat: " + myObj7.canWrite());
                        System.out.println("moze vykonat:" + myObj7.canExecute());
                        System.out.println("velkost: " + myObj7.length());
                        System.out.println("a: " + myObj7.toURI());
                        break;
                    case 'y':
                        File myObj8 = new File("filename.txt");
                        if (myObj8.exists()) {
                            myObj8.delete();
                            System.out.println("Objekt " + myObj8.getName() + " uspesne vymazany");
                        } else {
                            System.out.println("Problem pri vymazani suboru, pravdepodobne ho chces vymazat dva krata");
                        }
                        break;
                    case 'x':
                        break;

                }
                entryParam = reader.next().charAt(0);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
