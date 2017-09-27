/*
 * AddJoint.h
 *
 *  Created on: 22 sep. 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef UI_ADDJOINT_H_
#define UI_ADDJOINT_H_

// Include UI
#include "WindowHandler.h"
// Include Classes
// Include libs

using namespace std;

#define WIN_AJ_SIZE_X 					320
#define WIN_AJ_SIZE_Y 					200
#define EDIT_BOXES 						4

class AddJoint : private WindowHandler {

	LRESULT WndProc( UINT , WPARAM , LPARAM );
	void initWindow( );
	void createWindow( HWND & );
	void fillWindow( void );
	bool verifyAndAddValues( void );

	string subWindowName = "Add Joint";
	HWND hwnd_child;
	HINSTANCE & hInstRef;
	DHparam * dhpPtr;
	vector < HWND > inputbox;
	vector < HWND > listbox;

public:

	AddJoint( HWND & , HINSTANCE & , DHparam * );
	~AddJoint();

};

#endif /* UI_ADDJOINT_H_ */
