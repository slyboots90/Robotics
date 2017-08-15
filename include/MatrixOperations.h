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

	static int vectorMultiplication( const vector<int> * , vector< const int * > * );

public:
	MatrixOperations();
	virtual ~MatrixOperations();
	static void multiplication( Matrix & , const Matrix & , const Matrix & );
	static void addition( Matrix & , const Matrix & , const Matrix & );
	static void subtraction( Matrix & , const Matrix & , const Matrix & );

};

#endif /* MATRIXOPERATIONS_H_ */
