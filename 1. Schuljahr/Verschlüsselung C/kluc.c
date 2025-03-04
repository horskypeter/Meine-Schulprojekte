#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#include "kluc.h"

int kontrola_suboru(int typ)
{
	FILE* subor = NULL;
	if (typ == 1)
	{
		subor = fopen("kluc.txt", "r");


	}
	if (typ == 2)
	{
		subor = fopen("text.txt", "r");


	}
	if (subor == NULL)
	{
		if (typ == 1)
		{
			printf("Subor kluc.txt neexistuje\n");
		}
		else
		{
			if (typ == 2)
			{
				printf("Subor text.txt neexistuje\n");
			}
			else
			{
				printf("Zadany subor neexistuje\n");
			}
		}
		return 0;
	}
	else
	{
		if (typ == 1)
		{
			printf("Subor kluc.txt sa podarilo uspesne nacitat\n");
		}
		if (typ == 2)
		{
			printf("Subor text.txt sa podarilo uspesne nacitat\n");
		}
		fclose(subor);
		return 1;
	}

}