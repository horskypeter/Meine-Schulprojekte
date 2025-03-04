#include <iostream>
#include "stack.h"
#include <fstream>
ofstream output;
using namespace std;

int main()
{
	mystack my;
    output.open("vystup.txt", ofstream::out);                              // otvorenie vystupneho suboru

    cout << "\ta....Vytvor dva nove a prazdne zasobniky " << endl;         //hlavne menu
    output << "\ta....Vytvor dva nove a prazdne zasobniky " << endl;
    cout << "\tb... Vyprazdni obsah v oboch zasobnikoch" << endl;
    output << "\tb... Vyprazdni obsah v oboch zasobnikoch" << endl;
    cout << "\tc... Nacitaj novy retazec z klavesnice do prveho zasobnika a vytvor aj druhy zasobnik" << endl;
    output << "\tc... Nacitaj novy retazec z klavesnice do prveho zasobnika a vytvor aj druhy zasobnik" << endl;
    cout << "\td... Vypis obsah prveho zasobnika" << endl;
    output << "\td... Vypis obsah prveho zasobnika" << endl;
    cout << "\te... Vypis obsah druheho zasobnika" << endl;
    output << "\te... Vypis obsah druheho zasobnika" << endl;
    cout << "\tf... Urci, ci dany retazec je palindromom" << endl;
    output << "\tf... Urci, ci dany retazec je palindromom" << endl;
    cout << "\tx... Ukonci program" << endl;
    output << "\tx... Ukonci program" << endl;

    char input = 0;
    while (input != 'x')                                                  //opakovanie menu pokial volba nebude x
    {
        string just = "";
        int value = 0;
        cout << "Z akeho menu mam hladat? ";
        cin >> input;
        output << "Z akeho menu mam hladat? " << input << endl;
        switch (input)                                                    //prepinac
        {
        case 'a':
            value=my.isEmpty();
            if (value==1)
            {
                cout << "Zasobniky su prazdne" << endl;
                output << "Zasobniky su prazdne" << endl;
            }
           if(value==0)
            {
                cout << "Zasobniky obsahuju nieco" << endl;
                output << "Zasobniky obsahuju nieco" << endl;
            }
            break;
        case 'b':                                                         //vyprazdnenie
            my.empty();
            cout << "Vyprazdnene " << endl;
            output << "Vyprazdnene " << endl;
            break;
        case 'c':                                                       //pripisanie do zasobnika
            cout << "Zadaj vyraz "<<endl;
            output << "Zadaj vyraz "<<endl;
            cin.ignore();
            my.add();
            just=my.transform1();
            output << just<<endl;
            break;
        case'd':                                                          //vypis prveho zasobnika
            cout << "Obsah prveho zasobnika" << endl;
            output << "Obsah prveho zasobnika" << endl;
            if (!my.isEmpty())
            {
                my.print1();
            }
            just = my.transform2();
            output << just << endl;
            break;
        case 'e':                                                        //vypis druheho zasobnika
            cout << "Obsah druheho zasobnika" << endl;
            output << "Obsah druheho zasobnika" << endl;
            if (!my.isEmpty())
            {
                my.print2();
            }
            just = my.transform3();
            output << just << endl;
            break;
        case 'f':                                                         //zistenie ci je palindrom
            my.palindrom();
            just=my.palindrom();
            cout << just << endl;
            output << just << endl;
        break;
        case 'x':                                                           //ukoncienie switch       
            cout << "Tvoja volba na ukoncenie programu" << endl;
            output << "Tvoja volba na ukoncenie programu" << endl;
            break;
        default:                                                            //pri zadani inej volby z menu
            string nothing;
            cin >> nothing;
            cout << "Zadal si hlupost " << endl;
            output << "Zadal si hlupost " << endl;
            continue;
        }
    }
    output.close();                                                        //zatvorenie vystupneho suboru
	system("pause");
	return 0;
}
