#include "Neuron.h"

double sigmoid(double x)
{
	return (1 / (1 + exp(-x)));
}

double sigmoidPrime(double x)
{
	return ((1 / (1 + exp(-x))) * (1 - (1 / (1 + exp(-x)))));
}

double relu(double x)
{
	return x > 0 ? x : 0;
}

double reluPrime(double x)
{
	return x > 0 ? 1 : 0;
}

double tanhPrime(double x)
{
	return (1 - pow(tanh(x), 2));
}

Neuron::Neuron(double val)
{
	this->setVal(val);
}

Neuron::Neuron(double val, int activationType)
{
	this->activationType = activationType;
	this->setVal(val);
}

Neuron::~Neuron() { }

void Neuron::setVal(double val)
{
	this->val = val;
	activate();
	derive();
}

void Neuron::activate()
{
	if (activationType == Tanh)
	{
		this->activatedVal = tanh(this->val);
	}
	else if (activationType == Relu)
	{
		this->activatedVal = relu(this->val);
	}
	else if (activationType == Sigmoid)
	{
		this->activatedVal = sigmoid(this->val);
	}
	else
	{
		this->activatedVal = sigmoid(this->val);
	}
}

void Neuron::derive()
{
	if (activationType == Tanh)
	{
		this->derivatedVal = tanhPrime(this->activatedVal);
	}
	else if (activationType == Relu)
	{
		this->derivatedVal = reluPrime(this->val);
	}
	else if (activationType == Sigmoid)
	{
		this->derivatedVal = sigmoidPrime(this->activatedVal);
	}
	else
	{
		this->derivatedVal = sigmoidPrime(this->activatedVal);
	}
}