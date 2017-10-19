#include <string>
#include "utilitaires.h"

#include <iostream>
using namespace std;

const int MAXNUM=15000;

int main(){
	string nom[MAXNUM],prenom[MAXNUM];
	int nbNom(initTabNomPrenom("Noms_TP5.txt",nom)), nbPrenom(initTabNomPrenom("Prenoms_TP5.txt",prenom));
	cout << nbNom << " " << nbPrenom << endl;
	personne per(genererPersonne(nom, prenom,nbNom, nbPrenom));
	return 0;
}
