/*
 * Matrix.cpp
 *
 *  Created on: 24 juli 2017
 *      Author: mateusz.fraszczynski
 */

#include "../include/Matrix.h"
#include "../include/MatrixOperations.h"
#include <stdio.h> 							//printf

Matrix::Matrix() {
	this->allocateMatrixVectors( 1 , 1 );
}

Matrix::Matrix( unsigned int no_of_rows , unsigned int no_of_colums ) {
	if( ! no_of_rows || ! no_of_colums ) {
		printf ( "Amount of rows or columns cannot be 0!\n" );
		return;
	}
	this->allocateMatrixVectors( no_of_rows , no_of_colums );
}

Matrix::~Matrix() {
	// TODO Auto-generated destructor stub
}

void Matrix::allocateMatrixVectors( unsigned int no_of_rows , unsigned int no_of_colums ) {
	matrixData.resize( no_of_rows );
	for( unsigned int i = 0 ; i < matrixData.size() ; i++ ) {
		this->allocateVectorInVector( i );
	}
	for ( unsigned int i = 0 ; i < no_of_rows ; i++ ) {
		matrixData[ i ].resize( no_of_colums , 0 );
	}
}

void Matrix::allocateVectorInVector( unsigned int index ) {
	vector < int > allocation_vector;
	matrixData.at( index ) = allocation_vector;
}

bool Matrix::verifyRowIndex( unsigned int row_index ) const {
	if( row_index == 0 ) {
		printf ( "Error: row_index cannot be 0!\n" );
		return 1;
	} else if( row_index > matrixData.size() ) {
		printf ( "Error: row_index out of matrix range, matrix row size: %d, row_index %d\n" , matrixData.size() , row_index );
		return 1;
	}
	return 0;
}

bool Matrix::verifyColumnIndex( unsigned int column_index ) const {
	if( column_index == 0 ) {
		printf ( "Error: column_index cannot be 0!\n" );
		return 1;
	} else if( column_index > matrixData.begin()->size() ) {
		printf ( "Error: column_index out of matrix range, matrix column size: %d, column_index %d\n" , matrixData.begin()->size() , column_index );
		return 1;
	}
	return 0;
}

bool Matrix::addRow( unsigned int no_of_elements ) {
	if( matrixData.empty() ) {
		matrixData.resize( 1 );
		this->allocateVectorInVector( matrixData.size() - 1 );
		vector < vector < int > >::iterator it = matrixData.begin();
		it->resize( no_of_elements , 0 );
		return 0;
	} else {
		vector < vector < int > >::iterator it = matrixData.begin();
		if( it->size() == no_of_elements ) {
			return this->addRow();
		} else {
			printf ( "Cannot add: Size of elements doesn't fit to matrix, matrix row size: %d, provided %d\n" , it->size() , no_of_elements );
			return 1;
		}
	}
	printf ( "Cannot add: Unexpected error, no_of_elements %d\n" , no_of_elements );
	return 1;
}

bool Matrix::addRow() {
	if( matrixData.empty() ) {
		printf ( "Cannot add: Matrix desn't have any rows\n" );
		return 1;
	} else {
		//TODO Bug while adding vector in column size if using default constructor
		unsigned int x_size = matrixData.size();
		vector < vector < int > >::iterator it = matrixData.begin();
		unsigned int y_size = it->size();
		matrixData.resize( x_size + 1 );
		this->allocateVectorInVector( matrixData.size() - 1 );
		it = matrixData.end();
		( --it )->resize( y_size , 0 );
		return 0;
	}
	printf ( "Cannot add: Unexpected error, while adding row\n" );
	return 1;
}

bool Matrix::addRowWithData( vector < int > * data_ptr ) {
	if( ! (this->addRow() ) ) {
		return this->fillRowWithData( data_ptr , matrixData.size() - 1 );
	} else {
		return 1;
	}
	printf ( "Cannot fill: Unexpected error, while adding and filling Row\n" );
	return 1;
}

bool Matrix::fillRowWithData( int * data_ptr , unsigned int row_index ) {
	if( this->verifyRowIndex( row_index ) ) {
		return 1;
	} else {
		for( vector < int >::iterator it = matrixData[ row_index - 1 ].begin() ; it < matrixData[ row_index - 1 ].end() ; it++ , data_ptr++ ) {
			* it = * data_ptr;
		}
		return 0;
	}
	printf ( "Cannot fill: Unexpected error, while filling Row\n" );
	return 1;
}

bool Matrix::fillRowWithData( vector < int > * data_ptr , unsigned int row_index ) {
	if( this->verifyRowIndex( row_index ) ) {
		return 1;
	} else {
		//TODO matrixData[ row_index - 1 ].size() always 1 when using default constructor
		if( data_ptr->size() !=  matrixData[ row_index - 1 ].size() ) {
			printf ( "Cannot fill: Size of data vector doesn't match the Matrix! data size %d, Matrix row size %d\n" , data_ptr->size() , matrixData[ row_index - 1 ].size() );
			return 1;
		} else {
			matrixData[ row_index - 1 ] = * data_ptr;
			for( vector < int >::iterator it = matrixData[ row_index - 1 ].begin() ; it < matrixData[ row_index - 1 ].end() ; it++ ) {
			}
			return 0;
		}
	}
	printf ( "Cannot fill: Unexpected error, while filling Row\n" );
	return 1;
}

unsigned int Matrix::getRowsNo() const {
	if( matrixData.empty() ) return 0;
	return matrixData.size();
}

const vector< int > * Matrix::getRow( unsigned int index ) const {
	if( this->verifyRowIndex( index ) ) {
		printf( "ERROR: Cannot getRow - index of of range\n" );
		return & matrixData[ 0 ];
	} else {
		return & matrixData[ index - 1 ];
	}
	return & matrixData[ 0 ];
}

bool Matrix::addColumn( unsigned int no_of_elements ) {
	if( matrixData.empty() ) {
		matrixData.resize( no_of_elements );
		for( vector < vector < int > >::iterator it = matrixData.begin() ; it != matrixData.end() ; ++it ) {
			it->resize( 1 , 0 );
		}
		return 0;
	} else {
		if( matrixData.size() == no_of_elements ) {
			this->addColumn();
			return 0;
		} else {
			printf ( "Cannot add: Size of elements doesn't fit to matrix, matrix column size: %d, provided %d\n" , matrixData.size() , no_of_elements );
			return 1;
		}
	}
	printf ( "Cannot add: Unexpected error, no_of_elements %d\n" , no_of_elements );
	return 1;
}

bool Matrix::addColumn() {
	if( matrixData.empty() ) {
		printf ( "Cannot add: Matrix desn't have any columns\n" );
		return 1;
	} else {
		vector < vector < int > >::iterator it = matrixData.begin();
		unsigned int y_size = it->size();
		for( ; it != matrixData.end() ; ++it ) {
			it->resize( y_size + 1 , 0 );
		}
		return 0;
	}
	printf ( "Cannot add: Unexpected error, while adding column\n" );
	return 1;
}

bool Matrix::addColumnWithData( vector < int > * data_ptr ) {
	if( ! ( this->addColumn() ) ) {
		return this->fillRowWithData( data_ptr , matrixData.begin()->size() - 1 );
	} else {
		return 1;
	}
	printf ( "Cannot fill: Unexpected error, while adding and filling Column\n" );
	return 1;
}

bool Matrix::fillColumnWithData( int * data_ptr , unsigned int column_index ) {
	if( this->verifyColumnIndex( column_index ) ) {
		return 1;
	} else {
		for( vector < vector < int > >::iterator it = matrixData.begin() ; it < matrixData.end() ; it++ , data_ptr++ ) {
			it->at( column_index - 1 ) = * data_ptr;
		}
		return 0;
	}
	printf ( "Cannot fill: Unexpected error, while filling Column\n" );
	return 1;
}

bool Matrix::fillColumnWithData( vector < int > * data_ptr , unsigned int column_index ) {
	if( this->verifyColumnIndex( column_index ) ) {
		return 1;
	} else {
		if( data_ptr->size() !=  matrixData.size() ) {
			printf ( "Cannot fill: Size of data vector doesn't match the Matrix!\n" );
			return 1;
		} else {
			vector < vector < int > >::iterator it = matrixData.begin();
			for( vector < int >::iterator it_data = data_ptr->begin() ;  it != matrixData.end() ; it++ , it_data++ ) {
				it->at( column_index - 1 ) = * it_data;
			}
			return 0;
		}
	}
	printf ( "Cannot fill: Unexpected error, while filling Column\n" );
	return 1;
}

unsigned int Matrix::getColumnNo() const {
	if( matrixData.empty() ) return 0;
	return matrixData.begin()->size();
}

bool Matrix::getColumn( vector< const int * > * column_vector , unsigned int index ) const {
	if( this->verifyColumnIndex( index ) ) {
		printf( "ERROR: Cannot getColumn - index of of range\n" );
		return 1;
	} else {
		for( unsigned int i = 0 ; i < matrixData.size() ; i++ ) {
			column_vector->push_back( & matrixData[ i ].at( index - 1 ) );
		}
		return 0;
	}
	return 1;
}

//-------------DEBUG------------//
unsigned int Matrix::verifyMatrixDimensionY() {
	// After all this not needed
	if( matrixData.empty() ) return 0;
	return matrixData.size();
}

unsigned int Matrix::verifyMatrixDimensionX() {
	// After all this not needed
	if( matrixData.empty() ) {
		printf ( "Verification failed: Vector is empty\n" );
		return 0;
	} else if( matrixData.size() == 1 ) {
		return matrixData.begin()->size();
	} else {
		vector < vector < int > >::iterator it = matrixData.begin();
		vector < vector < int > >::iterator it_end = matrixData.end(); 	// need it for subtract 1
		while( it != it_end - 1 ) {
			if( it->size() != ( ++it )->size() ) {
				printf ( "Verification failed: amount of columns are different: %d, %d\n" , ( it - 1 )->size() , it->size() );
			}
		}
		return matrixData.begin()->size();
	}
}
//-----------EO DEBUG-----------//

void Matrix::printMatrix() {
	printf( "\n" );
	for( unsigned i = 0 ; i < matrixData.size() ; i++ ) {
		printf( "|" );
		for( vector < int >::iterator it = matrixData[ i ].begin() ; it != matrixData[ i ].end() ; ++it ) {
			printf( "%5d " , * it );
		}
		printf( "|\n" );
	}
	printf( "\n" );
}

Matrix & Matrix::operator =( const Matrix & argument ) {

}

Matrix & Matrix::operator *( const Matrix & argument ) {
	Matrix * result;
	if( this->getColumnNo() == argument.getRowsNo() ) {
		result = & ( MatrixOperations::multiplication( * this , argument ) );
	} else {
		printf( "ERROR: Cannot multiple - size of Matrix doesn't match!\n" );
		result = new Matrix();
	}
	return * result;
}

Matrix & Matrix::operator +( const Matrix & argument ) {
	Matrix * result;
	if( this->getColumnNo() == argument.getColumnNo() && this->getRowsNo() == argument.getRowsNo() ) {
		result = & ( MatrixOperations::addition( * this , argument ) );
	} else {
		printf( "ERROR: Cannot add - size of Matrix doesn't match!\n" );
		result = new Matrix();
	}
	return * result;
}
