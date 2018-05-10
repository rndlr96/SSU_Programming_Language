
// TOYDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "TOY.h"
#include "TOYDlg.h"
#include "afxdialogex.h"

#include "MyToy.h"
#include "MyStack.h"
#include "MyFunc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



MyFunc *functions[MAX_FUNC];
int functionNum = 0;





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


// CTOYDlg ��ȭ ����



CTOYDlg::CTOYDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTOYDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTOYDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTOYDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTOYDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTOYDlg::OnBnClickedButton2)
//	ON_BN_CLICKED(IDC_BUTTON3, &CTOYDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTOYDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CTOYDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CTOYDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CTOYDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON9, &CTOYDlg::OnBnClickedButton9)

	ON_BN_CLICKED(IDC_BUTTON8, &CTOYDlg::OnBnClickedButton8)

	ON_BN_CLICKED(IDC_BUTTON10, &CTOYDlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CTOYDlg �޽��� ó����

BOOL CTOYDlg::OnInitDialog()
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

	initDefun();

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CTOYDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTOYDlg::OnPaint()
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
HCURSOR CTOYDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//ȭ�� �����
void CTOYDlg::OnBnClickedButton1()
{
	//edit control ���� 
	CEdit *textBox;
	textBox = (CEdit*)GetDlgItem(IDC_EDIT1);
	//��ü ���� �� �����
	textBox->SetSel(0, -1);
	textBox->Clear();
}

//���α׷� �ε�
void CTOYDlg::OnBnClickedButton2()
{
	ULONGLONG length;
	char buff[256] = { 0 };
	//���� �ҷ����� ��ȭ����
	CFileDialog dlgaFile(TRUE, _T("txt"), _T("pre*.txt"), OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, NULL);
	dlgaFile.m_ofn.lpstrFilter = _T("Text File(*.txt)");

	//���ϳ��� �о����
	if (IDOK == dlgaFile.DoModal()) {

		CString strPathName = dlgaFile.GetPathName();
		CFile file;
		file.Open(strPathName, CFile::modeRead);
		length = file.GetLength();
		file.Read(buff, length*sizeof(char));
		file.Close();

		//edit control ���� 
		CEdit *textBox;
		textBox = (CEdit*)GetDlgItem(IDC_EDIT1);
		//���� ���� ����
		textBox->SetWindowTextW(CA2W(buff));
	}
}

//���� �޼��� ���
void printErr(int errNum,int row){
	char message[100] = { 0 };
	if (errNum == LEFT_ERR){
		sprintf(message, "%d��° ���� ( ��ġ�� �߸��Ǿ����ϴ�.",row+1);
		AfxMessageBox(CA2W(message));
	}
	else if (errNum == RIGHT_ERR){
		sprintf(message, "%d���� ���� ) ��ġ�� �߸��Ǿ����ϴ�.", row + 1);
		AfxMessageBox(CA2W(message));
	}
	else if (errNum == REAL_ERR){
		sprintf(message, "%d���� ���� �ǿ����ڰ� �Ǽ� �Դϴ�.", row + 1);
		AfxMessageBox(CA2W(message));
	}
	else if (errNum == NEGATIVE_ERR){
		sprintf(message, "%d���� ���� �ǿ����ڿ� -��ȣ�� �ݺ��Ǿ����ϴ�.", row + 1);
		AfxMessageBox(CA2W(message));
	}
	else if (errNum == UNDEFINE_ERR){
		sprintf(message, "%d���� ���� �����ڴ� ���� ������ �Դϴ�.", row + 1);
		AfxMessageBox(CA2W(message));
	}
	else if (errNum == DEFAULT_ERR){
		sprintf(message, "%d���� �࿡ �߸��� ���ڰ� �������ϴ�.", row + 1);
		AfxMessageBox(CA2W(message));
	}
	else if (errNum == COUNT_ERR){
		sprintf(message, "%d���� ���� �ǿ������� ������ �߸��Ǿ����ϴ�.", row + 1);
		AfxMessageBox(CA2W(message));
	}
	else if (errNum == NOOP_ERR){
		sprintf(message, "%d���� ���� �����ڰ� �����ϴ�.", row + 1);
		AfxMessageBox(CA2W(message));
	}
}



//�߰��ڵ� ����
void CTOYDlg::OnBnClickedButton4()
{
	MyToy *toy[10];

	CString tmpinput;
	char input[256] = { 0 };
	char output[500] = { 0 };
	char *token;
	int pc = 0;
	int errNum = 0;

	//edit control ����
	CEdit *textBox;
	textBox = (CEdit*)GetDlgItem(IDC_EDIT1);
	textBox->LineScroll(textBox->GetLineCount());
	textBox->GetWindowTextW(tmpinput);

	for (int i = 0; i < tmpinput.GetLength(); i++){
		input[i] = tmpinput.GetAt(i);
	}

	//���� ������ ��ū
	token = strtok(input, "\r\n");
	while (token != NULL){
		toy[pc] = new MyToy(token);
		pc++;
		token = strtok(NULL, "\r\n");
	}

	// output buff set
	strcat(output, "+ PROCESS DESCRTION\r\n");
	//toy1���� ����ߴ� toPre�Լ� �Ͽ�
	for (int i = 0; i < pc; i++){
		errNum = checkErr(toy[i]);
		if (errNum == 0){
			strcat(output, toPre(toy[i]));
			strcat(output, "\r\n");
		}
		//else
			//printErr(errNum, i);
	}
	strcat(output, "\r\n");
	strcat(output, "+ INTERMEDIATE CODE\r\n");
	//�߰��ڵ� ���� �Լ� toInter���
	for (int i = 0; i < pc; i++){
		errNum = checkErr(toy[i]);
		if (errNum == 0){
			strcat(output, "begin\r\n");
			strcat(output, toInter(toy[i]));
			strcat(output, "end\r\n\r\n");
		}
		else
			printErr(errNum, i);
	}
	if (errNum == 0)
		textBox->SetWindowTextW(CA2W(output));

}

//�߰��ڵ� ����
void CTOYDlg::OnBnClickedButton5()
{
	CString tmpinput;
	char input[500] = { 0 };

	//edit control ����
	CEdit *textBox;
	textBox = (CEdit*)GetDlgItem(IDC_EDIT1);

	textBox->GetWindowTextW(tmpinput);

	for (int i = 0; i < tmpinput.GetLength(); i++){
		input[i] = tmpinput.GetAt(i);
	}

	CFileDialog dlgFile(FALSE, _T("txt"), _T("inter*.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL);
	dlgFile.m_ofn.lpstrFilter = _T("Text File(*.txt)");

	if (IDOK == dlgFile.DoModal()) {
		CString strPathName = dlgFile.GetPathName();
		CFile file;
		file.Open(strPathName, CFile::modeWrite | CFile::modeCreate);
		file.Write(input,strlen(input));

		file.Close();
	}
	
}


//�߰��ڵ� �ε�
void CTOYDlg::OnBnClickedButton6()
{
	ULONGLONG length;
	char buff[500] = { 0 };
	//���� �ҷ����� ��ȭ����
	CFileDialog dlgaFile(TRUE, _T("txt"), _T("inter*.txt"), OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, NULL);
	dlgaFile.m_ofn.lpstrFilter = _T("Text File(*.txt)");


	//���ϳ��� �о����
	if (IDOK == dlgaFile.DoModal()) {

		CString strPathName = dlgaFile.GetPathName();
		CFile file;
		file.Open(strPathName, CFile::modeRead);
		length = file.GetLength();
		file.Read(buff, length*sizeof(char));
		file.Close();

		//edit control ���� 
		CEdit *textBox;
		textBox = (CEdit*)GetDlgItem(IDC_EDIT1);
		//���� ���� ����
		textBox->SetWindowTextW(CA2W(buff));
	}
}

//����
void CTOYDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here

	CString tmpinput;
	char input[500] = { 0 };
	char output[500] = { 0 };
	int pc = 0;

	//edit control ����
	CEdit *textBox;
	textBox = (CEdit*)GetDlgItem(IDC_EDIT1);

	textBox->GetWindowTextW(tmpinput);

	textBox->SetSel(0, -1);
	textBox->Clear();


	//����� ����
	MyStack *preStack = new MyStack();
	//����� ����
	MyStack *postStack = new MyStack();
	//����� ����
	MyStack *outputStack = new MyStack();
	char tmpStackItem[40] = { 0 };

	for (int i = 0; i < tmpinput.GetLength(); i++){
		input[i] = tmpinput.GetAt(i);
		output[i] = tmpinput.GetAt(i);
	}

	char *token = strtok(input, "\r\n\0");
	//����� ���ÿ� ����
	while (token != NULL){
		//����� push �����ϰ� ���ڸ� ����
		if (strncmp(token, "push", 4) == 0)
			preStack->push(token + 5);
		else if (strcmp(token, "begin") == 0){
			preStack->push(token);
			//�Էµ� �� ���� ī��Ʈ
			pc++;
		}
		else
			preStack->push(token);
		token = strtok(NULL, "\r\n\0");
	}
	//�Էµ� �� ���� ��ŭ
	for (int i = 0; i<pc; i++){
		while (true){
			char tmp[10] = { 0 };
			strcpy(tmp, preStack->pop());
			//�����ڸ� pop�ι� ������ push
			if (strcmp(tmp, "IF") == 0){
				char test[10] = { 0 };
				//toyValue�Լ� ���
				strcpy(test, toyValue("IF", postStack->pop(), postStack->pop()));
				postStack->push(test);
			}
			else if (strcmp(tmp, "MINUS") == 0){
				char test[10] = { 0 };
				strcpy(test, toyValue("MINUS", postStack->pop(), postStack->pop()));
				postStack->push(test);
			}

			else if (strcmp(tmp, "MOD") == 0) {
				char test[10] = { 0 };
				strcpy(test, toyValue("MOD", postStack->pop(), postStack->pop()));
				postStack->push(test);
			}

			else if (strcmp(tmp, "FACTORIAL") == 0) {
				char test[10] = { 0 };
				strcpy(test, toyValue("FACTORIAL", postStack->pop(), NULL));
				postStack->push(test);
			}

			else if (strcmp(tmp, "end") == 0)
				;
			//begin�̸� �� �� ����
			else if (strcmp(tmp, "begin") == 0)
				break;
			//�ǿ����� push
			else
				postStack->push(tmp);
		}
		//����� �Ųٷ� �Ǳ� ������ ��� ���ÿ� ����
		strcpy(tmpStackItem, postStack->pop());
		strcat(tmpStackItem, "\r\n");
		outputStack->push(tmpStackItem);
	}
	//��� �迭�� ��� ���ó��� ����
	strcat(output, "+ RESULT\r\n");
	int size = outputStack->size();
	for (int i = 0; i < size; i++){
		strcat(output, outputStack->pop());
	}

	textBox->SetWindowTextW(CA2W(output));
}

void CTOYDlg::initDefun()
{
	// TODO: Add your control notification handler code here


	char buff[1000] = { 0 };
	CFile file;
	file.Open(_T("defun.txt"), CFile::modeRead);
	int length = file.GetLength();
	file.Read(buff, length*sizeof(char));
	file.Close();

	//function�ʱ�ȭ
	char *token = strtok(buff, "\r\n");
	while (token != NULL){
		char *tmp = new char[strlen(token)];
		memset(tmp, 0, strlen(token));
		strcpy(tmp, token);
		functions[functionNum] = new MyFunc(tmp);
		functionNum++;
		token = strtok(NULL, "\r\n\0");
	}

}


/*

* MyToy ��ü�� ������
* defun�� ������ �˻��� �ʿ䰡 �־
* ���������� ����ϱ� ������
* cpp������ ���� ���� �ʰ� ���� ���Ͽ� ����

*/



MyToy::MyToy(){
	//��� �ʱ�ȭ
	lcount = 0;
	rcount = 0;
	type = 0;
	operand1 = NULL;
	operand2 = NULL;
	memset(value, 0, sizeof(char) * 10);
	memset(op, 0, sizeof(char) * 10);
	errNumber = 0;

	for (int i = 0; i < MAX_TOKEN; i++){
		tokenTable[i] = NULL;
		tokenType[i] = 0;
	}
	tokenNum = 0;
}

MyToy::MyToy(char *input){
	lcount = 0;
	rcount = 0;
	type = 0;
	operand1 = NULL;
	operand2 = NULL;
	memset(value, 0, sizeof(char) * 10);
	memset(op, 0, sizeof(char) * 10);
	errNumber = 0;

	for (int i = 0; i < MAX_TOKEN; i++){
		tokenTable[i] = NULL;
		tokenType[i] = 0;
	}
	tokenNum = 0;

	//�Ľ�, tokenTable �ϼ�
	lexicalAnalysis(input);

	//defun�Լ��� ���Ǿ�����, �� index���� errNumber
	while (errNumber > 0){
		int index;
		//function���� Ȯ��
		for (int i = 0; i < functionNum; i++){
			if (strcmp(tokenTable[errNumber], functions[i]->op) == 0)
				index = i;
		}

		//tmpopr ������ �迭�� function�� ���ǵǾ��ִ�
		//opernads��ŭ tokenTable�� ����
		char *tmpopr[MAX_OPR];
		int next = errNumber + 1;
		for (int i = 0; i < functions[index]->oprNum; i++){
			//operand�� ���ڸ� �״�� ����
			if (tokenType[next] == 3){
				tmpopr[i] = new char[strlen(tokenTable[next])];
				memset(tmpopr[i], 0, strlen(tokenTable[next]));
				strcpy(tmpopr[i], tokenTable[next]);
				next++;
			}
			//operand�� �Լ��� () ��ȣ ���ڿ� ����
			else if (tokenType[next] == 1){
				int j = next;
				tmpopr[i] = new char[100];
				memset(tmpopr[i], 0, 100);
				int count = 0;
				while (j < tokenNum){
					if (tokenType[j] == 1)
						count++;
					else if (tokenType[j] == 2)
						count--;

					strcat(tmpopr[i], tokenTable[j]);
					strcat(tmpopr[i], " ");
					if (count == 0)
						break;
					j++;
				}
				next =j+1;
			}
			else{
				errNumber = COUNT_ERR;
				break;
			}
		}

		//errnumber���� 
		//tmpopr����
		
		//defun�� �Լ��� �Լ��������� ��ū���� ������ ���ڿ� 
		char interner[256] = { 0 };
		for (int i = 0; i < errNumber; i++){
			//defun �Լ� ���̱� �������� �״��
			strcat(interner, tokenTable[i]);
			strcat(interner, " ");
		}
		//�Լ� �������� ��ū�� ���ڿ��� ������� ����
		for (int i = 1; i < functions[index]->tokenNum-1; i++){
			BOOL check = TRUE;
			//���۷��� �ڸ���, tmpopr�� ����
			for (int j = 0; j < functions[index]->oprNum; j++){
				if (strcmp(functions[index]->tokenTable[i], functions[index]->operands[j]) == 0){
					strcat(interner, tmpopr[j]);
					strcat(interner, " ");
					check = FALSE;
				}
			}
				if (check){
					strcat(interner, functions[index]->tokenTable[i]);
					strcat(interner, " ");
				}
			

		}
		//defun�Լ� ���� �޺κе� �״�� �����Ͽ�
		for (int i = next; i < tokenNum; i++){
			strcat(interner, tokenTable[i]);
			strcat(interner, " ");
		}

		//�ʱ�ȭ
		lcount = 0;
		rcount = 0;
		type = 0;
		operand1 = NULL;
		operand2 = NULL;
		memset(value, 0, sizeof(char) * 10);
		memset(op, 0, sizeof(char) * 10);
		errNumber = 0;

		for (int i = 0; i < MAX_TOKEN; i++){
			tokenTable[i] = NULL;
			tokenType[i] = 0;
		}
		tokenNum = 0;

		//�ٽ� ����Į
		lexicalAnalysis(interner);
	}

	if (errNumber == 0){
		syntaxAnalysis();
	}


	if (errNumber == 0){
		if (tokenNum > 3){
			if (strcmp(op, "") == 0)
				errNumber = NOOP_ERR;
		}
	}

}
//��ũ������
void MyToy::lexicalAnalysis(char *input){
	int i = 0;
	while (input[i] != '\0'){
		//��ū�� (
		if (input[i] == '('){
			tokenTable[tokenNum] = new char[2];
			tokenTable[tokenNum][0] = '(';
			tokenTable[tokenNum][1] = '\0';
			tokenType[tokenNum] = 1;
			tokenNum++;
		}
		// )
		else if (input[i] == ')'){
			tokenTable[tokenNum] = new char[2];
			tokenTable[tokenNum][0] = ')';
			tokenTable[tokenNum][1] = '\0';
			tokenType[tokenNum] = 2;
			tokenNum++;
		}
		//����
		else if (input[i] == '.' || input[i] == '-' || (input[i] >= '0' && input[i] <= '9')){
			int tmp = i;
			while (input[i] == '.' || input[i] == '-' || (input[i] >= '0'&&input[i] <= '9'))
				i++;
			tokenTable[tokenNum] = new char[i - tmp + 1];
			memset(tokenTable[tokenNum], 0, i - tmp + 1);

			strncpy(tokenTable[tokenNum], input + tmp, i - tmp);
			tokenType[tokenNum] = 3;
			tokenNum++;
			i--;
		}
		//���� IF/THEN/ELSE ������ /�߰�
		else if ((input[i] >= 'A'&& input[i] <= 'Z') ||  input[i]=='/'){
			int tmp = i;
			while ((input[i] >= 'A'&& input[i] <= 'Z') || input[i] == '/')
				i++;
			tokenTable[tokenNum] = new char[i - tmp + 1];
			memset(tokenTable[tokenNum], 0, i - tmp + 1);

			strncpy(tokenTable[tokenNum], input + tmp, i - tmp);
			tokenType[tokenNum] = 4;
			tokenNum++;
			i--;
		}
		else if (input[i] != ' '){
			//���� ���� ���� ��� ����
			errNumber = DEFAULT_ERR;
			return;
		}
		i++;
	}

	for (int j = 0; j < tokenNum; j++){
		//������ ���
		if (tokenType[j] == 3){
			int nc = 0;
			int dc = 0;
			for (int k = 0; k < strlen(tokenTable[j]); k++){
				if (tokenTable[j][k] == '.')
					dc++;
				else if (tokenTable[j][k] == '-')
					nc++;
			}
			if (nc > 1){
				// -���� ����
				errNumber = NEGATIVE_ERR;
				return;
			}
			else if (dc > 0){
				// �Ǽ� ����
				errNumber = REAL_ERR;
				return;
			}
		}
		else if (tokenType[j] == 4){
			//op�迭, ���� �迭�� ���� �˻�, op�� 4 �׷��� ������ 5
			if (strcmp(tokenTable[j], "IF") != 0 && strcmp(tokenTable[j], "MINUS") != 0){

				BOOL check = TRUE;
				//defun�� ���ǵ� �Լ��� ��ġ���� �˻�
				for (int k = 0; k < functionNum; k++){
					if (strcmp(tokenTable[j], functions[k]->op) == 0)
						check = FALSE;
				}

				if (check){
					errNumber = UNDEFINE_ERR;
					return;
				}
				//��ġ�ϸ� �� token�� index�� errNumber�� ����
				else
					errNumber = j;
			}
		}
	}
}
//MyToy �Ҵ�
void MyToy::syntaxAnalysis(){
	char opr[100] = { 0 };
	if (tokenNum == 1){
		strcpy(value, tokenTable[0]);
		return;
	}
	else
		for (int i = 0; i < tokenNum; i++){
			if (tokenType[i] == 1){
				// ( ��ȣ ī��Ʈ
				if (lcount == 0)
					lcount++;
				else if (lcount == 1){
					//(��ȣ �ȿ� (��ȣ�� ���̸� -> �ǿ����ڵ� �Լ���
					lcount++;
					memset(opr, 0, 100);
					int count = 0;
					while (i < tokenNum){
						if (tokenType[i] == 1)
							count++;
						else if (tokenType[i] == 2)
							count--;

						strcat(opr, tokenTable[i]);
						strcat(opr, " ");
						//��Ī�Ǵ� )���� 
						if (count == 0)
							break;
						i++;
					}
					//�ǿ����� �ڸ��� ã�� (...) �Ҵ�
					if (operand1 == NULL)
						operand1 = new MyToy(opr);
					else if (operand2 == NULL)
						operand2 = new MyToy(opr);
					else{
						errNumber = LEFT_ERR;
						return;
					}


				}
				//��������
				else if (lcount == 2){
					lcount++;
					memset(opr, 0, 100);
					int count = 0;
					while (i < tokenNum){
						if (tokenType[i] == 1)
							count++;
						else if (tokenType[i] == 2)
							count--;

						strcat(opr, tokenTable[i]);
						strcat(opr, " ");
						if (count == 0)
							break;
						i++;
					}

					if (operand1 == NULL)
						operand1 = new MyToy(opr);
					else if (operand2 == NULL)
						operand2 = new MyToy(opr);
					else{
						errNumber = LEFT_ERR;
						return;
					}

				}
				else
					errNumber = LEFT_ERR;

			}
			// ) ��ȣ
			else if (tokenType[i] == 2){
				rcount++;
			}
			//����
			else if (tokenType[i] == 3){
				if (operand1 == NULL)
					operand1 = new MyToy(tokenTable[i]);
				else if (operand2 == NULL)
					operand2 = new MyToy(tokenTable[i]);
				else
				{
					errNumber = COUNT_ERR;
					return;
				}
			}
			//���� -> ���ڴ� �Լ� �̸�
			else if (tokenType[i] == 4){
				strcpy(op, tokenTable[i]);
			}
			else if (tokenType[i] == 5){
				if (operand1 == NULL)
					operand1 = new MyToy(tokenTable[i]);
				else if (operand2 == NULL)
					operand2 = new MyToy(tokenTable[i]);
			}
		}

	if (rcount != 1){
		errNumber = RIGHT_ERR;
	}
}


char* toPre(MyToy *input){
	char *result = new char[256];
	memset(result, 0, 256);

	strcat(result, "( ");

	if (input->op != NULL){
		strcat(result, input->op);
	}
	strcat(result, " ");
	if (input->operand1 != NULL){
		if (strcmp(input->operand1->value, "") != 0){
			strcat(result, input->operand1->value);
		}
		else
			strcat(result, toPre(input->operand1));
	}
	strcat(result, " ");
	if (input->operand2 != NULL){
		if (strcmp(input->operand2->value, "") != 0){
			strcat(result, input->operand2->value);
		}
		else
			strcat(result, toPre(input->operand2));
	}

	strcat(result, " )");


	return result;
}


char* toInter(MyToy *input){
	char *result = new char[256];
	memset(result, 0, 256);

	if (strcmp(input->op, "") != 0){
		strcat(result, input->op);
		strcat(result, "\r\n");
	}
	else{
		if (input->operand1 == NULL){
			strcat(result, "push ");
			strcat(result, input->value);
			strcat(result, "\r\n");
		}
	}

	if (input->operand1 != NULL)
		strcat(result, toInter(input->operand1));
	if (input->operand2 != NULL)
		strcat(result, toInter(input->operand2));

	return result;
}

int checkErr(MyToy *input){
	int result = 0;

	if (input->operand1 != NULL){
		if (checkErr(input->operand1) != 0)
			result = input->operand1->errNumber;
	}
	if (input->operand2 != NULL){
		if (checkErr(input->operand2) != 0)
			result = input->operand2->errNumber;
	}
	if (input->errNumber != 0)
		result = input->errNumber;

	return result;
}


//�Լ����
void CTOYDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	ULONGLONG length;
	char buff[1000] = { 0 };

	//edit control ���� 
	CEdit *textBox;
	textBox = (CEdit*)GetDlgItem(IDC_EDIT1);

	CFile file;
	file.Open(_T("defun.txt"), CFile::modeRead);
	length = file.GetLength();
	file.Read(buff, length*sizeof(char));
	file.Close();


	//���� ���� ����
	textBox->SetWindowTextW(CA2W(buff));
}

int defun(char *func, int line){
	int i = 0;
	char *tokenTable[MAX_TOKEN];
	int tokenNum=0;
	int tokenType[MAX_TOKEN];
	int errNumber=0;

	char *operands[5];
	int oprNum = 0;
	int oprCheck[5] = { 0, 0, 0, 0, 0 };
		
	while (func[i] != '\0'){
		if (func[i] == '('){
			tokenTable[tokenNum] = new char[2];
			tokenTable[tokenNum][0] = '(';
			tokenTable[tokenNum][1] = '\0';
			tokenType[tokenNum] = 1;
			tokenNum++;
		}
		else if (func[i] == ')'){
			tokenTable[tokenNum] = new char[2];
			tokenTable[tokenNum][0] = ')';
			tokenTable[tokenNum][1] = '\0';
			tokenType[tokenNum] = 2;
			tokenNum++;
		}
		else if (func[i] == '.' || func[i] == '-' || (func[i] >= '0' && func[i] <= '9')){
			int tmp = i;
			while (func[i] == '.' || func[i] == '-' || (func[i] >= '0'&&func[i] <= '9'))
				i++;
			tokenTable[tokenNum] = new char[i - tmp + 1];
			memset(tokenTable[tokenNum], 0, i - tmp + 1);

			strncpy(tokenTable[tokenNum], func + tmp, i - tmp);
			tokenType[tokenNum] = 3;
			tokenNum++;
			i--;
		}
		else if ((func[i] >= 'A'&& func[i] <= 'Z') || func[i] == '/'){
			int tmp = i;
			while ((func[i] >= 'A'&& func[i] <= 'Z') || func[i] == '/')
				i++;
			tokenTable[tokenNum] = new char[i - tmp + 1];
			memset(tokenTable[tokenNum], 0, i - tmp + 1);

			strncpy(tokenTable[tokenNum], func + tmp, i - tmp);
			tokenType[tokenNum] = 4;
			tokenNum++;
			i--;
		}
		else if (func[i] >= 'a'&&func[i] <= 'z'){
			int tmp = i;
			while (func[i] >= 'a'&&func[i] <= 'z')
				i++;
			tokenTable[tokenNum] = new char[i - tmp + 1];
			memset(tokenTable[tokenNum], 0, i - tmp + 1);

			strncpy(tokenTable[tokenNum], func + tmp, i - tmp);
			tokenType[tokenNum] = 8;
			tokenNum++;
			i--;
		}
		else if (func[i] != ' '){
			errNumber = DEFAULT_ERR;
			break;
		}
	
		i++;
	}
	if (errNumber == 0){
		if (!(tokenType[0] == 1 && tokenType[tokenNum - 1] == 2)){
			//��ȣ����
			AfxMessageBox(_T("(,) ��ȣ�� �߸��Ǿ����ϴ�."));
			return -1;
		}
		if (!(tokenType[1] == 4 && strcmp(tokenTable[1], "DEFUN") == 0)){
			//DEFUN ��ɾ� ����
			AfxMessageBox(_T("DEFUN �� ��� �ٶ��ϴ�."));
			return -1;
		}
		for (int i = 0; i < functionNum; i++){
			if (strcmp(tokenTable[2], functions[i]->op) == 0){
				//�̸��ߺ�
				AfxMessageBox(_T("�̹� ���ǵǾ��ִ� �Լ� �Դϴ�. �ٸ� �̸��� ������ּ���."));
				return -1;
			}
		}
		//���۷��� ���� 4��° ��ū���� ���۷���
		for (int i = 4; i < 9; i++){
			//���۷�Ʈ Ÿ�� �ѹ� 8
			if (tokenType[i] == 8){
				if (strlen(tokenTable[i]) != 1){
					//opernad err ���۷���� �ҹ��� �ϳ�
					AfxMessageBox(_T("�ǿ����ڴ� �ҹ��� �ϳ��� ������ּ���."));
					return -1;
				}
				operands[oprNum] = new char[strlen(tokenTable[i])];
				strcpy(operands[oprNum], tokenTable[i]);
				oprNum++;
			}
			else
				break;
		}
		if (oprNum == 0){
			//���۷��尡 ����
			AfxMessageBox(_T("���۷��尡 �����ϴ�."));
			return -1;
		}
		//���۷��� ��� Ȯ��
		for (int i = 4 + oprNum; i < tokenNum; i++){
			if (tokenType[i] == 8){
				for (int j = 0; j < oprNum; j++){
					if (strcmp(tokenTable[i], operands[j]) == 0){
						//�� ���۷��� �������� �������� äũ �迭 ����
						tokenTable[i] = new char[4];
						tokenTable[i][0] = ' ';
						tokenTable[i][1] = '1';
						tokenTable[i][2] = ' ';
						tokenTable[i][3] = '\0';
						oprCheck[j]++;
					}
				}
			}
		}
		for (int i = 0; i < oprNum; i++){
			if (oprCheck[i] == 0){
				//������ ���� ���۷��尡 �ִ�
				AfxMessageBox(_T("������ ���� �п����ڰ� �ֽ��ϴ�."));
				return -1;
			}
		}

		char funcdef[50] = { 0 };

		for (int i = 4 + oprNum + 1; i < tokenNum - 1; i++){
			strcat(funcdef, tokenTable[i]);
		}

		MyToy *test = new MyToy(funcdef);
		if (test->errNumber == 0){
			//����
			return 0;
		}
		
	}
	else{
		printErr(errNumber, line);
		return -1;
	}
}

//�Լ��߰�
void CTOYDlg::OnBnClickedButton8()
{
	char *newFun[10];

	CString tmpinput;
	char input[256] = { 0 };
	char *token;
	int pc = 0;

	//edit control ����
	CEdit *textBox;
	textBox = (CEdit*)GetDlgItem(IDC_EDIT1);
	textBox->LineScroll(textBox->GetLineCount());
	textBox->GetWindowTextW(tmpinput);

	for (int i = 0; i < tmpinput.GetLength(); i++){
		input[i] = tmpinput.GetAt(i);

	}

	//���κ��� Ȯ��
	token = strtok(input, "\r\n");
	while (token != NULL){
		newFun[pc] = new char[strlen(token)];
		strcpy(newFun[pc], token);
		pc++;
		token = strtok(NULL, "\r\n");
	}

	//����Ȯ��
	int check = 0;
	for (int i = 0; i < pc; i++){
		check += defun(newFun[i],i);
	}
	//������ 
	if (check == 0){

		AfxMessageBox(_T("���������� ��ϵǾ����ϴ�."));
		//DEFUN ��ɾ� ������ �Լ� ���� ������ ����
		for (int i = 0; i < pc; i++){
			int start = 0;
			for (int j = 0; j < strlen(newFun[i]); j++){
				if (start == 1 && newFun[i][j] >= 'A'&&newFun[i][j] <= 'Z'){
					start = j;
					break;
				}
				if (newFun[i][j] == 'N'){
					start = 1;
				}
			}
			//���� ����
			CFile file;
			memset(input, 0, 256);
			strcat(input, "\r\n");
			strncat(input, newFun[i] + start, strlen(newFun[i]) - start - 1);
			file.Open(_T("defun.txt"), CFile::modeWrite | CFile::modeNoTruncate | CFile::modeCreate);
			file.SeekToEnd();
			file.Write(input, strlen(input));
			file.Close();
			//initDefun�Լ��� functions�� �ٽ� ���
			initDefun();
		}
	}	
}

//���α׷� ����
void CTOYDlg::OnBnClickedButton10()
{
	CString tmpinput;
	char input[500] = { 0 };

	//edit control ����
	CEdit *textBox;
	textBox = (CEdit*)GetDlgItem(IDC_EDIT1);
	textBox->GetWindowTextW(tmpinput);

	for (int i = 0; i < tmpinput.GetLength(); i++){
		input[i] = tmpinput.GetAt(i);
	}

	CFileDialog dlgFile(FALSE, _T("txt"), _T("pre*.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL);
	dlgFile.m_ofn.lpstrFilter = _T("Text File(*.txt)");

	if (IDOK == dlgFile.DoModal()) {

		CString strPathName = dlgFile.GetPathName();

		CFile file;
		file.Open(strPathName, CFile::modeWrite | CFile::modeCreate);
		file.Write(input, strlen(input));

		file.Close();
	}
}
