/*
fichier entierlong.h
pour d�finir le type EntierLong
*/

const int MAXCHIFFRES = 20;

typedef int tabEnt[MAXCHIFFRES];

struct EntierLong
{
    bool Negatif;
    tabEnt Chiffres;
};
