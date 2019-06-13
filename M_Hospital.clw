; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CM_HospitalDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "M_Hospital.h"

ClassCount=3
Class1=CM_HospitalApp
Class2=CM_HospitalDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_M_HOSPITAL_DIALOG

[CLS:CM_HospitalApp]
Type=0
HeaderFile=M_Hospital.h
ImplementationFile=M_Hospital.cpp
Filter=N

[CLS:CM_HospitalDlg]
Type=0
HeaderFile=M_HospitalDlg.h
ImplementationFile=M_HospitalDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CM_HospitalDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=M_HospitalDlg.h
ImplementationFile=M_HospitalDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_M_HOSPITAL_DIALOG]
Type=1
Class=CM_HospitalDlg
ControlCount=10
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_Run,button,1342242816
Control4=Input_path,edit,1350631552
Control5=Output_path,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=Output_number,edit,1350631552
Control8=IDC_PROGRESS1,msctls_progress32,1350565888
Control9=IDC_BUTTON1,button,1342242816
Control10=IDC_BUTTON2,button,1342242816

