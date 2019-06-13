// M_HospitalDlg.h : header file
//

#if !defined(AFX_M_HOSPITALDLG_H__332059FE_4A57_47D6_9382_1059E9C008F0__INCLUDED_)
#define AFX_M_HOSPITALDLG_H__332059FE_4A57_47D6_9382_1059E9C008F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CM_HospitalDlg dialog

class CM_HospitalDlg : public CDialog
{
// Construction
public:
	CM_HospitalDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CM_HospitalDlg)
	enum { IDD = IDD_M_HOSPITAL_DIALOG };
	CProgressCtrl	m_Process;
	CString	m_inputpath;
	CString	m_outputpath;
	int		m_outputnumber;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CM_HospitalDlg)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CM_HospitalDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void Start();
	afx_msg void OnStart();
	afx_msg void OnRun();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_M_HOSPITALDLG_H__332059FE_4A57_47D6_9382_1059E9C008F0__INCLUDED_)
