/*
 * ui.h
 *
 *  Created on: 8 sep. 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef UI_H_
#define UI_H_

#include <windows.h>

#define MAIN_WIN_SIZE_X 			800
#define MAIN_WIN_SIZE_Y 			500

int initMainWindow( HWND & , HINSTANCE & );
void fillMainWindow( HWND & , HINSTANCE & );

#endif /* UI_H_ */
