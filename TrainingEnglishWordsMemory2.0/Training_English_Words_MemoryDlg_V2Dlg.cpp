
// Training_English_Words_MemoryDlg_V2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Training_English_Words_MemoryDlg_V2.h"
#include "Training_English_Words_MemoryDlg_V2Dlg.h"
#include "afxdialogex.h"
#include "Training_Dialog_Panel.h"
#include "About_Dialog_Panel.h"
#include "About_Program.h"
#include "About_Authors.h"
#include "TESTING_MODE_Panel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTrainingEnglishWordsMemoryDlgV2Dlg dialog



CTrainingEnglishWordsMemoryDlgV2Dlg::CTrainingEnglishWordsMemoryDlgV2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TRAINING_ENGLISH_WORDS_MEMORYDLG_V2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrainingEnglishWordsMemoryDlgV2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTrainingEnglishWordsMemoryDlgV2Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTrainingEnglishWordsMemoryDlgV2Dlg::OnBnClickedButton1)

	ON_COMMAND(ID_ABOUT_QUICKGUIDE, &CTrainingEnglishWordsMemoryDlgV2Dlg::OnAboutQuickguide)
	ON_COMMAND(ID_ABOUT_ABOUTPROGRAM, &CTrainingEnglishWordsMemoryDlgV2Dlg::OnAboutAboutprogram)
	ON_COMMAND(ID_ABOUT_AUTHORS, &CTrainingEnglishWordsMemoryDlgV2Dlg::OnAboutAuthors)
	ON_BN_CLICKED(IDC_BUTTON2, &CTrainingEnglishWordsMemoryDlgV2Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CTrainingEnglishWordsMemoryDlgV2Dlg message handlers

BOOL CTrainingEnglishWordsMemoryDlgV2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTrainingEnglishWordsMemoryDlgV2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTrainingEnglishWordsMemoryDlgV2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTrainingEnglishWordsMemoryDlgV2Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	Training_Dialog_Panel nTrainingPanel;
	nTrainingPanel.DoModal();
}


void CTrainingEnglishWordsMemoryDlgV2Dlg::OnAboutQuickguide()
{
	// TODO: Add your command handler code here
	About_Dialog_Panel nAboutPanel;
	nAboutPanel.DoModal();
}




void CTrainingEnglishWordsMemoryDlgV2Dlg::OnAboutAboutprogram()
{
	// TODO: Add your command handler code here
	About_Program nAboutProgamPanel;
	nAboutProgamPanel.DoModal();
}


void CTrainingEnglishWordsMemoryDlgV2Dlg::OnAboutAuthors()
{
	// TODO: Add your command handler code here
	About_Authors nAboutAuthorsPanel;
	nAboutAuthorsPanel.DoModal();
}


void CTrainingEnglishWordsMemoryDlgV2Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	TESTING_MODE_Panel nTESTING_MODE_Panel;
	nTESTING_MODE_Panel.DoModal();
}
