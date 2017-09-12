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
#include <regex>

#define ERROR_DOUBLE_VALUE			2.2E-308

extern HWND input[ INPUT_BOXES ];
extern HWND listbox;

int initWindows( HWND & hwnd_main , HINSTANCE & hInst ) {
	if ( ! initMainWindow( hwnd_main , hInst ) ) return 0;
	if ( ! initAddJointWindow( hInst ) ) return 0;
	if ( ! initShowPositionWindow( hInst ) ) return 0;
	return 1;
}

bool verifyAndAddValues( DHparam * dhp ) {
	if ( dhp == NULL ) return false;
	jointParams jParams;
	INT selected = SendMessage( listbox , CB_GETCURSEL , 0 , 0 );
	if ( selected == 0 ) {
		jParams.unit = Degrees;
	} else if ( selected == 1 ) {
		jParams.unit = Radians;
	}
	for ( unsigned int i = 0 ; i < INPUT_BOXES ; i++ ) {
		double value = getValuesFromWindow( input[ i ] );
		if ( value == ERROR_DOUBLE_VALUE ) return false;
		switch ( i ) {
				case 0:
					//TODO add range here and in UI
					jParams.d = value;
					break;
				case 1: {
					if ( jParams.unit == Degrees ) {
						if ( ! ( value < 360 && value > -360 ) ) return false;
						jParams.theta = value;
					} else if ( jParams.unit == Radians ) {
						if ( ! ( value < 2 * PI && value > -2 * PI ) ) return false;
						jParams.theta = value;
					} else {
						printf ( "ERROR: Joint Params unit not found ! ");
						return false;
					}
					break;
				}
				case 2:
					jParams.r = value;
					break;
				case 3: {
					if ( jParams.unit == Degrees ) {
						if ( ! ( value < 360 && value > -360 ) ) return false;
						jParams.alpha = value;
					} else if ( jParams.unit == Radians ) {
						if ( ! ( value < 2 * PI && value > -2 * PI ) ) return false;
						jParams.alpha = value;
					} else {
						printf ( "ERROR: Joint Params unit not found ! ");
						return false;
					}
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
	if ( checkIfStringIsNumber( string_v.c_str() ) ) {
		return atof( string_v.c_str( ) );
	} else {
		return ERROR_DOUBLE_VALUE;
	}
}

bool checkIfStringIsNumber( const string & s ) {
	return regex_match( s , regex( "-?[0-9]+([.][0-9]+)?" ) );
}

string doubleToString( double value ) {
	ostringstream strs;
	strs << value;
	return strs.str();
}
