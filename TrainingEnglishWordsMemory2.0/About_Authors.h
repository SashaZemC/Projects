#pragma once


// About_Authors dialog

class About_Authors : public CDialog
{
	DECLARE_DYNAMIC(About_Authors)

public:
	About_Authors(CWnd* pParent = nullptr);   // standard constructor
	virtual ~About_Authors();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
