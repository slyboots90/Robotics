/*
 * ui.h
 *
 *  Created on: 8 sep. 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef UI_H_
#define UI_H_
// Include UI
// Include Classes
#include "../../include/DHparam.h"
// Include libs
#include <windows.h>
#include <sstream>

#define MAIN_WIN_SIZE_X 			800
#define MAIN_WIN_SIZE_Y 			500
#define DRAW_TAB_X					200
#define DRAW_TAB_Y				 	30
#define TABLE_COLUMNS			 	5
#define COLUMN_WIDTH 				100
#define COLUMN_HIGH				 	30

int initMainWindow( HWND & , HINSTANCE & );
int createMainWindow( HWND & , HINSTANCE & );
void fillMainWindow( HWND & , HINSTANCE & );
void drawRowInMainWindowTable( HDC & , int , int );
void fillRowsInMainWindowTable( HDC & , DHparam * );

#endif /* UI_H_ */
