/*
 * MatrixTest.h
 *
 *  Created on: 18 aug. 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef MATRIXTEST_H_
#define MATRIXTEST_H_

#include <vector>
#include "../include/Matrix.h"

class MatrixTest {

	double testData[ 25 ] = { 5 , 7 , 12 , 44 , 77 , 22 , 142 , 537 , 873 , 17 , 56 , 2 , 9 , 0 , 11 , 41 , -5 , -1 , 0 , 31 , -67 , 4 , 9 , -6 , 18 };
	double * data_ptr;
	std::vector < double > * data_vector_ptr;
	double scalar = 2;
	void Fill1on1Matrix( Matrix & matrix );
	void Fill3on3Matrix( Matrix & matrix );
	void Fill5on5Matrix( Matrix & matrix );
	void Fill3on5Matrix( Matrix & matrix );
	void Fill5on3Matrix( Matrix & matrix );

	void TestInit( void );
	void TestTeardown( void );

	void TestSuiteCreate( void );
	void CreateEmptyMatrix( void );
	void Create1on1Matrix( void );
	void Create3on3Matrix( void );
	void Create3on5Matrix( void );
	void Create5on3Matrix( void );

	void TestSuiteAdd( void );
	void AddRowToEmptyMatrix( void );
	void AddRowTo1on1Matrix( void );
	void AddRowTo3on3Matrix( void );
	void AddRowTo3on5Matrix( void );
	void AddColumnToEmptyMatrix( void );
	void AddColumnTo1on1Matrix( void );
	void AddColumnTo3on3Matrix( void );
	void AddColumnTo3on5Matrix( void );
	void Add2RowsToEmptyMatrix( void );
	void Add2RowsTo1on1Matrix( void );
	void Add2ColumnsToEmptyMatrix( void );
	void Add2ColumnsTo1on1Matrix( void );
	void AddRowThenColumnToEmptyMatrix( void );
	void AddRowThenColumnTo1on1Matrix( void );
	void AddColumnThenRowToEmptyMatrix( void );
	void AddColumnThenRowTo1on1Matrix( void );

	void TestSuiteFill( void );
	void FillMatrix1on1RowWithDataUsingPointer( void );
	void FillMatrix3on3RowWithDataUsingPointer( void );
	void FillMatrix1on1ColumnWithDataUsingPointer( void );
	void FillMatrix3on3ColumnWithDataUsingPointer( void );
	void FillMatrix1on1RowWithDataUsingVector( void );
	void FillMatrix3on3RowWithDataUsingVector( void );
	void FillMatrix1on1ColumnWithDataUsingVector( void );
	void FillMatrix3on3ColumnWithDataUsingVector( void );
	void AddRowWithDataToEmptyMatrix( void );
	void AddRowWithDataTo1on1Matrix( void );
	void AddRowWithDataTo3on3Matrix( void );
	void AddColumnWithDataToEmptyMatrix( void );
	void AddColumnWithDataTo1on1Matrix( void );
	void AddColumnWithDataTo3on3Matrix( void );

	void TestSuiteOperations( void );
	void SumTwo1on1Matrix( void );
	void SumTwo3on3Matrix( void );
	void SumTwo3on5Matrix( void );
	void SumThree3on3Matrix( void );
	void SubtractTwo1on1Matrix( void );
	void SubtractTwo3on3Matrix( void );
	void SubtractTwo3on5Matrix( void );
	void SubtractThree3on3Matrix( void );
	void MultipliTwo1on1Matrix( void );
	void MultipliTwo3on3Matrix( void );
	void Multipli3on5MatrixWith5on3Matrix( void );
	void MultipliThree3on3Matrix( void );
	void Multipli1on1MatrixbyScalarAndOverwriteMatrix( void );
	void Multipli3on3MatrixbyScalarAndOverwriteMatrix( void );
	void Multipli3on5MatrixbyScalarAndOverwriteMatrix( void );
	void Multipli1on1MatrixbyScalarIntoNewMatrix( void );
	void Multipli3on3MatrixbyScalarIntoNewMatrix( void );
	void Multipli3on3MatrixbyScalarIntoEmptyMatrix( void );
	void Multipli3on5MatrixbyScalarIntoNewMatrix( void );
	void Assign1on1MatrixToEmptyMatrix( void );
	void Assign3on3MatrixToEmptyMatrix( void );
	void Assign3on3MatrixTo1on1Matrix( void );
	void Assign3on5MatrixTo3on3Matrix( void );
	void Transpose1on1MatrixAndOverwriteMatrix( void );
	void Transpose3on3MatrixAndOverwriteMatrix( void );
	void Transpose3on5MatrixAndOverwriteMatrix( void );
	void Transpose1on1MatrixIntoNewMatrix( void );
	void Transpose3on3MatrixIntoNewMatrix( void );
	void Transpose3on3MatrixIntoEmptyMatrix( void );
	void Transpose3on5MatrixIntoNewMatrix( void );
	void Invert1on1MatrixAndOverwriteMatrix( void );
	void Invert3on3MatrixAndOverwriteMatrix( void );
	void Invert3on5MatrixAndOverwriteMatrix( void );
	void Invert1on1MatrixIntoNewMatrix( void );
	void Invert3on3MatrixIntoNewMatrix( void );
	void Invert3on5MatrixIntoNewMatrix( void );
	void Determinant1on1Matrix( void );
	void Determinant3on3Matrix( void );
	void Determinant5on5Matrix( void );
	void Rank1on1MatrixExpect0( void );
	void Rank1on1MatrixExpect1( void );
	void Rank3on3MatrixExpect0( void );
	void Rank3on3MatrixExpect1( void );
	void Rank3on3MatrixExpect2( void );
	void Rank3on3MatrixExpect3( void );
	void Rank5on5MatrixExpect2( void );
	void Rank5on5MatrixExpect3( void );
	void Rank3on5MatrixExpect2( void );
	void Rank5on3MatrixExpect2( void );
	void Rank3on5MatrixExpect0( void );
	void Rank5on3MatrixExpect0( void );

public:
	MatrixTest();
	virtual ~MatrixTest();
};

#endif /* MATRIXTEST_H_ */
