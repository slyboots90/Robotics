/*
 * matrix.h
 *
 *  Created on: 24 juli 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
using namespace std;

class matrix {

	void allocateMatrixVectors(unsigned int, unsigned int);
	void allocateVectorInVector(unsigned int);
	bool verifyRowIndex(unsigned int);
	bool verifyColumnIndex(unsigned int);

	vector< vector<int> > matrixData;

public:
	matrix();
	matrix(unsigned int, unsigned int);
	virtual ~matrix();
	// Rows
	bool addRow(unsigned int);
	bool addRow(void);
	bool fillRowWithData(int*, unsigned int);
	bool fillRowWithData(vector<int>*, unsigned int);
	unsigned int getRowsNo(void);
	// Columns
	bool addColumn(unsigned int);
	bool addColumn(void);
	bool fillColumnWithData(int*, unsigned int);
	bool fillColumnWithData(vector<int>*, unsigned int);
	unsigned int getColumnNo(void);
	// Debug
	unsigned int verifyMatrixDimensionY(void);
	unsigned int verifyMatrixDimensionX(void);
	//end of debug
	void printMatrix(void);
	int vector_multiple(int*, int*, unsigned int);

};

#endif /* MATRIX_H_ */
