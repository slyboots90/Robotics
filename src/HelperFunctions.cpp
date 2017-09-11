/*
 * HelperFunctions.cpp
 *
 *  Created on: 8 sep. 2017
 *      Author: mateusz.fraszczynski
 */

#include "../include/HelperFunctions.h"
// Include UI
#include "../include/UI/AddJointWindow.h"
#include "../include/UI/MainWindow.h"
#include "../include/UI/ShowPositionWindow.h"
// Include Classes
// Include libs

#define ERROR_DOUBLE_VALUE			2.2E-308

extern HWND input[ INPUT_BOXES ];

int initWindows( HWND & hwnd_main , HINSTANCE & hInst ) {
	if ( ! initMainWindow( hwnd_main , hInst ) ) return 0;
	if ( ! initAddJointWindow( hInst ) ) return 0;
	if ( ! initShowPositionWindow( hInst ) ) return 0;
	return 1;
}

bool verifyAndAddValues( DHparam * dhp ) {
	if ( dhp == NULL ) return false;
	jointParams jParams;
	//TODO add to window
	jParams.unit = Degrees;
	for ( unsigned int i = 0 ; i < INPUT_BOXES ; i++ ) {
		double value = getValuesFromWindow( input[ i ] );
		if ( value == ERROR_DOUBLE_VALUE ) return false;
		switch ( i ) {
				case 0:
					jParams.d = value;
					break;
				case 1: {
					if ( ! ( value < 360 && value > -360 ) ) return false;
					jParams.theta = value;
					break;
				}
				case 2:
					jParams.r = value;
					break;
				case 3: {
					if ( ! ( value < 360 && value > -360 ) ) return false;
					jParams.alpha = value;
					break;
				}
				default:
					break;
		}
	}
	dhp->addJointParams( jParams );
	return true;
}

double getValuesFromWindow( HWND hwnd ) {
	TCHAR buff[ 30 ];
	GetWindowText( hwnd , buff , 30 );
	string string_v = buff;
	//TODO case 51-1 provided in window
	if ( checkIfStringIsNumber( string_v.c_str() ) ) {
		return atof( string_v.c_str( ) );
	} else {
		return ERROR_DOUBLE_VALUE;
	}
}

bool checkIfStringIsNumber( const string & s ) {
    return( strspn( s.c_str() , "-.0123456789" ) == s.size() );
}

string doubleToString( double value ) {
	ostringstream strs;
	strs << value;
	return strs.str();
}
