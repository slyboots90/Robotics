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
	bool verifyRowIndex(unsigned int);
	void allocateVectorInVector(unsigned int);

	vector< vector<int> > matrixData;

public:
	matrix();
	matrix(unsigned int, unsigned int);
	virtual ~matrix();
	bool addRow(unsigned int);
	bool addRow(void);
	bool addColumn(unsigned int);
	bool addColumn(void);
	bool fillRowWithData(int*, unsigned int);
	bool fillRowWithData(vector<int>*, unsigned int);
	bool fillColumnWithData(int*, unsigned int);
	unsigned int getRowsNo(void);
	unsigned int getColumnNo(void);
	//debug
	unsigned int verifyMatrixDimensionY(void);
	unsigned int verifyMatrixDimensionX(void);
	unsigned int verifyMatrixCapacityY(void);
	unsigned int verifyMatrixCapacityX(void);
	//end of debug
	int vector_multiple(int*, int*, unsigned int);

};

#endif /* MATRIX_H_ */
