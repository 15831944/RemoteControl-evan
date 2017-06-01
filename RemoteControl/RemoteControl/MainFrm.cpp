// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "RemoteControl.h"
#include "MainFrm.h"

#include "RemoteControlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame
#define WM_ICON_NOTIFY WM_USER+10

CRemoteControlView  *g_pConnectView = NULL; // 在NotifyProc中初始化

CString              m_PassWord = "password";
CMainFrame           *g_pFrame;


IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_REGISTERED_MESSAGE(BCGM_RESETTOOLBAR, OnToolbarReset)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_STATUSIP,           // status line indicator
	ID_STATUSSPEED,
	ID_STATUSPORT,
	ID_STATUSCOUNT
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	g_pFrame = this;
}

CMainFrame::~CMainFrame()
{
}

void CMainFrame::Activate(UINT nPort, UINT nMaxConnections)
{
	CString str;


}
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	this->CenterWindow(CWnd::GetDesktopWindow());

	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// Status Bar
	m_wndStatusBar.SetPaneInfo(0, m_wndStatusBar.GetItemID(0), SBPS_STRETCH,200 );
	m_wndStatusBar.SetPaneInfo(1, m_wndStatusBar.GetItemID(1), SBPS_NORMAL, 160);
	m_wndStatusBar.SetPaneInfo(2, m_wndStatusBar.GetItemID(2), SBPS_NORMAL, 70);
	m_wndStatusBar.SetPaneInfo(3, m_wndStatusBar.GetItemID(3), SBPS_NORMAL, 80);

	if (!m_wndTab.Create(WS_CHILD|WS_VISIBLE|CTCS_AUTOHIDEBUTTONS|CTCS_TOOLTIPS|CTCS_DRAGMOVE|CTCS_LEFT,CRect(0,0,0,18),
		this,
		IDC_TABCTRL))
	{
		TRACE0("Failed to create tab control\n");
		return -1;
	}

	m_wndTab.SetDragCursors(AfxGetApp()->LoadStandardCursor(IDC_CROSS), NULL);
	m_wndTab.ModifyStyle(CTCS_LEFT, 0, 0);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style &= ~FWS_ADDTOTITLE;
	return TRUE;
}


// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame message handlers




LRESULT CMainFrame::OnToolbarReset(WPARAM /*wp*/,LPARAM)
{
	// TODO: reset toolbar with id = (UINT) wp to its initial state:
	//
	// UINT uiToolBarId = (UINT) wp;
	// if (uiToolBarId == IDR_MAINFRAME)
	// {
	//		do something with m_wndToolBar
	// }

	return 0;
}

