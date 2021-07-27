#pragma once
#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#define COST_MSE 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>

#include "Matrix.h"
#include "Layer.h"

using namespace std;
class NeuralNetwork
{
public:
	NeuralNetwork(vector <int> topology, double bias = 1, double learningRate = 0.05, double momentum = 1);
	NeuralNetwork(vector <int> toloplogy, int hidenActivationType, int ouputACtivationType, int costFunctionType, double bias = 1, double learningRate = 0.05, double momentum = 1);

	vector<double> getActivatedVals(int index) { return this->layers.at(index)->getActivatedVals(); };
	Matrix *getNeuronMatrix(int index) { return this->layers.at(index)->matrixifyVals(); }
	Matrix *getActivatedNeuronMatrix(int index) { return this->layers.at(index)->matrixifyActivatedVals(); }
	Matrix *getDerivedNeuronMatrix(int index) { return this->layers.at(index)->matrixifyDerivedVals(); }
	Matrix *getWeightMatrix(int index) { return new Matrix(*this->weightMatrices.at(index)); }


	void setCurrentInput(vector <double> input);
	void setCurrentTarget(vector <double> target) { this->target = target; }
	void setNeuronValue(int indexLayer, int indexNeuron, double val) { this->layers.at(indexLayer)->setVal(indexNeuron, val); }

	void feedForward();
	void backPropagation();
	void setErrors();
	void train(vector <double> input, vector <double> target, double bias, double learningRate, double momentum);

	int topologySize;
	int hidenActivationType = Relu;
	int ouputActivationType = Sigmoid;
	int costFunctionType = COST_MSE;

	vector<int> topology;
	vector<Layer *> layers;
	vector<Matrix *> weightMatrices;
	vector<Matrix *> gradientMatrices;
	vector<double> input;
	vector<double> target;
	vector<double> errors;
	vector<double> derivedErrors;

	double error = 0;
	double bias = 1;
	double momentum;
	double learningRate;

private:
	void setErrorMSE();
};

#endif // !NEURALNETWORK_H
