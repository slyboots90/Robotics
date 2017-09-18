/*
 * ShowPositionWindow.h
 *
 *  Created on: 11 sep. 2017
 *      Author: mateusz.fraszczynski
 */
#ifndef UI_SHOWPOSITIONWINDOW_H_
#define UI_SHOWPOSITIONWINDOW_H_

// Include UI
// Include Classes
#include "../DHparam.h"
// Include libs
#include <windows.h>

#define WIN_SP_SIZE_X 					325
#define WIN_SP_SIZE_Y 					240
#define WIN_SP_DRAW_TAB_X				0
#define WIN_SP_DRAW_TAB_Y				100
#define WIN_SP_TEXT_OFFSET_X			10
#define WIN_SP_TEXT_OFFSET_Y			107
#define WIN_SP_TABLE_COLUMNS			3
#define WIN_SP_COLUMN_WIDTH 			100
#define WIN_SP_COLUMN_HIGH				30

int initShowPositionWindow( HINSTANCE & );
int createShowPositionWindow( HWND & , HWND & , HINSTANCE & );
void fillShowPositionWindow( HWND & , HINSTANCE & , DHparam * );
double getXpos( DHparam * );
double getYpos( DHparam * );
double getZpos( DHparam * );
void drawRowInShowPositionWindowTable( HDC & , int , int );
void fillRowsInShowPositionWindowTable( HDC & , DHparam * );

#endif /* UI_SHOWPOSITIONWINDOW_H_ */
