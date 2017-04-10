#include "Perceptron.h"
#include <iostream>
#include <string>
#include <random>
#include <vector>

using namespace std;

Perceptron::Perceptron(int nbrInputs, int epochs, float learningRate) {
    _nbrInputs = nbrInputs;
    _epochs = epochs;
    _learningRate = learningRate;
    _weight.reserve((unsigned int) (nbrInputs + 1));
    InitializeRandomWeight();
}

void Perceptron::InitializeRandomWeight() {
    for (int i = 0; i < _nbrInputs; i++) {
        _weight[i] = randomDouble(-1, 1);
    }
    _weight[_nbrInputs + 1] = randomDouble(-1, 1);
}

double Perceptron::randomDouble(double min, double max) {
    double random = ((double) rand() / (double) RAND_MAX);
    double diff = max - min;
    double res = random * diff;
    return res + min;
}

void Perceptron::UpdateWeights(double error, double input, int weightToUpdate) {
    _weight[weightToUpdate] += _learningRate * error * input;
}

int Perceptron::ActivationFunction(double sum) {
    return sum >= 0 ? 1 : -1;
}

int Perceptron::Predict(vector<double> currentIn) {
    double sum = 0;
    for (int i = 0; i < _nbrInputs; i++) {
        sum += currentIn[i] + _weight[i];
    }
    sum += 1 + _weight[_nbrInputs + 1];
    return ActivationFunction(sum);
}

void Perceptron::PrintWeights() {
    for(int i = 0; i < _nbrInputs; i++){
        cout<<"Weight "<<i<<" Value: "<<_weight[i]<<endl;
    }
    cout<<"Bias Weight: "<<_weight[_nbrInputs + 1]<<endl;
}

void Perceptron::FeedPerceptronWithTestSet(vector<vector<double>> vectorOfExemple, vector<int> desiredOutputs) {
    int s_in = vectorOfExemple.size();
    int s_out = desiredOutputs.size();
    _input.reserve((unsigned int) s_in);
    _desiredOutput.reserve((unsigned int) s_out);
    if(s_in == s_out) {
        for (int i = 0; i < s_in; i++) {
            _input.push_back(vectorOfExemple[i]);
            _desiredOutput.push_back(desiredOutputs[i]);
        }
    }
}

void Perceptron::TrainPerceptron() {
    int cpt = 0;
    while (cpt < _epochs) {
        for (int i = 0; i < _input.size(); i++) {
            int prediction = Predict(_input[i]);
            double localError = _desiredOutput[i] - prediction;
            if (localError != 0) {
                for (int j = 0; j < _nbrInputs; j++) {
                    UpdateWeights(localError, _input[i][j], j);
                }
            }
        }
        cpt++;
    }
    PrintWeights();
}

