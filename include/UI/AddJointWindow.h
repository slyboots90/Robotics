/*
 * AddJointWindow.h
 *
 *  Created on: 8 sep. 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef UI_ADDJOINTWINDOW_H_
#define UI_ADDJOINTWINDOW_H_

// Include UI
// Include Classes
// Include libs
#include <windows.h>

#define WIN_SIZE_X 			330
#define WIN_SIZE_Y 			150

#define INPUT_BOXES 		8

int initChildWindow( HINSTANCE & );
int createChildWindow( HWND & , HWND & , HINSTANCE & );
void fillChildWindow( HWND & , HINSTANCE & );

#endif /* UI_ADDJOINTWINDOW_H_ */
