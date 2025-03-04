#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#include <time.h> /* knižnica potrebna ku generatoru */

int main(void)
{
	int i, nahodne_cislo,pokus=0;
	char znak;

	printf("Myslim si jedno cislo od 1 po 50\n");
	srand(time(0)); /* inicializacia generatora nahodnych cisiel */

	for (i = 0; i < 1; i++)
	{
		nahodne_cislo = rand() % 50 + 1; /* rozsah 1 až 100 */
		
	}
	printf("Hadaj cislo ktore mam na mysli ");
	
	while (scanf("%d",&pokus))
	{
		if (pokus < 1 || pokus>50)
		{
			printf("Ty pako ved som napisal ze od 1 do 50\n");
		}
		if (pokus < nahodne_cislo)
		{
			printf("Nie cislo je vacsie skus znovu: ");
		}
		if (pokus > nahodne_cislo)
		{
			printf("Nie cislo je mensie skus znovu: ");
		}
		if (pokus==nahodne_cislo)
		{
			printf("Bingo\nMal som na mysli cislo %d\n",nahodne_cislo);
			system("pause");
			return 0;
		}
	}
}