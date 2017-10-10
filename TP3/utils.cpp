#include <fstream>
#include "tris_def.h"
using namespace std;

fichAllumette readAllumette(string filename){
	ifstream myfile(filename.c_str());
	Allumette* vec=new VectAllumettes;
		string couleur;
		string taille;
		int sz;
		myfile >> sz;
		int index=0;
		while (myfile >> couleur >> taille){
			Allumette temp={stoi(couleur,nullptr),stoi(taille,nullptr)};
			vec[index]=temp;
			++index;
		}
	fichAllumette f={sz,vec};
	return f;
}

void writeAllumette(fichAllumette f){
	ofstream myfile("output.txt");
	myfile << f.sz<< endl;
	for (int i=0;i<f.sz ;++i){
		myfile << f.vec->couleur << ' ' << f.vec->taille << endl;
		++f.vec;
	}
}
