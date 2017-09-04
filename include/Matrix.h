/*
 * Matrix.h
 *
 *  Created on: 24 juli 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include <memory>							// shared_ptr
#include "../include/Timer.h"

using namespace std;

class Matrix {

	friend class MatrixOperations;
	shared_ptr < vector < vector < double > > > matrixDataPtr;

	Matrix( const Matrix & base_M );

	bool isEmpty( void ) const;
	bool isEqualSize( const Matrix & ) const;
	bool isColumnsNoEqualRowsNo( const Matrix & ) const;
	bool isSquareSize( void ) const;
	void allocateMatrixVectors( unsigned int , unsigned int );
	void allocateVectorInVector( void );
	bool verifyRowIndex( unsigned int ) const;
	bool verifyColumnIndex( unsigned int ) const;
	const vector < double > * getRow( unsigned int ) const;
	bool getColumn( vector < const double * > * , unsigned int ) const;

public:
	Matrix();
	Matrix( unsigned int , unsigned int );
	virtual ~Matrix();

	void printMatrix( void ) const;
	// Rows
	void addRow( void );
	bool addRowWithData( vector < double > * );
	bool fillRowWithData( double * , unsigned int );
	bool fillRowWithData( vector < double > * , unsigned int );
	void eraseRow( unsigned int );
	unsigned int getRowsNo( void ) const;
	// Columns
	void addColumn( void );
	bool addColumnWithData( vector < double > * );
	bool fillColumnWithData( double * , unsigned int );
	bool fillColumnWithData( vector < double > * , unsigned int );
	void eraseColumn( unsigned int );
	unsigned int getColumnsNo( void ) const;
	// Operators
	void operator =( shared_ptr < Matrix > );
	shared_ptr < Matrix > operator *( const Matrix & );
	shared_ptr < Matrix > operator *( shared_ptr < Matrix > );
	shared_ptr < Matrix > operator *( double );
	void operator *=( double );
	shared_ptr < Matrix > operator +( const Matrix & );
	shared_ptr < Matrix > operator -( const Matrix & );
	// Operations
	double det( void );
	unsigned int rank( void );
	void transIntra( void );
	shared_ptr < Matrix > transInter( void );

protected:
	void copyData( shared_ptr < Matrix > );

};

#endif /* MATRIX_H_ */
