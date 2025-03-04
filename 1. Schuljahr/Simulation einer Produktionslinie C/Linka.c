
// Modelovanie a simulacia:
// jednoducha implementacia modelu riadenej vyrobnej linky
// zdrojovy text na volne pouzitie

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

#define doprava   5                         // kolko krokov trva doprava dopravnikom
#define obrabanie 5                         // kolko krokov prebieha obrabanie

enum { prazdny = ' ', plny = '*' };         // senzor detekuje pritomnost predmetu
enum { stoji = 0, bezi = 1 };               // stav dopravnika aj obrabania

struct vyrobna_linka
{
    // senzory v stave prazdne/plne
    int senzor1;
    int senzor2;
    int senzor3;
    int senzor4;
    int senzor5;
    int senzor6;

    // dopravniky v stave stoji/bezi
    int dopravnik1;
    int dopravnik2;

    // dopravniky obsadene predmetom:
    // 0 - nie je, 1 - na konci pasu, N - na zaciatku pasu,
    // N = pocet krokov prechodu zo zaciatku na koniec, odpocitava sa
    int dopravnik1_predmet;
    int dopravnik2_predmet;

    // obrabanie v stave stoji/bezi
    int obrabanie1;
    int obrabanie2;

    // obrabanie obsadene predmetom:
    // 0 - nie je, 1 - dokoncene obrabanie, N - na zaciatku obrabania,
    // N = pocet krokov kolko trva obrabanie, odpocitava sa
    int obrabanie1_predmet;
    int obrabanie2_predmet;

} linka;

void linka_reset(void)
{
    linka.senzor1 = prazdny;
    linka.senzor2 = prazdny;
    linka.senzor3 = prazdny;
    linka.senzor4 = prazdny;
    linka.senzor5 = prazdny;
    linka.senzor6 = prazdny;

    linka.dopravnik1 = stoji;
    linka.dopravnik2 = stoji;

    linka.dopravnik1_predmet = 0;       // nie je na nom predmet
    linka.dopravnik2_predmet = 0;       // nie je na nom predmet

    linka.obrabanie1 = stoji;
    linka.obrabanie2 = stoji;

    linka.obrabanie1_predmet = 0;       // nie je v nom predmet
    linka.obrabanie2_predmet = 0;       // nie je v nom predmet
}

void linka_casovy_krok(void)
{
    if (linka.dopravnik1 == bezi)
        if (linka.dopravnik1_predmet > 1) linka.dopravnik1_predmet--;       // predmet sa posuva po dopravniku 1   

    if (linka.obrabanie1 == bezi)
        if (linka.obrabanie1_predmet > 1) linka.obrabanie1_predmet--;       // predmet sa obraba v zariadeni 1

    if (linka.obrabanie2 == bezi)
        if (linka.obrabanie2_predmet > 1) linka.obrabanie2_predmet--;       // predmet sa obraba v zariadeni 2

    if (linka.dopravnik2 == bezi)
        if (linka.dopravnik2_predmet > 1) linka.dopravnik2_predmet--;       // predmet sa posuva po dopravniku 2
}

void stop(void)
{
    char line[80];
    printf("\n  <Enter>");
    gets(line);
}

void linka_senzory_vystup(void)
{
    if (linka.dopravnik1_predmet == doprava)
        linka.senzor1 = plny;                   // predmet je na zaciatku doopravnika 1
    else  linka.senzor1 = prazdny;

    if (linka.dopravnik1_predmet == 1)
        linka.senzor2 = plny;                   // predmet je na konci dopravnika 1
    else  linka.senzor2 = prazdny;

    if (linka.obrabanie1_predmet > 0)
        linka.senzor3 = plny;                   // predmet je v obrabacom zariadeni 1
    else  linka.senzor3 = prazdny;

    if (linka.obrabanie2_predmet > 0)
        linka.senzor4 = plny;                   // predmet je v obrabacom zariadeni 2
    else  linka.senzor4 = prazdny;

    if (linka.dopravnik2_predmet == doprava)
        linka.senzor5 = plny;                   // predmet je na zaciatku doopravnika 2
    else  linka.senzor5 = prazdny;

    if (linka.dopravnik2_predmet == 1)
        linka.senzor6 = plny;                   // predmet je na konci dopravnika 2
    else  linka.senzor6 = prazdny;
}

void akcia_vloz_predmet(void)                   // na dopravnik1 vlozime predmet
{
    if (linka.dopravnik1_predmet != 0)
    {
        printf("\n  chyba: vkladame predmet na neprazdny dopravnik1"); stop();
    }
    linka.dopravnik1_predmet = doprava;         // zaciatok odpocitavania krokov dopravy
}

void akcia_odober_predmet(void)                 // z konca dopravnika2 vezmeme predmet
{
    if (linka.dopravnik2 != 1)
    {
        printf("\n  chyba: na konci dopravnika2 nie je predmet na odobranie");
        stop();
    }
    linka.dopravnik2_predmet = 0;               // dopravnik vyprazdneny
}

void akcia_podavac1(void)                       // podavac1 vykona celu svoju akciu ihned, v jednom casovom kroku
{
    if (linka.dopravnik1_predmet != 1)
    {
        printf("\n  chyba: podavac1 nenasiel predmet na konci dopravnika1");
        stop(); return;
    }                                           // nema co zobrat
    if (linka.obrabanie1_predmet > 0)
    {
        printf("\n  chyba: obrabanie1 narusene podavacom1");
        stop();
    }                                           // nema to kam dat
    linka.dopravnik1_predmet = 0;               // podavac odoberie predmet z dopravnika1
    linka.obrabanie1_predmet = obrabanie;       // a vlozi ho do obrabania1 a zacne sa pocitat pocet krokov obrabania1
}

void akcia_podavac2(void)                       // podavac2 vykona celu svoju akciu ihned, v jednom casovom kroku
{
    if (linka.obrabanie1_predmet != 1)
    {
        printf("\n  chyba: podavac2 nemoze prevziat predmet z obrabania1");
        stop(); return;                         // odkial
    }                 
    if (linka.obrabanie2_predmet > 0)
    {
        printf("\n  chyba: obrabanie2 narusene podavacom2");
        stop();                                 // kam
    }                         
    linka.obrabanie1_predmet = 0;               // podavac odoberie predmet z obrabania1
    linka.obrabanie2_predmet = obrabanie;       // a vlozi ho do obrabania2 a zacne sa pocitat pocet krokov obrabania2
    }

void akcia_podavac3(void)                       // podavac3 vykona celu svoju akciu ihned, v jednom casovom kroku

{
    if (linka.obrabanie2_predmet != 1)
    {
        printf("\n  chyba: podavac3 nemoze prevziat predmet z obrabania2");
        stop(); return;                          // odkial
    }                 
    if (linka.dopravnik2_predmet > 0)
    {
        printf("\n  chyba: dopravnik2 naruseny podavacom3");
        stop();                                 // kam
    }                          
    linka.obrabanie2_predmet = 0;               // podavac odoberie predmet z obrabania2
    linka.dopravnik2_predmet = doprava;         // a vlozi ho na dopravnik2 a zacne sa pocitat pocet krokov dopravnika2
   }

void akcia_dopravnik1(void)                     // dopravnik1 zapneme/vypneme
{
    if (linka.dopravnik1 == stoji) linka.dopravnik1 = bezi;
    else                          linka.dopravnik1 = stoji;
}

void akcia_dopravnik2(void)                     // dopravnik2 zapneme/vypneme
{
    if (linka.dopravnik2 == stoji) linka.dopravnik2 = bezi;
    else                          linka.dopravnik2 = stoji;
}

void akcia_obrabanie1(void)                     // obrabanie1 zapneme/vypneme
{
    if (linka.obrabanie1 == stoji) linka.obrabanie1 = bezi;
    else                          linka.obrabanie1 = stoji;
}

void akcia_obrabanie2(void)                     // obrabanie2 zapneme/vypneme
{
    if (linka.obrabanie2 == stoji) linka.obrabanie2 = bezi;
    else                          linka.obrabanie2 = stoji;
}

void linka_print(void)
{
    printf("\n\n  stav vyrobnej linky\n\n");

    printf("\n  senzor1    dopravnik1     senzor2");
    printf("\n    (%c) =======> T%d >======== (%c)\n",
        linka.senzor1, linka.dopravnik1_predmet, linka.senzor2);
    if (linka.senzor1 == prazdny)  printf("  prazdny      ");
    else                           printf("   plny        ");
    if (linka.dopravnik1 == stoji) printf("stoji        ");
    else                           printf("bezi         ");
    if (linka.senzor2 == prazdny)  printf("prazdny\n");
    else                           printf(" plny\n");

    printf("\n                               V");
    printf("\n                               V");

    printf("\n                                             obrabanie1      senzor3");
    printf("\n                            podavac1  > > >    (T%d) ---------- (%c)",
        linka.obrabanie1_predmet, linka.senzor3);
    if (linka.obrabanie1 == stoji)
        printf("\n                                               stoji");
    else
        printf("\n                                               bezi ");
    if (linka.senzor3 == prazdny)       printf("         prazdny\n");
    else                                printf("          plny\n");

    printf("\n                                                 V");
    printf("\n                                                 V\n");
    printf("\n                                              podavac2\n");
    printf("\n                                                 V");
    printf("\n                                                 V\n");

    printf("\n                                             obrabanie2      senzor4");
    printf("\n                            podavac3  < < <    (T%d) ---------- (%c)",
        linka.obrabanie2_predmet, linka.senzor4);
    if (linka.obrabanie2 == stoji)
        printf("\n                                               stoji");
    else
        printf("\n                                               bezi ");
    if (linka.senzor4 == prazdny)       printf("         prazdny");
    else                                printf("          plny");

    printf("\n                               V");
    printf("\n                               V\n");

    printf("\n  senzor6    dopravnik2     senzor5");
    printf("\n    (%c) =======< T%d <======== (%c)\n",
        linka.senzor6, linka.dopravnik2_predmet, linka.senzor5);
    if (linka.senzor6 == prazdny)  printf("  prazdny      ");
    else                           printf("   plny        ");
    if (linka.dopravnik2 == stoji) printf("stoji        ");
    else                           printf("bezi         ");
    if (linka.senzor5 == prazdny)  printf("prazdny");
    else                           printf(" plny");
}

void linka_rucne_riadenie(char line[80])
{
    if (line[0] == 'i') akcia_vloz_predmet();           // "insert" na dopravnik1 vlozime predmet
    if (line[0] == 't') akcia_odober_predmet();         // "take" z konca dopravnika2 vezmeme predmet
 

// kazdy podavac vykona celu svoju akciu ihned, v jednom casovom kroku
    if (line[0] == 'p' && line[1] == '1') akcia_podavac1();
    if (line[0] == 'p' && line[1] == '2') akcia_podavac2();
    if (line[0] == 'p' && line[1] == '3') akcia_podavac3();

    if (line[0] == 'd' && line[1] == '1') akcia_dopravnik1(); // dopravnik1 zapneme/vypneme
    if (line[0] == 'd' && line[1] == '2') akcia_dopravnik2(); // dopravnik2 zapneme/vypneme

    if (line[0] == 'o' && line[1] == '1') akcia_obrabanie1(); // obrabanie1 zapneme/vypneme
    if (line[0] == 'o' && line[1] == '2') akcia_obrabanie2(); // obrabanie2 zapneme/vypneme

    if (line[0] == '?')
        // Help me if you can, I'm feeling down, And I do appreciate you being 'round,
        // Help me get my feet back on the ground, Won't you please, please help me?
        // poznas tu pesnicku? napis do reportu :)
    {
        printf("\n  \" \"        - vykona sa iba casovy krok modelu");
        printf("\n  \"e\"        - exit, koniec");
        printf("\n  \"i\"        - vloz na dopravnik");
        printf("\n  \"t\"        - vezmi z dopravnika");
        printf("\n  \"d(cislo)\" - spusti/zastav dopravnik (cislo 1,2)");
        printf("\n  \"p(cislo)\" - vykonaj podavac (cislo 1,2,3)");
        printf("\n  \"o(cislo)\" - spusti/zastav obrabanie (cislo 1,2)\n");
        stop();
    }
}

void linka_automaticke_riadenie(void)
{
    static int miesto[4] = { 1 , 0, 0, 0 };        // miesta v Petriho sieti a pociatocny obsah tokenov
 
     if (miesto[0] == 1)             // ak je token
        if (linka.senzor1 == plny)  // ak je podmienka splnena
        {
            akcia_dopravnik1();      // zapneme dopravnik
            miesto[0] = 0;           // premiestnime token
            miesto[1] = 1;
        }

    if (miesto[1] == 1)             // ak je token
        if (linka.senzor2 == plny)  // ak je podmienka splnena
        {
            akcia_dopravnik1();      // vypneme dopravnik
            miesto[1] = 0;           // premiestnime token
            miesto[2] = 1;
        }

    if (miesto[2] == 1)             // ak je token
        if (1)                      // podmienka nie je
        {
            akcia_podavac1();        // podavac vykona akciu
            miesto[2] = 0;           // premiestnime token
            miesto[0] = 1;
            miesto[3] = 1;
        }

    /*
    zatial nevyuzite akcie:
    akcia_podavac2();
    akcia_podavac3();
    akcia_dopravnik2();
    akcia_obrabanie1();
    akcia_obrabanie2();
    */

    printf("\n\n  riadiace tokeny: "); for (int i = 0; i < 4; i++) printf("%d ", miesto[i]);
    }

int main()
{
    int krok = 0;
    char line[80];
    linka_reset();
    while (1)
    {
        linka_casovy_krok();
        printf("\n\n\n  krok %d: ", krok++);
        gets(line);
        if (line[0] == 'e') break;
        linka_rucne_riadenie(line);    // zasah cloveka
        linka_automaticke_riadenie();  // zasah automatu
        linka_senzory_vystup();
        linka_print();
    }
    return 0;
}