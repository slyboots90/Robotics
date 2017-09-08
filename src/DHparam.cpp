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
	end_coordination.x = 0;
	end_coordination.y = 0;
	end_coordination.z = 0;
}

DHparam::~DHparam() {
	// TODO Auto-generated destructor stub
}

bool DHparam::addJointParams( jointParams dhparams ) {
	if ( this->validateParams( dhparams ) ) {				// It still will be working, but come on...
		transformations->push_back( dhparams );
		return 1;
	} else {
		printf ( "ERROR: Cannot add jointParams, angle should be between -360 & 360 !\n");
		return 0;
	}
}

const jointParams * DHparam::getJointParams( unsigned int index ) {
	if ( transformations->empty( ) ) return NULL;
	if ( index > transformations->size( ) ) return NULL;
	return & transformations->at( index );
}

unsigned int DHparam::getNoOfJoints( void ) {
	if ( transformations->empty( ) ) return 0;
	return transformations->size( );
}

bool DHparam::validateParams( jointParams dhparams ) {
	if ( ! ( dhparams.alpha < 360 ) && ! ( dhparams.alpha > -360 ) ) return 0;
	if ( ! ( dhparams.theta < 360 ) && ! ( dhparams.theta > -360 ) ) return 0;
	return 1;
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
			printf ( "ERROR: Cannot calculate Tmatrix, singleHomogeneousTransformation return NULL\n" );
			return NULL;
		}
	}
	transformations_M->printMatrix();
	return transformations_M;
}

void DHparam::designateCoordinates( void ) {
	shared_ptr < Matrix > transformations_M ( new Matrix( ) );
	transformations_M = this->transformation( transformations->size() );
	const vector < double > * xRow = transformations_M->getRow( 0 );
	const vector < double > * yRow = transformations_M->getRow( 1 );
	const vector < double > * zRow = transformations_M->getRow( 2 );
	end_coordination.x = xRow->back();
	end_coordination.y = yRow->back();
	end_coordination.z = zRow->back();
	printf ( "X: %f Y: %f Z: %f \n" , end_coordination.x , end_coordination.y , end_coordination.z );
}
