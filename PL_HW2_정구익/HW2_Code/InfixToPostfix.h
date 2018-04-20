

// InfixToPostfix.h : ��� ����
// ����ǥ����� ����ǥ������� ��ȯ�ϴ� class

#pragma once
#include "afxwin.h"
#include <list>


class InfixToPostfix{
private:

	//Infix ����ų CStringA�� ������
	CStringA* Infix;
	//CStringA�� char�� ������ ó�� �̿��Ҷ� �ʿ��� char�� ������
	char* tmpbuf;
	//���ڿ� ���� 
	int len;

	//���� �ֱ� ������
	int current_opnum;
	//�ùٸ� �ĵ��� list���·� �����ϰ� �ȴ�.
	std::list<CStringA> listofPostfix;

	//���� �޼��� + �ùٸ� ���� ����ǥ���
	CStringA message;

	//�� ������ �ӽ� ����
	CStringA tmp_str;

	//���� ��ȣ
	//0: ���� X, 1: �ǿ����ڰ� �Ǽ� �϶�, 2: ��ȣ �߸���� �Ǿ�����
	//3: ���ĺ��� - ������ ��ȣ �Է� �Ǿ�����
	//4: ������ �ڸ��� IF�� MINUS�� ������ ��ȣ�� �ԷµǴ� ���
	//5: �ǿ����ڿ� -�������� ���ö�
	//6: ���ڵڿ� ���� �ƴѰ� ���� ���� ���ö�
	int errnum;

	//������ ���� index
	int linestart;

	//������ �� index
	int lineend;

	//����ǥ������� ����� �Լ�
	void make_Postfix();
	//���� ������ index ���� err�� �ش� errnum 
	//���� ��ȣ�ΰ�?
	int Is_open_parentheses(int index);
	//index�� ���� ���;���
	//���� ������ index ���� err�� �ش� errnum 
	//�����ΰ�?
	int Is_val(int index);
	//index�� ���� ���;���
	//���� ������ index ���� err�� �ش� errnum 
	//����ΰ�?
	int Is_con(int index);
	//index�� ���� ���;���
	//���� ������ index ���� err�� �ش� errnum 
	//������ �ΰ�?
	int Is_op(int index);
	//index�� - ���;���
	//���� ������ index ���� err�� �ش� errnum 
	//-�� ���۵Ǵ� ����ΰ�?
	int Is_minus_con(int index);


	//�����޼��� ���, ����� errnum=0�� ����
	void printerror();

	//�ϳ��� ���α׷��� ������ ���� ������ index�� �����Ѵ�.
	//���� ���α׷��� ���� ���̿� ������ ������ �ٸ� ���ڰ� ������� err üũ�Ѵ�.
	int check_err_after_program(int index);

	//������ ��Ƴ��� �迭
	char *oper[2];

	//���� ���ڿ�
	char* errnum_string[7];

public:
	//������
	InfixToPostfix(CString Infix_tmp);
	//�Ҹ���
	~InfixToPostfix();
	//�ùٸ� �ĵ� ���������� �Ѱ���
	std::list<CStringA> getPostfix();
	//���� �޼��� + �ùٸ� ���� ����ǥ���
	CString getMessage_Postfix();
};

