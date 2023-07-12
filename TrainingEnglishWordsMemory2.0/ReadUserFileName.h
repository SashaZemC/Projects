#pragma once


// ReadUserFileName dialog

class ReadUserFileName : public CDialog
{
	DECLARE_DYNAMIC(ReadUserFileName)

public:
	ReadUserFileName(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ReadUserFileName();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	HICON m_hIcon;

	DECLARE_MESSAGE_MAP()
private:
	CString UserInputFileName;
	CString user_input_file_name;
	//CString ms;
	//CString All_Lines;
	//CStringArray settingsArray;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	CButton WriteUserFileName;
};
