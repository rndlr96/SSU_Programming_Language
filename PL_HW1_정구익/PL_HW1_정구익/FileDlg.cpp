// FileDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TicTacToe.h"
#include "FileDlg.h"
#include "afxdialogex.h"


// CFileDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFileDlg, CDialog)

CFileDlg::CFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileDlg::IDD, pParent)
{
	m_fileStr = _T("");
}

CFileDlg::~CFileDlg()
{

}

void CFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILE, m_fileStr);
}


BEGIN_MESSAGE_MAP(CFileDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CFileDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CFileDlg �޽��� ó�����Դϴ�.


void CFileDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	CDialog::OnOK();
}
