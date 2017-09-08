/*
 * ui.h
 *
 *  Created on: 8 sep. 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef UI_H_
#define UI_H_

#include <windows.h>

#define mainWinSizeX 800
#define mainWinSizeY 500
#define childWinSizeX 330
#define childWinSizeY 150

#define ID_BUTTON_ADD_JOINT 	101
#define ID_BUTTON_SHOW_CHAIN 	102
#define ID_BUTTON_REMOVE_JOINT 	103
#define ID_BUTTON_ADD 			104

#define INPUT_BOXES 8

int initMainWindow( HWND & , HINSTANCE & );
int initChildWindow( HINSTANCE & );
int createChildWindow( HWND & , HWND & , HINSTANCE & );
void fillMainWindow( HWND & , HINSTANCE & );
void fillChildWindow( HWND & , HINSTANCE & );

#endif /* UI_H_ */
