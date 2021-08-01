#pragma once
#ifndef NEURON_H
#define NEURON_H
#define Tanh 1
#define Relu 2
#define Sigmoid 3

#include <cmath>
using namespace std;

class Neuron
{
public:
	Neuron(double val);
	Neuron(double val, int activationType);
	~Neuron();
	void setVal(double v);
	void activate();
	void derive();

	double getVal() { return this->val; };
	double getActivateVal() { return this->activatedVal; };
	double getDerivedVal() { return this->derivatedVal; };

private:
	double val;
	double activatedVal;
	double derivatedVal;
	int activationType = Sigmoid;
};

#endif // !NEURON_H