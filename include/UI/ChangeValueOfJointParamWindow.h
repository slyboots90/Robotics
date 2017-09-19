/*
 * ChangeValueOfJointParamWindow.h
 *
 *  Created on: 18 sep. 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef UI_CHANGEVALUEOFJOINTPARAMWINDOW_H_
#define UI_CHANGEVALUEOFJOINTPARAMWINDOW_H_

// Include UI
// Include Classes
#include "../../include/DHparam.h"
// Include libs
#include <windows.h>

#define WIN_JP_SIZE_X 			350
#define WIN_JP_SIZE_Y 			170
#define WIN_JP_LPCREATE			99

int initChangeValueOfJointParamWindow( HINSTANCE & );
int createChangeValueOfJointParamWindow( HWND & , HWND & , HINSTANCE & , WPARAM );
void fillChangeValueOfJointParamWindow( HWND & , HINSTANCE & , DHparam * , unsigned int );

#endif /* UI_CHANGEVALUEOFJOINTPARAMWINDOW_H_ */
