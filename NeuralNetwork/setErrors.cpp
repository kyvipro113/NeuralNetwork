#include <cassert>
#include "NeuralNetwork.h"

void NeuralNetwork::setErrors()
{
	switch (costFunctionType)
	{
		case(COST_MSE): 
			this->setErrorMSE();
			break;
		default:
			this->setErrorMSE();
			break;
	}
}

void NeuralNetwork::setErrorMSE()
{
	int ouptLayerIndex = this->layers.size() - 1;
	vector <Neuron *> ouputNeurons = this->layers.at(ouptLayerIndex)->getNeurons();
	this->error = 0.00;
	for (int i = 0; i < target.size(); i++)
	{
		double t = target.at(i);
		double y = ouputNeurons.at(i)->getActivateVal();
		errors.at(i) = 0.05 * pow(abs((t - y)), 2);
		derivedErrors.at(i) = (y - t);
		this->error += errors.at(i);
	}
}