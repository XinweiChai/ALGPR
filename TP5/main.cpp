/*************************************************************

		Programme Principal

    ------------------------------------------------------
 Auteurs : équipe pédagogique ALGPR
 Date : 01/10/2009
 Modifié : 10/04/2013 (Vincent Tourre)
 Fichier: main.cpp
 
*************************************************************/

#include "constantes.h"
#include "monde.h"
#include "fourmi.h"
#include "affichage.h"
#include "proba.h"

const int NB_FOURMIS = 200;

int main()
{
	t_fourmi LesFourmis[NB_FOURMIS];
	t_monde environnement;
	t_matrice pheromones;
	int retour,coup;
	int i,j;


	// Lecture de l'environnement dans un fichier
	environnement = LireEnvironnement();

	// Initialisation de l'affichage
	retour = InitAffichage( environnement.L, environnement.H );

	// initialisation de la postion
	for(i=0;i<NB_FOURMIS;i=i+1)
	{
		LesFourmis[i].y = environnement.Fy;
		LesFourmis[i].x = environnement.Fx;
		LesFourmis[i].recherche=1;
		LesFourmis[i].direction = nalea(8);
	}

	// initialisation des pheromones
	for(i=0;i<environnement.L;i++)
		for(j=0;j<environnement.H;j++)
			pheromones[i][j]= 0;

	// Boucle
	coup=0;
	while (retour!=0)
	{
		// Déplace et affiche les fourmis une à une
		for(i=0;i<NB_FOURMIS;i=i+1)
		{
			DeplaceFourmi( LesFourmis[i], environnement, pheromones );
			MiseAJourFourmi( LesFourmis[i].x, LesFourmis[i].y, LesFourmis[i].recherche );
		}

		// décroissance des phéromones
		if (coup%270) EvaporationPheromones( pheromones, environnement.L, environnement.H);

		// Affiche la nourriture et la pheromone
		MiseAJourEnvironnement( environnement);
		MiseAJourPheromones( pheromones);

		// temporisation
		retour = Affichage();
		coup++;
	}

    return 0;
}

