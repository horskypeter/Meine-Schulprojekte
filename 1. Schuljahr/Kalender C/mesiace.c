#include "mesiace.h"
const char* emesiac_smesiac(tmesiac m)
{
	static char* smesiac[eDEC + 1] =
	{ "Januar", "Februar", "Marec", "April","Maj", "Jun", "Jul", "August", "September", "Oktober", "November", "December" };
	return smesiac[m];
}