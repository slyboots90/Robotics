/*
 * Matrix.cpp
 *
 *  Created on: 24 juli 2017
 *      Author: mateusz.fraszczynski
 */

#include "../include/Matrix.h"
#include "../include/MatrixOperations.h"
#include <stdio.h> 							// printf

#define matrixData matrixDataPtr.get()


Matrix::Matrix() {
	matrixDataPtr = shared_ptr < vector < vector < int > > > ( new vector < vector < int > > );
	this->allocateMatrixVectors( 0 , 0 );
}

Matrix::Matrix( unsigned int no_of_rows , unsigned int no_of_colums ) {
	if ( ! no_of_rows || ! no_of_colums ) {
		printf ( "Amount of rows or columns cannot be 0!\n" );
		return;
	}
	matrixDataPtr = shared_ptr < vector < vector < int > > > ( new vector < vector < int > > );
	this->allocateMatrixVectors( no_of_rows , no_of_colums );
}

Matrix::~Matrix() {

}

bool Matrix::isEmpty() const {
	if ( this->getColumnsNo() || this->getRowsNo() ) {
		return 0;
	}
	return 1;
}

bool Matrix::isEqualSize( const Matrix & argument ) const {
	if ( this->getColumnsNo() == argument.getColumnsNo() && this->getRowsNo() == argument.getRowsNo() ) {
		return 1;
	}
	return 0;
}

bool Matrix::isColumnsNoEqualRowsNo( const Matrix & argument ) const {
	if ( this->getColumnsNo() == argument.getRowsNo() ) {
		return 1;
	}
	return 0;
}


void Matrix::allocateMatrixVectors( unsigned int no_of_rows , unsigned int no_of_colums ) {
	for ( unsigned int i = 0 ; i < no_of_rows ; i++ ) {
		this->allocateVectorInVector( );
	}
	for ( unsigned int i = 0 ; i < no_of_rows ; i++ ) {
		for ( unsigned int j = 0 ; j < no_of_colums ; j++ ) {
			matrixData->at( i ).push_back( 0 );
		}
	}
}

void Matrix::allocateVectorInVector( ) {
	vector < int > allocation_vector;
	matrixData->push_back( allocation_vector );
}

bool Matrix::verifyRowIndex( unsigned int row_index ) const {
	if ( row_index >= matrixData->size() ) {
		printf ( "Error: row_index out of matrix range, matrix row size: %d, row_index %d\n" , matrixData->size() , row_index );
		return 1;
	}
	return 0;
}

bool Matrix::verifyColumnIndex( unsigned int column_index ) const {
	if ( column_index >= matrixData->begin()->size() ) {
		printf ( "Error: column_index out of matrix range, matrix column size: %d, column_index %d\n" , matrixData->begin()->size() , column_index );
		return 1;
	}
	return 0;
}

void Matrix::printMatrix() {
	printf( "\n" );
	for ( unsigned i = 0 ; i < matrixData->size() ; i++ ) {
		printf( "|" );
		for ( vector < int >::iterator it = matrixData->at( i ).begin() ; it != matrixData->at( i ).end() ; ++it ) {
			printf( "%5d " , * it );
		}
		printf( "|\n" );
	}
	printf( "\n" );
}

void Matrix::addRow() {
	this->allocateVectorInVector( );
	vector < vector < int > >::iterator it = matrixData->end();
	it--;																// Iterator set on new added row
	unsigned int y_size;
	matrixData->size() > 1 ? y_size = ( it - 1 )->size() : y_size = 1; // it - 1 because new row must be the same y size as previous
	for ( unsigned int i = 0 ; i < y_size ; i++ ) {
		( it )->push_back( 0 );
	}
}

bool Matrix::addRowWithData( vector < int > * data_ptr ) {
	if ( ! matrixData->empty() ) {
		this->addRow();
	} else {
		this->allocateMatrixVectors( 1 ,  data_ptr->size() );
	}
	return this->fillRowWithData( data_ptr , matrixData->size() - 1 );
}

bool Matrix::fillRowWithData( int * data_ptr , unsigned int row_index ) {
	if ( this->verifyRowIndex( row_index ) ) {
		return 1;
	} else {
		for ( vector < int >::iterator it = matrixData->at( row_index ).begin() ; it < matrixData->at( row_index ).end() ; it++ , data_ptr++ ) {
			 * it = * data_ptr;
		}
		return 0;
	}
	printf ( "Cannot fill: Unexpected error, while filling Row\n" );
	return 1;
}

bool Matrix::fillRowWithData( vector < int > * data_ptr , unsigned int row_index ) {
	if ( this->verifyRowIndex( row_index ) ) {
		return 1;
	} else {
		if ( data_ptr->size() !=  matrixData->at( row_index ).size() ) {
			printf ( "Cannot fill: Size of data vector doesn't match the Matrix! data size %d, Matrix row size %d\n" , data_ptr->size() , matrixData->at( row_index ).size() );
			return 1;
		} else {
			matrixData->at( row_index ) = * data_ptr;
			return 0;
		}
	}
	printf ( "Cannot fill: Unexpected error, while filling Row\n" );
	return 1;
}

unsigned int Matrix::getRowsNo() const {
	if ( matrixData->empty() ) return 0;
	return matrixData->size();
}

const vector< int > * Matrix::getRow( unsigned int index ) const {
	if ( matrixData->empty() ) {
		printf( "ERROR: Cannot getRow - Matrix is empty\n" );
		return NULL;
	} else if ( this->verifyRowIndex( index ) ) {
		printf( "ERROR: Cannot getRow - index of of range\n" );
		return NULL;
	}
	return & matrixData->at( index );
}

void Matrix::addColumn() {
	if ( matrixData->empty() ) {
		this->addRow();
	} else {
		vector < vector < int > >::iterator it;
		for ( it = matrixData->begin() ; it != matrixData->end() ; ++it ) {
			it->push_back( 0 );
		}
	}
}

bool Matrix::addColumnWithData( vector < int > * data_ptr ) {
	if ( ! matrixData->empty() ) {
		this->addColumn();
	} else {
		this->allocateMatrixVectors( data_ptr->size() , 1 );
	}
	return this->fillColumnWithData( data_ptr , matrixData->begin()->size() - 1 );
}

bool Matrix::fillColumnWithData( int * data_ptr , unsigned int column_index ) {
	if ( this->verifyColumnIndex( column_index ) ) {
		return 1;
	} else {
		for ( vector < vector < int > >::iterator it = matrixData->begin() ; it < matrixData->end() ; it++ , data_ptr++ ) {
			it->at( column_index ) = * data_ptr;
		}
		return 0;
	}
	printf ( "Cannot fill: Unexpected error, while filling Column\n" );
	return 1;
}

bool Matrix::fillColumnWithData( vector < int > * data_ptr , unsigned int column_index ) {
	if ( this->verifyColumnIndex( column_index ) ) {
		return 1;
	} else {
		if ( data_ptr->size() !=  matrixData->size() ) {
			printf ( "Cannot fill: Size of data vector doesn't match the Matrix!\n" );
			return 1;
		} else {
			vector < vector < int > >::iterator it = matrixData->begin();
			for ( vector < int >::iterator it_data = data_ptr->begin() ;  it != matrixData->end() ; it++ , it_data++ ) {
				it->at( column_index ) = * it_data;
			}
			return 0;
		}
	}
	printf ( "Cannot fill: Unexpected error, while filling Column\n" );
	return 1;
}

unsigned int Matrix::getColumnsNo() const {
	if ( matrixData->empty() ) return 0;
	return matrixData->begin()->size();
}

bool Matrix::getColumn( vector< const int * > * column_vector , unsigned int index ) const {
	if ( this->verifyColumnIndex( index ) ) {
		printf( "ERROR: Cannot getColumn - index of of range\n" );
		return 1;
	} else {
		for ( unsigned int i = 0 ; i < matrixData->size() ; i++ ) {
			column_vector->push_back( & matrixData->at( i ).at( index ) );
		}
		return 0;
	}
	return 1;
}

void Matrix::operator =(  Matrix & argument ) {

}

Matrix & Matrix::operator *( const Matrix & argument ) {
	//Matrix * result = new Matrix();
	//TODO creating Matrix with column size is work around until Matrix will be fixed - column issue
	Matrix * result = new Matrix( 1 , argument.getColumnsNo() );
	if ( this->isColumnsNoEqualRowsNo( argument ) ) {
		MatrixOperations::multiplication( * result , * this , argument );
	} else {
		printf( "ERROR: Cannot multiple - size of Matrix doesn't match!\n" );
	}
	return * result;
}

Matrix & Matrix::operator +( const Matrix & argument ) {
	//Matrix * result = new Matrix();
	//TODO creating Matrix with column size is work around until Matrix will be fixed - column issue
	Matrix * result = new Matrix( 1 , argument.getColumnsNo() );
	if ( this->isEqualSize( argument ) ) {
		MatrixOperations::addition( * result , * this , argument );
	} else {
		printf( "ERROR: Cannot add - size of Matrix doesn't match!\n" );
	}
	return * result;
}

Matrix & Matrix::operator -( const Matrix & argument ) {
	//Matrix * result = new Matrix();
	//TODO creating Matrix with column size is work around until Matrix will be fixed - column issue
	//Matrix * result = new Matrix( 1 , argument.getColumnsNo() );
	//shared_ptr < Matrix > result ( new Matrix( 1 , argument.getColumnsNo() ) );
	shared_ptr < Matrix > result ( new Matrix( ) );
	if ( this->isEqualSize( argument ) ) {
		MatrixOperations::subtraction( * result , * this , argument );
	} else {
		printf( "ERROR: Cannot subtract - size of Matrix doesn't match!\n" );
	}
	return * result;
}
