#include "tris_def.h"
#include "affichage.h"

Allumette* inserer(Allumette* vec, int i, int j){
	Allumette temp = vec[i];
	for (int k=i;k>j;k--){
		vec[k]=vec[k-1];
	}
	vec[j] = temp;
	return vec;
}

Allumette* tri_insertion(int nbAllumettes, Allumette* vec){
	int i, j;
	for (i=1;i<nbAllumettes;++i){
		j=0;
		while ((j<i) && ((vec[j].taille < vec[i].taille) || ((vec[j].taille == vec[i].taille) && (vec[j].couleur < vec[i].couleur)))){
			++j;
		}
		affiche(vec,nbAllumettes);
		inserer(vec, i, j);
	}	
	return vec;
}

Allumette* permuter(Allumette* vec, int i, int j){
	Allumette temp=vec[i];
	vec[i]=vec[j];
	vec[j]=temp;
	return vec;
}

Allumette* tri_bulle(int nbAllumettes, Allumette* vec){
	for (int i=nbAllumettes-1;i>0;--i){
		for (int j=0;j<nbAllumettes-1;++j){
			if (vec[j].taille>vec[j+1].taille){
				vec=permuter(vec,j,j+1);
			}
		}
	}

	return vec;
}
