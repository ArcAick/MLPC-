#include <iostream>

using namespace std;

int main()
{
    float txApprentissage = 0.2;
    const int nbCouches = 3;
    int epochs = 10;
    int mstruct[nbCouches] = {2,3,2};
    const int nbEntrees = 2;
    const int nbExemples = 4;
    float Exemple[nbExemples][nbEntrees] = {{0,0}, {1,1}, {1,0}, {0,1}};
    float sortiesCible[nbExemples][1] = {{0}, {0}, {1}, {1}};
    MultiLayerPerceptron firstMLP;
    firstMLP.creer(mstruct, nbCouches, txApprentissage, epochs);
    float *resultat;
    for (int i = 0; i < epochs; i++) {
        for (int j = 0; j < nbExemples; j++) {
            firstMLP.apprentissage(Exemple[j], sortiesCible[j]);
        }
    }

return 0;
}
