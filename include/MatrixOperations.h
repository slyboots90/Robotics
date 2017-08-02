/*
 * MatrixOperations.h
 *
 *  Created on: 2 aug. 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef MATRIXOPERATIONS_H_
#define MATRIXOPERATIONS_H_

#include <vector>
#include "Matrix.h"
using namespace std;

class MatrixOperations {

	static vector<int> getColumnVector(unsigned int);
	static int vectorMultiplication(vector<int>*, vector<int>*);


public:
	MatrixOperations();
	virtual ~MatrixOperations();
	static Matrix & multiplication(const Matrix &, const Matrix &);
};

#endif /* MATRIXOPERATIONS_H_ */
