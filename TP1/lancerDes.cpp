#include <iostream>
#include <cstdlib>

using namespace std;
typedef int type[100];
int main()
{

    const int faces=6;
    int nbLancers, valeur;
    type nb={0};
    nbLancers=0;
    cout << "1ere valeur de la suite de lancers" << endl;
    cin >> valeur;
    while ((valeur >0) and (valeur<7))
    {
        ++nb[valeur-1];
        ++nbLancers;
        cout << nbLancers+1 <<"ere valeur de la suite de lancers" << endl;
        cin >> valeur;
    }
    if (nbLancers!=0)
    {
        for (int i=1;i<=faces;++i)
        {

            cout << "frequence de " << i << " est " << (float)nb[i-1]/nbLancers << endl;
        }
    }
    else
    {
        cout << "aucune valeur entre 1 et "<< faces <<endl;
    }
    return (EXIT_SUCCESS);
}
