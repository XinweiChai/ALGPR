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

Allumette* tri_rapide(Allumette* vec, int start, int end){
	if (start >= end){
		return vec;
	}
	Allumette mid = vec[end];
	int left = start, right = end-1;
	while (left < right){
		while (vec[left].taille < mid.taille && left < right){
			++left;
		}
		while (vec[right].taille >= mid.taille && left < right){
			--right;
		}

		vec=permuter(vec,left,right);
		affiche(vec,end+1);
	}
	if (vec[left].taille >= vec[end].taille){
		vec=permuter(vec,left,end);
		affiche(vec,end+1);
	}
	else{
		++left;
	}
	vec=tri_rapide(vec, start, left-1);
	vec=tri_rapide(vec, left +1, end);
	return vec;
}
