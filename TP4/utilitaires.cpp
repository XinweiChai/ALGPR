#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <cstdio>
#include "type_def.h"

using namespace std;

typedef char* ch;

string* initTabNomPrenom(string fileName, int sizefile){
	ifstream fn(fileName.c_str());
	fn >> sizefile;
	string* nom = new string[sizefile];
	for (int i=0;i<sizefile;++i){
        fn >> nom[i];
    }
    return nom;
}

personne genererPersonne(string* listNom, string* listPrenom, int nbNom, int nbPrenom){
	srand(time(NULL));
//	ostringstream ss;
	ch sexe, annee, moisNaiss, depart, commune, etatCiv;
	sprintf(sexe,"%02d",rand()%98+1);
	string res=string(sexe);
	
//	ss << setw(2) << setfill('0')<<rand()%98+1;
	sprintf(annee,"%02d",rand()%98+1),
        sprintf(moisNaiss,"%02d",rand()%12+1),
        sprintf(depart,"%02d",rand()%98+1),
        sprintf(commune,"%03d",rand()%998+1),
        sprintf(etatCiv,"%03d",rand()%998+1);
    string temp = listNom[rand()%nbNom];

//sexe+annee+moisNaiss+depart+commune+etatCiv
//	if (annee<10){
//		sannee="0"+sprintf(annee);
//	}else{
//		sannee=sprintf(annee);
//	}
	personne per;
	return per;
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

