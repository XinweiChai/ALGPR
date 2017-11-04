#include "proba.h"
#include "fourmi.h"
#include "constantes.h"
#include <math.h>
int tdx[]={1,1,0,-1,-1,-1,0,1},
    tdy[]={0,1,1,1,0,-1,-1,-1};

int modulo8(int x){
	return ((x+8)%8);
}

bool PositionPossible(int x, int y, t_monde m){
	return !((x<0)||(y<0)||(x==m.L)||(y==m.H)||(m.mat[x][y]==-1));
}

t_fourmi DeplaceFourmi(t_fourmi fourmi, t_monde m){
	int comportement=nalea(8);
	int p_toutdroit[]={12,2,1,1,0,1,1,2},
	    ponderation[8];
	int dir,i;
	for (i=0;i<8;++i){
		dir = modulo8(i - fourmi.direction);
		ponderation[i] = p_toutdroit[dir];
	}
	for (i=0;i<8;++i){
		if (!PositionPossible(fourmi.x+tdx[i],fourmi.y+tdy[i],m))
			ponderation[i]=0;
	}
	fourmi.direction=nalea_pondere(ponderation);
	fourmi.x+=tdx[fourmi.direction];
	fourmi.y+=tdy[fourmi.direction];
	return fourmi;
}

int DirFourmililiere(int x, int y, int Fx, int Fy){
	int resultat;
	int dx= Fx-x;
	int dy= Fy-y;
	float norme = sqrt(dx*dx+dy*dy);
	dx = (int)round(dx/norme);
	dy = (int)round(dy/norme);
	for (int i = 0; i<=7;++i){
		if (dx == tdx[i] && dy == tdy[i]){
			resultat=i;
		}
	}
	return resultat;
}

t_monde EvaporationPheromone(t_monde m){
	for (int i=0;i<m.L;++i)
		for (int j=0;i<m.H;++j){
			if (m[i][j])
				--m[i][j];
		}
	return m;
}
