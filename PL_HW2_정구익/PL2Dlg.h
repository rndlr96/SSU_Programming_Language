
// PL2Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include <list>

// CPL2Dlg ��ȭ ����
class CPL2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CPL2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PL2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//ȭ�� �����
	afx_msg void OnBnClickedButton1();
	//���� �ҷ�����
	afx_msg void OnBnClickedButton2();
	//ǥ��� ��ȯ
	afx_msg void OnBnClickedButton3();
	//�߰��ڵ� ����
	afx_msg void OnBnClickedButton4();
	//�߰��ڵ� ����
	afx_msg void OnBnClickedButton5();
	//�߰��ڵ� �ҷ�����
	afx_msg void OnBnClickedButton6();
	//���� ����
	afx_msg void OnBnClickedButton7();
	//������
	afx_msg void OnBnClickedButton8();


	// <�����Է�>
	CString expression_editbox;
	//<ǥ��� ��ȯ/�߰��ڵ�>
	CString intermediate_code_editbox;
	//<����� ���>
	CString result_editbox;
	// <�����Է�> ��Ʈ��
	CEdit expression_editbox_control;
	// <ǥ��� ��ȯ/�߰��ڵ�> ��Ʈ��
	CEdit intermediate_code_editbox_control;
	// <����� ���> ��Ʈ��
	CEdit result_editbox_control;

	//InfixToPostfix Class -> ���� ǥ������ ���� ǥ�������� �ٲ��ִ� class
	//������ ���ڷ� �����Է��� ���ڿ��� �ѱ��.
	//�̰����� �������� ���� üũ ���.
	InfixToPostfix *topostfix=NULL;
	//PostfixToIntermediate class-> ���� ǥ������ �߰� �ڵ�� �ٲ��ִ� class
	//�����ڷ� InfixToPostfix Class���� ���� list<CStringA>(����ǥ��� ���پ� �� �ִ�)�� �޴´�.
	PostfixToIntermediate *tointermediate = NULL;
	//load_intermediate class -> ���Ϸκ��� ���� �о�� �߰� �ڵ带 �����ϴ� CStringA
	CStringA *load_intermediate = NULL;

	//���� ������ ȣ���
	virtual void OnCancel();
};
