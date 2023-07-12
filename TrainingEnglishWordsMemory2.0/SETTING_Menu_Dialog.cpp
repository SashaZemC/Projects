// SETTING_Menu_Dialog.cpp : implementation file
//

#include "pch.h"
#include "Training_English_Words_MemoryDlg_V2.h"
#include "SETTING_Menu_Dialog.h"
#include "Training_Dialog_Panel.h"
#include "afxdialogex.h"


// SETTING_Menu_Dialog dialog

IMPLEMENT_DYNAMIC(SETTING_Menu_Dialog, CDialog)

SETTING_Menu_Dialog::SETTING_Menu_Dialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG3, pParent)
	, Show_words_count(FALSE)
	, Show_incorrect_words_count(FALSE)
	, Show_result_window(FALSE)
	, Endless_mode(FALSE)
	, Repeat_word_with_mistake(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

SETTING_Menu_Dialog::~SETTING_Menu_Dialog()
{
}

void SETTING_Menu_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Check(pDX, IDC_CHECK1, Show_words_count);
	DDX_Check(pDX, IDC_CHECK2, Show_incorrect_words_count);
	DDX_Check(pDX, IDC_CHECK3, Show_result_window);
	DDX_Check(pDX, IDC_CHECK4, Endless_mode);
	DDX_Check(pDX, IDC_CHECK5, Repeat_word_with_mistake);
}


BEGIN_MESSAGE_MAP(SETTING_Menu_Dialog, CDialog)
	ON_WM_QUERYDRAGICON()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &SETTING_Menu_Dialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// SETTING_Menu_Dialog message handlers



void SETTING_Menu_Dialog::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class


	CDialog::OnCancel();
}

BOOL SETTING_Menu_Dialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	SetIcon(m_hIcon, TRUE);	 
	SetIcon(m_hIcon, FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void SETTING_Menu_Dialog::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CStdioFile setting_file(L"settings.txt", CFile::modeWrite);

	UpdateData(true);
	show_incorrect_words_count = Show_incorrect_words_count;
	show_result_window = Show_result_window;
	show_words_count = Show_words_count;
	endless_mode = Endless_mode;
	repeat_word_with_mistake = Repeat_word_with_mistake;
	UpdateData(false);

	t.Format(L"%i", (int)show_incorrect_words_count);
	ms += t;
	ms += " ";
	t.Format(L"%i", (int)show_words_count);
	ms += t;
	ms += " ";
	t.Format(L"%i", (int)endless_mode);
	ms += t;
	ms += " ";
	t.Format(L"%i", (int)show_result_window);
	ms += t;
	ms += " ";
	t.Format(L"%i", (int)repeat_word_with_mistake);
	ms += t;

	setting_file.WriteString(ms);
	setting_file.Flush();
	setting_file.Close();


}



