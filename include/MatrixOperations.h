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

	static int vectorMultiplication( const vector< int > * , vector< const int * > * );

public:
	MatrixOperations();
	virtual ~MatrixOperations();
	static void multiplication( Matrix & , const Matrix & , const Matrix & );
	static void scalarmultiplication( Matrix & , const Matrix & , int );
	static void scalarmultiplication( Matrix & , int );
	static void addition( Matrix & , const Matrix & , const Matrix & );
	static void subtraction( Matrix & , const Matrix & , const Matrix & );
	//TODO Following implementation needed
	static void transposition( Matrix & , const Matrix & );
	static int determinant( const Matrix & ); //return float?
	static void inverse( Matrix & , const Matrix & );
	static void inverse( Matrix & );
	static void minor();

};

#endif /* MATRIXOPERATIONS_H_ */
