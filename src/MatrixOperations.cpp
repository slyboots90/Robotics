/*
 * MatrixOperations.cpp
 *
 *  Created on: 2 aug. 2017
 *      Author: mateusz.fraszczynski
 */

#include "../include/MatrixOperations.h"
#include <stdio.h> 							//printf


MatrixOperations::MatrixOperations() {
	// TODO Auto-generated constructor stub

}

MatrixOperations::~MatrixOperations() {
	// TODO Auto-generated destructor stub
}

Matrix & MatrixOperations::multiplication( const Matrix & multiplicand , const Matrix & multiplier ) {
	const vector < int > * row_pointer;
	Matrix * result = new Matrix();
	if( multiplicand.getRowsNo() && multiplier.getColumnNo() ) {
		//TODO creating here Matrix is work around until Matrix will be fixed - column issue
		Matrix * result = new Matrix(1,multiplier.getColumnNo() );
		for( unsigned int i = 1 ; i <= multiplicand.getRowsNo() ; i++ ) {
			vector < int > temporary_vector;
			for( unsigned int j = 1 ; j <= multiplier.getColumnNo() ; j++ ) {
				vector < const int * > pointers_to_column;
				row_pointer = multiplicand.getRow( i );
				multiplier.getColumn( & pointers_to_column , j );
				int outcome_value = MatrixOperations::vectorMultiplication( row_pointer , & pointers_to_column );
				temporary_vector.push_back( outcome_value );
			}
			if( result->addRowWithData( & temporary_vector ) ) {
				printf("Fail to add temporary_vector to Matrix\n");
			}
		}
		//TODO delete after all
		result->printMatrix();
		//TODO return * result;  here is work around until Matrix fix
		return * result;
	}
	return * result;
}

int MatrixOperations::vectorMultiplication( const vector < int > * row_pointer , vector < const int * > * column_pointer ) {
	int result = 0;
	if( row_pointer->size() != column_pointer->size() ) {
		printf ( "Size of multiplied vectors isn't equal - must be the same! row size: %d, column size: %d\n", row_pointer->size() , column_pointer->size() );
	} else {
		for( unsigned int i = 0 ; i < row_pointer->size() ; i++ ) {
			result += row_pointer->at( i ) * *( column_pointer->at( i ) ) ;
		}
		return result;
	}
	return 0;
}
