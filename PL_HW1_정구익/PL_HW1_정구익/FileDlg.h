#pragma once


// CFileDlg ��ȭ �����Դϴ�.

class CFileDlg : public CDialog
{
	DECLARE_DYNAMIC(CFileDlg)

public:
	CFileDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFileDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FILEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_fileStr;			/* ���ϸ� ������ ���� */
};
