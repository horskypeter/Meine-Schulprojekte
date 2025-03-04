
/**************************************************************************
Hlavolam "patnastka"

// Modelovanie a simulacia:
// zjednodusena implementacia rubikovej kocky
// zdrojovy text na volne pouzitie
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning(disable : 4996)
/**************************************************************************

  hlavolam 15:
  vektor s cielovou poziciou 15 kamenov (0 - prazdne miesto, ktorym tahame)


                        0   1   2   3

                        4   5   6   7

                        8   9  10  11

                       12  13  14  15

*/

#define DIM 16      /* rozmer stavoveho vektora (pozicie kamenov) */

int state[DIM] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 }; // stavovy vektor hry
int stat0[DIM];                                         // kopia na ulozenie predosleho stavu

int pos[DIM][2] =         /* pociatocne pozicie kamenov v suradniciach x,y: pos[x][y]
                            pozicia [0,0] je vlavo hore */
{
  {0,0},
  {1,0},
  {2,0},
  {3,0},
  {0,1},
  {1,1},
  {2,1},
  {3,1},
  {0,2},
  {1,2},
  {2,2},
  {3,2},
  {0,3},
  {1,3},
  {2,3},
  {3,3},
};


/**************************************/
// deklaracie funkcii pre externe ucely
int  evaluategame(void);
void showgame(void);
int  position0(void);
int  randint(int base);
int  abs(int x);
int  movegame(int optor);
void mixgame(void);
void undogame(void);
int  bestmove(void);


/******************************************************************************/
// vypocet "manhattanskej vzdialenosti" kazdeho kamena od jeho cielovej pozicie
int evaluategame(void)
{
    int i, n, sum;

    sum = 0;
    for (i = 0; i < DIM; i++)
    {
        n = state[i];
        sum = sum + abs(pos[n][0] - pos[i][0]) + abs(pos[n][1] - pos[i][1]);
        //vypocet rozdielov suradnic: x-x1 + y-y1
    }
    return(sum);
}


/*************************************/
// vypis stavu hry na textovy terminal
void showgame(void)
{
    int i;
    char stat[DIM];

    for (i = 0; i < DIM; i++) // konverzia na prijemnejsie znaky
    {
        if (state[i] == 0)               stat[i] = '0';
        if (state[i] > 0 && state[i] < 10) stat[i] = state[i] + '0';
        if (state[i] >= 10)              stat[i] = state[i] - 10 + 'A';
    }

    printf("\n\n");
    printf("    %c  %c  %c  %c\n", stat[0], stat[1], stat[2], stat[3]);
    printf("    %c  %c  %c  %c\n", stat[4], stat[5], stat[6], stat[7]);
    printf("    %c  %c  %c  %c\n", stat[8], stat[9], stat[10], stat[11]);
    printf("    %c  %c  %c  %c\n", stat[12], stat[13], stat[14], stat[15]);
    printf("\n    ohodnotenie stavu: %d\n", evaluategame());
}


/********************************/
// najdi poziciu prazdneho miesta
int position0(void)
{
    int i;
    for (i = 0; i < DIM; i++)
        if (state[i] == 0) return(i);
    return(-1);
}


/**************************************************************/
// nahodne cele cislo z intervalu <0,base>
int randint(int base)
{
    return((int)((double)(rand()) / RAND_MAX * (base)));
}


/**************************************************************/
int abs(int x)
{
    if (x < 0) return(-1 * x);
    else    return(x);
}


/*************************************************************************/
// tahanie 0-hore, 1-vpravo, 2-dole, 3-vlavo  (TAHAME PRAZDNYM MIESTOM!!!)
int movegame(int optor)
{
    int pos, i;

    //printf("taham:%d ",optor);

    if (optor < 0) return(0); // netaham

    for (i = 0; i < DIM; i++) stat0[i] = state[i]; // uloz predosly stav

    pos = position0(); // kde je prazdne miesto?

    if (optor == 0)
    {
        if (pos == 0 || pos == 1 || pos == 2 || pos == 3) return(0); // niet kam tahat
        else
        {
            state[pos] = state[pos - 4];
            state[pos - 4] = 0;
        }
    }

    if (optor == 1)
    {
        if (pos == 3 || pos == 7 || pos == 11 || pos == 15) return(0);
        else
        {
            state[pos] = state[pos + 1];
            state[pos + 1] = 0;
        }
    }

    if (optor == 2)
    {
        if (pos == 12 || pos == 13 || pos == 14 || pos == 15) return(0);
        else
        {
            state[pos] = state[pos + 4];
            state[pos + 4] = 0;
        }
    }

    if (optor == 3)
    {
        if (pos == 0 || pos == 4 || pos == 8 || pos == 12) return(0);
        else
        {
            state[pos] = state[pos - 1];
            state[pos - 1] = 0;
        }
    }

    return(1);
}


/**************/
// miesanie hry
void mixgame(void) // nahodnymi tahmi zamiesaj hru
{
    int i;
    srand(time(0));

    for (i = 0; i < 10000; i++) movegame(randint(4)); // magicke cislo je zvoleny pocet nahodnych tahov
}


/***************************************************/
// navrat pozicie o jeden tah dozadu (operacia UNDO)
void undogame(void)
{
    int i;
    for (i = 0; i < DIM; i++) state[i] = stat0[i];
}


/*************************************/
// najdi najlepsi tah v danej situacii
int bestmove(void)
{
    int e, eval, move = 4;
    //printf("\nhladam najlepsi tah, skusam vsetky styri moznosti: ");

    eval = evaluategame();

    movegame(0);
    e = evaluategame();
    if (e < eval) { eval = e; move = 0; }
    undogame();

    movegame(1);
    e = evaluategame();
    if (e < eval) { eval = e; move = 1; }
    undogame();

    movegame(2);
    e = evaluategame();
    if (e < eval) { eval = e; move = 2; }
    undogame();

    movegame(3);
    e = evaluategame();
    if (e < eval) { eval = e; move = 3; }
    undogame();

    if (move == 4) return(-1); // ani jeden tah nevyhovuje
    else        return(move);
}


/*********/
// M A I N

int main_1(void) // strategia "hill climbing" (horolezecky optimalizacny algoritmus)
{
    int i;

    mixgame();

    while (1)
    {
        showgame();
        i = bestmove();
        if (i == 0) printf("\nnajlepsi tah je zhora, urob ho!\n");
        if (i == 1) printf("\nnajlepsi tah je zprava, urob ho!\n");
        if (i == 2) printf("\nnajlepsi tah je zdola, urob ho!\n");
        if (i == 3) printf("\nnajlepsi tah je zlava, urob ho!\n");
        if (i < 0) { printf("\nnie je kam tahat pre zlepsenie stavu\n"); return 0; }
        movegame(i);
        printf("\n\nstlac Enter"); (void)getchar();
    }

    return 0;
}


int main_2(void) // strategia "random walking" (nahodne kracanie)
{
    mixgame();

    while (1) // random walking
    {
        showgame();
        printf("\n\nstlac Enter"); (void)getchar();
        movegame(randint(4));
    }
    return 0;
}


int main_3(void) // strategia nahodneho hladania
{
    int temp, e, f, c;

    mixgame();
    showgame();
    e = evaluategame();

    for (temp = 1000; temp > 0; temp--)
    {
        for (c = 0; c < 1000; c++) movegame(randint(4));   // random move
        //if(0==temp%100) printf("*");
        f = evaluategame();
        if (f < e) e = f;
    }

    printf("\nnajmensia doteraz dosiahnuta hodnota %d", e);
    printf("\n\nstlac Enter"); (void)getchar();
    return 0;
}


int main(void) // strategia simulovaneho zihania
{
    int temp, i, j, c;

    mixgame();
    showgame();
    i = j = 0;

    for (temp = 1000; temp > 1; temp--)
    {
        for (c = 0; c < 1000; c++)
        {
            if (randint(1000) > temp) { movegame(bestmove()); i++; }  // deterministic move
            else { movegame(randint(4)); j++; }  // random move
            if (0 == evaluategame()) break;
        }
        if (0 == temp % 100) { printf("\n<%d %d>", i, j); i = j = 0; }
        if (0 == evaluategame()) break;
    }

    showgame();
    printf("\n\nstlac Enter"); (void)getchar();
    return 0;
}