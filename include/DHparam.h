/*
 * DHparam.h
 *
 *  Created on: 4 sep. 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef DHPARAM_H_
#define DHPARAM_H_

#include "Matrix.h"
#include <stdio.h>
#include <vector>

using namespace std;

struct params {
	double d;				// segment offset
	double theta;			// angle of joint
	double r;				// segment length
	double alpha;			// twist angle
};

class DHparam {

	shared_ptr < vector < params > > transformations;

public:
	DHparam();
	virtual ~DHparam();
	void addParams( params );
	void singleHomogeneousTransformation( void );
};

#endif /* DHPARAM_H_ */
