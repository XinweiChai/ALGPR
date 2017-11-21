/*************************************************************

                  Fichier entete de monde.cpp

    ------------------------------------------------------

 Fichier: monde.h
 But: prototypes des fonctions permettant de lire l'environnement
      depuis un fichier, et permettant de simuler l'évaporation
      de phéromones

*************************************************************/

#ifndef MONDE_H
#define MONDE_H

//action: LireEnvironnement
//parametres: environnement : t_monde représentant l'environnement (qui va être remplit par l'action)
//but: permet de lire l'environnement depuis un fichier
t_monde LireEnvironnement ();


//action: DecroissancePheromones
//parametres: pheromones : matrice où la valeur des pheromones dans le monde est stocké (modifié par l'action)
//           L : largeur du monde
//           H : hauteur du monde
//but: permet de simuler l'évaporation des pheromones
void EvaporationPheromones( t_matrice pheromones, int L, int H);

#endif