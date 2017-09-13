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
#include "../include/UI/CommonID.h"
// Include Classes
// Include libs
#include <regex>

#define ERROR_DOUBLE_VALUE			2.2E-308

extern HWND input[ INPUT_BOXES ];
extern HWND listbox_unit;
extern HWND listbox_type;

int initWindows( HWND & hwnd_main , HINSTANCE & hInst ) {
	if ( ! initMainWindow( hwnd_main , hInst ) ) return 0;
	if ( ! initAddJointWindow( hInst ) ) return 0;
	if ( ! initShowPositionWindow( hInst ) ) return 0;
	return 1;
}

bool verifyAndAddValues( DHparam * dhp ) {
	if ( dhp == NULL ) return false;
	jointParams jParams;
	INT selected_type = SendMessage( listbox_type , CB_GETCURSEL , 0 , 0 );
	if ( selected_type == 0 ) {
		jParams.type = Rotational;
	} else if ( selected_type == 1 ) {
		jParams.type = Linear;
	}
	INT selected_units = SendMessage( listbox_unit , CB_GETCURSEL , 0 , 0 );
	if ( selected_units == 0 ) {
		jParams.unit = Degrees;
	} else if ( selected_units == 1 ) {
		jParams.unit = Radians;
	}
	for ( unsigned int i = 0 ; i < INPUT_BOXES ; i++ ) {
		double value = getValuesFromWindow( input[ i ] );
		if ( value == ERROR_DOUBLE_VALUE ) return false;
		switch ( i ) {
				case 0:
					//TODO add range here and in UI ( help info )
					if ( ! ( value < MAX_A_INPUT_VALUE && value > MIN_A_INPUT_VALUE ) ) return false;
					jParams.a = value;
					break;
				case 1: {
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
				case 2:
					jParams.d = value;
					break;
				case 3: {
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

bool removeLastJoint( DHparam * dhp ) {
	if ( dhp == NULL ) return 0;
	if ( dhp->removeLastJointParams( ) ) return 1;
	return 0;
}
