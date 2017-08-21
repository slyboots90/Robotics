/*
 * MatrixTest.cpp
 *
 *  Created on: 18 aug. 2017
 *      Author: mateusz.fraszczynski
 */

#include "../include/MatrixTest.h"
#include "../include/Matrix.h"
#include <stdio.h>

MatrixTest::MatrixTest() : data_ptr( testData ) {
	TestInit();
	TestSuiteCreate();
	TestSuiteAdd();
	TestSuiteFill();
	TestTeardown();
}

MatrixTest::~MatrixTest() {
	// TODO Auto-generated destructor stub
}

void MatrixTest::TestInit( void ) {
	printf ( ":::::########## Matrix Test ##########:::::\n");
}

void MatrixTest::TestTeardown( void ) {
	printf ( ":::::########## End of Matrix Test ##########:::::\n");
}

void MatrixTest::TestSuiteCreate( void ) {
	printf ( "########## TEST SUITE : Create ##########\n");
	CreateEmptyMatrix( );
	Create1on1Matrix( );
	Create3on3Matrix( );
	Create3on5Matrix( );
	Create5on3Matrix( );
}

void MatrixTest::TestSuiteAdd( void ) {
	printf ( "########## TEST SUITE : Add ##########\n");
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

void MatrixTest::TestSuiteFill( void ) {
	printf ( "########## TEST SUITE : Fill ##########\n");
	FillMatrix1on1RowWithDataUsingPointer( );
	FillMatrix3on3RowWithDataUsingPointer( );
	FillMatrix1on1ColumnWithDataUsingPointer( );
	FillMatrix3on3ColumnWithDataUsingPointer( );
	FillMatrix1on1RowWithDataUsingVector( );
	FillMatrix3on3RowWithDataUsingVector( );
	FillMatrix1on1ColumnWithDataUsingVector( );
	FillMatrix3on3ColumnWithDataUsingVector( );
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

void MatrixTest::FillMatrix1on1RowWithDataUsingPointer( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: FillMatrix1on1RowWithDataUsingPointer ");
	Eva.fillRowWithData( data_ptr , 0 );
	Eva.printMatrix();
}

void MatrixTest::FillMatrix3on3RowWithDataUsingPointer( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: FillMatrix3on3RowWithDataUsingPointer ");
	Eva.fillRowWithData( data_ptr , 0 );
	Eva.fillRowWithData( data_ptr + 3 , 1 );
	Eva.fillRowWithData( data_ptr + 6 , 2 );
	Eva.printMatrix();
}

void MatrixTest::FillMatrix1on1ColumnWithDataUsingPointer( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: FillMatrix1on1ColumnWithDataUsingPointer ");
	Eva.fillColumnWithData( data_ptr , 0 );
	Eva.printMatrix();
}

void MatrixTest::FillMatrix3on3ColumnWithDataUsingPointer( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: FillMatrix3on3ColumnWithDataUsingPointer ");
	Eva.fillColumnWithData( data_ptr , 0 );
	Eva.fillColumnWithData( data_ptr + 3 , 1 );
	Eva.fillColumnWithData( data_ptr + 6 , 2 );
	Eva.printMatrix();
}

void MatrixTest::FillMatrix1on1RowWithDataUsingVector( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: FillMatrix1on1RowWithDataUsingVector ");
	data_vector_ptr = new std::vector < int >;
	for(unsigned int i = 0 ; i < 1 ; i++ ) data_vector_ptr->push_back( testData[ i ] );
	Eva.fillRowWithData( data_vector_ptr , 0 );
	delete data_vector_ptr;
	Eva.printMatrix();
}

void MatrixTest::FillMatrix3on3RowWithDataUsingVector( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: FillMatrix3on3RowWithDataUsingVector ");
	data_vector_ptr = new std::vector < int >;
	for(unsigned int i = 1 ; i < 10 ; i++ )  {
		data_vector_ptr->push_back( testData[ i - 1 ] );
		if ( ! ( i % 3 ) ) {
			Eva.fillRowWithData( data_vector_ptr , ( i / 3 ) - 1 );
			data_vector_ptr->clear();
		}
	}
	delete data_vector_ptr;
	Eva.printMatrix();
}

void MatrixTest::FillMatrix1on1ColumnWithDataUsingVector( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: FillMatrix1on1ColumnWithDataUsingVector ");
	data_vector_ptr = new std::vector < int >;
	for(unsigned int i = 0 ; i < 1 ; i++ ) data_vector_ptr->push_back( testData[ i ] );
	Eva.fillColumnWithData( data_vector_ptr , 0 );
	delete data_vector_ptr;
	Eva.printMatrix();
}

void MatrixTest::FillMatrix3on3ColumnWithDataUsingVector( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: FillMatrix3on3ColumnWithDataUsingVector ");
	data_vector_ptr = new std::vector < int >;
	for(unsigned int i = 1 ; i < 10 ; i++ )  {
			data_vector_ptr->push_back( testData[ i - 1 ] );
			if ( ! ( i % 3 ) ) {
				Eva.fillColumnWithData( data_vector_ptr , ( i / 3 ) - 1 );
				data_vector_ptr->clear();
			}
		}
	delete data_vector_ptr;
	Eva.printMatrix();
}

