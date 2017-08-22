/*
 * MatrixTest.cpp
 *
 *  Created on: 18 aug. 2017
 *      Author: mateusz.fraszczynski
 */

#include "../include/MatrixTest.h"
#include <stdio.h>

MatrixTest::MatrixTest() : data_ptr( testData ) {
	TestInit();
	TestSuiteCreate();
	TestSuiteAdd();
	TestSuiteFill();
	TestSuiteOperations( );
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
	AddRowWithDataToEmptyMatrix(  );
	AddRowWithDataTo1on1Matrix(  );
	AddRowWithDataTo3on3Matrix(  );
	AddColumnWithDataToEmptyMatrix(  );
	AddColumnWithDataTo1on1Matrix(  );
	AddColumnWithDataTo3on3Matrix(  );
}

void MatrixTest::TestSuiteOperations( void ) {
	printf ( "########## TEST SUITE : Operations ##########\n");
	SumTwo1on1Matrix( );
	SumTwo3on3Matrix( );
	SumTwo3on5Matrix( );
	SumThree3on3Matrix( );
	SubtractTwo1on1Matrix( );
	SubtractTwo3on3Matrix( );
	SubtractTwo3on5Matrix( );
	SubtractThree3on3Matrix( );
	MultipliTwo1on1Matrix( );
	MultipliTwo3on3Matrix( );
	Multipli3on5MatrixWith5on3Matrix( );
	MultipliThree3on3Matrix( );
	Multipli1on1MatrixbyScalarAndOverwriteMatrix( );
	Multipli3on3MatrixbyScalarAndOverwriteMatrix( );
	Multipli3on5MatrixbyScalarAndOverwriteMatrix( );
	Multipli1on1MatrixbyScalarIntoNewMatrix( );
	Multipli3on3MatrixbyScalarIntoNewMatrix( );
	Multipli3on3MatrixbyScalarIntoEmptyMatrix( );
	Multipli3on5MatrixbyScalarIntoNewMatrix( );
	Assign1on1MatrixToEmptyMatrix( );
	Assign3on3MatrixToEmptyMatrix( );
	Assign3on3MatrixTo1on1Matrix( );
	Assign3on5MatrixTo3on3Matrix( );
	Transpose1on1MatrixAndOverwriteMatrix( );
	Transpose3on3MatrixAndOverwriteMatrix( );
	Transpose3on5MatrixAndOverwriteMatrix( );
	Transpose1on1MatrixIntoNewMatrix( );
	Transpose3on3MatrixIntoNewMatrix( );
	Transpose3on3MatrixIntoEmptyMatrix( );
	Transpose3on5MatrixIntoNewMatrix( );
	Invert1on1MatrixAndOverwriteMatrix( );
	Invert3on3MatrixAndOverwriteMatrix( );
	Invert3on5MatrixAndOverwriteMatrix( );
	Invert1on1MatrixIntoNewMatrix( );
	Invert3on3MatrixIntoNewMatrix( );
	Invert3on5MatrixIntoNewMatrix( );
}

void MatrixTest::CreateEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: CreateEmptyMatrix " );
	Eva.printMatrix();
}

void MatrixTest::Create1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: Create1on1Matrix " );
	Eva.printMatrix();
}

void MatrixTest::Create3on3Matrix( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: Create3on3Matrix " );
	Eva.printMatrix();
}

void MatrixTest::Create3on5Matrix( void ) {
	Matrix Eva( 3 , 5 );
	printf ( " TEST: Create3on5Matrix " );
	Eva.printMatrix();
}

void MatrixTest::Create5on3Matrix( void ) {
	Matrix Eva( 5 , 3 );
	printf ( " TEST: Create5on3Matrix " );
	Eva.printMatrix();
}

void MatrixTest::AddRowToEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: AddRowToEmptyMatrix " );
	Eva.addRow();
	Eva.printMatrix();
}

void MatrixTest::AddRowTo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: AddRowTo1on1Matrix " );
	Eva.addRow();
	Eva.printMatrix();
}

void MatrixTest::AddRowTo3on3Matrix( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: AddRowTo3on3Matrix " );
	Eva.addRow();
	Eva.printMatrix();
}

void MatrixTest::AddRowTo3on5Matrix( void ) {
	Matrix Eva( 3 , 5 );
	printf ( " TEST: AddRowTo3on5Matrix " );
	Eva.addRow();
	Eva.printMatrix();
}

void MatrixTest::AddColumnToEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: AddColumnToEmptyMatrix " );
	Eva.addColumn();
	Eva.printMatrix();
}

void MatrixTest::AddColumnTo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: AddColumnTo1on1Matrix " );
	Eva.addColumn();
	Eva.printMatrix();
}

void MatrixTest::AddColumnTo3on3Matrix( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: AddColumnTo3on3Matrix " );
	Eva.addColumn();
	Eva.printMatrix();
}

void MatrixTest::AddColumnTo3on5Matrix( void ) {
	Matrix Eva( 3 , 5 );
	printf ( " TEST: AddColumnTo3on5Matrix " );
	Eva.addColumn();
	Eva.printMatrix();
}

void MatrixTest::Add2RowsToEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: Add2RowsToEmptyMatrix " );
	Eva.addRow();
	Eva.addRow();
	Eva.printMatrix();
}

void MatrixTest::Add2RowsTo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: Add2RowsTo1on1Matrix " );
	Eva.addRow();
	Eva.addRow();
	Eva.printMatrix();
}

void MatrixTest::Add2ColumnsToEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: Add2ColumnsToEmptyMatrix " );
	Eva.addColumn();
	Eva.addColumn();
	Eva.printMatrix();
}
void MatrixTest::Add2ColumnsTo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: Add2ColumnsTo1on1Matrix " );
	Eva.addColumn();
	Eva.addColumn();
	Eva.printMatrix();
}

void MatrixTest::AddRowThenColumnToEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: AddRowThenColumnToEmptyMatrix " );
	Eva.addRow();
	Eva.addColumn();
	Eva.printMatrix();
}

void MatrixTest::AddRowThenColumnTo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: AddRowThenColumnTo1on1Matrix " );
	Eva.addRow();
	Eva.addColumn();
	Eva.printMatrix();
}

void MatrixTest::AddColumnThenRowToEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: AddColumnThenRowToEmptyMatrix " );
	Eva.addColumn();
	Eva.addRow();
	Eva.printMatrix();
}

void MatrixTest::AddColumnThenRowTo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: AddColumnThenRowTo1on1Matrix " );
	Eva.addColumn();
	Eva.addRow();
	Eva.printMatrix();
}

void MatrixTest::FillMatrix1on1RowWithDataUsingPointer( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: FillMatrix1on1RowWithDataUsingPointer " );
	Eva.fillRowWithData( data_ptr , 0 );
	Eva.printMatrix();
}

void MatrixTest::FillMatrix3on3RowWithDataUsingPointer( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: FillMatrix3on3RowWithDataUsingPointer " );
	Eva.fillRowWithData( data_ptr , 0 );
	Eva.fillRowWithData( data_ptr + 3 , 1 );
	Eva.fillRowWithData( data_ptr + 6 , 2 );
	Eva.printMatrix();
}

void MatrixTest::FillMatrix1on1ColumnWithDataUsingPointer( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: FillMatrix1on1ColumnWithDataUsingPointer " );
	Eva.fillColumnWithData( data_ptr , 0 );
	Eva.printMatrix();
}

void MatrixTest::FillMatrix3on3ColumnWithDataUsingPointer( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: FillMatrix3on3ColumnWithDataUsingPointer " );
	Eva.fillColumnWithData( data_ptr , 0 );
	Eva.fillColumnWithData( data_ptr + 3 , 1 );
	Eva.fillColumnWithData( data_ptr + 6 , 2 );
	Eva.printMatrix();
}

void MatrixTest::FillMatrix1on1RowWithDataUsingVector( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: FillMatrix1on1RowWithDataUsingVector " );
	data_vector_ptr = new std::vector < int >;
	for( unsigned int i = 0 ; i < 1 ; i++ ) data_vector_ptr->push_back( testData[ i ] );
	Eva.fillRowWithData( data_vector_ptr , 0 );
	delete data_vector_ptr;
	Eva.printMatrix();
}

void MatrixTest::FillMatrix3on3RowWithDataUsingVector( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: FillMatrix3on3RowWithDataUsingVector " );
	data_vector_ptr = new std::vector < int >;
	for( unsigned int i = 1 ; i < 10 ; i++ )  {
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
	printf ( " TEST: FillMatrix1on1ColumnWithDataUsingVector " );
	data_vector_ptr = new std::vector < int >;
	for( unsigned int i = 0 ; i < 1 ; i++ ) data_vector_ptr->push_back( testData[ i ] );
	Eva.fillColumnWithData( data_vector_ptr , 0 );
	delete data_vector_ptr;
	Eva.printMatrix();
}

void MatrixTest::FillMatrix3on3ColumnWithDataUsingVector( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: FillMatrix3on3ColumnWithDataUsingVector " );
	data_vector_ptr = new std::vector < int >;
	for( unsigned int i = 1 ; i < 10 ; i++ )  {
			data_vector_ptr->push_back( testData[ i - 1 ] );
			if ( ! ( i % 3 ) ) {
				Eva.fillColumnWithData( data_vector_ptr , ( i / 3 ) - 1 );
				data_vector_ptr->clear();
			}
		}
	delete data_vector_ptr;
	Eva.printMatrix();
}

void MatrixTest::AddRowWithDataToEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: AddRowWithDataToEmptyMatrix " );
	data_vector_ptr = new std::vector < int >;
	for( unsigned int i = 0 ; i < 1 ; i++ )  data_vector_ptr->push_back( testData[ i ] );
	Eva.addRowWithData( data_vector_ptr );
	delete data_vector_ptr;
	Eva.printMatrix();
}

void MatrixTest::AddRowWithDataTo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: AddRowWithDataTo1on1Matrix " );
	data_vector_ptr = new std::vector < int >;
	for( unsigned int i = 0 ; i < 1 ; i++ )  data_vector_ptr->push_back( testData[ i ] );
	Eva.addRowWithData( data_vector_ptr );
	delete data_vector_ptr;
	Eva.printMatrix();
}

void MatrixTest::AddRowWithDataTo3on3Matrix( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: AddRowWithDataTo3on3Matrix " );
	data_vector_ptr = new std::vector < int >;
	for( unsigned int i = 0 ; i < 3 ; i++ )  data_vector_ptr->push_back( testData[ i ] );
	Eva.addRowWithData( data_vector_ptr );
	delete data_vector_ptr;
	Eva.printMatrix();
}

void MatrixTest::AddColumnWithDataToEmptyMatrix( void ) {
	Matrix Eva;
	printf ( " TEST: AddColumnWithDataToEmptyMatrix " );
	data_vector_ptr = new std::vector < int >;
	for( unsigned int i = 0 ; i < 1 ; i++ )  data_vector_ptr->push_back( testData[ i ] );
	Eva.addColumnWithData( data_vector_ptr );
	delete data_vector_ptr;
	Eva.printMatrix();
}

void MatrixTest::AddColumnWithDataTo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: AddColumnWithDataTo1on1Matrix " );
	data_vector_ptr = new std::vector < int >;
	for( unsigned int i = 0 ; i < 1 ; i++ )  data_vector_ptr->push_back( testData[ i ] );
	Eva.addColumnWithData( data_vector_ptr );
	delete data_vector_ptr;
	Eva.printMatrix();
}

void MatrixTest::AddColumnWithDataTo3on3Matrix( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: AddColumnWithDataTo3on3Matrix " );
	data_vector_ptr = new std::vector < int >;
	for( unsigned int i = 0 ; i < 3 ; i++ )  data_vector_ptr->push_back( testData[ i ] );
	Eva.addColumnWithData( data_vector_ptr );
	delete data_vector_ptr;
	Eva.printMatrix();
}

void MatrixTest::SumTwo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	Matrix Adam( 1 , 1 );
	printf ( " TEST: SumTwo1on1Matrix " );
	Fill1on1Matrix( Eva );
	Fill1on1Matrix( Adam );
	std::shared_ptr< Matrix > Matrix_ptr = Eva + Adam;
	Matrix_ptr->printMatrix();
}

void MatrixTest::SumTwo3on3Matrix( void ) {
	Matrix Eva( 3 , 3 );
	Matrix Adam( 3 , 3 );
	printf ( " TEST: SumTwo3on3Matrix " );
	Fill3on3Matrix( Eva );
	Fill3on3Matrix( Adam );
	std::shared_ptr< Matrix > Matrix_ptr = Eva + Adam;
	Matrix_ptr->printMatrix();
}

void MatrixTest::SumTwo3on5Matrix( void ) {
	Matrix Eva( 3 , 5 );
	Matrix Adam( 3 , 5 );
	printf ( " TEST: SumTwo3on5Matrix " );
	Fill3on5Matrix( Eva );
	Fill3on5Matrix( Adam );
	std::shared_ptr< Matrix > Matrix_ptr = Eva + Adam;
	Matrix_ptr->printMatrix();
}

void MatrixTest::SumThree3on3Matrix( void ) {
	Matrix Eva( 3 , 3 );
	Matrix Adam( 3 , 3 );
	Matrix Abel( 3 , 3 );
	printf ( " TEST: SumThree3on3Matrix " );
	Fill3on3Matrix( Eva );
	Fill3on3Matrix( Adam );
	Fill3on3Matrix( Abel );
	//TODO Implementation of triple +
	//std::shared_ptr< Matrix > Matrix_ptr = Eva + Adam + Abel;
	//Matrix_ptr->printMatrix();
	printf ( "\nFAILED\n" );
}

void MatrixTest::SubtractTwo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	Matrix Adam( 1 , 1 );
	printf ( " TEST: SubtractTwo1on1Matrix " );
	Fill1on1Matrix( Eva );
	Fill1on1Matrix( Adam );
	std::shared_ptr< Matrix > Matrix_ptr = Eva - Adam;
	Matrix_ptr->printMatrix();
}

void MatrixTest::SubtractTwo3on3Matrix( void ) {
	Matrix Eva( 3 , 3 );
	Matrix Adam( 3 , 3 );
	printf ( " TEST: SubtractTwo3on3Matrix " );
	Fill3on3Matrix( Eva );
	Fill3on3Matrix( Adam );
	std::shared_ptr< Matrix > Matrix_ptr = Eva - Adam;
	Matrix_ptr->printMatrix();
}

void MatrixTest::SubtractTwo3on5Matrix( void ) {
	Matrix Eva( 3 , 5 );
	Matrix Adam( 3 , 5 );
	printf ( " TEST: SubtractTwo3on5Matrix " );
	Fill3on5Matrix( Eva );
	Fill3on5Matrix( Adam );
	std::shared_ptr< Matrix > Matrix_ptr = Eva - Adam;
	Matrix_ptr->printMatrix();
}

void MatrixTest::SubtractThree3on3Matrix( void ) {
	Matrix Eva( 3 , 3 );
	Matrix Adam( 3 , 3 );
	Matrix Abel( 3 , 3 );
	printf ( " TEST: SubtractThree3on3Matrix " );
	Fill3on3Matrix( Eva );
	Fill3on3Matrix( Adam );
	Fill3on3Matrix( Abel );
	//TODO Implementation of triple -
	//std::shared_ptr< Matrix > Matrix_ptr = Eva - Adam - Abel;
	//Matrix_ptr->printMatrix();
	printf ( "\nFAILED\n" );
}

void MatrixTest::MultipliTwo1on1Matrix( void ) {
	Matrix Eva( 1 , 1 );
	Matrix Adam( 1 , 1 );
	printf ( " TEST: MultipliTwo1on1Matrix " );
	Fill1on1Matrix( Eva );
	Fill1on1Matrix( Adam );
	std::shared_ptr< Matrix > Matrix_ptr = Eva * Adam;
	Matrix_ptr->printMatrix();
}

void MatrixTest::MultipliTwo3on3Matrix( void ) {
	Matrix Eva( 3 , 3 );
	Matrix Adam( 3 , 3 );
	printf ( " TEST: MultipliTwo3on3Matrix " );
	Fill3on3Matrix( Eva );
	Fill3on3Matrix( Adam );
	std::shared_ptr< Matrix > Matrix_ptr = Eva * Adam;
	Matrix_ptr->printMatrix();
}

void MatrixTest::Multipli3on5MatrixWith5on3Matrix( void ) {
	Matrix Eva( 3 , 5 );
	Matrix Adam( 5 , 3 );
	printf ( " TEST: Multipli3on5MatrixWith5on3Matrix " );
	Fill3on5Matrix( Eva );
	Fill5on3Matrix( Adam );
	std::shared_ptr< Matrix > Matrix_ptr = Eva * Adam;
	Matrix_ptr->printMatrix();
}

void MatrixTest::MultipliThree3on3Matrix( void ) {
	Matrix Eva( 3 , 3 );
	Matrix Adam( 3 , 3 );
	Matrix Abel( 3 , 3 );
	printf ( " TEST: MultipliThree3on3Matrix " );
	Fill3on3Matrix( Eva );
	Fill3on3Matrix( Adam );
	Fill3on3Matrix( Abel );
	//TODO Implementation of triple *
	//std::shared_ptr< Matrix > Matrix_ptr = Eva * Adam * Abel;
	//Matrix_ptr->printMatrix();
	printf ( "\nFAILED\n" );
}

void MatrixTest::Multipli1on1MatrixbyScalarAndOverwriteMatrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: Multipli1on1MatrixbyScalarAndOverwriteMatrix " );
	Fill1on1Matrix( Eva );
	Eva *= scalar;
	Eva.printMatrix();
}

void MatrixTest::Multipli3on3MatrixbyScalarAndOverwriteMatrix( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: Multipli3on3MatrixbyScalarAndOverwriteMatrix " );
	Fill3on3Matrix( Eva );
	Eva *= scalar;
	Eva.printMatrix();
}

void MatrixTest::Multipli3on5MatrixbyScalarAndOverwriteMatrix( void ) {
	Matrix Eva( 3 , 5 );
	printf ( " TEST: Multipli3on5MatrixbyScalarAndOverwriteMatrix " );
	Fill3on5Matrix( Eva );
	Eva *= scalar;
	Eva.printMatrix();
}

void MatrixTest::Multipli1on1MatrixbyScalarIntoNewMatrix( void ) {
	Matrix Eva( 1 , 1 );
	Matrix Adam( 1 , 1 );
	printf ( " TEST: Multipli1on1MatrixbyScalarIntoNewMatrix " );
	Fill1on1Matrix( Eva );
	Adam = Eva * scalar;
	Adam.printMatrix();
}

void MatrixTest::Multipli3on3MatrixbyScalarIntoNewMatrix( void ) {
	Matrix Eva( 3 , 3 );
	Matrix Adam( 3 , 3 );
	printf ( " TEST: Multipli3on3MatrixbyScalarIntoNewMatrix " );
	Fill3on3Matrix( Eva );
	Adam = Eva * scalar;
	Adam.printMatrix();
}

void MatrixTest::Multipli3on3MatrixbyScalarIntoEmptyMatrix( void ) {
	Matrix Eva( 3 , 3 );
	Matrix Adam;
	printf ( " TEST: Multipli3on3MatrixbyScalarIntoEmptyMatrix " );
	Fill3on3Matrix( Eva );
	Adam = Eva * scalar;
	Adam.printMatrix();
}

void MatrixTest::Multipli3on5MatrixbyScalarIntoNewMatrix( void ) {
	Matrix Eva( 3 , 5 );
	Matrix Adam( 3 , 5 );
	printf ( " TEST: Multipli3on5MatrixbyScalarIntoNewMatrix " );
	Fill3on5Matrix( Eva );
	Adam = Eva * scalar;
	Adam.printMatrix();
}

void MatrixTest::Assign1on1MatrixToEmptyMatrix( void ) {
	Matrix Eva( 1 , 1 );
	Matrix Adam;
	printf ( " TEST: Assign1on1MatrixToEmptyMatrix " );
	Fill1on1Matrix( Eva );
	Adam = Eva;
	Adam.printMatrix();
}

void MatrixTest::Assign3on3MatrixToEmptyMatrix( void ) {
	Matrix Eva( 3 , 3 );
	Matrix Adam;
	printf ( " TEST: Assign3on3MatrixToEmptyMatrix " );
	Fill3on3Matrix( Eva );
	Adam = Eva;
	Adam.printMatrix();
}

void MatrixTest::Assign3on3MatrixTo1on1Matrix( void ) {
	Matrix Eva( 3 , 3 );
	Matrix Adam( 1 , 1 );
	printf ( " TEST: Assign3on3MatrixTo1on1Matrix " );
	Fill3on3Matrix( Eva );
	Adam = Eva;
	Adam.printMatrix();
}

void MatrixTest::Assign3on5MatrixTo3on3Matrix( void ) {
	Matrix Eva( 3 , 5 );
	Matrix Adam( 3 , 3 );
	printf ( " TEST: Assign3on5MatrixTo3on3Matrix " );
	Fill3on5Matrix( Eva );
	Adam = Eva;
	Adam.printMatrix();
}

void MatrixTest::Transpose1on1MatrixAndOverwriteMatrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: Transpose1on1MatrixAndOverwriteMatrix " );
	Fill1on1Matrix( Eva );
	Eva.transIntra();
	Eva.printMatrix();
}

void MatrixTest::Transpose3on3MatrixAndOverwriteMatrix( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: Transpose3on3MatrixAndOverwriteMatrix " );
	Fill3on3Matrix( Eva );
	Eva.transIntra();
	Eva.printMatrix();
}

void MatrixTest::Transpose3on5MatrixAndOverwriteMatrix( void ) {
	Matrix Eva( 3 , 5 );
	printf ( " TEST: Transpose3on5MatrixAndOverwriteMatrix " );
	Fill3on5Matrix( Eva );
	Eva.transIntra();
	Eva.printMatrix();
}

void MatrixTest::Transpose1on1MatrixIntoNewMatrix( void ) {
	Matrix Eva( 1 , 1 );
	Matrix Adam( 1 , 1 );
	printf ( " TEST: Transpose1on1MatrixIntoNewMatrix " );
	Fill1on1Matrix( Eva );
	Fill1on1Matrix( Adam );
	Adam = Eva.transInter();
	Adam.printMatrix();
}

void MatrixTest::Transpose3on3MatrixIntoNewMatrix( void ) {
	Matrix Eva( 3 , 3 );
	Matrix Adam( 3 , 3 );
	printf ( " TEST: Transpose3on3MatrixIntoNewMatrix " );
	Fill3on3Matrix( Eva );
	Fill3on3Matrix( Adam );
	Adam = Eva.transInter();
	Adam.printMatrix();
}

void MatrixTest::Transpose3on3MatrixIntoEmptyMatrix( void ) {
	Matrix Eva( 3 , 3 );
	Matrix Adam;
	printf ( " TEST: Transpose3on3MatrixIntoEmptyMatrix " );
	Fill3on3Matrix( Eva );
	Adam = Eva.transInter();
	Adam.printMatrix();
}

void MatrixTest::Transpose3on5MatrixIntoNewMatrix( void ) {
	Matrix Eva( 3 , 5 );
	Matrix Adam( 3 , 5 );
	printf ( " TEST: Transpose3on5MatrixIntoNewMatrix " );
	Fill3on5Matrix( Eva );
	Fill3on5Matrix( Adam );
	Adam = Eva.transInter();
	Adam.printMatrix();
}

void MatrixTest::Invert1on1MatrixAndOverwriteMatrix( void ) {
	Matrix Eva( 1 , 1 );
	printf ( " TEST: Invert1on1MatrixAndOverwriteMatrix " );
}

void MatrixTest::Invert3on3MatrixAndOverwriteMatrix( void ) {
	Matrix Eva( 3 , 3 );
	printf ( " TEST: Invert3on3MatrixAndOverwriteMatrix " );
}

void MatrixTest::Invert3on5MatrixAndOverwriteMatrix( void ) {
	Matrix Eva( 3 , 5 );
	printf ( " TEST: Invert3on5MatrixAndOverwriteMatrix " );
}

void MatrixTest::Invert1on1MatrixIntoNewMatrix( void ) {
	Matrix Eva( 1 , 1 );
	Matrix Adam( 1 , 1 );
	printf ( " TEST: Invert1on1MatrixIntoNewMatrix " );
}

void MatrixTest::Invert3on3MatrixIntoNewMatrix( void ) {
	Matrix Eva( 3 , 3 );
	Matrix Adam( 3 , 3 );
	printf ( " TEST: Invert3on3MatrixIntoNewMatrix " );
}

void MatrixTest::Invert3on5MatrixIntoNewMatrix( void ) {
	Matrix Eva( 3 , 5 );
	Matrix Adam( 3 , 5 );
	printf ( " TEST: Invert3on5MatrixIntoNewMatrix " );
}

//########## HELPER FUNCTION ###########//

void MatrixTest::Fill1on1Matrix( Matrix & matrix ) {
	matrix.fillRowWithData( data_ptr , 0 );
}

void MatrixTest::Fill3on3Matrix( Matrix & matrix ) {
	matrix.fillRowWithData( data_ptr , 0 );
	matrix.fillRowWithData( data_ptr + 3 , 1 );
	matrix.fillRowWithData( data_ptr + 6 , 2 );
}

void MatrixTest::Fill3on5Matrix( Matrix & matrix ) {
	matrix.fillRowWithData( data_ptr , 0 );
	matrix.fillRowWithData( data_ptr + 5 , 1 );
	matrix.fillRowWithData( data_ptr + 10 , 2 );
}

void MatrixTest::Fill5on3Matrix( Matrix & matrix ) {
	matrix.fillRowWithData( data_ptr , 0 );
	matrix.fillRowWithData( data_ptr + 3 , 1 );
	matrix.fillRowWithData( data_ptr + 6 , 2 );
	matrix.fillRowWithData( data_ptr + 9 , 3 );
	matrix.fillRowWithData( data_ptr + 12 , 4 );
}
