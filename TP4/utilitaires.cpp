#include <fstream>
#include <iomanip>
#include <sstream>
#include "type_def.h"

using namespace std;


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
	ostringstream ss;
	string res="";
	ss << setw(2) << setfill('0')<<rand()%98+1;
//	string sexe = to_string(rand()%2+1),
//	       annee = to_string("%02d",rand()%98+1),
//	       moisNaiss = to_string("%02d",rand()%12+1),
//	       depart = to_string("%02d",rand()%98+1),
//	       commune = to_string("03d",rand()%998+1),
//	       etatCiv = to_string("03d",rand()%998+1);
    string temp = listNom[rand()%nbNom];
	personne per({listNom[rand()%nbNom],listPrenom[rand()%nbPrenom],ss.str()});

//sexe+annee+moisNaiss+depart+commune+etatCiv
//	if (annee<10){
//		sannee="0"+to_string(annee);
//	}else{
//		sannee=to_string(annee);
//	}
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

