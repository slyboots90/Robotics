/*
 * MatrixTest.h
 *
 *  Created on: 18 aug. 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef MATRIXTEST_H_
#define MATRIXTEST_H_

#include <vector>

class MatrixTest {

	int testData[9] = { 5 , 7 , 12 , 44 , 77 , 22 , 142 , 537 , 873 };
	int * data_ptr;
	std::vector < int > * data_vector_ptr;
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

public:
	MatrixTest();
	virtual ~MatrixTest();
};

#endif /* MATRIXTEST_H_ */
