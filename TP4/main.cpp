#include <string>
#include "type_def.h"
#include "utilitaires.h"

using namespace std;

int main(){
	int nbNom, nbPrenom;
	string *nom=initTabNomPrenom("Noms_TP5.txt",nbNom), *prenom=initTabNomPrenom("Prenom_TP5.txt",nbPrenom);
	string temp=nom[1];
	personne per=genererPersonne(nom, prenom,nbNom, nbPrenom);
	return 0;
}
