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

#define MAIN_WIN_SIZE_X 				800
#define MAIN_WIN_SIZE_Y 				500
#define MAIN_DRAW_TAB_X					200
#define MAIN_DRAW_TAB_Y				 	30
#define MAIN_TEXT_OFFSET_X				230
#define MAIN_TEXT_OFFSET_Y				38
#define MAIN_TABLE_COLUMNS			 	5
#define MAIN_COLUMN_WIDTH 				100
#define MAIN_COLUMN_HIGH				30

int initMainWindow( HWND & , HINSTANCE & );
int createMainWindow( HWND & , HINSTANCE & );
void fillMainWindow( HWND & , HINSTANCE & );
void drawRowInMainWindowTable( HDC & , int , int );
void fillRowsInMainWindowTable( HDC & , DHparam * );
void updateButtons( HWND & , HINSTANCE & , DHparam * );

#endif /* UI_H_ */
