/*
 * ChangeValueOfJointParam.h
 *
 *  Created on: 27 sep. 2017
 *      Author: mateusz.fraszczynski
 */
#ifndef UI_CHANGEVALUEOFJOINTPARAM_H_
#define UI_CHANGEVALUEOFJOINTPARAM_H_

// Include UI
#include "WindowHandler.h"
// Include Classes
// Include libs

using namespace std;

#define WIN_JP_SIZE_X 					350
#define WIN_JP_SIZE_Y 					170
#define WIN_JP_LPCREATE					99

class ChangeValueOfJointParam : private WindowHandler {

	LRESULT WndProc( UINT , WPARAM , LPARAM );
	void initWindow( );
	void createWindow( HWND & );
	void fillWindow( void );
	bool verifyAndChangeValue( void );

	string subWindowName = "Change value of joint param";
	HWND hwnd_child;
	HINSTANCE & hInstRef;
	DHparam * dhpPtr;
	HWND changeBox;
	unsigned int jointIndex;

public:

	ChangeValueOfJointParam( HWND & , HINSTANCE & , DHparam * , WPARAM );
	virtual ~ChangeValueOfJointParam();

};

#endif /* UI_CHANGEVALUEOFJOINTPARAM_H_ */
