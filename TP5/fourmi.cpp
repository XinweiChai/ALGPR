#include "proba.h"
#include "fourmi.h"
#include "constantes.h"

void DeplaceFourmi(t_fourmi f){
	int comportement=nalea(8);
	switch (comportement){
		case 0 : --f.x;--f.y;
		case 1 : --f.y;
		case 2 : ++f.x;--f.y;
		case 3 : ++f.x;
		case 4 : ++f.x;++f.y;
		case 5 : ++f.y;
		case 6 : --f.x;++f.y;
		case 7 : --f.x;
	}
}
