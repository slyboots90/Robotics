/*
 * DHparam.cpp
 *
 *  Created on: 4 sep. 2017
 *      Author: mateusz.fraszczynski
 */

#include "../include/DHparam.h"
#include "math.h"


DHparam::DHparam() {
	transformations = shared_ptr < vector < params > > ( new vector < params > );

}

DHparam::~DHparam() {
	// TODO Auto-generated destructor stub
}

void DHparam::addParams( params dhparams ) {
	transformations->push_back( dhparams );
}

void DHparam::singleHomogeneousTransformation( ) {
	Matrix A( 4 , 4 );
	vector < double > r0;
	vector < double > r1;
	vector < double > r2;
	vector < double > r3;
	r0.push_back( cos( transformations->at( 0 ).theta ) );
	r0.push_back( -1 * sin( transformations->at( 0 ).theta ) * cos( transformations->at( 0 ).alpha ) );
	r0.push_back( sin( transformations->at( 0 ).theta ) * sin( transformations->at( 0 ).alpha ) );
	r0.push_back( transformations->at( 0 ).r * cos( transformations->at( 0 ).theta ) );
	r1.push_back( sin( transformations->at( 0 ).theta ) );
	r1.push_back( cos( transformations->at( 0 ).theta * cos( transformations->at( 0 ).alpha ) ) );
	r1.push_back( -1 * cos( transformations->at( 0 ).theta ) * sin( transformations->at( 0 ).alpha ) );
	r1.push_back( transformations->at( 0 ).r * sin( transformations->at( 0 ).theta ) );
	r2.push_back( 0 );
	r2.push_back( sin( transformations->at( 0 ).alpha ) );
	r2.push_back( cos( transformations->at( 0 ).alpha ) );
	r2.push_back( transformations->at( 0 ).d );
	r3.push_back( 0 );
	r3.push_back( 0 );
	r3.push_back( 0 );
	r3.push_back( 1 );
}
