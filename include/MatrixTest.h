/*
 * MatrixTest.h
 *
 *  Created on: 18 aug. 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef MATRIXTEST_H_
#define MATRIXTEST_H_

class MatrixTest {

	void CreateEmptyMatrix( void );
	void Create1on1Matrix( void );
	void Create3on3Matrix( void );
	void Create3on5Matrix( void );
	void Create5on3Matrix( void );
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

public:
	MatrixTest();
	virtual ~MatrixTest();
};

#endif /* MATRIXTEST_H_ */
