#pragma once


// About_Program dialog

class About_Program : public CDialog
{
	DECLARE_DYNAMIC(About_Program)

public:
	About_Program(CWnd* pParent = nullptr);   // standard constructor
	virtual ~About_Program();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
