/*
 * MatrixOperations.cpp
 *
 *  Created on: 2 aug. 2017
 *      Author: mateusz.fraszczynski
 */

#include "../include/MatrixOperations.h"
#include "../include/Matrix.h"
#include <stdio.h> 							//printf


MatrixOperations::MatrixOperations() {
	// TODO Auto-generated constructor stub

}

MatrixOperations::~MatrixOperations() {
	// TODO Auto-generated destructor stub
}

Matrix & MatrixOperations::multiplication( const Matrix & multiplicand , const Matrix & multiplier ) {
	Matrix * resoult = new Matrix( multiplicand.getRowsNo() , multiplier.getColumnNo() );

	return * resoult;
}

int MatrixOperations::vectorMultiplication( vector<int> * vector_x , vector<int> * vector_y ) {
	int resoult;
	if( vector_x->size() != vector_y->size() ) {
		printf ( "Size of multiplied vectors isn't equal - must be the same! \n" );
	} else {
		for( unsigned int i = 0 ; i < vector_x->size() ; i++ ) {
			resoult += vector_x->at( i ) * vector_y->at( i );
		}
		return resoult;
	}
	return 0;
}

vector<int> MatrixOperations::getColumnVector( unsigned int column_index ) {
	//TODO wyrzucic tworzenie wektora
//	vector<int> column_vector;
//	if(this->verifyColumnIndex(column_index)) {
//		printf ("Verification failed: Wrong column index, returning empty vector\n");
//	} else {
//		for(vector<vector<int> >::iterator it = matrixData.begin(); it < matrixData.end(); it++) {
//			column_vector.push_back(it->at(column_index - 1));
//		}
//	}
//	return column_vector;
}
