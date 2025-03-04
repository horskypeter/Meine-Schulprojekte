/*
hlavickovy subor pre mesiace.c
 deklaruje a definuje:
 - emesiac_smesiac()
*/
typedef enum { eJAN, eFEB, eMAR, eAPR, eMAI, eJUN, eJUL, eAUG, eSEP, eOKT, eNOV, eDEC } tmesiac;
const char* emesiac_smesiac(tmesiac m);

