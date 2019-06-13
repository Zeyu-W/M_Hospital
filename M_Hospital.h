// M_Hospital.h : main header file for the M_HOSPITAL application
//

#if !defined(AFX_M_HOSPITAL_H__70F902B0_2C40_483B_84F3_8792D34BA3E8__INCLUDED_)
#define AFX_M_HOSPITAL_H__70F902B0_2C40_483B_84F3_8792D34BA3E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CM_HospitalApp:
// See M_Hospital.cpp for the implementation of this class
//

class CM_HospitalApp : public CWinApp
{
public:
	CM_HospitalApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CM_HospitalApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CM_HospitalApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_M_HOSPITAL_H__70F902B0_2C40_483B_84F3_8792D34BA3E8__INCLUDED_)
