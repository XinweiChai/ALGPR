void LireEnvironnement(string filename){
	ifstream f(string.scr(filename));
	t_monde monde;	
	f << monde.L << monde.H;
	f << Fx << Fy;

}
