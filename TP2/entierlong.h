/*
fichier entierlong.h
pour définir le type EntierLong
*/

const int MAXCHIFFRES = 20;

typedef int tabEnt[MAXCHIFFRES];

struct EntierLong
{
    bool Negatif;
    tabEnt Chiffres;
};
