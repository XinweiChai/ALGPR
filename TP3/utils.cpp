#include <fstream>
#include "tris_def.h"
#include <ctime>

using namespace std;

fichAllumette readAllumette(string filename){
	ifstream myfile(filename.c_str());
	Allumette* vec=new VectAllumettes;
		int sz;
		myfile >> sz;
		int index=0;
		while (myfile >> vec[index++].couleur >> vec[index].taille){
		}
	fichAllumette f={sz,vec};
	return f;
}

void writeAllumette(fichAllumette f){
	ofstream myfile("output.txt");
	myfile << f.sz<< endl;
	for (int i=0;i<f.sz;++i){
		myfile << f.vec[i].couleur << ' ' << f.vec[i].taille << endl;
	}
}


fichAllumette generationAleatoire(int nbAlumettes){
	fichAllumette f={nbAlumettes,new VectAllumettes};
	srand(time(NULL));
	for (int i=0;i<nbAlumettes;++i){
		f.vec[i]={rand()%6+1,rand()%20+1};
	}
	return f;
}
