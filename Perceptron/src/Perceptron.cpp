#include "Perceptron.h"
#include <iostream>
#include <string>
#include <random>
#include <vector>

Perceptron::Perceptron(int nbInput, int epoque, float txApprentissage)
{
    _nbInput = nbInput;
    _epoque = epoque;
    _txApprentissage = txApprentissage;
    _poids.reserve((unsigned int)(nbInput + 1));
    initPoidsRandom();
    //ctor
}

void Perceptron::initPoidsRandom() {
    for (int i = 0; i < _nbInput; i++) {
        _poids[i] = aleatDouble(-1, 1);
    }
    _poids[_nbInput + 1] = aleatDouble(-1, 1);
}

double Perceptron::aleatDouble(double min, double max) {
    double random = ((double) rand() / (double) RAND_MAX);
    double diff = max - min;
    double res = random * diff;
    return res + min;
}

void Perceptron::majPoids(double error, double input, int poidsAMaj) {
    _poids[poidsAMaj] += _txApprentissage * error * input;
}

int Perceptron::fonctionActivation(double sum) {
    return sum >= 0 ? 1 : -1;
}

int Perceptron::prediction(vector<double> inCourant) {
    double sum = 0;
    for (int i = 0; i < _nbInput; i++) {
        sum += inCourant[i] + _poids[i];
    }
    sum += 1 + _poids[_nbInput + 1];
    return fonctionActivation(sum);
}

void Perceptron::affichePoids() {
    for(int i = 0; i < _nbInput; i++){
        cout<<"poids "<<i<<" valeur: "<<_weight[i]<<endl;
    }
    cout<<"poids de biais: "<<_poids[_nbInput + 1]<<endl;
}

void Perceptron::perceptronTest(vector<vector<double>> exempleVector, vector<int> outputPrevu) {
    int s_in = exempleVector.size();
    int s_out = outputPrevu.size();
    _input.reserve((unsigned int) s_in);
    _outputPrevu.reserve((unsigned int) s_out);
    if(s_in == s_out) {
        for (int i = 0; i < s_in; i++) {
            _input.push_back(exempleVector[i]);
            _outputPrevu.push_back(outputPrevu[i]);
        }
    }
}

void Perceptron::Apprentissage() {
    int cpt = 0;
    while (cpt < _epoque) {
        for (int i = 0; i < _input.size(); i++) {
            int predict = prediction(_input[i]);
            double localError = _outputPrevu[i] - predict;
            if (localError != 0) {
                for (int j = 0; j < _nbInput; j++) {
                    majPoids(localError, _input[i][j], j);
                }
            }
        }
        cpt++;
    }
    affichePoids();
}
