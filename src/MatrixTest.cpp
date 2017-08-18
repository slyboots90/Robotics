/*
 * MatrixTest.cpp
 *
 *  Created on: 18 aug. 2017
 *      Author: mateusz.fraszczynski
 */

#include "../include/MatrixTest.h"
#include "../include/Matrix.h"
#include <stdio.h>

MatrixTest::MatrixTest() {
	CreateEmptyMatrix( );
	Create1on1Matrix( );
	Create3on3Matrix( );
	Create3on5Matrix( );
	Create5on3Matrix( );
	AddRowToEmptyMatrix( );
	AddRowTo1on1Matrix( );
	AddRowTo3on3Matrix( );
	AddRowTo3on5Matrix( );
	AddColumnToEmptyMatrix( );
	AddColumnTo1on1Matrix( );
	AddColumnTo3on3Matrix( );
	AddColumnTo3on5Matrix( );
	Add2RowsToEmptyMatrix( );
	Add2RowsTo1on1Matrix( );
	Add2ColumnsToEmptyMatrix( );
	Add2ColumnsTo1on1Matrix( );
	AddRowThenColumnToEmptyMatrix( );
	AddRowThenColumnTo1on1Matrix( );
	AddColumnThenRowToEmptyMatrix( );
	AddColumnThenRowTo1on1Matrix( );

}

MatrixTest::~MatrixTest() {
	// TODO Auto-generated destructor stub
}

void MatrixTest::CreateEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: CreateEmptyMatrix ");
	Eva.printMatrix();
}

void MatrixTest::Create1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: Create1on1Matrix ");
	Eva.printMatrix();
}

void MatrixTest::Create3on3Matrix( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: Create3on3Matrix ");
	Eva.printMatrix();
}

void MatrixTest::Create3on5Matrix( void ) {
	Matrix Eva( 3 , 5 );
	printf ( " TEST: Create3on5Matrix ");
	Eva.printMatrix();
}

void MatrixTest::Create5on3Matrix( void ) {
	Matrix Eva( 5 , 3 );
	printf ( " TEST: Create5on3Matrix ");
	Eva.printMatrix();
}

void MatrixTest::AddRowToEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: AddRowToEmptyMatrix ");
	Eva.addRow();
	Eva.printMatrix();
}

void MatrixTest::AddRowTo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: AddRowTo1on1Matrix ");
	Eva.addRow();
	Eva.printMatrix();
}

void MatrixTest::AddRowTo3on3Matrix( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: AddRowTo3on3Matrix ");
	Eva.addRow();
	Eva.printMatrix();
}

void MatrixTest::AddRowTo3on5Matrix( void ) {
	Matrix Eva( 3 , 5 );
	printf ( " TEST: AddRowTo3on5Matrix ");
	Eva.addRow();
	Eva.printMatrix();
}

void MatrixTest::AddColumnToEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: AddColumnToEmptyMatrix ");
	Eva.addColumn();
	Eva.printMatrix();
}

void MatrixTest::AddColumnTo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: AddColumnTo1on1Matrix ");
	Eva.addColumn();
	Eva.printMatrix();
}

void MatrixTest::AddColumnTo3on3Matrix( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: AddColumnTo3on3Matrix ");
	Eva.addColumn();
	Eva.printMatrix();
}

void MatrixTest::AddColumnTo3on5Matrix( void ) {
	Matrix Eva( 3 , 5 );
	printf ( " TEST: AddColumnTo3on5Matrix ");
	Eva.addColumn();
	Eva.printMatrix();
}

void MatrixTest::Add2RowsToEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: Add2RowsToEmptyMatrix ");
	Eva.addRow();
	Eva.addRow();
	Eva.printMatrix();
}

void MatrixTest::Add2RowsTo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: Add2RowsTo1on1Matrix ");
	Eva.addRow();
	Eva.addRow();
	Eva.printMatrix();
}

void MatrixTest::Add2ColumnsToEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: Add2ColumnsToEmptyMatrix ");
	Eva.addColumn();
	Eva.addColumn();
	Eva.printMatrix();
}
void MatrixTest::Add2ColumnsTo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: Add2ColumnsTo1on1Matrix ");
	Eva.addColumn();
	Eva.addColumn();
	Eva.printMatrix();
}

void MatrixTest::AddRowThenColumnToEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: AddRowThenColumnToEmptyMatrix ");
	Eva.addRow();
	Eva.addColumn();
	Eva.printMatrix();
}

void MatrixTest::AddRowThenColumnTo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: AddRowThenColumnTo1on1Matrix ");
	Eva.addRow();
	Eva.addColumn();
	Eva.printMatrix();
}

void MatrixTest::AddColumnThenRowToEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: AddColumnThenRowToEmptyMatrix ");
	Eva.addColumn();
	Eva.addRow();
	Eva.printMatrix();
}

void MatrixTest::AddColumnThenRowTo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: AddColumnThenRowTo1on1Matrix ");
	Eva.addColumn();
	Eva.addRow();
	Eva.printMatrix();
}
