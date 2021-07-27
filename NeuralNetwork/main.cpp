#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
#include <ostream>
#include <streambuf>
#include <ctime>

#include "Matrix.h"
#include "Math.h"
#include "NeuralNetwork.h"

using namespace std;

int main(int argc, char **argv)
{
	vector<double> input;
	input.push_back(0.2);
	input.push_back(0.5);
	input.push_back(0.1);

	vector<double> target;
	target.push_back(0.2);
	target.push_back(0.5);
	target.push_back(0.1);

	double learningRate = 0.05;
	double momentum = 1;
	double bias = 1;

	vector<int> topology;
	topology.push_back(10);
	topology.push_back(10);
	topology.push_back(10);

	cout << "Done\n";
	NeuralNetwork *n = new NeuralNetwork(topology, 2, 3, 1, 1, 0.05, 1);
	cout << "Done\n";

	for (int i = 0; i < 10; i++) {
		// cout << "Training at index " << i << endl;
		n->train(input, target, bias, learningRate, momentum);
		cout << "Error: " << n->error << endl;
	}
	// Primeiro teste:
	/*     for (int i = 0; i < 100; i++) {
	Matrix *a = new Matrix(100, 100, true);
	Matrix *b = new Matrix(100, 100, true);
	Matrix *c = new Matrix(a->getNumRows(), b->getNumRows(), false);
	cout << "Multiplying matrix at index " << i << endl;
	utils::Math::multiplyMatrix(a, b, c);
	delete a;
	delete b;
	delete c;
	} */
	return 0;
}