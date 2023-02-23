#pragma once

// SETTING_Menu_Dialog dialog

class SETTING_Menu_Dialog : public CDialog
{
	DECLARE_DYNAMIC(SETTING_Menu_Dialog)

public:
	SETTING_Menu_Dialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SETTING_Menu_Dialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation

	DECLARE_MESSAGE_MAP()
private:
	HICON m_hIcon;
	virtual void OnCancel();
	afx_msg void OnBnClickedButton1();	
	BOOL Show_words_count;
	BOOL Show_incorrect_words_count;
	BOOL Show_result_window;
	BOOL Endless_mode;
	BOOL Repeat_word_with_mistake;
	bool show_words_count;
	bool show_incorrect_words_count;
	bool show_result_window;
	bool endless_mode;
	bool repeat_word_with_mistake;
	CString ms, t;
public:
	virtual BOOL OnInitDialog();
};
