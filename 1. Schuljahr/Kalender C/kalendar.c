#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#include "rok.h" 
#include "mesiace.h"
#define NIE_ROK 0
int priestupny_rok(int rok);

int main(void)
{
	//deklaracia premennych
	int i;
	int a = 0, b = 0, emesiac = 0;
	int rok = 0, den = 0, cislo = 0;
	char znak;
	//vystup na monitore
	printf("Zadaj rok, pre ktory chces kalendar : \n");
	i = scanf("%i%c", &rok, &znak);
	//funkcia na vypocet priestupneho roku 
	priestupny_rok(rok);
	//podmienky aby precitalo len cislo a jediny povoleny znak je novy riadok inak vypise zly vstup
	if (priestupny_rok(rok) == 1)
	{
		printf("Rok %i je priestupny.\n", rok);
	}
	else
	{
		printf("Rok %i nie je priestupny.\n", rok);
	}
	if (znak == '\n')
		i = 1;
	if (i == 0 || i == 2)
	{
		printf("Zadal si zly vstup. \n");
		return 0;
	}
	//ak prebeholo uspesne nacitanie roku tak program pokracuje
	else if (i == 1)
	{
		printf("\nNa ktory den pripadne 1. Januar %i ?: \n", rok);
		scanf_s("%i", &den);
		//podmienka na zadanie 
		if (den < 1 || den > 7)
		{
			printf("Zadal si zly vstup. \n");
			return 0;
		}
		//tlac do subora
		FILE* subor = fopen("vystup.txt", "w");
		fprintf(subor, "Zadaj rok, pre ktory chces kalendar : \n");
		fprintf(subor, "%i", rok);
		fprintf(subor, "\nNa ktory den pripadne 1. Januar %i ?: \n", rok);
		fprintf(subor, "%i", den);
		//nacitanie programu mesiace.c 
		while ((emesiac_smesiac(emesiac)) > '12')
		{
			printf("\n%s %i \n", emesiac_smesiac(emesiac),rok);
			fprintf(subor, "\n%s %i \n", emesiac_smesiac(emesiac),rok);
			printf(" P  U  S  S  P  S  N\n");
			fprintf(subor, " P  U  S  S  P  S  N\n");
			printf("--------------------\n");
			fprintf(subor, "--------------------\n");
			//rozmnozenie dna pre urcenie poctu medzier
			a = den;
			//opakuj pokial den(nacitane)odrataj -1 a porovnaj ci je vacsie ako cislo (0)
			while (a - 1 > cislo)
			{
				printf("   ");
				fprintf(subor, "   ");
				a--;
			}
			//vypocet priestupneho roku
			emesiac++;
			if (priestupny_rok(rok) == 1)
			{
				if (emesiac == 2)
					b = 29;
				else if (emesiac == 1 || emesiac == 3 || emesiac == 5 || emesiac == 7 || emesiac == 8 || emesiac == 10 || emesiac == 12)
					b = 31;
				else if (emesiac == 4 || emesiac == 6 || emesiac == 9 || emesiac == 11)
					b = 30;
			}
			//urcenie poctu dni v prislusnom mesiaci
			else
			{
				if (emesiac == 2)
					b = 28;
				else if (emesiac == 1 || emesiac == 3 || emesiac == 5 || emesiac == 7 || emesiac == 8 || emesiac == 10 || emesiac == 12)
					b = 31;
				else if (emesiac == 4 || emesiac == 6 || emesiac == 9 || emesiac == 11)
					b = 30;
			}
			//opakuj pokial cislo (0) je mensi ako b (pocet dni)
			while (cislo < b)
			{
				cislo++;
				if (cislo < 10)
				{
					printf(" %d ", cislo);
					fprintf(subor, " %d ", cislo);
				}
				else
				{
					printf("%d ", cislo);
					fprintf(subor, "%d ", cislo);
				}
				if (den == 7)
				{
					printf("\n");
					fprintf(subor, "\n");
					den = 0;
				}
				den++;
			}
			cislo = 0;
			printf("\n");
			fprintf(subor, "\n");
		}
		fclose(subor);
	}
	system("pause");
	return (0);
}