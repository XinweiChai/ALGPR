/*
author : V. Tourre
date : 26-09-2017
file name : ADeboguer.cpp

ENONCÉ
Vous ne devez retirer aucune instruction de ce programme.
Vous devez ajouter les éléments nécessaires pour que la compilation
et l'éxécution se déroulent correctement

*/
#include <iostream>
#include <cstdlib>

//using namespace std;
int main(void){


	int nbBug;
	std::cout << "A votre avis, combien est-ce que je contiens de bogues ?" << std::endl;
	std::cin >> nbBug;

	while(nbBug < 0) {
		std::cout << "Le nombre de bogues doit être positif ou nul" << std::endl;
		std::cin >> nbBug;
	}

	std::cout << "Vous avez dit que je contiens ";

	if(nbBug == 0 || nbBug == 1) {
		std::cout << nbBug << " bogue" << std::endl;
	}
	else {
		std::cout << nbBug << " bogues" << std::endl;
	}

	return (EXIT_SUCCESS);
}

