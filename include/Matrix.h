/*
 * Matrix.h
 *
 *  Created on: 24 juli 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
using namespace std;

class Matrix {

	void allocateMatrixVectors( unsigned int , unsigned int );
	void allocateVectorInVector( unsigned int );
	bool verifyRowIndex( unsigned int ) const;
	bool verifyColumnIndex( unsigned int ) const ;
	vector < vector < int > > matrixData;

public:
	Matrix();
	Matrix( unsigned int , unsigned int );
	virtual ~Matrix();
	// Rows
	bool addRow( unsigned int );
	bool addRow( void );
	bool addRowWithData( vector < int > * );
	bool fillRowWithData( int * , unsigned int );
	bool fillRowWithData( vector < int > * , unsigned int );
	unsigned int getRowsNo( void ) const;
	const vector< int > * getRow( unsigned int ) const;
	// Columns
	bool addColumn( unsigned int );
	bool addColumn( void );
	bool addColumnWithData( vector < int > * );
	bool fillColumnWithData( int * , unsigned int );
	bool fillColumnWithData( vector < int > * , unsigned int );
	unsigned int getColumnNo( void ) const;
	bool getColumn( vector< const int * > * , unsigned int ) const;
	// Debug
	unsigned int verifyMatrixDimensionY( void );
	unsigned int verifyMatrixDimensionX( void );
	//end of debug
	void printMatrix( void );
	Matrix & operator =( const Matrix & argument );
	Matrix & operator *( const Matrix & argument );
	Matrix & operator +( const Matrix & argument );
};

#endif /* MATRIX_H_ */
