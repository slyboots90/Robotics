/*
 * ShowPosition.h
 *
 *  Created on: 26 sep. 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef UI_SHOWPOSITION_H_
#define UI_SHOWPOSITION_H_

// Include UI
#include "WindowHandler.h"
// Include Classes
// Include libs

using namespace std;

#define WIN_SP_SIZE_X 					325
#define WIN_SP_SIZE_Y 					240
#define WIN_SP_DRAW_TAB_X				0
#define WIN_SP_DRAW_TAB_Y				100
#define WIN_SP_TEXT_OFFSET_X			10
#define WIN_SP_TEXT_OFFSET_Y			107
#define WIN_SP_TABLE_COLUMNS			3
#define WIN_SP_COLUMN_WIDTH 			100
#define WIN_SP_COLUMN_HIGH				30

class ShowPosition : private WindowHandler {

	LRESULT WndProc( UINT , WPARAM , LPARAM );
	void initWindow( );
	void createWindow( HWND & );
	void fillWindow( void );
	double getXpos( );
	double getYpos( );
	double getZpos( );
	void drawRowInTable( HDC & , int , int );
	void fillRowsInTable( HDC & );

	string subWindowName = "Show Position";
	HWND hwnd_child;
	HINSTANCE & hInstRef;
	DHparam * dhpPtr;

public:

	ShowPosition( HWND & , HINSTANCE & , DHparam * );
	virtual ~ShowPosition();

};

#endif /* UI_SHOWPOSITION_H_ */
