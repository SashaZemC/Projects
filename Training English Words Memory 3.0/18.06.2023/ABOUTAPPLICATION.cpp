// ABOUTAPPLICATION.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory_by_Zemtsov.h"
#include "ABOUTAPPLICATION.h"
#include "afxdialogex.h"
#include <cstdio>
#include <iostream>


// ABOUTAPPLICATION dialog

IMPLEMENT_DYNAMIC(ABOUTAPPLICATION, CDialog)

ABOUTAPPLICATION::ABOUTAPPLICATION(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ABOUTAPPLICATION, pParent)
	, EC1(_T("Hi dear user"))
{

}

ABOUTAPPLICATION::~ABOUTAPPLICATION()
{
}

void ABOUTAPPLICATION::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, EC1);
}


BEGIN_MESSAGE_MAP(ABOUTAPPLICATION, CDialog)
END_MESSAGE_MAP()


// ABOUTAPPLICATION message handlers


BOOL ABOUTAPPLICATION::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	setlocale(LC_ALL, "rus");
	bool fg1 = false; // program found the start of description in settings.txt
	CString ms;

	CStdioFile SettingFile;

	if (SettingFile.Open(L"settings.txt", CFile::modeRead))
	{
		while (SettingFile.ReadString(CStringBuffer))	//read all strings from file settings.txt
		{
			if (CStringBuffer == "AboutApplicationEND")fg1 = false;
			if (fg1)ms += CStringBuffer;
			if (CStringBuffer == "AboutApplicationSTART") fg1 = true;
			
		}
		SettingFile.Close();

		UpdateData(true);
		EC1 = ms;
		UpdateData(false);

	}
	else
	{
	/*	Training_Dialog_Panel errorObject;
		errorObject.error_type = 1;
		UserErrorDialog errorDialog;		// todo add erro algorithm
		errorDialog.ReadErrorType(errorObject);
		errorDialog.DoModal();*/
	}



	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
