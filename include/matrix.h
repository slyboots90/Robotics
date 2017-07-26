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

	vector< vector<int> > matrixData;

public:
	matrix();
	matrix(unsigned int, unsigned int);
	virtual ~matrix();
	int addRow(unsigned int);
	int addRow(void);
	int addColumn(unsigned int);
	int addColumn(void);
	int fillRowWithData(int*, unsigned int);
	int fillColumnWithData(int*, unsigned int);
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
