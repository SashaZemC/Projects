// About_Dialog_Panel.cpp : implementation file
//

#include "pch.h"
#include "Training_English_Words_MemoryDlg_V2.h"
#include "About_Dialog_Panel.h"
#include "afxdialogex.h"


// About_Dialog_Panel dialog

IMPLEMENT_DYNAMIC(About_Dialog_Panel, CDialog)

About_Dialog_Panel::About_Dialog_Panel(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
{

}

About_Dialog_Panel::~About_Dialog_Panel()
{
}

void About_Dialog_Panel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_E2, E2);
}


BEGIN_MESSAGE_MAP(About_Dialog_Panel, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &About_Dialog_Panel::OnBnClickedButton1)
END_MESSAGE_MAP()


// About_Dialog_Panel message handlers

void About_Dialog_Panel::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	if ((n == 1)) {
		E2.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP2)));
		n++;
	}
	else if ((n == 2)) {
		E2.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP3)));
		n++;
	}
	else if ((n == 3)) {
		E2.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP4)));
		n++;
	}
	else if ((n == 4)) {
		E2.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP5)));
		n = 1;
	}
}

