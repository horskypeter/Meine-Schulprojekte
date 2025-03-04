//pouzita kniznica
#include <stdio.h>
//definovanie co je zaklad
#define zaklad 20000.0f
 
//hlavny program
int main(void)
{
//premenne a ich nazov
	float cislo,prvasplatka=0;
	char znak;
//text ktory ziada o zadanie vstupu s ktorym bude program pracovat 
	printf("Zadaj sumu, ktoru si chces pozicat: \n");
//zoskenovanie zadaneho textu(popripade znakov)a pridelenie hodnoty
	int i=scanf("%f%c",&cislo,&znak);
//ak sa nacitaju menej ako dve premenne alebo znak nie je novy riadok alebo cislo je mensie rovne ako 0 potom zly vstup
	if (i < 2 || znak != '\n'|| cislo <= 0 )
	{
		printf("Zly vstup\n");
	}
	else 
	{
		//priklad 1
		if (cislo < zaklad)
			prvasplatka = cislo / 100.0f;
		//priklad 2
		else if (cislo <= 49999.99f)
			prvasplatka = (cislo - zaklad) * 0.02f + 200.0f;
		//definovanie pre ostatne pripady
		else if (cislo >= 50000.0f && cislo <= 150000.0f)
			prvasplatka = (cislo - zaklad) * 0.03f + 800.0f;
		//priklad 3
		else if (cislo > 150000.0f)
			printf("Banka neschvaluje pozicky nad 150 000 Eur!!!\n");
		//vyriesenie problemu s automatickym zaukruhlovanim
		if (prvasplatka > 0)
		{
			long zaokruhlenie = (long)(prvasplatka * 100.0f);
			prvasplatka = (float)zaokruhlenie / 100.0f;
			printf("Pri schvaleni pozicky na %.2f: %.2f eur\n", cislo, prvasplatka);
		}
	}
	printf("Koniec programu\n");
	return 0;
}