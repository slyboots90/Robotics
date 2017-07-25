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
	this->allocateMatrixVectors(noOfRows, noOfColums);
}

matrix::~matrix() {
	// TODO Auto-generated destructor stub
}

void matrix::allocateMatrixVectors(unsigned int noOfRows, unsigned int noOfColums) {
	matrixData.reserve(noOfRows);
	for (unsigned int i=0; i < noOfRows; i++) {
		matrixData[i].reserve(noOfColums);
	}
}

int matrix::addRow(unsigned int noOfElements) {
	if(matrixData.empty()) {
		matrixData.reserve(1);
		vector<vector<int> >::iterator it = matrixData.begin();
		it->reserve(noOfElements);
		return 1;
	} else {
		vector<vector<int> >::iterator it = matrixData.begin();
		if(it->size() == noOfElements) {
			matrixData.reserve(matrixData.size() + 1);
			it = matrixData.end();
			it->reserve(noOfElements);
			return 1;
		}
		else {
			printf ("Cannot add: Size of elements doesn't fit to matrix, matrix row size: %d, provided %d\n", it->size(), noOfElements);
			return 0;
		}
	}
	printf ("Cannot add: Unexpected error, noOfElements %d\n", noOfElements);
	return 0;
}

int matrix::addColumn(unsigned int noOfElements) {
	if(matrixData.empty()) {
		matrixData.reserve(noOfElements);
		for(vector<vector<int> >::iterator it = matrixData.begin(); it != matrixData.end(); ++it) {
			it->reserve(1);
		}
		return 1;
	} else {
		if(matrixData.size() == noOfElements) {
			for(vector<vector<int> >::iterator it = matrixData.begin(); it != matrixData.end(); ++it) {
				it->reserve(it->size() + 1);
			}
			return 1;
		} else {
			printf ("Cannot add: Size of elements doesn't fit to matrix, matrix column size: %d, provided %d\n", matrixData.size(), noOfElements);
			return 0;
		}
	}
	printf ("Cannot add: Unexpected error, noOfElements %d\n", noOfElements);
	return 0;
}


int matrix::fillRowWithData(int* data, unsigned int rowIndex) {
	if(rowIndex > matrixData.size()) {
		printf ("Cannot fill: rowIndex out of matrix range, matrix row size: %d, rowIndex %d\n", matrixData.size(), rowIndex);
		return 0;
	} else {
		// TODO
	}
	return 0;
}

int matrix::fillColumnWithData(int* data, unsigned int columnIndex) {
	vector<vector<int> >::iterator it = matrixData.begin();
	if(columnIndex > it->size()) {
		printf ("Cannot fill: columnIndex out of matrix range, matrix column size: %d, columnIndex %d\n", it->size(), columnIndex);
		return 0;
	} else {
		// TODO
	}
	return 0;
}



int matrix::vector_multiple(int* vectorX, int* vectorY, unsigned int lenght) {
	//TODO del lenght
	int resoult = 0;
	for(unsigned int i=0; i < lenght; i++) {
		resoult += (*vectorX++)*(*vectorY++);
	}
	return resoult;
}
