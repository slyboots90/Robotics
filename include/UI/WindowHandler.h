/*
 * WindowHandler.h
 *
 *  Created on: 22 sep. 2017
 *      Author: mateusz.fraszczynski
 */
#ifndef UI_WINDOWHANDLER_H_
#define UI_WINDOWHANDLER_H_

// Include UI
// Include Classes
#include "../DHparam.h"
// Include libs
#include <windows.h>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

#define ERROR_DOUBLE_VALUE			2.2E-308

class WindowHandler {

	virtual LRESULT WndProc( UINT , WPARAM , LPARAM ) = 0;
	virtual void initWindow( ) = 0;
	virtual void createWindow( HWND & ) = 0;
	virtual void fillWindow( void ) = 0;

protected:

	static map < HWND , WindowHandler * > s_NotifyWindows;
    static LRESULT CALLBACK WindowProcHandler( HWND , UINT , WPARAM , LPARAM );

	double getValuesFromWindow( HWND );
	bool checkIfStringIsNumber( const string & );
	string doubleToString( double );

public:

	virtual ~WindowHandler();

};

#endif /* UI_WINDOWHANDLER_H_ */
