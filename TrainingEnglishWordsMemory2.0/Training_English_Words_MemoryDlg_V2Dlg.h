
// Training_English_Words_MemoryDlg_V2Dlg.h : header file
//

#pragma once


// CTrainingEnglishWordsMemoryDlgV2Dlg dialog
class CTrainingEnglishWordsMemoryDlgV2Dlg : public CDialog
{
// Construction
public:
	CTrainingEnglishWordsMemoryDlgV2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRAINING_ENGLISH_WORDS_MEMORYDLG_V2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnAboutQuickguide();
//	virtual void OnCancel();
	afx_msg void OnAboutAboutprogram();
	afx_msg void OnAboutAuthors();
	afx_msg void OnBnClickedButton2();


};
