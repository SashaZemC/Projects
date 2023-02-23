#pragma once


// UserErrorDialog dialog

class UserErrorDialog : public CDialog
{
	DECLARE_DYNAMIC(UserErrorDialog)

public:
	UserErrorDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~UserErrorDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	virtual BOOL OnInitDialog();
	CString E1;
	CString messageE1;
	afx_msg void OnBnClickedButton2();
public:
	afx_msg void ReadErrorType(const Training_Dialog_Panel &errorObject);

};
