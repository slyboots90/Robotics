/*
 * MatrixOperations.cpp
 *
 *  Created on: 2 aug. 2017
 *      Author: mateusz.fraszczynski
 */

#include "../include/MatrixOperations.h"
#include "../include/Timer.h"
#include <stdio.h> 							// printf
#include <math.h>							// Power of numbers


MatrixOperations::MatrixOperations() {
	// TODO Auto-generated constructor stub

}

MatrixOperations::~MatrixOperations() {
	// TODO Auto-generated destructor stub
}

void MatrixOperations::multiplication( Matrix & product , const Matrix & multiplicand , const Matrix & multiplier ) {
	const vector < int > * row_pointer = NULL;
	if ( ! multiplicand.isEmpty() && ! multiplier.isEmpty() ) {
		for ( unsigned int i = 0 ; i < multiplicand.getRowsNo() ; i++ ) {
			vector < int > temporary_vector;
			for ( unsigned int j = 0 ; j < multiplier.getColumnsNo() ; j++ ) {
				vector < const int * > pointers_to_column;
				row_pointer = multiplicand.getRow( i );
				if ( row_pointer == NULL) {
					printf( "Fail to get Row from Matrix\n" );
					break;
				}
				if ( multiplier.getColumn( & pointers_to_column , j ) ) {
					printf( "Fail to get Column from Matrix\n" );
					break;
				}
				int outcome_value = MatrixOperations::vectorMultiplication( row_pointer , & pointers_to_column );
				temporary_vector.push_back( outcome_value );
			}
			if ( product.addRowWithData( & temporary_vector ) ) {
				printf( "Fail to add temporary_vector to Matrix\n" );
			}
		}
	}
}

void MatrixOperations::scalarmultiplication( Matrix & product , const Matrix & multiplicand , int multiplier ) {
	const vector < int > * row_pointer = NULL;
	if ( ! multiplicand.isEmpty() ) {
		for ( unsigned int i = 0 ; i < multiplicand.getRowsNo() ; i++ ) {
			vector < int > temporary_vector;
			row_pointer = multiplicand.getRow( i );
			if ( row_pointer == NULL) {
				printf( "Fail to get Row from Matrix\n" );
				break;
			}
			for ( unsigned int j = 0 ; j < row_pointer->size() ; j++ ) {
				temporary_vector.push_back( row_pointer->at( j ) * multiplier );
			}
			if ( product.addRowWithData( & temporary_vector ) ) {
				printf( "Fail to add temporary_vector to Matrix\n" );
			}
		}
	}
}

void MatrixOperations::scalarmultiplication( Matrix & multiplicand , int multiplier ) {
	if ( ! multiplicand.isEmpty() ) {
		for ( unsigned int i = 0 ; i < multiplicand.getRowsNo() ; i++ ) {
			for( unsigned int j = 0 ; j < multiplicand.getColumnsNo() ; j++ ) {
				multiplicand.matrixDataPtr->at( i ).at( j ) *= multiplier;
			}
		}
	}
}

int MatrixOperations::vectorMultiplication( const vector < int > * row_pointer , vector < const int * > * column_pointer ) {
	int result = 0;
	if ( row_pointer->size() != column_pointer->size() ) {
		printf ( "Size of multiplied vectors isn't equal - must be the same! row size: %d, column size: %d\n" , row_pointer->size() , column_pointer->size() );
	} else {
		for ( unsigned int i = 0 ; i < row_pointer->size() ; i++ ) {
			result += row_pointer->at( i ) * *( column_pointer->at( i ) ) ;
		}
		return result;
	}
	return 0;
}

void MatrixOperations::addition( Matrix & sum , const Matrix & component_a , const Matrix & component_b ) {
	const vector < int > * component_a_row_pointer = NULL;
	const vector < int > * component_b_row_pointer = NULL;
		if ( ! component_a.isEmpty() && ! component_b.isEmpty() ) {
			for ( unsigned int i = 0 ; i < component_a.getRowsNo() ; i++ ) {
				vector < int > temporary_vector;
				component_a_row_pointer = component_a.getRow( i );
				component_b_row_pointer = component_b.getRow( i );
				if ( component_a_row_pointer == NULL || component_b_row_pointer == NULL ) {
					printf( "Fail to get Row from Matrix\n" );
					break;
				}
				for ( unsigned int j = 0 ; j < component_a.getColumnsNo() ; j++ ) {
					int outcome_value = component_a_row_pointer->at( j ) + component_b_row_pointer->at( j );
					temporary_vector.push_back( outcome_value );
				}
				if ( sum.addRowWithData( & temporary_vector ) ) {
					printf( "Fail to add temporary_vector to Matrix\n" );
				}
			}
		}
}

void MatrixOperations::subtraction( Matrix & difference , const Matrix & minuend , const Matrix & subtrahend ) {
	const vector < int > * minuend_row_pointer = NULL;
	const vector < int > * subtrahend_row_pointer = NULL;
		if ( ! minuend.isEmpty() && ! subtrahend.isEmpty() ) {
			for ( unsigned int i = 0 ; i < minuend.getRowsNo() ; i++ ) {
				vector < int > temporary_vector;
				minuend_row_pointer = minuend.getRow( i );
				subtrahend_row_pointer = subtrahend.getRow( i );
				if ( subtrahend_row_pointer == NULL || minuend_row_pointer == NULL ) {
					printf( "Fail to get Row from Matrix\n" );
					break;
				}
				for ( unsigned int j = 0 ; j < minuend.getColumnsNo() ; j++ ) {
					int outcome_value = minuend_row_pointer->at( j ) - subtrahend_row_pointer->at( j );
					temporary_vector.push_back( outcome_value );
				}
				if ( difference.addRowWithData( & temporary_vector ) ) {
					printf( "Fail to add temporary_vector to Matrix\n" );
				}
			}
		}
}

void MatrixOperations::transposition( Matrix & base_MT, const Matrix & base_M ) {
	const vector < int > * matrix_base_row_pointer = NULL;
	if ( ! base_M.isEmpty() ) {
		for ( unsigned int i = 0 ; i < base_M.getRowsNo() ; i++ ) {
			vector < int > temporary_vector;
			matrix_base_row_pointer = base_M.getRow( i );
			if ( matrix_base_row_pointer == NULL ) {
				printf( "Fail to get Row from Matrix\n" );
				break;
			}
			for ( unsigned int j = 0 ; j < base_M.getColumnsNo() ; j++ ) {
				temporary_vector.push_back( matrix_base_row_pointer->at( j ) );
			}
			base_MT.addColumnWithData( & temporary_vector );
		}
	}
}

int MatrixOperations::determinant( const Matrix & base_M ) {
	if ( base_M.isEmpty( ) ) {
		printf( "Fail to calculate determinant, Matrix is empty\n" );
		return 0;
	}
	if ( base_M.isSquareSize( ) ) {
		switch ( base_M.getRowsNo( ) ) {
			case 1:
			case 2: {
				return smallDetCalculation( base_M );
			}
			case 3: {
				//detSarrusMethodFunWay( base_M );
				return detSarrusMethod( base_M );
			}
			default:
				return detLaplaceMethod( base_M );
		}
	} else {
		printf( "Fail to calculate determinant, Matrix isn't square size: %dx%d\n" , base_M.getRowsNo() , base_M.getColumnsNo() );
		base_M.printMatrix();
	}
	return 0;
}

int MatrixOperations::smallDetCalculation( const Matrix & base_M ) {
	if ( base_M.getRowsNo( ) == 1 ) {
		const vector < int > * rp = base_M.getRow( 0 );
		return rp->at( 0 );
	} else {
		const vector < int > * rpt = base_M.getRow( 0 );
		const vector < int > * rpb = base_M.getRow( 1 );
		return rpt->at( 0 ) * rpb->at( 1 ) - rpb->at( 0 ) * rpt->at( 1 );
	}
}

int MatrixOperations::detSarrusMethod( const Matrix & base_M ) {
	const vector < int > * rpt = base_M.getRow( 0 );
	const vector < int > * rpm = base_M.getRow( 1 );
	const vector < int > * rpb = base_M.getRow( 2 );
	// a11a22a33+a12a23a31+a13a21a32-(a13a22a31+a11a23a32+a12a21a33)
	int product_a = 0 , product_b = 0 , product_c = 0;
	product_a = rpt->at( 0 ) * rpm->at( 1 ) * rpb->at( 2 );
	product_b = rpt->at( 1 ) * rpm->at( 2 ) * rpb->at( 0 );
	product_c = rpt->at( 2 ) * rpm->at( 0 ) * rpb->at( 1 );
	int minuend = product_a + product_b + product_c;
	product_a = rpt->at( 2 ) * rpm->at( 1 ) * rpb->at( 0 );
	product_b = rpt->at( 0 ) * rpm->at( 2 ) * rpb->at( 1 );
	product_c = rpt->at( 1 ) * rpm->at( 0 ) * rpb->at( 2 );
	int subtrahend = product_a + product_b + product_c;
	return minuend - subtrahend;
}

void MatrixOperations::detSarrusMethodFunWay( const Matrix & base_M ) {
	shared_ptr < Matrix > subMatrix ( new Matrix( base_M ) );
	for ( unsigned int i = 0 ; i < 2 ; i++ ) {
		vector < const int * > pointers_to_column;
		vector < int > new_column;
		base_M.getColumn( & pointers_to_column , i );
		for ( unsigned int j = 0 ; j < pointers_to_column.size() ; j++ ) {
			new_column.push_back( * pointers_to_column.at( j ) );
		}
		subMatrix->addColumnWithData( & new_column );
	}
	int sub_sum1 = 0;
	for ( unsigned int i = 0 ; i < 3 ; i++ ) {
		int sub_product = 1;
		for ( unsigned int j = 0 ; j < 3 ; j++ ) {
			sub_product *= subMatrix->matrixDataPtr->at( j ).at( i + j );
		}
		sub_sum1 += sub_product;
	}
	int sub_sum2 = 0;
	for ( unsigned int i = 0 ; i < 3 ; i++ ) {
		int sub_product = 1;
		for ( unsigned int j = 2 , k = 0 ; k < 3 ; j-- , k++ ) {
			sub_product *= subMatrix->matrixDataPtr->at( j ).at( k + i );
		}
		sub_sum2 += sub_product;
	}
	printf ( "Det FunWay = %d\n" , sub_sum1 - sub_sum2 );
}

int MatrixOperations::detLaplaceMethod( const Matrix & base_M ) {
	unsigned int row = 0;
	int det = 0 , minor = 0;
	const vector < int > * main_row = base_M.getRow( row );
	Matrix * subMatrix = new Matrix( base_M.getRowsNo() - 1 , base_M.getColumnsNo() - 1 );
	//det A = (-1)1+1 × a11 × M1,1 + (-1)1+2 × a12 × M1,2 + (-1)1+3 × a13 × M1,3 + n...
	for ( unsigned int i = 0 ; i < base_M.getColumnsNo() ; i++ ) {
		createSubMatrix( base_M , * subMatrix , row , i );
		subMatrix->getColumnsNo() == 3 ? minor = detSarrusMethod( * subMatrix ) : minor = detLaplaceMethod( * subMatrix );
		det += pow( -1 , row + i ) * main_row->at( i ) * minor;
	}
	delete subMatrix;
	return det;
}

void MatrixOperations::createSubMatrix( const Matrix & base_M , Matrix & subMatrix , unsigned int row , unsigned int column ) {
	for ( unsigned int i = 0 , j = 0 ; i < base_M.getColumnsNo() ; i++ ) {
		if ( i == column ) continue;
		vector < const int * > column_ptr;
		vector < int > * insert_column = new vector < int >;
		base_M.getColumn( & column_ptr , i );
		vector < const int * >::iterator it = column_ptr.begin();
		for ( unsigned int j = 0 ; j < row ; j++ ) it++;
		column_ptr.erase( it );
		for ( unsigned int j = 0 ; j < column_ptr.size() ; j++ ) {
			//TODO avoid copy
			insert_column->push_back( * column_ptr.at( j ) );
		}
		subMatrix.fillColumnWithData( insert_column , j++ );
		delete insert_column;
	}
}

int MatrixOperations::detGaussMethod( const Matrix & base_M ) {
	//TODO
	return 0;
}

unsigned int MatrixOperations::rank( const Matrix & base_M ) {
	if ( base_M.isEmpty() ) return 0;
	if ( base_M.isSquareSize() ) {
		if ( determinant( base_M ) ) return base_M.getRowsNo();
		return subRank( base_M );
	} else {
		unsigned int diff = 0;
		unsigned int rank = 0;
		Matrix * subBase_M;
		if ( base_M.getRowsNo() > base_M.getColumnsNo() ) {
			diff = base_M.getRowsNo() - base_M.getColumnsNo();
			subBase_M = new Matrix( base_M.getColumnsNo() , base_M.getColumnsNo() );
			for ( unsigned int i = 0 ; i < diff + 1 ; i++ ) {
				for ( unsigned int j = 0 ; j < base_M.getColumnsNo() ; j++ ) {
					const vector < int > * tmp_vector = base_M.getRow( i + j );
					vector < int > * data = new vector < int >;
					for ( unsigned int k = 0 ; k < tmp_vector->size() ; k++ ) {
						data->push_back( tmp_vector->at( k ) );
					}
					subBase_M->fillRowWithData( data , j );
					delete data;
				}
				unsigned int tmp = MatrixOperations::rank( * subBase_M );
				if ( tmp > rank ) rank = tmp;
			}
			delete subBase_M;
			return rank;
		} else {
			diff = base_M.getColumnsNo() - base_M.getRowsNo();
			subBase_M = new Matrix( base_M.getRowsNo() , base_M.getRowsNo() );
			for ( unsigned int i = 0 ; i < diff + 1 ; i++ ) {
				for ( unsigned int j = 0 ; j < base_M.getRowsNo() ; j++ ) {
					vector < const int * > pointers_to_column;
					base_M.getColumn( & pointers_to_column , i + j );
					vector < int > * data = new vector < int >;
					for ( unsigned int k = 0 ; k < pointers_to_column.size() ; k++ ) {
						data->push_back(  * pointers_to_column.at( k ) );
					}
					subBase_M->fillColumnWithData( data , j );
					delete data;
				}
				unsigned int tmp = MatrixOperations::rank( * subBase_M );
				if ( tmp > rank ) rank = tmp;
			}
			delete subBase_M;
			return rank;
		}
	}
}

unsigned int MatrixOperations::subRank( const Matrix & base_M ) {
	unsigned int rank = 0;
	unsigned int size = base_M.getRowsNo();
	if ( size > 1 ) {
		Matrix * subMatrix = new Matrix( size - 1 , size - 1 );
		for ( unsigned int row = 0 ; row < size ; row++ ) {
			for ( unsigned int column = 0 ; column < size ; column++ ) {
				createSubMatrix( base_M , * subMatrix , row , column );
				if ( determinant( * subMatrix ) ) {
					unsigned int return_rank = subMatrix->getRowsNo();
					delete subMatrix;
					return return_rank;
				} else {
					unsigned int tmp = subRank( * subMatrix );
					if ( tmp > rank ) rank = tmp;
				}
			}
		}
		delete subMatrix;
	} else {
		if ( determinant( base_M ) ) return base_M.getRowsNo();
	}
	return rank;
}
