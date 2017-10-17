#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <cstdio>
#include "type_def.h"
#include <iostream>
using namespace std;


int initTabNomPrenom(string fileName, string* nom){
	int sizefile(0);
	ifstream fn(fileName.c_str());
	fn >> sizefile;
	for (int i=0;i<sizefile;++i){
        fn >> nom[i];
    }
    return sizefile;
}

personne genererPersonne(string* listNom, string* listPrenom, int nbNom, int nbPrenom){
	srand(time(NULL));
	char sexe[1], annee[2], moisNaiss[2], depart[2], commune[3], etatCiv[3];
	sprintf(sexe,"%d",rand()%2+1);
	cout << sexe << endl;
	sprintf(annee,"%02d",rand()%98+1);
	sprintf(moisNaiss,"%02d",rand()%12+1);
	sprintf(depart,"%02d",rand()%98+1);
	sprintf(commune,"%03d",rand()%998+1);
	sprintf(etatCiv,"%03d",rand()%998+1);

	return personne({listNom[rand()%nbNom],listPrenom[rand()%nbPrenom],
	(string(sexe,1)+string(annee,2)+string(moisNaiss,3)+string(depart,2)+string(commune,3)+string(etatCiv,3))});
}

bool egalitePersonne(personne per1, personne per2){
	if (per1.nom!=per2.nom){
		return false;
	}
	if (per1.prenom!=per2.prenom){
		return false;
	}
	return (per1.nSec==per2.nSec);
}

bool comparerPersonne(personne per1, personne per2){
	if (egalitePersonne(per1,per2)){
		return false;
	}
	if (per1.nom!=per2.nom){
		return (per1.nom<per2.nom);
	}
	if (per1.prenom!=per2.prenom){
		return (per1.prenom<per2.prenom);
	}
	return (per1.nSec<per2.nSec);
}

