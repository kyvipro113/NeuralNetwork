#pragma once
#ifndef LAYER_H
#define LAYER_H
#include <iostream>
#include <vector>
#include "Neuron.h"
#include "Matrix.h"

using namespace std;

class Layer
{
public:
	Layer(int size);
	Layer(int size, int activationType);
	void setVal(int i, int v);
	void setNeuron(vector <Neuron *> Neuron) { this->neurons = neurons; }
	vector <double> getActivatedVals();
	vector <Neuron *> getNeurons() { return this->neurons; }
	Matrix *matrixifyVals();
	Matrix *matrixifyActivatedVals();
	Matrix *matrixifyDerivedVals();
private:
	int size;
	vector <Neuron *> neurons;
};

#endif // !LAYER_H

