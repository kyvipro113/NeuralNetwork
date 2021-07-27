#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
using namespace std;
class Matrix
{
public:
	Matrix(int numRows, int numCols, bool isRandom);
	Matrix *transpose();
	Matrix *copy();
	void printToConsole();
	void setValue(int r, int c, double v) { this->values.at(r).at(c) = v; }
	int getNumRows() { return this->numRows; };
	int getNumCols() { return this->numCols; };
	double getValue(int r, int c) { return this->values.at(r).at(c); }


private:
	int numRows;
	int numCols;
	vector < vector<double> > values;
	double generateRandomNumber();
};

#endif // !MATRIX_H
