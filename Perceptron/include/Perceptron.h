#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include <iostream>
#include <string>
#include <random>

class Perceptron
{
    private:
        int nbInput;
        int epoque;
        double txApprentissage;
        std::vector<std::vector<double>> input;
        std::vector<double> poids;
        std::vector<int> outputPrevu;

        void initPoidsRandom();
        void majPoids(double error, double input, int poidsAMaj);
        double aleatDouble(double min, double max);
        int fonctionActivation(double sum);
        int prediction(std::vector<double> inCourant);
        std::vector<std::vector<double>> conversionTabVersVector(double *tabLineaire);


    public:
        Perceptron();
        ~Perceptron();

        int GetnbInput() {
            return nbInput;
        }

        void SetnbInput(int val) {
            nbInput = val;
        }

        int Getepoque() {
            return epoque;
        }
        void Setepoque(int val) {
            epoque = val;
        }

        double GettxApprentissage() {
            return txApprentissage;
        }

        void SettxApprentissage(double val) {
            txApprentissage = val;
        }

        std::vector<std::vector<double>> Getinput() {
            return input;
        }

        void Setinput(std::vector<std::vector<double>> val) {
            input = val;
        }
        std::vector<double> Getpoids() {
            return poids;
        }

        void Setpoids(std::vector<double> val) {
            poids = val;
        }

        std::vector<int> GetoutputPrevu() {
            return outputPrevu;
        }

        void SetoutputPrevu(std::vector<int> val) {
            outputPrevu = val;
        }

        void GetinitPoidsRandom() {
            return initPoidsRandom;
        }

        void SetinitPoidsRandom(void val) {
            initPoidsRandom = val;
        }

        void GetmajPoids() {
            return majPoids;
        }

        void SetmajPoids(void val) {
            majPoids = val;
        }

        double GetaleatDouble() {
            return aleatDouble;
        }

        void SetaleatDouble(double val) {
            aleatDouble = val;
        }

        int GetfonctionActivation() {
            return fonctionActivation;
        }

        void SetfonctionActivation(int val) {
            fonctionActivation = val;
        }

        int Getprediction() {
            return prediction;
        }

        void Setprediction(int val) {
            prediction = val;
        }

        std::vector<std::vector<double>> GetconversionTabVersVector() {
            return conversionTabVersVector;
        }

        void SetconversionTabVersVector(std::vector<std::vector<double>> val) {
            conversionTabVersVector = val;
        }

        void GetApprentissage() {
            return Apprentissage;
        }

        void SetApprentissage(void val) {
            Apprentissage = val;
        }

        void GetaffichePoids() {
            return affichePoids;
        }

        void SetaffichePoids(void val) {
            affichePoids = val;
        }

        void GetperceptronTest() {
            return perceptronTest;
        }

        void SetperceptronTest(void val) {
            perceptronTest = val;
        }

        void Apprentissage();
        void affichePoids();
        void perceptronTest(std::vector<std::vector<double>> tableauExemples, std::vector<int> outputPrevu);
        Perceptron(int nbInput, int epoque, float txApprentissage);


};

#endif // PERCEPTRON_H
