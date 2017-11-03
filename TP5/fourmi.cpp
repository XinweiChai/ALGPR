#include "proba.h"
#include "fourmi.h"
#include "constantes.h"

int modulo8(int x){
	return ((x+8)%8);
}

bool PositionPossible(int x, int y, t_monde m){
	return !((x<0)||(y<0)||(x==m.L)||(y==m.H)||(m.mat[x][y]==-1));
}

t_fourmi DeplaceFourmi(t_fourmi fourmi, t_monde m){
	int comportement=nalea(8);
//	switch (comportement){
//		case 0 : --f.x;--f.y;
//		case 1 : --f.y;
//		case 2 : ++f.x;--f.y;
//		case 3 : ++f.x;
//		case 4 : ++f.x;++f.y;
//		case 5 : ++f.y;
//		case 6 : --f.x;++f.y;
//		case 7 : --f.x;
//	}
	int tdx[]={1,1,0,-1,-1,-1,0,1}, 
	    tdy[]={0,1,1,1,0,-1,-1,-1},
	    p_toutdroit[]={12,2,1,1,0,1,1,2},
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



