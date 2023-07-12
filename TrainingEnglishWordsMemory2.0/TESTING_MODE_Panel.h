#pragma once


// TESTING_MODE_Panel dialog

class TESTING_MODE_Panel : public CDialog
{
	DECLARE_DYNAMIC(TESTING_MODE_Panel)

public:
	TESTING_MODE_Panel(CWnd* pParent = nullptr);   // standard constructor
	virtual ~TESTING_MODE_Panel();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
