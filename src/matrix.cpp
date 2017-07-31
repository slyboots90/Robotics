/*
 * matrix.cpp
 *
 *  Created on: 24 juli 2017
 *      Author: mateusz.fraszczynski
 */

#include "../include/matrix.h"
#include <stdio.h> 							//printf

matrix::matrix() {
	this->allocateMatrixVectors(1, 1);
}

matrix::matrix(unsigned int no_of_rows, unsigned int no_of_colums) {
	if(!no_of_rows || !no_of_colums) {
		printf ("Amount of rows or columns cannot be 0!\n");
		return;
	}
	this->allocateMatrixVectors(no_of_rows, no_of_colums);
}

matrix::~matrix() {
	// TODO Auto-generated destructor stub
}

void matrix::allocateMatrixVectors(unsigned int no_of_rows, unsigned int no_of_colums) {
	matrixData.resize(no_of_rows);
	for(unsigned int i = 0; i < matrixData.size(); i++ ) {
		this->allocateVectorInVector(i);
	}
	for (unsigned int i = 0; i < no_of_rows; i++) {
		matrixData[i].resize(no_of_colums, 0);
	}
}

bool matrix::addRow(unsigned int no_of_elements) {
	if(matrixData.empty()) {
		matrixData.resize(1);
		this->allocateVectorInVector(matrixData.size() - 1);
		vector<vector<int> >::iterator it = matrixData.begin();
		it->resize(no_of_elements, 0);
		return 0;
	} else {
		vector<vector<int> >::iterator it = matrixData.begin();
		if(it->size() == no_of_elements) {
			return this->addRow();
		} else {
			printf ("Cannot add: Size of elements doesn't fit to matrix, matrix row size: %d, provided %d\n", it->size(), no_of_elements);
			return 1;
		}
	}
	printf ("Cannot add: Unexpected error, no_of_elements %d\n", no_of_elements);
	return 1;
}

bool matrix::addRow() {
	if(matrixData.empty()) {
		printf ("Cannot add: Matrix desn't have any rows\n");
		return 1;
	} else {
		unsigned int x_size = matrixData.size();
		vector<vector<int> >::iterator it = matrixData.begin();
		unsigned int y_size = it->size();
		matrixData.resize(x_size + 1);
		this->allocateVectorInVector(matrixData.size() - 1);
		it = matrixData.end();
		(--it)->resize(y_size, 0);
		return 0;
	}
	printf ("Cannot add: Unexpected error, while adding row\n");
	return 1;
}

bool matrix::addColumn(unsigned int no_of_elements) {
	if(matrixData.empty()) {
		matrixData.resize(no_of_elements);
		for(vector<vector<int> >::iterator it = matrixData.begin(); it != matrixData.end(); ++it) {
			it->resize(1, 0);
		}
		return 0;
	} else {
		if(matrixData.size() == no_of_elements) {
			this->addColumn();
			return 0;
		} else {
			printf ("Cannot add: Size of elements doesn't fit to matrix, matrix column size: %d, provided %d\n", matrixData.size(), no_of_elements);
			return 1;
		}
	}
	printf ("Cannot add: Unexpected error, no_of_elements %d\n", no_of_elements);
	return 1;
}

bool matrix::addColumn() {
	if(matrixData.empty()) {
		printf ("Cannot add: Matrix desn't have any columns\n");
		return 1;
	} else {
		vector<vector<int> >::iterator it = matrixData.begin();
		unsigned int y_size = it->size();
		for( ; it != matrixData.end(); ++it) {
			it->resize(y_size + 1, 0);
		}
		return 0;
	}
	printf ("Cannot add: Unexpected error, while adding column\n");
	return 1;
}

void matrix::allocateVectorInVector(unsigned int index) {
	vector<int> allocation_vector;
	matrixData.at(index) = allocation_vector;
}

bool matrix::fillRowWithData(int* data_ptr, unsigned int row_index) {
	if(this->verifyRowIndex(row_index)) {
		return 1;
	} else {
		for(vector<int>::iterator it = matrixData[row_index - 1].begin(); it < matrixData[row_index - 1].end(); it++, data_ptr++) {
			*it = *data_ptr;
		}
		return 0;
	}
	printf ("Cannot fill: Unexpected error, while filling Row\n");
	return 1;
}

bool matrix::fillRowWithData(vector<int>* data_ptr, unsigned int row_index) {
	if(this->verifyRowIndex(row_index)) {
		return 1;
	} else {
		if(data_ptr->size() !=  matrixData[row_index - 1].size()) {
			printf ("Cannot fill: Size of data vector doesn't match the Matrix!\n");
			return 1;
		} else {
			matrixData[row_index - 1] = *data_ptr;
			for(vector<int>::iterator it = matrixData[row_index - 1].begin(); it < matrixData[row_index - 1].end(); it++) {
			}
			return 0;
		}
	}
	printf ("Cannot fill: Unexpected error, while filling Row\n");
	return 1;
}

bool matrix::fillColumnWithData(int* data_ptr, unsigned int column_index) {
	if(this->verifyColumnIndex(column_index)) {
		return 1;
	} else {
		for(vector<vector<int> >::iterator it = matrixData.begin(); it < matrixData.end(); it++, data_ptr++) {
			it->at(column_index - 1) = *data_ptr;
		}
		return 0;
	}
	printf ("Cannot fill: Unexpected error, while filling Column\n");
	return 1;
}

bool matrix::fillColumnWithData(vector<int>* data_ptr, unsigned int column_index) {
	if(this->verifyColumnIndex(column_index)) {
		return 1;
	} else {
		if(data_ptr->size() !=  matrixData.size()) {
			printf ("Cannot fill: Size of data vector doesn't match the Matrix!\n");
			return 1;
		} else {
			vector<vector<int> >::iterator it = matrixData.begin();
			for(vector<int>::iterator it_data = data_ptr->begin();  it != matrixData.end(); it++, it_data++) {
				it->at(column_index - 1) = *it_data;
			}
			return 0;
		}
	}
	printf ("Cannot fill: Unexpected error, while filling Column\n");
	return 1;
}

bool matrix::verifyRowIndex(unsigned int row_index) {
	if(row_index == 0) {
		printf ("Cannot fill: row_index cannot be 0!\n");
		return 1;
	} else if(row_index > matrixData.size()) {
		printf ("Cannot fill: row_index out of matrix range, matrix row size: %d, row_index %d\n", matrixData.size(), row_index);
		return 1;
	}
	return 0;
}

bool matrix::verifyColumnIndex(unsigned int column_index) {
	if(column_index == 0) {
		printf ("Cannot fill: column_index cannot be 0!\n");
		return 1;
	} else if(column_index > matrixData.begin()->size()) {
		printf ("Cannot fill: column_index out of matrix range, matrix column size: %d, column_index %d\n", matrixData.begin()->size(), column_index);
		return 1;
	}
	return 0;
}

unsigned int matrix::getRowsNo() {
	if(matrixData.empty()) return 0;
	return matrixData.size();
}

unsigned int matrix::getColumnNo() {
	if(matrixData.empty()) return 0;
	return matrixData.begin()->size();
}

unsigned int matrix::verifyMatrixDimensionY() {
	// After all this not needed
	if(matrixData.empty()) return 0;
	return matrixData.size();
}

unsigned int matrix::verifyMatrixDimensionX() {
	// After all this not needed
	if(matrixData.empty()) {
		printf ("Verification failed: Vector is empty\n");
		return 0;
	} else if(matrixData.size() == 1) {
		return matrixData.begin()->size();
	} else {
		vector<vector<int> >::iterator it = matrixData.begin();
		vector<vector<int> >::iterator it_end = matrixData.end();
		while(it != it_end - 1) {
			if(it->size() != (++it)->size()) {
				printf ("Verification failed: amount of columns are different: %d, %d\n", (it-1)->size(), it->size());
			}
		}
		return matrixData.begin()->size();
	}
}

void matrix::printMatrix() {
	for(unsigned i = 0 ; i < matrixData.size() ; i++) {
		printf("|");
		for(vector<int>::iterator it = matrixData[i].begin(); it != matrixData[i].end(); ++it ) {
			printf("%5d ", *it);
		}
		printf("|\n");
	}
}

int matrix::vector_multiple(int* vector_x, int* vector_y, unsigned int lenght) {
	//TODO del lenght
	int result = 0;
	for(unsigned int i=0; i < lenght; i++) {
		result += (*vector_x++)*(*vector_y++);
	}
	return result;
}
