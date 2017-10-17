#include "tris_def.h"
#include "utils.h"
#include "affichage.h"
#include "tris.h"
#include <ctime>
#include <iostream>

using namespace std;

int main(){
//	fichAllumette f=readAllumette("allumettes_donnees.txt");
//	writeAllumette(f);
	fichAllumette f = generationAleatoire(30);
	time_t start,end;
	init();
	start=time(NULL);
	f.vec=tri_rapide(f.vec,0,f.sz-1);
	end=time(NULL);
//	f.vec=tri_insertion(f.sz,f.vec);
//	f.vec=tri_bulle(f.sz,f.vec);
	affiche(f.vec,f.sz);
	finish();
	cout << end-start << endl;

	return 0;
}
