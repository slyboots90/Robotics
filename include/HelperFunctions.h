/*
 * HelperFunctions.h
 *
 *  Created on: 8 sep. 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef HELPERFUNCTIONS_H_
#define HELPERFUNCTIONS_H_

// Include UI
// Include Classes
#include "DHparam.h"
// Include libs
#include <windows.h>

int initWindows( HWND & , HINSTANCE & );
bool verifyAndAddValues( DHparam * );
double getValuesFromWindow( HWND );
bool checkIfStringIsNumber( const string & );
string doubleToString( double );
bool removeLastJoint( DHparam * );
bool verifyAndChangeValue( DHparam * , unsigned int );

#endif /* HELPERFUNCTIONS_H_ */
