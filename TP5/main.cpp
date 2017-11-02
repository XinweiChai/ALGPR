#include <string>
#include "constantes.h"
#include "monde.h"
#include "affichage.h"
#include "fourmi.h"
#include <iostream>

using namespace std;
int main(){
	t_monde m=LireEnvironnement("monde1.dat");
	InitAffichage(m.L,m.H);
	MiseAJourEnvironnement(m);
	MiseAJourFourmi(5,5,0);
	Affichage();
	return 0;
}
