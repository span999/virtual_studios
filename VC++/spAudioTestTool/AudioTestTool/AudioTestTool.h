// AudioTestTool.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#ifdef STANDARDSHELL_UI_MODEL
#include "resource.h"
#endif

// CAudioTestToolApp:
// See AudioTestTool.cpp for the implementation of this class
//

class CAudioTestToolApp : public CWinApp
{
public:
	CAudioTestToolApp();
	
// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CAudioTestToolApp theApp;
