// RemoteControlDoc.cpp : implementation of the CRemoteControlDoc class
//

#include "stdafx.h"
#include "RemoteControl.h"

#include "RemoteControlDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRemoteControlDoc

IMPLEMENT_DYNCREATE(CRemoteControlDoc, CDocument)

BEGIN_MESSAGE_MAP(CRemoteControlDoc, CDocument)
END_MESSAGE_MAP()


// CRemoteControlDoc construction/destruction

CRemoteControlDoc::CRemoteControlDoc()
{
	// TODO: add one-time construction code here

}

CRemoteControlDoc::~CRemoteControlDoc()
{
}

//BOOL CRemoteControlDoc::OnNewDocument()
//{
//	if (!CDocument::OnNewDocument())
//		return FALSE;
//
//	// TODO: add reinitialization code here
//	// (SDI documents will reuse this document)
//
//	return TRUE;
//}




// CRemoteControlDoc serialization

void CRemoteControlDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CRemoteControlDoc diagnostics

#ifdef _DEBUG
void CRemoteControlDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRemoteControlDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRemoteControlDoc commands


void CRemoteControlDoc::DeleteContents()
{
	// TODO: Add your specialized code here and/or call the base class

	CDocument::DeleteContents();
}
