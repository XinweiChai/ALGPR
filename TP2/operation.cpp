#include "entierlong.h"
#include "utilitaire.h"

EntierLong addSameSign(EntierLong x, EntierLong y){
	for (int i=0;i<MAXCHIFFRES;++i){
		x.Chiffres[i]+=y.Chiffres[i];
		while (x.Chiffres[i]>=10){
			x.Chiffres[i]-=10;
			++x.Chiffres[i+1];
		}
	}
	return x;
}

EntierLong subSameSign(EntierLong x, EntierLong y){
	for (int i=0;i<MAXCHIFFRES;++i){
        	x.Chiffres[i]-=y.Chiffres[i];
        	while (x.Chiffres[i]<0){
        		x.Chiffres[i]+=10;
        		--x.Chiffres[i+1];
        	}
        }
        return x;
}

EntierLong add(EntierLong x, EntierLong y){
	if (x.Negatif==y.Negatif)
		return addSameSign(x,y);
	if (compareVA(x,y))
		return subSameSign(y,x);
	else
		return subSameSign(x,y);
}

EntierLong sub(EntierLong x, EntierLong y){
    if (equals(x,y))
        return convert(0);
    if (x.Negatif==y.Negatif){
		if (compareVA(x,y)){
            		EntierLong temp=subSameSign(y,x);
            		temp.Negatif=!x.Negatif;
            		return temp;
		}
        else
            return subSameSign(x,y);
	}
	return addSameSign(x,y);
}

EntierLong fibonacci(int n){
    EntierLong x,y,temp;
    x=convert(0);
    y=convert(1);
    for (int i=0;i<n-1;++i){
        temp=add(x,y);
        x=y;
        y=temp;
    }
    return temp;
}

int length(EntierLong x){
	for (int i=MAXCHIFFRES-1;i>=0;i--)
		if (x.Chiffres[i]!=0)
			return i;
	return 0;
}

EntierLong init(){
	EntierLong x;
	x.Negatif=false;
	for (int i=0;i<MAXCHIFFRES;++i)
		x.Chiffres[i]=0;
	return x;
}

EntierLong times(EntierLong x, EntierLong y){
	EntierLong temp,sum;
	sum=init();
	if (length(x)+length(y)>MAXCHIFFRES-1)
		return sum;
	for (int i=0;i<=length(x);++i){
		temp=init();
		for (int j=0;j<=length(y);++j){
			temp.Chiffres[i+j]+=x.Chiffres[i]*y.Chiffres[j];
		}
		sum=addSameSign(sum,temp);
	}
	sum.Negatif=(x.Negatif!=y.Negatif);
	return sum;
}

EntierLong power(int i){
    EntierLong x=init();
    x.Chiffres[i]=1;
    return x;
}

EntierLong divide(EntierLong x, EntierLong y){
	EntierLong quot=init();
	if (equals(x,y))
        return convert(1);
    y.Negatif=!y.Negatif;
    if (equals(x,y))
        return convert(-1);
    y.Negatif=!y.Negatif;
	if (compareVA(x,y)){
        return convert(0);
	}
	for (int i=length(x)-length(y);i>=0;i--){
        while (compareVA(times(y,power(i)),x)){
            x=subSameSign(x,times(y,power(i)));
            quot.Chiffres[i]++;
        }
	}
	quot.Negatif=(x.Negatif!=y.Negatif);
	return quot;
}
