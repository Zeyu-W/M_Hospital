// M_HospitalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "M_Hospital.h"
#include "M_HospitalDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CM_HospitalDlg dialog

CM_HospitalDlg::CM_HospitalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CM_HospitalDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CM_HospitalDlg)
	m_inputpath = _T("");
	m_outputpath = _T("");
	m_outputnumber = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CM_HospitalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CM_HospitalDlg)
	DDX_Control(pDX, IDC_PROGRESS1, m_Process);
	DDX_Text(pDX, Input_path, m_inputpath);
	DDX_Text(pDX, Output_path, m_outputpath);
	DDX_Text(pDX, Output_number, m_outputnumber);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CM_HospitalDlg, CDialog)
	//{{AFX_MSG_MAP(CM_HospitalDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Run, OnRun)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CM_HospitalDlg message handlers
int marker = 1;
char buffer_1[32];
char buffer_2[32];
BOOL CM_HospitalDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
FILE* con;
con = fopen("config.txt","rt+");
if(con)
{
	fgets(buffer_1,32,con);
	buffer_1[strlen(buffer_1)-2] = '\0';
	fgets(buffer_2,32,con);
	buffer_2[strlen(buffer_2)-1] = '\0';
	m_inputpath=buffer_1;
	m_outputpath=buffer_2;
	UpdateData(FALSE);
	marker=0;
}

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CM_HospitalDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CM_HospitalDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CM_HospitalDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CM_HospitalDlg::OnOK() 
{
	// TODO: Add extra validation here
	MessageBox("hello world");
	
	CDialog::OnOK();
}

void CM_HospitalDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CM_HospitalDlg::Start() 
{
	// TODO: Add your control notification handler code here
	
}

#include<stdio.h>
#include<stdlib.h>
#include <direct.h>
#include<string.h>
#include<windows.h>
#include <wchar.h>
#include <locale.h>
char* ToGBK(unsigned int ucode/*unicode码,为四个字节*/)
{     
    char* Unicode_char=new char[5];                   
    wsprintf(Unicode_char,"%wc",(wchar_t)ucode);              
    return Unicode_char;//返回gbk码
}
char cur_path[_MAX_PATH]={0};

//getcwd(cur_path,_MAX_PATH);

void CM_HospitalDlg::OnRun() 
{
	UpdateData(TRUE);
	//Change CString into char[]
    char inputpath[32]={0};
	char outputpath[32]={0};

	char file_suffix[]="\\";
	char line_feed[]="\n";
	char *point;

	point=m_inputpath.GetBuffer(m_inputpath.GetLength()); 
    m_inputpath.ReleaseBuffer(); 
	strcpy(inputpath,point);
	strcat(inputpath,file_suffix);

	point=m_outputpath.GetBuffer(m_outputpath.GetLength()); 
    m_outputpath.ReleaseBuffer(); 
	strcpy(outputpath,point);
	strcat(outputpath,file_suffix);


	//To_creat_config_file
	//char cur_path[_MAX_PATH]={0};
	//_getcwd(cur_path,_MAX_PATH);
	if(marker)
	{
	FILE *config;
	config = fopen("config.txt","ab+");
	fputs(inputpath,config);
	fputs(line_feed,config);
	fputs(outputpath,config);
	fclose(config);
	}
	
/*
	config = fopen("config_2.txt","ab+");
	//fwrite(inputpath,32,1,config);
	fwrite(outputpath,32,1,config);
	fclose(config);
*/
	//cmd_1:creat <all_file_index.txt> to store the ".e" file path
	//cmd_3:creat <all_folder_index.txt> to store the subfile name
	char cmd_1[128]="dir /b /s /a-d ";
	char cmd_3[128]="dir /b /ad ";
	char patname[]="patient_name.txt";
	char writein[]="*.e >";
	char writein_2[]=" > ";
	char target_file[]="all_file_index.txt";
	char target_file_2[]="all_folder_index.txt";
	
	strcat(cmd_1,inputpath);
	strcat(cmd_1,writein);
	//strcat(cmd_1,inputpath);

	strcat(cmd_3,inputpath);
	strcat(cmd_3,writein_2);
	//strcat(cmd_3,inputpath);

	strcat(cmd_1,target_file);
	strcat(cmd_3,target_file_2);
	system(cmd_1);
	system(cmd_3);
	//open <all_file_index.txt> as index_file
	//open <all_folder_index.txt> as folder_file
	FILE* index_file;
	char input_path[1024]="";
	//getcwd(input_path,1024);
	//strcat(input_path,inputpath);
	strcat(input_path,target_file);
	index_file = fopen(input_path,"rt+");
	char efile_path[1024]; 

	FILE* folder_file;
	char input_path_1[1024]="";
	//strcat(input_path_1,inputpath);
	strcat(input_path_1,target_file_2);
	folder_file = fopen(input_path_1,"rt+");
	char subfolder_name[1024];
	//to count the files number
	char counter_1[1024];
	char counter_2[1024];
	int file_number=0;

	while(((fgets(counter_1,1024,folder_file))&&(fgets(counter_2,1024,index_file)))!=NULL)
	{
		++file_number;
	}
	fseek(folder_file,0,SEEK_SET);
	fseek(index_file,0,SEEK_SET);
	m_Process.SetRange(0,file_number);
	m_Process.SetStep(1);
	//every row in these two files is a loop
	while(((fgets(subfolder_name,1024,folder_file))&&(fgets(efile_path,1024,index_file)))!=NULL)
	{
		m_Process.StepIt();
		char cmd_2[128]="md ";
		//char cmd_4[1024]="xcopy /E/I/Y/D ";
		char cmd_4[1024]="move /Y ";
		//get every row in two files
		char* p;
	    for(p=efile_path;!(*p=='.');++p)
		{
			char b=0;
		}
		p=p+2;
		*p='\0';
		char* q;
	    for(q=subfolder_name;!(*q=='1');++q)
		{
			char b=0;
		}
		q=q+5;
		*q='\0';
		//open the ".e" file as nicolet and get the patient's name
		FILE* nicolet;
		nicolet = fopen(efile_path,"rb");
		wchar_t pat_name[12];
		//FILE* pat_name;
		if(!nicolet)
		{
			puts("Cannot open file.");
		}
		fseek(nicolet,893406,SEEK_SET);
		int k;
		for(k = 0;k<10;++k)
		{
			fread(&pat_name[k],sizeof(unsigned short),1,nicolet);
		}
		fclose(nicolet);
		//to store the patient's name a file <patient_name.txt>
		char output_path[1024]="";

		FILE* patien_name;
		strcat(output_path,outputpath);
		strcat(output_path,patname);
		patien_name = fopen(output_path,"wb+");
		if(!patien_name)
		{
			puts("Cannot open file.");
		}
		char head[2]={(char)0xff,(char)0xfe};
		if(patien_name)
		{
			fwrite(head,2,1,patien_name);
			fwrite(pat_name,10,1,patien_name);
		}
		//get the patient's name from the file <patient_name.txt>
		fseek(patien_name,2,SEEK_SET);
		char *firstname = NULL;
		char *midname = NULL;
		char *lastname = NULL;
		char *forthname = NULL;
		char *fifthname = NULL;
		char *off = "深";
		int name=0;
		fread(&name,2,1,patien_name);
		firstname = ToGBK(name);
		fread(&name,2,1,patien_name);
		midname = ToGBK(name);
		strcat(firstname,midname);

		fread(&name,2,1,patien_name);
		lastname = ToGBK(name);
		if(*lastname==*off)
		{
		strcat(cmd_2,outputpath);
		strcat(cmd_2,firstname);
		system(cmd_2);
		}
		else
		{
		strcat(firstname,lastname);
		fread(&name,2,1,patien_name);
		forthname = ToGBK(name);
		if(*forthname==*off)
		{
		strcat(cmd_2,outputpath);
		strcat(cmd_2,firstname);
		system(cmd_2);
		}
		else
		{
		strcat(firstname,forthname);
		fread(&name,2,1,patien_name);
		fifthname = ToGBK(name);
		if(*fifthname==*off)
		{
		strcat(cmd_2,outputpath);
		strcat(cmd_2,firstname);
		system(cmd_2);
		}
		else
		{
		strcat(firstname,fifthname);
		strcat(cmd_2,outputpath);
		strcat(cmd_2,firstname);
		system(cmd_2);
		}

		}

		}
		//creat a folder named the patient's name
		//strcat(cmd_2,outputpath);
		//strcat(cmd_2,firstname);
		//system(cmd_2); 
		/*
		FILE* folder_file;
		char input_path_1[1024]=""; 
		strcat(input_path_1,inputpath);
		strcat(input_path_1,target_file_2);
		folder_file = fopen(input_path_1,"rt+");
		char subfolder_name[1024];
		fgets(subfolder_name,1024,folder_file);
		*/
		//copy the ".e" file from the inputpath to outputpath
		char output_path_1[1024]="";
		strcat(output_path_1,outputpath);
		strcat(output_path_1,firstname);
		strcat(output_path_1,"\\");
		strcat(output_path_1,subfolder_name);
		strcat(cmd_4,inputpath);
		strcat(cmd_4,subfolder_name);
		strcat(cmd_4," ");
		strcat(cmd_4,output_path_1);
		system(cmd_4); 
	}
	m_outputnumber = file_number;
	system("echo Finished");
	UpdateData(FALSE); 
}

void CM_HospitalDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	char szPath[MAX_PATH];     //store the path 
    CString str;
 
    ZeroMemory(szPath, sizeof(szPath));   
 
    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName = szPath;   
    bi.lpszTitle = "Please select the input folder:";   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //弹出选择目录对话框
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);   
 
    if(lp && SHGetPathFromIDList(lp, szPath))   
    {
        str.Format("The selected folder is: %s", szPath);
        AfxMessageBox(str); 
    }
    else   
        AfxMessageBox("Invalid path,please reselect");
	m_inputpath = szPath;
	UpdateData(FALSE);
	
}
void CM_HospitalDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
		char szPath[MAX_PATH];     //store the path 
    CString str;
 
    ZeroMemory(szPath, sizeof(szPath));   
 
    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName = szPath;   
    bi.lpszTitle = "Please select the output folder:";   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //弹出选择目录对话框
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);   
 
    if(lp && SHGetPathFromIDList(lp, szPath))   
    {
        str.Format("The selected folder is: %s",  szPath);
        AfxMessageBox(str); 
    }
    else   
        AfxMessageBox("Invalid path,please reselect");
	m_outputpath = szPath;
	UpdateData(FALSE);
}

BOOL CM_HospitalDlg::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::Create(IDD, pParentWnd);
}
