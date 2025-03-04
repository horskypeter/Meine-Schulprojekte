#include <iostream>
#include <queue> 
#include <fstream>
using namespace std;
ifstream input;
ofstream output;
queue<float> magazine1;
queue<float> magazine2;
queue<float> magazine3;
queue<float> help;

char symbol = 0;
float sum=0, item =0, pieces=0, price=0, value = 0;
char menu = 0;
int pcs=0;

void tomagazine1()                                                                       //obraty prvej polozky
{
    if (symbol == 'K')                                                                  //pre kupu               
    {
        if (menu != 'n')
        {
            cout << "Nakupene do prvej polozky " << pieces << " ks v cene " << price << endl;
        }
        while (pieces != 0)
        {
            magazine1.push(price);
            pieces--;
        }
    }
    if (symbol == 'P')                                                                   //pre predaj
    {
        if (magazine1.size() < pieces)                                                   //kontrola dospupnosti
        {
            cout << "Transakcia zamietnuta" << endl;
        }
        else
        {
            if (menu != 'n')
            {
                cout << "Predalo sa " << pieces << " ks z polozky 1" << endl;
            }
            while (pieces != 0)
            {
                magazine1.pop();
                pieces--;
            }
        }
    }
}
void tomagazine2()                                                                       //obraty druhej polozky
{
    if (symbol == 'K')                                                                   //pre kupu
    {
        if (menu != 'n')
        {
            cout << "Nakupene do druhej polozky " << pieces << " ks v cene " << price << endl;
        }
        while (pieces != 0)
        {
            magazine2.push(price);
            pieces--;
        }
    }
    if (symbol == 'P')                                                                   //pre predaj
    {
        if (magazine2.size() < pieces)                                                   //kontrola dospupnosti
        {
            cout << "Transakcia zamietnuta" << endl;
        }
        else
        {
            if (menu != 'n')
            {
                cout << "Predalo sa " << pieces << " ks z polozky 2" << endl;
            }
            while (pieces != 0)
            {
                magazine2.pop();
                pieces--;
            }
        }
    }
}
void tomagazine3()                                                                       //obraty tretej polozky
{
    if (symbol == 'K')                                                                   //pre kupu
    {
        if (menu != 'n')
        {
            cout << "Nakupene do tretej polozky " << pieces << " ks v cene " << price << endl;
        }
        while (pieces != 0)
        {
            magazine3.push(price);
            pieces--;
        }
    }
    if (symbol == 'P')                                                                   //pre predaj
    {
        if (magazine3.size() < pieces)                                                   //kontrola dospupnosti
        {
            cout << "Transakcia zamietnuta" << endl;
        }
        else
        {
            if (menu != 'n')
            {
                cout << "Predalo sa " << pieces << " ks z polozky 3" << endl;
            }
            while (pieces != 0)
            {
                magazine3.pop();
                pieces--;
            }
        }
    }
}

void print1()                                                                            //tlac prvej polozky
{
    help = magazine1;
    while (!magazine1.empty())
    {
        magazine1.front();
        if (magazine1.front() != value)
        {
            if (value > 0)
            {
                if (menu == 's' || menu == 'i')
                {
                    cout << "Polozka 1 obsahuje: " << pcs << " ks v cene : " << value << endl;
                }
                else if (menu == 'w')
                {
                    output << "Polozka 1 obsahuje: " << pcs << " ks v cene : " << value << endl;
                }
                pcs = 0;
            }
            value = magazine1.front();
        }
        if (magazine1.front() == value)
        {
            pcs++;
            sum = sum + value;
        }
        magazine1.pop();
    }
    if (menu == 's' || menu == 'i')
    {
        cout << "Polozka 1 obsahuje: " << pcs << " ks v cene : " << value << endl;
         if (menu == 's')
          {
             cout << "\t\t\tCelkova hodnota je: " << sum << endl;
          }
    }
    else if (menu == 'w')
    {
        output << "Polozka 1 obsahuje: " << pcs << " ks v cene : " << value << endl;
        output << "\t\t\tCelkova hodnota je: " << sum << endl;
    }
    pcs = 0; value = 0; sum = 0;
    magazine1 = help;
    while (!help.empty())
    {
        help.front();
        help.pop();
    }
}
void print2()                                                                               //tlac druhej polozky
{
    help = magazine2;
    while (!magazine2.empty())
    {
        magazine2.front();
        if (magazine2.front() != value)
        {
            if (value > 0)
            {
                if (menu == 's' || menu == 'i')
                {
                    cout << "Polozka 2 obsahuje: " << pcs << " ks v cene : " << value << endl;
                }
                else if (menu == 'w')
                {
                    output << "Polozka 2 obsahuje: " << pcs << " ks v cene : " << value << endl;
                }
                pcs = 0;
            }
            value = magazine2.front();
        }
        if (magazine2.front() == value)
        {
            pcs++;
            sum = sum + value;
        }
        magazine2.pop();
    }
    if (menu == 's' || menu == 'i')
    {
        cout << "Polozka 2 obsahuje: " << pcs << " ks v cene : " << value << endl;
        if (menu == 's')
        {
            cout << "\t\t\tCelkova hodnota je: " << sum << endl;
        }
    }
    else if (menu == 'w')
    {
        output << "Polozka 2 obsahuje: " << pcs << " ks v cene : " << value << endl;
        output << "\t\t\tCelkova hodnota je: " << sum << endl;
    }
    pcs = 0; value = 0; sum = 0;
    magazine2 = help;
    while (!help.empty())
    {
        help.front();
        help.pop();
    }
}
void print3()                                                                               //tlac tretej polozky
{   
    help = magazine3;
    while (!magazine3.empty())
    {
        magazine3.front();
        if (magazine3.front() != value)
        {
            if (value > 0)
            {
                if (menu == 's' ||menu== 'i')
                {
                    cout << "Polozka 3 obsahuje: " << pcs << " ks v cene : " << value << endl;
                }
                else if (menu == 'w')
                {
                    output << "Polozka 3 obsahuje: " << pcs << " ks v cene : " << value << endl;
                }
                pcs = 0;
            }
            value = magazine3.front();
        }
        if (magazine3.front() == value)
        {
            pcs++;
            sum = sum + value;
        }
        magazine3.pop();
    }
    if (menu == 's' ||menu== 'i')
    {
        cout << "Polozka 3 obsahuje: " << pcs << " ks v cene : " << value << endl;
        if (menu == 's')
        {
            cout << "\t\t\tCelkova hodnota je: " << sum << endl;
        }
    }
    else if (menu == 'w')
    {
        output << "Polozka 3 obsahuje: " << pcs << " ks v cene : " << value << endl;
        output << "\t\t\tCelkova hodnota je: " << sum << endl<<endl;
    }
    pcs = 0; value = 0; sum = 0;
    magazine3 = help;
    while (!help.empty())
    {
        help.front();
        help.pop();
    }
}

int main()                                                                               //hlavny program
{
   
    input.open("inventar.txt", ifstream::in);                                            //otvorenie vstupneho suboru
    output.open("out.txt", ofstream::out);                                               //otvorenie vystupneho suboru
    

    while (menu != 'e')                                                                  //zaciatok slucky
    {
        cout << "\t  <i>    inventar \t vypis inventar pre cislo polozky" << endl;       //hlavne menu
        cout << "\t  <k>    kup \t\t nakup kusov pre cislo polozky" << endl;
        cout << "\t  <p>    predaj \t predaj kusov pre cislo polozky" << endl;
        cout << "\t  <n>    nacitaj \t nacitaj inventar zo suboru" << endl;
        cout << "\t  <s>    statistika \t vypis statistiku zbozia" << endl;
        cout << "\t  <w>    write \t\t zapis inventar do suboru" << endl;
        cout << "\t  <e>    exit \t\t ukoncit program" << endl;
        cout << "Z akeho menu mam hladat? ";
        cin >> menu;
        switch (menu)
        {
        case 'i':                                                                        //volba pre inventar
            cout << "Pre ktoru polozka: ";
            cin >> item;
            if (item == 1)
            {
                print1();
            }
            else if (item == 2)
            {
                print2();
            }
            else if (item == 3)
            {
                print3();
            }
            else
            {
                cout << "Zadal si hlupost " << endl;
            }
            break;
        case 'k':                                                                        //volba pre kupa
            cout << "Polozka: ";
            cin >> item;
            symbol = 'K';
            cout << "Pocet: ";
            cin >> pieces;
            cout << "Cena: ";
            cin >> price;
            if (item == 1)
            {
                tomagazine1();
            }
            else if (item == 2)
            {
                tomagazine2();
            }
            else if (item == 3)
            {
                tomagazine3();
            }
            else
            {
                cout << "Zadal si hlupost " << endl;
            }
            break;
        case 'p':                                                                        //volba pre predaj
            cout << "Polozka: ";
            cin >> item;
            symbol = 'P';
            cout << "Pocet: ";
            cin >> pieces;
            if (item == 1)
            {
                tomagazine1();
            }
            else if (item == 2)
            {
                tomagazine2();
            }
            else if (item == 3)
            {
                tomagazine3();
            }
            else
            {
                cout << "Zadal si hlupost " << endl;
            }
            break;
        case 'n':                                                                        //volba nacitanie zo subora
            if (input)
            {
                cout << "Otvorenie prebehlo uspesne " << endl;
                while (input.good())
                {
                    if (input >> item, input >> symbol, input >> pieces, input >> price)
                    {
                        if (item == 1)
                        {
                            tomagazine1();
                        }
                        else if (item == 2)
                        {
                            tomagazine2();
                        }
                        else if (item == 3)
                        {
                            tomagazine3();
                        }
                        else
                        {
                            cout << "Zadal si hlupost " << endl;
                        }
                    }
                }
              cout << "Nacitanie inventara prebehlo v poriadku. " << endl;
            }
            else
            {
                cout << "Subor sa nenasiel " << endl;
            }
            break;
        case 's':                                                                        //volba pre statistiku 
            print1();
            print2();
            print3();
            break;
        case 'w':                                                                        //volba pre tlac do subora
            print1();
            print2();
            print3();
            cout << "Inventar bol zapisany do s suboru " << endl;
            break;
        case 'e':                                                                        //volba pre ukoncenie slucky
            cout << "Tvoja volba na ukoncenie programu " << endl;
            break;
        default:
            string nothing;
            cin >> nothing;
            cout << "Zadal si hlupost " << endl;
            continue;
        }
    }

    input.close();                                                      //zavretie vstupu
    output.close();                                                     //zavretie vystupu

    system("pause");
    return 0;
}