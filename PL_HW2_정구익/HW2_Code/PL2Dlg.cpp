
// PL2Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "PL2.h"
#include "PL2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPL2Dlg ��ȭ ����



CPL2Dlg::CPL2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPL2Dlg::IDD, pParent)
	, expression_editbox(_T(""))
	, intermediate_code_editbox(_T(""))
	, result_editbox(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPL2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, expression_editbox);
	DDX_Text(pDX, IDC_EDIT2, intermediate_code_editbox);
	DDX_Text(pDX, IDC_EDIT3, result_editbox);
	DDX_Control(pDX, IDC_EDIT1, expression_editbox_control);
	DDX_Control(pDX, IDC_EDIT2, intermediate_code_editbox_control);
	DDX_Control(pDX, IDC_EDIT3, result_editbox_control);
}

BEGIN_MESSAGE_MAP(CPL2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPL2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPL2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CPL2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CPL2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CPL2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CPL2Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CPL2Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CPL2Dlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CPL2Dlg �޽��� ó����

BOOL CPL2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CPL2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CPL2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CPL2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//ȭ�� �����
void CPL2Dlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	//���� ���̾�α� edit box ���� �ҷ�����
	UpdateData(TRUE);
	// <�����Է�> �ʱ�ȭ
	expression_editbox.Format(_T(""));
	//<ǥ��� ��ȯ/�߰��ڵ�>
	intermediate_code_editbox.Format(_T(""));
	//<����� ���>
	result_editbox.Format(_T(""));
	//���� ���� ����
	UpdateData(FALSE);

	//���� ǥ�� �ʱ�ȭ
	if (topostfix != NULL){
		delete topostfix;
		topostfix = NULL;
	}
	//�߰� �ڵ� �ʱ�ȭ
	if (tointermediate != NULL){
		delete tointermediate;
		tointermediate = NULL;
	}
	//�ҷ��� �߰� �ڵ� �ʱ�ȭ
	if (load_intermediate != NULL){
		delete load_intermediate;
		load_intermediate = NULL;
	}


}

//���� �ҷ�����
void CPL2Dlg::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.


	//�ҷ��� ��� �����ϱ� ���� CFileDiaglog�� class 
	CFileDialog fDlg(true, _T("txt"), _T("infix.txt"), OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("�ؽ�Ʈ����(*.txt)|*.txt|"));

	//���� ��θ� �ҷ����� ���̾�α� ȣ��
	//���������� ���� ��ΰ� ��� ������
	//���� �ҷ��������
	if (IDOK == fDlg.DoModal())
	{
		//���� ��ũ����
		CFile savefile;

		//��θ� ����� ����
		CString Pathname = fDlg.GetPathName();

		//���� ���� ������ ����
		CStringA tmp;


		//�о�帰 ������ index;
		int index = 0;

		//���� ����
		if (!savefile.Open(Pathname, CFile::modeRead))
		{
			MessageBox(_T("������ ���� �����ϴ�."), _T(""), MB_OK);
			return;
		}

		//CStringA�� char�� ������ ó�� �̿��Ҷ� �ʿ��� char�� ������
		char* wheretmp;

		//���̺� ������ ũ��
		int lenfile = (int)savefile.GetLength();

		//CString class�� char�迭 ó�� ���
		//���̺� ���� ũ�� ��ŭ ���� ��
		wheretmp = tmp.GetBuffer(lenfile+1);

		//���� ���θ� ���ۿ� ��
		savefile.Read(wheretmp, lenfile);

		
		//�������� NULL�־���
		wheretmp[lenfile] = NULL;		
		
		//���� �ݱ�
		savefile.Close();

		//���� ���� ����
		tmp.ReleaseBuffer();
		
		//CStringA�� CString������
		CString tmp2(tmp);


		//���� ���̾�α� edit box ���� �ҷ�����
		UpdateData(TRUE);
		//���� �Էµ� ���ڰ� ������ �̾� ������ �ƴϸ� ����� ���� �ҷ����� ���Ҽ� �ִ�.
		if ((expression_editbox.GetLength() != 0)){
			if (MessageBox(_T("�Էµ� ���ڿ��� �ֽ��ϴ�\n�̾� ���̽ðڽ��ϱ�?"), _T(""), MB_YESNO | MB_ICONQUESTION) == IDNO){
				expression_editbox.Format(_T(""));				
			}
			//�̾� ���϶� �����ѹ� ���ְ� �̾� ����
			else{
				expression_editbox.Append(_T("\r\n"));
			}
		}
		//�о�� ������ edit box�� ����Ѵ�.
		expression_editbox.Append(tmp2);

		//����� edit box�� ����
		UpdateData(FALSE);

		//��ũ�� edit box ���������� ������
		expression_editbox_control.LineScroll(expression_editbox_control.GetLineCount());		
	}



}

//ǥ��� ��ȯ
void CPL2Dlg::OnBnClickedButton3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	//���� ���̾�α� edit box ���� �ҷ�����
	UpdateData(TRUE);
	//<�����Է�>�� �Էµ� ���� �ֳ�?
	if ((expression_editbox.GetLength() != 0)){
		//topostfix�� �ִٸ� ������ �޸� ����
		if (topostfix != NULL){
			delete topostfix;
			topostfix = NULL;
		}
		//�߰� �ڵ� �ʱ�ȭ
		if (tointermediate != NULL){
			delete tointermediate;
			tointermediate = NULL;
		}
		//�ҷ��� �߰� �ڵ� �ʱ�ȭ
		if (load_intermediate != NULL){
			delete load_intermediate;
			load_intermediate = NULL;
		}

		//InfixToPostfix class����
		topostfix = new InfixToPostfix(expression_editbox);
		//�ӽ�tmp�� <ǥ�����ȯ/�߰��ڵ�>�� ����� �޼��� �޾��
		CString tmp = topostfix->getMessage_Postfix();
		//������ ��������� �޾ƿ� �޼��� �������
		intermediate_code_editbox.Format(_T(""));
		intermediate_code_editbox.Append(tmp);
		//���� �Է¿� ������ ���� ���ٸ�
		if (topostfix->getPostfix().empty()){
			MessageBox(_T("�Էµ� ���� ���ų�, �ùٸ� ���� �ϳ��� �����ϴ�."), _T(""), MB_OK);
		}
		//��� �ڽ� �ʱ�ȭ
		result_editbox.Format(_T(""));
		//����� ���� edit�ڽ��� ����
		UpdateData(FALSE);

		//��ũ�� edit box ���������� ������
		intermediate_code_editbox_control.LineScroll(expression_editbox_control.GetLineCount());

	}
	//<�����Է�>�� �ԷµȰ� ������
	else{
		MessageBox(_T("�Էµ� ���� �����ϴ�"), _T(""), MB_OK);
	}
}

//�߰��ڵ� ����
void CPL2Dlg::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//�ı������ ��ȯ�Ǿ���?
	if (topostfix != NULL){
		//�ƹ��͵� ���� ���¿��� �ı�� ��ȯ ������ ��
		if (topostfix->getPostfix().empty()){
			MessageBox(_T("�Էµ� ��(������)�� �����ϴ�."), _T(""), MB_OK);
			return;
		}

		//���� �߰� �ڵ� �ʱ�ȭ
		if (tointermediate != NULL){
			delete tointermediate;
			tointermediate = NULL;
		}
		//�ҷ��� �߰� �ڵ� �ʱ�ȭ
		if (load_intermediate != NULL){
			delete load_intermediate;
			load_intermediate = NULL;
		}

		//PostfixToIntermediate class ����
		tointermediate = new PostfixToIntermediate(topostfix->getPostfix());
		//������ ��������� �޾ƿ� �޼��� �������
		intermediate_code_editbox.Format(_T(""));

		// �ùٸ� �����ĸ� ��� (list�� ����� �����ĵ� �ϳ��� ������ templist�� ����)
		std::list<CStringA> liststring;
		liststring = topostfix->getPostfix();

		CStringA templist;
		while (!liststring.empty())
		{
			templist.Append(liststring.front().GetString());
			templist.Append("\r\n");
			liststring.pop_front();
		}
		//templist�� intermediate_code_editbox�� �ֱ�
		CString tmp(templist);
		intermediate_code_editbox.Append(tmp);
		intermediate_code_editbox.Append(_T("\r\n"));

		//�߰��ڵ�
		CString tmp1(tointermediate->getIntermediate());
		intermediate_code_editbox.Append(tmp1);


		//��� �ڽ� �ʱ�ȭ
		result_editbox.Format(_T(""));

		//����� ���� edit�ڽ��� ����
		UpdateData(FALSE);

		//��ũ�� edit box ���������� ������
		intermediate_code_editbox_control.LineScroll(intermediate_code_editbox_control.GetLineCount());

	}
	else{
		MessageBox(_T("�Էµ� ��(������)�� �����ϴ�."), _T(""), MB_OK);
		return;
	}

}

//�߰��ڵ� ����
void CPL2Dlg::OnBnClickedButton5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//�߰��ڵ�� ��ȯ�� �� ���� ��
	if (tointermediate != NULL){
		//���� ��� �ҷ����� ���� CFileDialog class 
		CFileDialog fDlg(false, _T("txt"), _T("inteCode.txt"), OFN_OVERWRITEPROMPT, _T("�ؽ�Ʈ����(*.txt)|*.txt|"));

		//���̾�α� ȣ��
		if (IDOK == fDlg.DoModal())
		{
			//��θ� ����
			CString Pathname = fDlg.GetPathName();
			//���� ��ũ����
			CFile savefile;

			//������ ����
			if (!savefile.Open(Pathname, CFile::modeWrite | CFile::modeCreate))
			{
				MessageBox(_T("������ ���� �����ϴ�."), _T(""), MB_OK);
				return;
			}

			CStringA tmpS(tointermediate->getIntermediate());
			//���Ͽ� ����
			savefile.Write(tmpS, tmpS.GetLength());

			//���� �ݱ�
			savefile.Close();

		}

	}
	else{
		MessageBox(_T("�߰� �ڵ尡 ���� ���� �ʾҽ��ϴ�.\n(�ҷ��� �߰� �ڵ�� �������� ���մϴ�.)"), _T(""), MB_OK);
	}
}

//�߰��ڵ� �ҷ�����
void CPL2Dlg::OnBnClickedButton6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	//�ҷ��� ��� �����ϱ� ���� CFileDiaglog�� class 
	CFileDialog fDlg(true, _T("txt"), _T("inteCode.txt"), OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("�ؽ�Ʈ����(*.txt)|*.txt|"));

	//���� ��θ� �ҷ����� ���̾�α� ȣ��
	//���������� ���� ��ΰ� ��� ������
	//���� �ҷ��������
	if (IDOK == fDlg.DoModal())
	{
		//���� ��ũ����
		CFile savefile;

		//��θ� ����� ����
		CString Pathname = fDlg.GetPathName();

		//���� ���� ������ ����
		CStringA tmp;


		//�о�帰 ������ index;
		int index = 0;

		//���� ����
		if (!savefile.Open(Pathname, CFile::modeRead))
		{
			MessageBox(_T("������ ���� �����ϴ�."), _T(""), MB_OK);
			return;
		}

		//CStringA�� char�� ������ ó�� �̿��Ҷ� �ʿ��� char�� ������
		char* wheretmp;

		//���̺� ������ ũ��
		int lenfile = (int)savefile.GetLength();

		//CString class�� char�迭 ó�� ���
		//���̺� ���� ũ�� ��ŭ ���� ��
		wheretmp = tmp.GetBuffer(lenfile + 1);

		//���� ���θ� ���ۿ� ��
		savefile.Read(wheretmp, lenfile);		

		//�������� NULL�־���
		wheretmp[lenfile] = NULL;

		//���� �ݱ�
		savefile.Close();

		//���� ���� ����
		tmp.ReleaseBuffer();

		//�ε� �� �� ������ �ʱ�ȭ
		if (load_intermediate != NULL)
		{
			delete load_intermediate;
			load_intermediate = NULL;
		}
		//������ �߰��ڵ�� ������ �޸� ����
		if (tointermediate != NULL){
			delete tointermediate;
			tointermediate = NULL;
		}		
		if (topostfix != NULL){
			delete topostfix;
			topostfix = NULL;
		}

		//���̺� ���� ����
		load_intermediate = new CStringA(tmp);

		//CStringA�� CString������ (ȭ�鿡 �Ѹ��� ����)
		CString tmp2(tmp);
		//���� ���̾�α� edit box ���� �ҷ�����
		UpdateData(TRUE);

		//�о�� ������ edit box�� ����Ѵ�.

		intermediate_code_editbox.Format(_T(""));
		intermediate_code_editbox.Append(tmp2);


		//���� ��� �ʱ�ȭ
		result_editbox.Format(_T(""));

		//����� edit box�� ����
		UpdateData(FALSE);

		//��ũ�� edit box ���������� ������
		intermediate_code_editbox_control.LineScroll(intermediate_code_editbox_control.GetLineCount());
	}
}

//���� ����
void CPL2Dlg::OnBnClickedButton7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	if (tointermediate != NULL){


		//���� ���̾�α� edit box ���� �ҷ�����
		UpdateData(TRUE);

		//result editbox �ʱ�ȭ
		result_editbox.Format(_T(""));
		//Interpreter class ����
		Interpreter in(tointermediate->getIntermediate());
		//��� �޾ƿ���
		CString temp(in.getResult());
		//���
		result_editbox.Format(_T(""));
		result_editbox.Append(temp);

		//����� ���� edit�ڽ��� ����
		UpdateData(FALSE);
		//��ũ�� edit box ���������� ������
		result_editbox_control.LineScroll(result_editbox_control.GetLineCount());
		//��ũ�� edit box ���������� ������ (??? ���� ���� Intermediate ���ڷ��� �����? )
		intermediate_code_editbox_control.LineScroll(intermediate_code_editbox_control.GetLineCount());

	}
	else if (load_intermediate != NULL){
		//���� ���̾�α� edit box ���� �ҷ�����
		UpdateData(TRUE);

		//result editbox �ʱ�ȭ
		result_editbox.Format(_T(""));
		//Interpreter class ����
		Interpreter in(*load_intermediate);
		//��� �޾ƿ���
		CString temp(in.getResult());
		//���
		result_editbox.Format(_T(""));
		result_editbox.Append(temp);

		//����� ���� edit�ڽ��� ����
		UpdateData(FALSE);
		//��ũ�� edit box ���������� ������
		result_editbox_control.LineScroll(result_editbox_control.GetLineCount());
		//��ũ�� edit box ���������� ������ (??? ���� ���� Intermediate ���ڷ��� �����? )
		intermediate_code_editbox_control.LineScroll(intermediate_code_editbox_control.GetLineCount());

	}
	else{
		MessageBox(_T("�Էµ� �߰��ڵ尡 �����ϴ�."), _T(""), MB_OK);
		return;
	}

}

//������
void CPL2Dlg::OnBnClickedButton8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//���� �޼��� ����(Oncancel ȣ��)
	AfxGetMainWnd()->SendMessage(WM_COMMAND, ID_APP_EXIT, NULL);
}


void CPL2Dlg::OnCancel()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (MessageBox(_T("�����Ͻðڽ��ϱ�?"), _T(""), MB_YESNO | MB_ICONQUESTION) == IDYES){
		//���� ǥ�� �ʱ�ȭ
		if (topostfix != NULL){
			delete topostfix;
			topostfix = NULL;
		}
		//�߰� �ڵ� �ʱ�ȭ
		if (tointermediate != NULL){
			delete tointermediate;
			tointermediate = NULL;
		}
		//�ҷ��� �߰� �ڵ� �ʱ�ȭ
		if (load_intermediate != NULL){
			delete load_intermediate;
			load_intermediate = NULL;
		}
		CDialogEx::OnCancel();
	}
}
