/*
 * matrix.cpp
 *
 *  Created on: 24 juli 2017
 *      Author: mateusz.fraszczynski
 */

#include "../include/matrix.h"
#include <stdio.h> 		//printf

matrix::matrix() {

}

matrix::matrix(unsigned int noOfRows, unsigned int noOfColums) {
	if(!noOfRows || !noOfColums) {
		printf ("Rows and Column amount cannot be 0!");
		return;
	}
	this->allocateMatrixVectors(noOfRows, noOfColums);
}

matrix::~matrix() {
	// TODO Auto-generated destructor stub
}

void matrix::allocateMatrixVectors(unsigned int noOfRows, unsigned int noOfColums) {
	matrixData.resize(noOfRows);
	for (unsigned int i=0; i < noOfRows; i++) {
		matrixData[i].resize(noOfColums, 0);
	}
}

int matrix::addRow(unsigned int noOfElements) {
	if(matrixData.empty()) {
		matrixData.resize(1);
		vector<vector<int> >::iterator it = matrixData.begin();
		it->resize(noOfElements, 0);
		return 0;
	} else {
		//TODO delete noOfElements
		vector<vector<int> >::iterator it = matrixData.begin();
		if(it->size() == noOfElements) {
			matrixData.resize(matrixData.size() + 1);
			it = matrixData.end();
			it->resize(noOfElements, 0);
			return 0;
		}
		else {
			printf ("Cannot add: Size of elements doesn't fit to matrix, matrix row size: %d, provided %d\n", it->size(), noOfElements);
			return 1;
		}
	}
	printf ("Cannot add: Unexpected error, noOfElements %d\n", noOfElements);
	return 1;
}

int matrix::addColumn(unsigned int noOfElements) {
	if(matrixData.empty()) {
		matrixData.resize(noOfElements);
		for(vector<vector<int> >::iterator it = matrixData.begin(); it != matrixData.end(); ++it) {
			it->resize(1, 0);
		}
		return 0;
	} else {
		//TODO delete noOfElements
		if(matrixData.size() == noOfElements) {
			for(vector<vector<int> >::iterator it = matrixData.begin(); it != matrixData.end(); ++it) {
				it->resize(it->size() + 1, 0);
			}
			return 0;
		} else {
			printf ("Cannot add: Size of elements doesn't fit to matrix, matrix column size: %d, provided %d\n", matrixData.size(), noOfElements);
			return 1;
		}
	}
	printf ("Cannot add: Unexpected error, noOfElements %d\n", noOfElements);
	return 1;
}


int matrix::fillRowWithData(int* data, unsigned int rowIndex) {
	if(rowIndex > matrixData.size()) {
		printf ("Cannot fill: rowIndex out of matrix range, matrix row size: %d, rowIndex %d\n", matrixData.size(), rowIndex);
		return 1;
	} else {
		// TODO
	}
	return 1;
}

int matrix::fillColumnWithData(int* data, unsigned int columnIndex) {
	vector<vector<int> >::iterator it = matrixData.begin();
	if(columnIndex > it->size()) {
		printf ("Cannot fill: columnIndex out of matrix range, matrix column size: %d, columnIndex %d\n", it->size(), columnIndex);
		return 1;
	} else {
		// TODO
	}
	return 1;
}

unsigned int matrix::verifyMatrixDimensionY() {
	if(matrixData.empty()) return 0;
	return matrixData.size();
}

unsigned int matrix::verifyMatrixDimensionX() {
	if(matrixData.empty()) {
		printf ("Verification failed: Vector is empty\n");
		return 1;
	}
	//TODO No of Row = 1 case
	vector<vector<int> >::iterator it = matrixData.begin();
	while(it != matrixData.end()) {
		if(it->size() != (++it)->size()) {
			printf ("Verification failed: amount of columns are different: %d, %d\n", (it-1)->size(), it->size());
		}
		printf ("Debug: amount of columns: %d\n", it->size());
	}
	return matrixData.begin()->size();
}

unsigned int matrix::verifyMatrixCapacityY() {
	return matrixData.capacity();
}

unsigned int matrix::verifyMatrixCapacityX() {
	vector<vector<int> >::iterator it = matrixData.begin();
	return it->capacity();
}

int matrix::vector_multiple(int* vectorX, int* vectorY, unsigned int lenght) {
	//TODO del lenght
	int resoult = 0;
	for(unsigned int i=0; i < lenght; i++) {
		resoult += (*vectorX++)*(*vectorY++);
	}
	return resoult;
}
