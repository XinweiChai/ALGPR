/*************************************************************

		Fonctions de déplacement des fourmis

    ------------------------------------------------------
 Auteurs : équipe pédagogique ALGPR
 Date : 01/10/2009
 Modifié : 10/04/2013, 04/11/2013 (Vincent Tourre)
 Fichier: fourmi.cpp
 
*************************************************************/

#include "constantes.h"
#include "fourmi.h"
#include "math.h"
#include "proba.h"


// constantes
const int tdx[8] = {+1,+1, 0,-1,-1,-1, 0,+1};			// déplacement	5   6   7
const int tdy[8] = { 0,+1,+1,+1, 0,-1,-1,-1};			//				4       0
														//				3   2   1
const int ponderation_recherche[8] = {12,2,1,1,0,1,1,2};
const int ponderation_fourmiliere[8] = {200,32,8,2,1,2,8,32};


// Vérifie si la position est possible pour une fourmi
int PositionPossible (int x, int y, t_monde environnement)
{
    int resultat = 1;
	// fourmi en dehors du monde ?
	if ( (x<0) || (y<0) || (x>=environnement.L) || (y>=environnement.H) ) {
        resultat = 0;
    }  else {
	    // fourmi sur un obstacle ?
    	if (environnement.mat[x][y]==OBSTACLE) 
            resultat = 0;
    }

    return resultat;
}


// indique la direction de la fourmiliere (entre 0 et 7)
int DirFourmiliere( int x, int y,int Fx, int Fy)
{
    int i;
	int result = -1;
	int dx = Fx - x;
	int dy = Fy - y;
	float norme = sqrt( (float) (dx*dx + dy*dy) );
	dx = (int)round(dx / norme);
	dy = (int)round(dy / norme);
	for (i = 0; i < 8; i++)
	{
		if(dx == tdx[i] && dy == tdy[i])	result = i;
	}
	return result;
}


// ramène x dans la fourchette [0;7]
// (meme pour x négatif)
int modulo8(int x)
{
	return ( x + 8) % 8;	// car x est compris entre -7 et +7
					// et donc x+8 entre 1 et 15
}


// déplace une fourmi
void DeplaceFourmi( t_fourmi& fourmi, t_monde& environnement, t_matrice pheromones)
{

/*
1er mode de recherche
	1) choisir la nouvelle direction
		- mode recherche :
			direction = ( direction + rotation ) modulo 8
			avec rotation pris dans [0;7] avec des ponderation 24, 2, 1, 1, 0, 1, 1, 2
			(la ponderation devient nulle si le deplacement n'est pas possible (obstacle ou bord))
		- mode retour_fourmiliere
			direction = ( direction_fourmiliere + rotation ) modulo 8
			avec rotation pris dans [-4;4] avec des ponderation 1024, 32, 8, 2 ,1, 2, 8, 32
			(la ponderation devient nulle si le deplacement n'est pas possible (obstacle ou bord))

	2) avancer dans cette direction

	3) - mode recherche :
		si on a atteint la nourriture :
			- passer en mode retour_fourmiliere
	   - mode retour_fourmiliere
	   	si on a atteint la fourmiliere
			- faire demi-tour
			- passer en mode recherche
*/



	// calcul des ponderations
/*	t_poids ponderation;
	int dir;
	// 1) on privilégie tjs de suivre la meme direction qu'avant
	for(int i=0;i<8;i++)
	{
		dir = modulo8( i - fourmi->direction );
		ponderation[i] = ponderation_recherche[dir];
	}
*/
/*
	// 2) pondération avec la phéromone.
	if (fourmi->recherche)
	{
		for(int i=0;i<8;i++)
		{
			int delta_dir = modulo8(i + DirFourmiliere(fourmi->x+tdx[i],fourmi->y+tdy[i],Fx,Fy) );
			delta_dir = ((delta_dir+12) % 8) -4; //pour avoir delta_dir entre -4 et 3
			ponderation[i] = ponderation[i] + pheromones[fourmi->x+tdx[i]][fourmi->y+tdy[i]]*(abs(delta_dir)+1);
		}
	}

	//si on est en mode retour à la fourmillière, on ajoute la pondération
	//fourmillère
	if(!fourmi->recherche)
	{
		for(int i=0;i<8;i++)
		{
			int base_dir = DirFourmiliere( fourmi->x, fourmi->y, Fx, Fy);
			dir = (base_dir + i) % 8;
			ponderation[i] += ponderation_recherche[dir];
		}
	}

	// si on trouve de la nourriture et qu'on en recherche
	// ou si on trouve la fourmiliere, et qu'on la recherche
	// alors ponderation= max
	for(int i=0;i<8;i++)
	{
		if ( (fourmi->recherche) && (environnement[fourmi->x+tdx[i]][fourmi->y+tdy[i]]>0) )
			ponderation[i]=100000;
		if ( (!fourmi->recherche) && (environnement[fourmi->x+tdx[i]][fourmi->y+tdy[i]])==FOURMILLIERE)
			ponderation[i]=100000;
	}
*/
	//on met la pondération 0 sur les obstacles.
/*	for(int i=0;i<8;i++)
	{
		if ( !PositionPossible( fourmi->x+tdx[i], fourmi->y+tdy[i], L, H, environnement) )
		ponderation[i] = 0;
	}

	fourmi->direction = nalea_pondere(ponderation);
*/
// 1) choix d'une direction

	int ponderation[8];
	int dir;
	int dir_a_suivre;
    int i;

	// choix de la direction à suivre (vers la fourmiliere, ou la meme direction qu'avant)
	if (fourmi.recherche)
		dir_a_suivre = fourmi.direction;
	else
		dir_a_suivre = DirFourmiliere( fourmi.x, fourmi.y,environnement.Fx, environnement.Fy);

	// on examine une a une les direction possibles
	for(i=0;i<8;i++)
	{
		// nouvelle direction empruntee
		dir = (dir_a_suivre + i) % 8;

		// on regarde si le déplacement dans cette direction est possible
		if ( PositionPossible( fourmi.x+tdx[dir], fourmi.y+tdy[dir], environnement) )
		{
			// si oui, on affecte la ponderation correspondant au mode de la fourmi
			if (fourmi.recherche) ponderation[i] = ponderation_recherche[i];
			else ponderation[i] = ponderation_fourmiliere[i];

			// pondere les endroits o˘ il y a le plus de pheromones, en mode recherche
			// et qui sont le plus éloignés
			if (fourmi.recherche)
			{
				int delta_dir = DirFourmiliere(fourmi.x+tdx[dir],fourmi.y+tdy[dir],environnement.Fx,environnement.Fy) - dir;
				delta_dir = ((delta_dir+12) % 8) -4; //pour avoir delta_dir entre -4 et 3
				ponderation[i] = ponderation[i] + pheromones[fourmi.x+tdx[dir]][fourmi.y+tdy[dir]]*((int)fabs((float)delta_dir)+1);
			}

			// mais si on trouve de la nourriture, ponderation= max
			if ( (fourmi.recherche) && (environnement.mat[fourmi.x+tdx[dir]][fourmi.y+tdy[dir]]>0) 
				 && !(fourmi.x+tdx[dir]==environnement.Fx && fourmi.y+tdy[dir]==environnement.Fy))
				ponderation[i]=100000;
		}
		else
		{
			// sinon, la ponderation est nulle
			ponderation[i] = 0;
		}


	}
	// on tire une nouvelle direction, avec un random pondéré
	fourmi.direction = ( dir_a_suivre + nalea_pondere(ponderation) ) % 8;



// 2) on avance dans cette direction
	fourmi.x = fourmi.x + tdx[fourmi.direction];
	fourmi.y = fourmi.y + tdy[fourmi.direction];

// 3) action après déplacement

	if (fourmi.recherche)
	{
		if (environnement.mat[fourmi.x][fourmi.y]>0 && !((fourmi.x==environnement.Fx) && (fourmi.y==environnement.Fy)))
		{
			//printf("fourmi sur de la nourriture\n");
			fourmi.recherche=0;
			environnement.mat[fourmi.x][fourmi.y]--;	// on enleve de la nourriture
		}
	}
	else
	{
		if ( (fourmi.x==environnement.Fx) && (fourmi.y==environnement.Fy) )
		{
			//printf("fourmi sur la fourmillière\n");
			environnement.mat[fourmi.x][fourmi.y] ++;
			fourmi.recherche=1;
			fourmi.direction = (fourmi.direction+4) % 8;
		}
		else
		{
			// depose pheromone là o˘ il est et sur les cases environnantes
			pheromones[fourmi.x][fourmi.y]+=10;
			if(pheromones[fourmi.x][fourmi.y] > PHEROMONES_MAX)
				pheromones[fourmi.x][fourmi.y]=PHEROMONES_MAX;
			for(i = 0; i < 8; i++)
			{
				if(PositionPossible(fourmi.x+tdx[i], fourmi.y+tdy[i], environnement))
				{
					pheromones[fourmi.x+tdx[i]][fourmi.y+tdy[i]]+=5;
					if(pheromones[fourmi.x+tdx[i]][fourmi.y+tdy[i]] > PHEROMONES_MAX)
						pheromones[fourmi.x+tdx[i]][fourmi.y+tdy[i]]=PHEROMONES_MAX;
				}
			}
		}
	}


}
