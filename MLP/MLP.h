#ifndef PERCEPTRONC_PERCEPTRON_H
#define PERCEPTRONC_PERCEPTRON_H
#include <iostream>
#include <string>
#include <random>


class Perceptron {
public:
    void TrainPerceptron();
    void PrintWeights();
    void FeedPerceptronWithTestSet(std::vector<std::vector<double>> linearArrayOfExemples, std::vector<int> desiredOutputs);
    void FeedPerceptronWithData();

    Perceptron(int nbrInputs, int epochs, float learningRate);

private:
    int _nbrInputs;
    int _epochs;
    double _learningRate;
    std::vector<std::vector<double>> _input;
    std::vector<double> _weight;
    std::vector<int> _desiredOutput;

    void InitializeRandomWeight();
    void UpdateWeights(double error, double input, int weightToUpdate);
    double randomDouble(double min, double max);
    int ActivationFunction(double sum);
    int Predict(std::vector<double> currentIn);
    std::vector<std::vector<double>> convertArrayToVector(double *linearArray);
};


#endif //PERCEPTRONC_PERCEPTRON_H
