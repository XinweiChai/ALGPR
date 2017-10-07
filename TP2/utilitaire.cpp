#include "entierlong.h"
EntierLong convert(int x){
	EntierLong y;
	y.Negatif=x<0;
	for (int i=0;i<MAXCHIFFRES;i++)
        y.Chiffres[i]=0;
	int ind=0;
	if (x<0)
        x=-x;
	while (x){
		y.Chiffres[ind]=x%10;
		ind++;
		x=x/10;
	}
	return y;
}

bool equals(EntierLong x, EntierLong y){
	if (x.Negatif!=y.Negatif)
		return false;
	for (int i=0;i<MAXCHIFFRES;i++){
		if (x.Chiffres[i]!=y.Chiffres[i])
			return false;
	}
	return true;
}

bool compareVA(EntierLong x, EntierLong y){
	for (int i=MAXCHIFFRES-1;i>=0;i--){
		if (x.Chiffres[i]<y.Chiffres[i])
			return true;
		else if (x.Chiffres[i]>y.Chiffres[i])
			return false;
		}
	return true;
}

