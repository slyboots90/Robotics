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
	rotationalMatrix = shared_ptr < Matrix > ( new Matrix ( 3 , 3 ) );
}

DHparam::~DHparam() {

}

bool DHparam::addJointParams( jointParams dhparams ) {
	if ( this->validateParams( dhparams ) ) {				// It still will be working, but come on...
		transformations->push_back( dhparams );
	} else {
		printf ( "ERROR: Cannot add jointParams, angle should be between -360 & 360 !\n");
		return 0;
	}
	this->designateCoordinates( );
	return 1;
}

bool DHparam::removeLastJointParams( void ) {
	if ( ! transformations->empty() ) {
		vector < jointParams >::iterator it = transformations->end();
		transformations->erase( --it );
	} else {
		return 0;
	}
	this->designateCoordinates( );
	return 1;
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
	if ( dhparams.type != Rotational && dhparams.type != Linear ) return 0;
	if ( dhparams.unit == Degrees ) {
		if ( ! ( dhparams.alpha < 360 ) && ! ( dhparams.alpha > -360 ) ) return 0;
		if ( ! ( dhparams.theta < 360 ) && ! ( dhparams.theta > -360 ) ) return 0;
		return 1;
	} else if ( dhparams.unit == Radians ) {
		if ( ! ( dhparams.alpha < 2 * PI ) && ! ( dhparams.alpha > -2 * PI ) ) return 0;
		if ( ! ( dhparams.theta < 2 * PI ) && ! ( dhparams.theta > -2 * PI ) ) return 0;
		return 1;
	} else {
		printf ( "ERROR: Unknown units, validateParams failed");
		return 0;
	}
}

/**
 *
 * DHT Matrix:
 *
 *  [   cos(theta)  -sin(theta)cos(alpha)     sin(theta)sin(alpha)      r*cos(theta)    ]
 *  [   sin(theta)   cos(theta)cos(alpha)    -cos(theta)sin(alpha)      r*sin(theta)    ]
 *  [     0             sin(alpha)                  cos(alpha)              d           ]
 *  [     0                 0                           0                   1           ]
 *
 */

shared_ptr < Matrix > DHparam::singleHomogeneousTransformation( unsigned int joint_index ) {
	if ( joint_index > transformations->size() ) {
		printf ( "ERROR: Cannot calculate s-h-t, parameters of this joint doesn't exist. Params vector size: %d , joint_index %d\n" , transformations->size() , joint_index );
		return NULL;
	}
	shared_ptr < Matrix > TransformationMatrix ( new Matrix( ) );
	vector < double > r0 , r1 , r2 , r3;
	double sinTheta , cosTheta , sinAlpha , cosAlpha;
	double a = transformations->at( joint_index ).a;
	double d = transformations->at( joint_index ).d;
	if ( transformations->at( joint_index ).unit == Degrees ) {
		sinTheta = sin( ( transformations->at( joint_index ).theta ) * PI / 180 );
		cosTheta = cos( ( transformations->at( joint_index ).theta ) * PI / 180 );
		sinAlpha = sin( ( transformations->at( joint_index ).alpha ) * PI / 180 );
		cosAlpha = cos( ( transformations->at( joint_index ).alpha ) * PI / 180 );
	} else {
		sinTheta = sin( transformations->at( joint_index ).theta );
		cosTheta = cos( transformations->at( joint_index ).theta );
		sinAlpha = sin( transformations->at( joint_index ).alpha );
		cosAlpha = cos( transformations->at( joint_index ).alpha );
	}
	r0.push_back( cosTheta );
	r0.push_back( -1 * sinTheta * cosAlpha );
	r0.push_back( sinTheta * sinAlpha );
	r0.push_back( a * cosTheta );
	r1.push_back( sinTheta );
	r1.push_back( cosTheta * cosAlpha );
	r1.push_back( -1 * cosTheta * sinAlpha );
	r1.push_back( a * sinTheta );
	r2.push_back( 0 );
	r2.push_back( sinAlpha );
	r2.push_back( cosAlpha );
	r2.push_back( d );
	r3.push_back( 0 );
	r3.push_back( 0 );
	r3.push_back( 0 );
	r3.push_back( 1 );
	TransformationMatrix->addRowWithData( &r0 );
	TransformationMatrix->addRowWithData( &r1 );
	TransformationMatrix->addRowWithData( &r2 );
	TransformationMatrix->addRowWithData( &r3 );
	//TODO delete after all
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
	//TODO delete after all
	transformations_M->printMatrix();
	return transformations_M;
}

void DHparam::designateCoordinates( void ) {
	if ( transformations->empty( ) ) return;
	shared_ptr < Matrix > transformations_M ( new Matrix( ) );
	transformations_M = this->transformation( transformations->size( ) );
	for ( unsigned int i = 0 ; i < ROTMATRIXSIZE ; i++ ) {
		const vector < double > * rowPtr = transformations_M->getRow( i );
		vector < double > tmp;
		for ( unsigned int j = 0 ; j < ROTMATRIXSIZE ; j++ ) tmp.push_back( rowPtr->at( j ) );
		rotationalMatrix->fillRowWithData( & tmp , i );
		switch ( i ) {
			case 0 : {
				end_coordination.x = rowPtr->back( );
				break;
			}
			case 1 : {
				end_coordination.y = rowPtr->back( );
				break;
			}
			case 2 : {
				end_coordination.z = rowPtr->back( );
				break;
			}
			default : {
				break;
			}
		}
	}
}

double DHparam::getPositionX( void ) {
	return end_coordination.x;
}

double DHparam::getPositionY( void ) {
	return end_coordination.y;
}

double DHparam::getPositionZ( void ) {
	return end_coordination.z;
}

shared_ptr < Matrix > DHparam::getRotationalMatrix( void ) {
	return rotationalMatrix;
}

bool DHparam::updateJointValue( unsigned int index , double value ) {
	if ( ! ( index < this->getNoOfJoints( ) ) ) return false;
	jointParams * params = & ( this->transformations->at( index ) );
	if ( params->type == Linear ) {
		params->d = value;
	} else if ( params->type == Rotational ) {
		params->theta = value;
	} else {
		return false;
	}
	this->designateCoordinates( );
	return true;
}
