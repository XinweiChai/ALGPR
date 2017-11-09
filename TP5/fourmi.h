/*************************************************************

               Fichier entete de fourmi.cpp

    ------------------------------------------------------
 Auteurs : équipe pédagogique ALGPR
 Date : 01/10/2009
 Modifié : 10/04/2013, 04/11/2013 (Vincent Tourre)
 Fichier: fourmi.h
 But: définition du type fourmi et déclaration des fonctions de déplacement de la fourmi
 
*************************************************************/

#ifndef FOURMI_H
#define FOURMI_H

struct t_fourmi
{
	int x,y;		// position de la fourmi
	int direction;	// direction de la fourmi (son orientation)
	int recherche;	// indique si la fourmi est en recherche de nourriture (=1) ou si elle porte de la nourriture (=0)
};

void DeplaceFourmi( t_fourmi& fourmi, t_monde& environnement, t_matrice pheromones);


#endif