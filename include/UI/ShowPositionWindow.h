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

#define WIN_SP_SIZE_X 			600
#define WIN_SP_SIZE_Y 			400

int initShowPositionWindow( HINSTANCE & );
int createShowPositionWindow( HWND & , HWND & , HINSTANCE & , DHparam * );
void fillShowPositionWindow( HWND & , HINSTANCE & , DHparam * );
double getXpos( DHparam * );
double getYpos( DHparam * );
double getZpos( DHparam * );

#endif /* UI_SHOWPOSITIONWINDOW_H_ */
