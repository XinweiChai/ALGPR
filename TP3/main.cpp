#include "tris_def.h"
#include "utils.h"
#include "affichage.h"
#include "tris.h"

int main(){
	fichAllumette f=readAllumette("allumettes_donnees.txt");
//	writeAllumette(f);

	init();
	f.vec=tri_insertion(f.sz,f.vec);
//	f.vec=tri_bulle(f.sz,f.vec);
	affiche(f.vec,f.sz);
	finish();

	return 0;
}
