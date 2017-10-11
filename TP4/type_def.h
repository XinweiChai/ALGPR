#include <string>

using namespace std;

struct personne{
	string nom;
	string prenom;
	string nSec;
};

typedef personne vectPersonne [1000];

struct elementListe{
	personne per;
	personne* suiv;
	personne* prec;
};

struct noeud{
	personne per;
	personne* droit;
	personne gauche;
};
