// RemoteControl.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "RemoteControl.h"
#include "MainFrm.h"

#include "RemoteControlDoc.h"
#include "RemoteControlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const int  iMaxUserToolbars		= 10;
const UINT uiFirstUserToolBarId	= AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId	= uiFirstUserToolBarId + iMaxUserToolbars - 1;

// CRemoteControlApp

BEGIN_MESSAGE_MAP(CRemoteControlApp, CBCGPWinApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CBCGPWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CBCGPWinApp::OnFileOpen)
END_MESSAGE_MAP()


// CRemoteControlApp construction

CRemoteControlApp::CRemoteControlApp()
{
	CBCGPVisualManagerVS2012::m_bAutoGrayscaleImages = FALSE;

	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2000, ID_VIEW_APPLOOK_2000);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_XP, ID_VIEW_APPLOOK_XP);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2003, ID_VIEW_APPLOOK_2003);
	AddVisualTheme(BCGP_VISUAL_THEME_VS_2005, ID_VIEW_APPLOOK_VS2005);
	AddVisualTheme(BCGP_VISUAL_THEME_VS_2008, ID_VIEW_APPLOOK_VS2008);
	AddVisualTheme(BCGP_VISUAL_THEME_VS_2010, ID_VIEW_APPLOOK_VS2010);
	AddVisualTheme(BCGP_VISUAL_THEME_VS_2013_LIGHT, ID_VIEW_APPLOOK_VS2013_LIGHT);
	AddVisualTheme(BCGP_VISUAL_THEME_VS_2013_DARK, ID_VIEW_APPLOOK_VS2013_DARK);
	AddVisualTheme(BCGP_VISUAL_THEME_VS_2013_BLUE, ID_VIEW_APPLOOK_VS2013_BLUE);
	AddVisualTheme(BCGP_VISUAL_THEME_DEFAULT, ID_VIEW_APPLOOK_WINDOWS_NATIVE);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2007_BLUE, ID_VIEW_APPLOOK_2007);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2007_BLACK, ID_VIEW_APPLOOK_2007_1);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2007_SILVER, ID_VIEW_APPLOOK_2007_2);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2007_AQUA, ID_VIEW_APPLOOK_2007_3);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2010_BLUE, ID_VIEW_APPLOOK_2010_1);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2010_BLACK, ID_VIEW_APPLOOK_2010_2);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2010_SILVER, ID_VIEW_APPLOOK_2010_3);
	AddVisualTheme(BCGP_VISUAL_THEME_SCENIC, ID_VIEW_APPLOOK_SCENIC);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2013_WHITE, ID_VIEW_APPLOOK_2013_1);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2013_GRAY, ID_VIEW_APPLOOK_2013_2);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2013_DARK_GRAY, ID_VIEW_APPLOOK_2013_3);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2016_COLORFUL, ID_VIEW_APPLOOK_2016_1);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2016_DARK_GRAY, ID_VIEW_APPLOOK_2016_2);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2016_WHITE, ID_VIEW_APPLOOK_2016_3);
	AddVisualTheme(BCGP_VISUAL_THEME_OFFICE_2016_BLACK, ID_VIEW_APPLOOK_2016_4);

	SetVisualTheme(BCGP_VISUAL_THEME_VS_2013_BLUE);
	
	// Remove this line if you don't need themed product dialogs:
	globalData.m_bUseVisualManagerInBuiltInDialogs = TRUE;

	// 初始化本进程的图像列表，为加载系统图标做准备
	typedef BOOL(WINAPI *pfn_FileIconInit)(BOOL fFullInit);
	pfn_FileIconInit FileIconInit = (pfn_FileIconInit)GetProcAddress(LoadLibrary("shell32.dll"), (LPCSTR)660);
	FileIconInit(TRUE);

	CString strCurPath;
	GetModuleFileName(NULL, strCurPath.GetBufferSetLength(MAX_PATH + 1), MAX_PATH);
	strCurPath.ReleaseBuffer();
	int pos = strCurPath.ReverseFind('\\');
	strCurPath = strCurPath.Left(pos);
	SetCurrentDirectory(strCurPath);

	HANDLE hFile = CreateFile("QQwry.dat", 0, 0,NULL,OPEN_EXISTING, 0, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
	    m_bIsQQwryExist = TRUE;
	}
	else
	{
		m_bIsQQwryExist = False;
	}
	CloseHandle(hFile);

	// 显示气泡
	m_bIsDisablePopTips = m_IniFile.GetInt("Settings", "PopTips", FALSE);
	m_pConnectView = NULL;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CRemoteControlApp object

CRemoteControlApp theApp;


// CRemoteControlApp initialization

BOOL CRemoteControlApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CBCGPWinApp::InitInstance();

	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("BCGP AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)

	SetRegistryBase(_T("Settings"));

	// Initialize all Managers for usage. They are automatically constructed
	// if not yet present
	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CRemoteControlDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CRemoteControlView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);



	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it
	
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// call DragAcceptFiles only if there's a suffix
	//  In an SDI app, this should occur after ProcessShellCommand

	// 启动IOCP服务器
	int nPort = m_IniFile.GetInt("Settings", "ListenPort", 83);
	if (nPort == 0)
		nPort = 83;
	int nMaxConnection = m_IniFile.GetInt("Settings", "MaxConnection",10000);
	if (nMaxConnection == 0)
		nMaxConnection = 10000;

	if (m_IniFile.GetInt("Settings", "MaxConnectionAuto"),8000)
		nMaxConnection = 8000;
	
	((CMainFrame*)m_pMainWnd)->Activate(nPort,nMaxConnection);
	return TRUE;
}

// CRemoteControlApp message handlers

int CRemoteControlApp::ExitInstance() 
{
	return CBCGPWinApp::ExitInstance();
}

// CAboutDlg dialog used for App About

class CAboutDlg : public CBCGPDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };
	CBCGPURLLinkButton m_btnURL;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CBCGPDialog(CAboutDlg::IDD)
{
	EnableVisualManagerStyle(TRUE, TRUE);
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMPANY_URL, m_btnURL);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CBCGPDialog)
	
END_MESSAGE_MAP()

// App command to run the dialog
void CRemoteControlApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CRemoteControlApp message handlers


void CRemoteControlApp::PreLoadState()
{

	GetContextMenuManager()->AddMenu(_T("My menu"), IDR_CONTEXT_MENU);

	// TODO: add another context menus here
}

