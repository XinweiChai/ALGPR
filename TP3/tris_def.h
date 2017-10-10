struct Allumette{
	int couleur;
	int taille;
};

const int sizeVect = 40;
typedef Allumette VectAllumettes [sizeVect];

struct fichAllumette{
	int sz;
	Allumette* vec;
};
