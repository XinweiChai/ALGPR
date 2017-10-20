#include <fstream>
//#include <iomanip>
#include <stdlib.h>
//#include <cstdio>
#include "type_def.h"
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
	string sexe(to_string(rand()%2+1)),annee(to_string(rand()%98+1)), moisNaiss(to_string(rand()%12+1)), depart(to_string(rand()%98+1)), commune(to_string(rand()%998+1)), etatCiv(to_string(rand()%998+1));
	annee.insert(0,2-annee.size(),'0');
	moisNaiss.insert(0,2-moisNaiss.size(),'0');
	depart.insert(0,2-depart.size(),'0');
	commune.insert(0,3-commune.size(),'0');
	etatCiv.insert(0,3-etatCiv.size(),'0');
//	char sexe[1], annee[2], moisNaiss[2], depart[2], commune[3], etatCiv[3];
//	sprintf(sexe,"%d",rand()%2+1);
//	sprintf(annee,"%02d",rand()%98+1);
//	sprintf(moisNaiss,"%02d",rand()%12+1);
//	sprintf(depart,"%02d",rand()%98+1);
//	sprintf(commune,"%03d",rand()%998+1);
//	sprintf(etatCiv,"%03d",rand()%998+1);
//	personne per({listNom[rand()%nbNom],listPrenom[rand()%nbPrenom], (string(sexe,1)+string(annee,2)+string(moisNaiss,2)+string(depart,2)+string(commune,3)+string(etatCiv,3))});
	personne per({listNom[rand()%nbNom],listPrenom[rand()%nbPrenom], sexe+annee+moisNaiss+depart+commune+etatCiv});
	fstream f("repertoire.txt",ios::out);
	f << per.nom << " " << per.prenom << " " << per.nSec << endl;
	f.close();
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

