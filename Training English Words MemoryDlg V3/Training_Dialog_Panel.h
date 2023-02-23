
#pragma once


// Training_Dialog_Panel dialog

class Training_Dialog_Panel : public CDialog
{
	DECLARE_DYNAMIC(Training_Dialog_Panel)

public:
	Training_Dialog_Panel(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Training_Dialog_Panel();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	HICON m_hIcon;

	DECLARE_MESSAGE_MAP()
private:
	virtual BOOL OnInitDialog();
	afx_msg CString Training_Dialog_Panel::Translate_checking();
	afx_msg CString Training_Dialog_Panel::Cutting_Word_From_String_number();
	afx_msg CString Training_Dialog_Panel::derivation_of_user_statistics(bool show_words_count, bool show_incorrect_words_count, int incorrect_words_counter, int translated_words_counter);
	CString E1;
	CString E2;
	CString All_Lines;
	CString buffer1, buffer2;
	CStringArray WordPairsArray;
	CStringArray settingsArray;
	CString LanguageMode;
	CString Word;
	CString Translation;
	CString ms, t, z, h;
	CString word, translate, translate_check;
	int word_pair_counter = 0;
	int arr_words_with_mistakes[20];
	char buff[20];
	bool File_control = true, Start_button_on = false;
	bool Language_Mode;
	char ch;
	int incorrect_words_counter;
	int translated_words_counter;
	afx_msg void OnMenuStart();
	afx_msg void OnMenuStop();
	afx_msg void OnMenuReset();
	afx_msg void OnMenuSettings();
	afx_msg void OnMenuChoosefilename();
	bool show_words_count;
	bool show_incorrect_words_count;
	bool show_result_window;
	bool endless_mode;
	bool repeat_word_with_mistake;
	bool fg2=true;
	bool fg1 = true;
	int buffer_counter, a;
	virtual void OnOK();
public:
	int error_type;

};
