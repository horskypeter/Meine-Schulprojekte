#include <iostream>
#include <fstream>
#include <string>
 using namespace std;
string words[30], meaning[30];
ifstream input;
ofstream output;
string beginning ;
string middle;
string ending;


void function_one()                                               //Funkcia ktora pracuje zo znakmi ktore sa nachadzaju na zaciatku
{
    int count = 0;
    cout << "Zadaj znaky ktore su na zaciatku slova ";
    cin >> beginning;
    output << "Zadaj znaky ktore su na zaciatku slova "<< beginning << endl;
    for (int i=0; i < 30; i++)
    {
        if (words[i].rfind(beginning, 0) == 0)                      //zistenie poctu uspesne najdenych slov
        {                                           
            count++;
        }
    }
    if (count > 1)                                                 //ak bolo viacej uspesnych najdeni
    {
        for (int i = 0; i < 30; i++)
        {
            if (words[i].rfind(beginning, 0) == 0)
            {                                               
                cout << "slovo:" << words[i] << endl;
                output << "slovo:" << words[i] << endl;
            }
        }
    }
    if (count == 1)                                                 //ak bolo len jedno uspesne najdenie
    {
        for (int i= 0; i < 30; i++)                             
        {
            if (words[i].rfind(beginning, 0) == 0)
            {
                cout << "slovo:" << words[i] << "\tvyznam:" << meaning[i] << endl;
                output << "slovo:" << words[i] << "\tvyznam:" << meaning[i] << endl;
            }
        }
    }
    if (count == 0)                                                 //ak nenacita ziadne uspesne najdenie
    {
         cout << "Slovo "<< beginning <<" nie je v slovniku" << endl;
         output << "Slovo " << beginning << " nie je v slovniku" << endl;
    }
}
void function_two()                                                  //Funkcia ktora pracuje zo znakmi ktore sa nachadzaju v strede
{
    int count=0;
    cout << "Zadaj znaky ktore sa maju nachadzat v slove ";
    cin >> middle;
    output << "Zadaj znaky ktore sa maju nachadzat v slove " << middle << endl;
    for (int i=0; i < 30; i++)
    {
        size_t found = words[i].find(middle);
        if (found != string::npos)                                  //zistenie poctu uspesne najdenych slov
        {
            count++;
        }
    }
    if (count > 1)                                                  //ak bolo viacej uspesnych najdeni
    {
        for (int i = 0; i < 30; i++)
        {
            size_t found = words[i].find(middle);
            if (found != string::npos)
            {
                cout << "slovo:" << words[i] << endl;
                output << "slovo:" << words[i] << endl;
            }
        }
    }
    if (count == 1)
    {
        for (int i = 0; i < 30; i++)                                //ak bolo len jedno uspesne najdenie
        {
            size_t found = words[i].find(middle);
            if (found != string::npos)
            {
                cout << "slovo:" << words[i] << "\tvyznam:" << meaning[i] << endl;
                output << "slovo:" << words[i] << "\tvyznam:" << meaning[i] << endl;
            }
        }
    }
    if (count == 0)                                                  //ak nenacita ziadne uspesne najdenie
    {
        cout << "Slovo "<< middle <<" nie je v slovniku" << endl;
        output << "Slovo " << middle << " nie je v slovniku" << endl;
    }
}
void function_three()                                                 //Funkcia ktora pracuje zo znakmi ktore sa nachadzaju na konci
{
    int count = 0;
    cout << "Zadaj znaky ktore su na konci slova ";
     cin >> ending;
     output << "Zadaj znaky ktore su na konci slova " << ending << endl;
    for (int i=0; i < 30; i++)
    {
        string reversed = words[i];                                  //otocenie slova
        reverse(reversed.begin(), reversed.end());
        if (reversed.rfind(ending, 0) == 0)                           //zistenie poctu uspesne najdenych slov
        {
            count++;
        }
    }
    if (count > 1)                                                      //ak bolo viacej uspesnych najdeni
    {
        for (int i = 0; i < 30; i++)                            
        {
            string reversed = words[i];
            reverse(reversed.begin(), reversed.end());
            if (reversed.rfind(ending, 0) == 0)
            {
                cout << "slovo:" << words[i] << endl;
                output << "slovo:" << words[i] << endl;
            }
        }
    }
    if (count == 1)                                             //ak bolo len jedno uspesne najdenie
    {
        for (int i = 0; i < 30; i++)
        {
            string reversed = words[i];
            reverse(reversed.begin(), reversed.end());
            if (reversed.rfind(ending, 0) == 0)
            {
                cout << "slovo:" << words[i] << "\tvyznam:\t" << meaning[i] << endl;
                output << "slovo:" << words[i] << "\tvyznam:\t" << meaning[i] << endl;
            }
        }
    }
        if (count == 0)                                          //ak nenacita ziadne uspesne najdenie
        {
            cout << "Slovo "<< ending <<" nie je v slovniku" << endl;
            output << "Slovo " << ending << " nie je v slovniku" << endl;
        }
}
                        //zaciatok hlavneho programu
int main()
{
    input.open("slovnik.txt", ifstream::in);                        //otvorenie vstupneho suboru
    output.open("out.txt", ofstream::out);                          //otvorenie vystupneho suboru
    if (input)
    {
        cout << "Otvorenie prebehlo uspesne" << endl;
    }                                                                     //kontrola vstupneho suboru      
    else
    {                                                                       
        cout << "Subor sa nenasiel" << endl;
    }
    cout << "Menu" << endl;                                                 //hlavne menu
    output << "Menu" << endl;
    cout << "1-starting  \t najdi vyznam slova zacinajuceho danymi znakmi" << endl;
    output << "1-starting  \t najdi vyznam slova zacinajuceho danymi znakmi" << endl;
    cout << "2-containing \t najdi vyznam slova obsahujuceho dane znaky" << endl;
    output << "2-containing \t najdi vyznam slova obsahujuceho dane znaky" << endl;
    cout << "3-ending \t najdi vyznam slova konciaceho danymi znakmi" << endl;
    output << "3-ending \t najdi vyznam slova konciaceho danymi znakmi" << endl;
    cout << "4-stop \t\t ukonci dany program" << endl;
    output << "4-stop \t\t ukonci dany program" << endl<<endl;

    if (input.is_open())
    {
        input.clear();
        input.seekg(0);

        int position = 0;
        while (!input.eof())
        {
            string slovo = "";
            string vyznam = "";
            getline(input, slovo, ';');                             //nacitanie dat zo vstupu 
            getline(input, vyznam, '\n');

            size_t found1 = slovo.find_first_not_of(" ");           //vymazanie znakov vpredu pred slovom
            slovo.replace(0, found1, "");

            size_t found2 = vyznam.find_first_not_of(" ");            //vymazanie znakov pred vyznamom
            vyznam.replace(0, found2, "");

            string whitespaces(" \t\f\v\n\r");                      //vymazanie znakov za slovom
            size_t found3 = slovo.find_last_not_of(whitespaces);
            if (found3 != string::npos)
            {
                slovo.erase(found3 + 1);
            }
            else
            {
                slovo.clear();
            }

            size_t found4 = vyznam.find_last_not_of(whitespaces);       //vymazanie znakov za vyznamom
            if (found4 != string::npos)
            {
                vyznam.erase(found4 + 1);
            }
            else
            {
                vyznam.clear();
            }

            words[position] = slovo;                                     //ukladanie  do pamate
            meaning[position] = vyznam;
            position++;
        }
        char input = 0;
        while (input != 4)                                                  //opakovanie menu pokial volba nebude 4
        {
            int count = 0;
            cout << "Z akeho menu mam hladat? ";
            cin >> input;
            output << "Z akeho menu mam hladat? " << input << endl;
            switch (input)
            {
            case '1':                                                    //rozdelenie podla volby
                function_one();
                break;
            case '2':
                function_two();
                break;
            case '3':
                function_three();
                break;
            case '4': cout << "Tvoja volba na ukoncenie programu" << endl;
                output << "Tvoja volba na ukoncenie programu" << endl;
                input = 4;
                break;
            default:
                string nothing;
                cin >> nothing;
                cout << "Zadal si hlupost" << endl;
                output << "Zadal si hlupost" << endl;
                break;
            }
        }
    }
    else
    {
             cout << "Vstup nie je otvoreny"<<endl;
    }
    
  
    input.close();                                                      //zavretie vstupu
    output.close();                                                     //zavretie vystupu

    system("pause");
    return 0;
}