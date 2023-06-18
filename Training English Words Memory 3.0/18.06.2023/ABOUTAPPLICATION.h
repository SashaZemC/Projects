#pragma once


// ABOUTAPPLICATION dialog

class ABOUTAPPLICATION : public CDialog
{
	DECLARE_DYNAMIC(ABOUTAPPLICATION)

public:
	ABOUTAPPLICATION(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ABOUTAPPLICATION();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTAPPLICATION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CString EC1;
	CString CStringBuffer;
	virtual BOOL OnInitDialog();
};
