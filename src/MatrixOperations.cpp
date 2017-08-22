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

void MatrixOperations::multiplication( Matrix & product , const Matrix & multiplicand , const Matrix & multiplier ) {
	const vector < int > * row_pointer = NULL;
	if ( ! multiplicand.isEmpty() && ! multiplier.isEmpty() ) {
		for ( unsigned int i = 0 ; i < multiplicand.getRowsNo() ; i++ ) {
			vector < int > temporary_vector;
			for ( unsigned int j = 0 ; j < multiplier.getColumnsNo() ; j++ ) {
				vector < const int * > pointers_to_column;
				row_pointer = multiplicand.getRow( i );
				if ( row_pointer == NULL) {
					printf( "Fail to get Row from Matrix\n" );
					break;
				}
				if ( multiplier.getColumn( & pointers_to_column , j ) ) {
					printf( "Fail to get Column from Matrix\n" );
					break;
				}
				int outcome_value = MatrixOperations::vectorMultiplication( row_pointer , & pointers_to_column );
				temporary_vector.push_back( outcome_value );
			}
			if ( product.addRowWithData( & temporary_vector ) ) {
				printf( "Fail to add temporary_vector to Matrix\n" );
			}
		}
	}
}

void MatrixOperations::scalarmultiplication( Matrix & product , const Matrix & multiplicand , int multiplier ) {
	const vector < int > * row_pointer = NULL;
	if ( ! multiplicand.isEmpty() ) {
		for ( unsigned int i = 0 ; i < multiplicand.getRowsNo() ; i++ ) {
			vector < int > temporary_vector;
			row_pointer = multiplicand.getRow( i );
			if ( row_pointer == NULL) {
				printf( "Fail to get Row from Matrix\n" );
				break;
			}
			for ( unsigned int j = 0 ; j < row_pointer->size() ; j++ ) {
				temporary_vector.push_back( row_pointer->at( j ) * multiplier );
			}
			if ( product.addRowWithData( & temporary_vector ) ) {
				printf( "Fail to add temporary_vector to Matrix\n" );
			}
		}
	}
}

void MatrixOperations::scalarmultiplication( Matrix & multiplicand , int multiplier ) {
	if ( ! multiplicand.isEmpty() ) {
		for ( unsigned int i = 0 ; i < multiplicand.getRowsNo() ; i++ ) {
			for( unsigned int j = 0 ; j < multiplicand.getColumnsNo() ; j++ ) {
				multiplicand.matrixDataPtr->at( i ).at( j ) *= multiplier;
			}
		}
	}
}

int MatrixOperations::vectorMultiplication( const vector < int > * row_pointer , vector < const int * > * column_pointer ) {
	int result = 0;
	if ( row_pointer->size() != column_pointer->size() ) {
		printf ( "Size of multiplied vectors isn't equal - must be the same! row size: %d, column size: %d\n" , row_pointer->size() , column_pointer->size() );
	} else {
		for ( unsigned int i = 0 ; i < row_pointer->size() ; i++ ) {
			result += row_pointer->at( i ) * *( column_pointer->at( i ) ) ;
		}
		return result;
	}
	return 0;
}

void MatrixOperations::addition( Matrix & sum , const Matrix & component_a , const Matrix & component_b ) {
	const vector < int > * component_a_row_pointer = NULL;
	const vector < int > * component_b_row_pointer = NULL;
		if ( ! component_a.isEmpty() && ! component_b.isEmpty() ) {
			for ( unsigned int i = 0 ; i < component_a.getRowsNo() ; i++ ) {
				vector < int > temporary_vector;
				component_a_row_pointer = component_a.getRow( i );
				component_b_row_pointer = component_b.getRow( i );
				if ( component_a_row_pointer == NULL || component_b_row_pointer == NULL ) {
					printf( "Fail to get Row from Matrix\n" );
					break;
				}
				for ( unsigned int j = 0 ; j < component_a.getColumnsNo() ; j++ ) {
					int outcome_value = component_a_row_pointer->at( j ) + component_b_row_pointer->at( j );
					temporary_vector.push_back( outcome_value );
				}
				if ( sum.addRowWithData( & temporary_vector ) ) {
					printf( "Fail to add temporary_vector to Matrix\n" );
				}
			}
		}
}

void MatrixOperations::subtraction( Matrix & difference , const Matrix & minuend , const Matrix & subtrahend ) {
	const vector < int > * minuend_row_pointer = NULL;
	const vector < int > * subtrahend_row_pointer = NULL;
		if ( ! minuend.isEmpty() && ! subtrahend.isEmpty() ) {
			for ( unsigned int i = 0 ; i < minuend.getRowsNo() ; i++ ) {
				vector < int > temporary_vector;
				minuend_row_pointer = minuend.getRow( i );
				subtrahend_row_pointer = subtrahend.getRow( i );
				if ( subtrahend_row_pointer == NULL || minuend_row_pointer == NULL ) {
					printf( "Fail to get Row from Matrix\n" );
					break;
				}
				for ( unsigned int j = 0 ; j < minuend.getColumnsNo() ; j++ ) {
					int outcome_value = minuend_row_pointer->at( j ) - subtrahend_row_pointer->at( j );
					temporary_vector.push_back( outcome_value );
				}
				if ( difference.addRowWithData( & temporary_vector ) ) {
					printf( "Fail to add temporary_vector to Matrix\n" );
				}
			}
		}
}

int MatrixOperations::determinant( const Matrix & base ) {

}
