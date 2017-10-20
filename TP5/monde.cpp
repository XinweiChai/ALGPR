#include <string>
#include <fstream>
#include "constantes.h"

using namespace std;

t_monde LireEnvironnement(string filename){
	ifstream f(filename.c_str());
	t_monde m;	
	f >> m.L >> m.H;
	f >> m.Fx >> m.Fy;
	for (int i=0;i<m.H;++i){
		for (int j=0;j<m.L;++j){
			f >> m.mat[i][j];
		}
	}
	f.close();
	return m;
}
