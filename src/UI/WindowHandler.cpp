/*
 * WindowHandler.cpp
 *
 *  Created on: 22 sep. 2017
 *      Author: mateusz.fraszczynski
 */

// Include UI
#include "../../include/UI/WindowHandler.h"
// Include Classes
// Include libs
#include <regex>

map < HWND , WindowHandler * > WindowHandler::s_NotifyWindows;

WindowHandler::~WindowHandler() {

}

LRESULT CALLBACK WindowHandler::WindowProcHandler( HWND hwnd , UINT umsg , WPARAM wparam , LPARAM lparam ) {
    map < HWND , WindowHandler * > ::iterator search = s_NotifyWindows.find( hwnd );
    printf ("hwnd - %d \n" , hwnd);
    printf ("umsg - %d \n" , umsg);
    if ( search != s_NotifyWindows.end() ) {
        search->second->WndProc( umsg , wparam , lparam );
    }
    return DefWindowProc( hwnd , umsg , wparam , lparam );
}

double WindowHandler::getValuesFromWindow( HWND hwnd ) {
	TCHAR buff[ 30 ];
	GetWindowText( hwnd , buff , 30 );
	string string_v = buff;
	if ( checkIfStringIsNumber( string_v.c_str() ) ) {
		return atof( string_v.c_str( ) );
	} else {
		return ERROR_DOUBLE_VALUE;
	}
}

bool WindowHandler::checkIfStringIsNumber( const string & s ) {
	return regex_match( s , regex( "-?[0-9]+([.][0-9]+)?" ) );
}

string WindowHandler::doubleToString( double value ) {
	ostringstream strs;
	strs << value;
	return strs.str();
}
