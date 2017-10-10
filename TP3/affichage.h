/*************************************************************
                     TP TRI DES ALLUMETTES

               Fichier entete de affichage.cpp

    ------------------------------------------------------

 Auteurs: Equipe pÈdagogique ALGPR
 Date: 21/04/2009
 Fichier: affichage.h
 But: prototypes des fonctions permettant d'afficher pseudo-
 	  graphiquement des allumettes que l'on souhaite trier

*************************************************************/

#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

// Couleurs
#define NOIR  0
#define BLANC  1
#define ROUGE  2
#define JAUNE  3
#define BLEU  4
#define MAGENTA  5
#define GREEN  6

/* Prototype de la fonction init
      Parametres : aucun
      But : initialise l'affichage pseudo-graphique
      Réesultat : aucun */
void init();

/* Prototype de la fonction finish
      Parametres : aucun
      But : quitte proprement le mode pseudo graphique
      Réesultat : aucun */
void finish();

/* Prototype de la fonction affiche
      Parametres : a : t_VectAllumettes
				   nbAllumettes : entier
      But : affiche un vecteur d'allumettes (composÈ d'un nombre d'ÈlÈments
	        Ègal ‡ nbAllumettes) fourni en parametre
      Réesultat : aucun */
void affiche(VectAllumettes, int nbAllumettes);

#endif // AFFICHAGE_H_INCLUDED
