
// Training_English_Words_MemoryDlg_V2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTrainingEnglishWordsMemoryDlgV2App:
// See Training_English_Words_MemoryDlg_V2.cpp for the implementation of this class
//

class CTrainingEnglishWordsMemoryDlgV2App : public CWinApp
{
public:
	CTrainingEnglishWordsMemoryDlgV2App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTrainingEnglishWordsMemoryDlgV2App theApp;
