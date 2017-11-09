/*************************************************************

         Lecture de l'environnement dans un fichier
         et Evaporation de la phéromone

    ------------------------------------------------------

 Auteur: HILAIRE Thibault, Mikaèl BRIDAY
 Date: 01/10/2003
 Révisé et porté en C par Didier LIME le 7/05/2009
 modifié : 10/04/2013 Vincent Tourre
 Fichier: monde.cpp
 But: Fonctions permettant de lire l'environnement depuis un
      fichier, et permettant de simuler l'évaporation de
      phéromones

*************************************************************/


#include <fstream>
#include "constantes.h"

#include "monde.h"

using namespace std;

//action: LireEnvironnement
//arguments: environnement : t_monde représentant l'environnement (qui va Ítre remplit par l'action)
//but: permet de lire l'environnement depuis un fichier
//principe: lecture de la taille du tableau, puis du tableau (depuis le fichier)
t_monde LireEnvironnement()
{
	int i,j;
	ifstream file;
	t_monde environnement;

	// ouverture du fichier
	file.open("monde1.dat");
	//file.open("monde2.dat");
	//file.open("monde3.dat");

	// lire hauteur et largeur
	file >> environnement.L;	//largeur
	file >> environnement.H;	//hauteur

	// lire la position de la fourmilière
	file >> environnement.Fx;
	file >> environnement.Fy;
	
	// puis lire le tableau
	for(j=0;j<environnement.H;j++) //pour tte les lignes => y
		for(i=0;i<environnement.L;i++)	//pour tte les colonnes => x
		{
			file >> environnement.mat[i][j];	
		}

    return environnement;
}


//action: DecroissancePheromones
//arguments: pheromones : matrice où la valeur des pheromones dans le monde est stocké (modifié par l'action)
//but: permet de simuler l'évaporation des pheromones
//principe: on décrémente (de 1) le niveau de phéromones, lorsque celui-ci est strictement positif (phéromone présente)
void EvaporationPheromones( t_matrice pheromones, int L, int H)
{
	int i,j;
	for(j=0;j<H;j++)
		for(i=0;i<L;i++)
			if (pheromones[i][j]>0)	pheromones[i][j]--;
}

