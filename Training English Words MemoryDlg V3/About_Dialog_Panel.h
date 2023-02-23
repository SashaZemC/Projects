#pragma once


// About_Dialog_Panel dialog

class About_Dialog_Panel : public CDialog
{
	DECLARE_DYNAMIC(About_Dialog_Panel)

public:
	About_Dialog_Panel(CWnd* pParent = nullptr);   // standard constructor
	virtual ~About_Dialog_Panel();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	int n=2;
	afx_msg void OnBnClickedButton1();
	CStatic E2;
};
