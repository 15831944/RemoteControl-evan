// RemoteControlView.cpp : implementation of the CRemoteControlView class
//

#include "stdafx.h"
#include "RemoteControl.h"

#include "RemoteControlDoc.h"
#include "RemoteControlView.h"
#include "MainFrm.h"
#include "SettingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern CRemoteControlView* g_pConnectView;
extern CMainFrame* g_pFrame;


#define WM_MYINITIALUPDATE (WM_USER + 101)
typedef struct
{
	char *title;
	int nWidth;
}COLUMNSTRUCT;

COLUMNSTRUCT g_Column_Data[] =
{
	{"IP",				55 }, //0
	{"外网IP",			110}, //1
	{"内网IP",			110}, //2
	{"计算机名/备注",	100}, //3
	{"操作系统",			70 }, //4
	{"处理器",			80 }, //5
	{"延迟",				40 }, //6
	{"摄像头",			50 }, //7
	{"上线标识",			60 }, //8
	{"DDOS",			50 }, //9
	{"区域",				100}, //10
};


int g_Column_Width = 0;
int g_Column_Count = (sizeof(g_Column_Data) / 8);
// CRemoteControlView

IMPLEMENT_DYNCREATE(CRemoteControlView, CListView)

BEGIN_MESSAGE_MAP(CRemoteControlView, CListView)
	ON_REGISTERED_MESSAGE(BCGM_CHANGEVISUALMANAGER, OnChangeVisualManager)
	ON_MESSAGE(WM_MYINITIALUPDATE, &CRemoteControlView::OnMyinitialupdate)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CRemoteControlView construction/destruction

CRemoteControlView::CRemoteControlView()
{
	// TODO: add construction code here

	((CRemoteControlApp*)AfxGetApp())->m_pConnectView = this;
	m_pListCtrl = NULL;
}

CRemoteControlView::~CRemoteControlView()
{
}

BOOL CRemoteControlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= LVS_REPORT;
	return CListView::PreCreateWindow(cs);
}

void CRemoteControlView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	
	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().

	NONCLIENTMETRICS ncm;
	memset(&ncm, 0, sizeof(NONCLIENTMETRICS));
	ncm.cbSize = sizeof(NONCLIENTMETRICS);

	VERIFY(::SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(NONCLIENTMETRICS), &ncm, 0));
	ncm.lfMessageFont.lfWeight = 500;

	m_pListCtrl = &GetListCtrl();
	HIMAGELIST hImageListSmall = NULL;
	Shell_GetImageLists(NULL, &hImageListSmall);
	ListView_SetImageList(m_pListCtrl->m_hWnd, hImageListSmall, LVSIL_SMALL);

	m_pListCtrl->SetExtendedStyle(LVIF_PARAM | LVS_EX_FULLROWSELECT |
		LVS_EX_ONECLICKACTIVATE | LVS_EX_UNDERLINEHOT | LVS_EX_SUBITEMIMAGES);

	for (int i = 0;i < g_Column_Count;i++)
	{
		m_pListCtrl->InsertColumn(i, g_Column_Data[i].title);
		m_pListCtrl->SetColumnWidth(i, g_Column_Data[i].nWidth);
		g_Column_Width += g_Column_Data[i].nWidth;
	}

	PostMessage(WM_MYINITIALUPDATE, 0, 0);
}


// CRemoteControlView diagnostics

#ifdef _DEBUG
void CRemoteControlView::AssertValid() const
{
	CListView::AssertValid();
}

void CRemoteControlView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CRemoteControlDoc* CRemoteControlView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRemoteControlDoc)));
	return (CRemoteControlDoc*)m_pDocument;
}
#endif //_DEBUG


// CRemoteControlView message handlers
LRESULT CRemoteControlView::OnChangeVisualManager(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	return 0;
}


afx_msg LRESULT CRemoteControlView::OnMyinitialupdate(WPARAM wParam, LPARAM lParam)
{
	CRemoteControlView* pView = this;
	((CMainFrame*)AfxGetApp()->m_pMainWnd)->AddView("主界面", this, "Connections Users");

	CSettingView *pSettingView = new CSettingView;
	((CWnd*)pSettingView)->Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), AfxGetApp()->GetMainWnd(), AFX_IDW_PANE_FIRST, NULL);
	((CMainFrame*)AfxGetApp()->m_pMainWnd)->AddView("配置服务端", pSettingView, "配置服务端");
	((CMainFrame*)AfxGetApp()->m_pMainWnd)->SetCurView(0);
	return 0;
}


void CRemoteControlView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CListView::OnRButtonDown(nFlags, point);

	CMenu popup;
	popup.LoadMenu(IDR_LIST);
	CMenu* pM = popup.GetSubMenu(0);
	CPoint p;
	GetCursorPos(&p);
	int count = pM->GetMenuItemCount();
	pM->EnableMenuItem(count - 1, MF_BYPOSITION | MF_ENABLED);
	pM->TrackPopupMenu(TPM_LEFTALIGN, p.x, p.y, this);
}
