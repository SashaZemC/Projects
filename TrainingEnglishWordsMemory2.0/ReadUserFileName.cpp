// ReadUserFileName.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Training_English_Words_MemoryDlg_V2.h"
#include "ReadUserFileName.h"
#include "afxdialogex.h"
#include <iostream>


// ReadUserFileName dialog

IMPLEMENT_DYNAMIC(ReadUserFileName, CDialog)

ReadUserFileName::ReadUserFileName(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG7, pParent)
	, UserInputFileName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON4);
}

ReadUserFileName::~ReadUserFileName()
{
}

void ReadUserFileName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, UserInputFileName);
	DDX_Control(pDX, IDC_BUTTON1, WriteUserFileName);
}


BEGIN_MESSAGE_MAP(ReadUserFileName, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &ReadUserFileName::OnBnClickedButton1)
END_MESSAGE_MAP()

BOOL ReadUserFileName::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	WriteUserFileName.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP6)));

	SetIcon(m_hIcon, TRUE);	 
	SetIcon(m_hIcon, FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
// ReadUserFileName message handlers


void ReadUserFileName::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	CString ms;
	CString All_Lines;
	CStringArray settingsArray;

	UpdateData(true);
	user_input_file_name = UserInputFileName;
	UpdateData(false);

	CStdioFile read_setting_file(L"settings.txt", CFile::modeRead); 
	while (read_setting_file.ReadString(All_Lines))
	{
		settingsArray.Add(All_Lines);
	}
	read_setting_file.Close();

	ms = user_input_file_name;
	if (!((user_input_file_name[user_input_file_name.GetLength() - 1] == 't') && (user_input_file_name[user_input_file_name.GetLength() - 2] == 'x') &&
		(user_input_file_name[user_input_file_name.GetLength() - 3] == 't') && (user_input_file_name[user_input_file_name.GetLength() - 4] == '.')))ms += ".txt";
	
	settingsArray[1] = ms; 
	ms = settingsArray[0];
	for (int i = 1; i < settingsArray.GetSize(); i++)
	{
		ms += "\n";
		ms += settingsArray[i];
	}

	CStdioFile write_setting_in_file(L"recreate.txt", CFile::modeCreate | CFile::modeWrite);
	write_setting_in_file.WriteString(ms);     
	write_setting_in_file.Flush();              
	write_setting_in_file.Close();             
	remove("settings.txt");					   
	rename("recreate.txt", "settings.txt");                  

}



