#include <iostream>
#include "entierlong.h"
#include "lit_ecrit.h"
#include "operation.h"
using namespace std;

int main(){
	EntierLong x,y;
	x=LitEntierLong();
	y=LitEntierLong();
	cout << "addition" << endl;
	AfficheEntierLong(add(x,y));
	cout << "subtraction" << endl;
	AfficheEntierLong(sub(x,y));
	cout << "multiplication" << endl;
	AfficheEntierLong(times(x,y));
	cout << "division" << endl;
	AfficheEntierLong(divide(x,y));


       // cout << equals(fibonacci(60),add(fibonacci(59),fibonacci(58))) << endl;
	return 0;
}
