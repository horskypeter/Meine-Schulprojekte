#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
int kontrola_suboru(int typ);


int main(int argc, const char* argv[])
{
	//pouzite premenne
	FILE* kluc, * text;
	char znak = 0;
	int num;
	int pocet = 0;
	int vysledok;

	//1. funkcia zistenie ci subor existuje
	vysledok = kontrola_suboru(1);
	if (vysledok == 0)//ak sa nepodarilo otvorit subor program sa ukonci
	{
		system("pause");
		return 0;
	}
	//otvorenie suboru
	kluc = fopen("kluc.txt", "r");
	//zistenie pocet klucov
	while (fscanf(kluc, "%d %c", &num, &znak) > 0)
	{
		pocet++;
	}
	//vrati subor na zaciatok inak by boto treba subor zavriet a znovu otvorit
	rewind(kluc);
	//alokacia pamate podla poctu klucov
	char* keys = malloc(sizeof(char) * pocet);
	while (fscanf(kluc, "%d %c", &num, &znak) > 0)
	{
		/*
			pre vytlacenie priebehu ukladania
			printf("Sifra %d %c\n", num, znak);
		*/
		keys[num] = znak;
	}
	//2. funkcia zistenie ci subor existuje
	vysledok = kontrola_suboru(2);
	if (vysledok == 0)//ak sa nepodarilo otvorit subor program sa ukonci
	{
		system("pause");
		return 0;
	}
	text = fopen("text.txt", "r");

	//otvorenie na zapis prekladu a nasledne zapisovanie
	FILE* preklad = fopen("preklad.txt", "w");
	while (fscanf(text, "%d", &num) > 0)
	{

		if (num > pocet)
		{
			printf(" ");
			fprintf(preklad, " ");
		}
		else
		{
			printf("%c", keys[num]);
			fprintf(preklad, "%c", keys[num]);
		}

	}
	printf("\n");

	//uzatvaranie
	fclose(preklad);
	fclose(text);
	fclose(kluc);
	// uvolnenie pamate
	free(keys);

	system("pause");
	return 0;
}
/*
	ina verzi tlace na monitor a aj do suboru
	while (fscanf(text, "%d", &num) > 0)
	{
		if (num > pocet)
		{
			printf(" ");
			fprintf(preklad, " ");
		}
		else
		{
			printf("%c", keys[num]);
			fprintf(preklad, "%c", keys[num]);
		}
	}
*/