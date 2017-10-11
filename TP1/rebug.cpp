/* rebug.cpp
auteur : Vincent Tourre
date : 23/09/2015

Etape Rebug - vous devez ajouter les bogues donnés par l'enseignant
Rebug stage - you have to add the bugs given by the teacher
*/

// Librairies
#include <iostream>
#include <cstdlib>
using namespace std;

// definition du type vectReels
const int MAX = 50;
typedef float vectReels[MAX];

// fonction lecture
int lecture(vectReels notes)
{
    int nb = 0;
    int tmp;

    cout<<"Saisissez les notes une par une"<<endl;
    cin>>tmp;

    while(tmp >= 0 && nb<MAX)
    {
        notes[nb] = tmp;
        nb = nb + 1;
        if(nb<MAX)
        {
            cout<<"note suivante"<<endl;
            cin>>tmp;
        }
    }

    return nb;
}

// fonction moyenne
float moyenne(vectReels notes, int nbE)
{
    int i;
    float moy;
    moy = 0.0f;
    for(i = 0; i<nbE; i=i+1)
    {
        moy = moy + notes[i];
    }
    moy = moy/nbE;
    return moy;
}

// programme principal
int main()
{
    // déclaration des variables
    vectReels vect;
    int taille;
    float m;

    // obtenir les données
    taille = lecture(vect);

    // traiter les données et afficher
    if(taille > 0)
    {
        m = moyenne(vect, taille);
        cout<<"La moyenne est "<< m <<endl;
    }
    else
    {
        cout<<"Il n'y a pas de notes"<<endl;
    }
    return EXIT_SUCCESS;
}
