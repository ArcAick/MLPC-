#ifndef MULTILAYERPERCEPTRON_H
#define MULTILAYERPERCEPTRON_H

struct Neurone {
    Neurone();
    ~Neurone();
    float *m_poids;
    float m_sorties;
    float m_poidstotal;
    int m_nbEntrees;

    void creer(int s_nbEntrees);
};

struct couche {
    couche();
    ~couche();
    Neurone **m_neurones;
    int m_nbNeurones;
    const int m_biais;
    float activer(float x);

    void creer(int s_nbNeurone, int s_nbEntree, bool coucheSortie);
};

class MultiLayerPerceptron {

private:
    couche *m_coucheDEntree;
    couche *m_coucheCachee;
    couche *m_coucheDeSortie;
    int m_nbCouchesCachee;
    int m_nbCouches;
    float m_txApprentissage;
    int m_epochs;

public:
    MultiLayerPerceptron();
    ~MultiLayerPerceptron();
    void creer(int *s_structureModele,int s_nbCouches, float s_txApprentissage, int s_epochs);
    float *feedForward(float *s_entrees);
    void propagation(float *s_sortiesVoulus, float *s_sortie);
    float majPoids(float poids, float entreeSuivante);
    float apprentissage(float *s_entrees, float *s_sortiesVoulut);
};

#endif // MULTILAYERPERCEPTRON_H
