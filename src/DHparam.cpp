/*
 * DHparam.cpp
 *
 *  Created on: 4 sep. 2017
 *      Author: mateusz.fraszczynski
 */

#include "../include/DHparam.h"
#include "math.h"


DHparam::DHparam() {
	transformations = shared_ptr < vector < jointParams > > ( new vector < jointParams > );

}

DHparam::~DHparam() {
	// TODO Auto-generated destructor stub
}

void DHparam::addJointParams( jointParams dhparams ) {
	transformations->push_back( dhparams );
}

shared_ptr < Matrix > DHparam::singleHomogeneousTransformation( unsigned int joint_index) {
	if ( joint_index > transformations->size() ) {
		printf ( "ERROR: Cannot calculate s-h-t, parameters of this joint doesn't exist. Params vector size: %d , joint_index %d\n" , transformations->size() , joint_index );
		return NULL;
	}
	shared_ptr < Matrix > TransformationMatrix ( new Matrix( ) );
	vector < double > r0 , r1 , r2 , r3;
	r0.push_back( cos( transformations->at( joint_index ).theta ) );
	r0.push_back( -1 * sin( transformations->at( joint_index ).theta ) * cos( transformations->at( joint_index ).alpha ) );
	r0.push_back( sin( transformations->at( joint_index ).theta ) * sin( transformations->at( joint_index ).alpha ) );
	r0.push_back( transformations->at( joint_index ).r * cos( transformations->at( joint_index ).theta ) );
	r1.push_back( sin( transformations->at( joint_index ).theta ) );
	r1.push_back( cos( transformations->at( joint_index ).theta * cos( transformations->at( joint_index ).alpha ) ) );
	r1.push_back( -1 * cos( transformations->at( joint_index ).theta ) * sin( transformations->at( joint_index ).alpha ) );
	r1.push_back( transformations->at( joint_index ).r * sin( transformations->at( joint_index ).theta ) );
	r2.push_back( 0 );
	r2.push_back( sin( transformations->at( joint_index ).alpha ) );
	r2.push_back( cos( transformations->at( joint_index ).alpha ) );
	r2.push_back( transformations->at( joint_index ).d );
	r3.push_back( 0 );
	r3.push_back( 0 );
	r3.push_back( 0 );
	r3.push_back( 1 );
	TransformationMatrix->addRowWithData( &r0 );
	TransformationMatrix->addRowWithData( &r1 );
	TransformationMatrix->addRowWithData( &r2 );
	TransformationMatrix->addRowWithData( &r3 );
	TransformationMatrix->printMatrix();
	return TransformationMatrix;
}

shared_ptr < Matrix > DHparam::transformation( unsigned int joint_End ) {
	if ( ! transformations->size() ) {
		printf ( "ERROR: Cannot calculate Tmatrix, transformation parameters are empty !\n");
		return NULL;
	} else if ( joint_End > transformations->size() ) {
		printf ( "ERROR: Cannot calculate Tmatrix, parameters of last this joint doesn't exist. Params vector size: %d , joint_End %d\n" , transformations->size() , joint_End );
		return NULL;
	}
	shared_ptr < Matrix > transformations_M ( new Matrix( 4 , 4 ) );
	for ( unsigned int i = 0 ; i < joint_End ; i++ ) {
		shared_ptr < Matrix > tmp = singleHomogeneousTransformation( i );
		if ( tmp != NULL ) {
			if ( ! i ) transformations_M = tmp;
			else transformations_M = * transformations_M * tmp;
		} else {
			printf ( "ERROR: Cannot calculate Tmatrix, singleHomogeneousTransformation return NULL\n");
			return NULL;
		}
	}
	transformations_M->printMatrix();
	return transformations_M;
}
