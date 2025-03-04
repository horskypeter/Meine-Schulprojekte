#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (((a) >= (b)) ? (a): (b))
#define MIN(a, b) (((a) <= (b)) ? (a): (b))

int main(void)
{
	FILE* subor;
	char znak;
	float cislo = -1, sucet = 0, pocet = 0, max = INT_MIN, min = INT_MAX;
	int i;

	subor = fopen("dataf.txt", "r");
	if (!subor)printf("Zadany subor neexistuje\n");
	else {
		printf("\nZadany subor existuje\n");
		//Pre vytlacenie cisel    
		printf("Subor obsahuje tieto cisla: \n");
		while ((i = fscanf(subor, "%f%c", &cislo, &znak)) != EOF)
		{
			if (i == 0)
			{
				fscanf(subor, "%c", &znak);
				continue;
			};
			if (cislo < 0)printf("%.2f je zaporne cislo a budem ho ignorovat\n", cislo);
			else if (cislo > 100) printf("%.2f je mimo zadany rozzsah a budem ho ignorovat\n", cislo);
			else {
				// Pre vytlacenie cisel 
				printf("%.2f\n", cislo);
				sucet = sucet + cislo;
				pocet++;
				max = MAX(max, cislo);
				min = MIN(min, cislo);
			}
		}
		if (pocet > 0) {
			printf("\nSucet: %.2f \n", sucet);
			printf("Pocet cisel: %.0f \n", pocet);
			printf("Najmensia hodnota je: %.2f \nNajvacsia hodnota je: %.2f \n", min, max);
			printf("Priemer je: %.2f \n", sucet / pocet);
		}
		fclose(subor);
	}
	system("pause");
	return 0;
}