#include "tris_def.h"
#include "utils.h"
#include "affichage.h"
#include "tris.h"

int main(){
//	fichAllumette f=readAllumette("allumettes_donnees.txt");
//	writeAllumette(f);
	fichAllumette f = generationAleatoire(30);
	init();
	f.vec=tri_rapide(f.vec,0,f.sz-1);
//	f.vec=tri_insertion(f.sz,f.vec);
//	f.vec=tri_bulle(f.sz,f.vec);
	affiche(f.vec,f.sz);
	finish();

	return 0;
}
