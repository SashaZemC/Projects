// UserErrorDialog.cpp : implementation file
//

#include "pch.h"
#include "Training_English_Words_MemoryDlg_V2.h"
#include "Training_English_Words_MemoryDlg_V2Dlg.h"
#include "Training_Dialog_Panel.h"
#include "UserErrorDialog.h"
#include "afxdialogex.h"


// UserErrorDialog dialog

IMPLEMENT_DYNAMIC(UserErrorDialog, CDialog)

UserErrorDialog::UserErrorDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG8, pParent)
	, E1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON3);
}

UserErrorDialog::~UserErrorDialog()
{
}

void UserErrorDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_E1, E1);
}


BEGIN_MESSAGE_MAP(UserErrorDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &UserErrorDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// UserErrorDialog message handlers


BOOL UserErrorDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	SetIcon(m_hIcon, TRUE);	
	SetIcon(m_hIcon, FALSE);

	//messageE1 = "No errors";
	UpdateData(true);
	E1 = messageE1;
	UpdateData(false);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void UserErrorDialog::ReadErrorType(const Training_Dialog_Panel &errorObject)
{
	int error_type1 = errorObject.error_type;

	switch (error_type1)
	{
	case 0:
		messageE1 = "No errors";
		break;
	case 1:
		messageE1 = "trouble in setting file";
		break;
	case 2:
		messageE1 = "incorrect resource filename";
		break;
	}
}


void UserErrorDialog::OnBnClickedButton2()
{
	// close error window

	CDialog::OnOK();

}
