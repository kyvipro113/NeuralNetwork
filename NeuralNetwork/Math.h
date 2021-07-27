#pragma once
#ifndef MATH_H
#define MATH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cassert>
#include <cmath>
#include "Matrix.h"

using namespace std;
namespace utils
{
	class Math
	{
	public:
		static void multiplyMatrix(Matrix *a, Matrix *b, Matrix *c);
	};

}
#endif // !MATH_H
