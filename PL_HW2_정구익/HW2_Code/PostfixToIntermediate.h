

// PostfixToIntermediate.h : ��� ����
// ����ǥ����� �߰� �ڵ�� ��ȯ�ϴ� class
// ������ ���ڷ� �޴� list<CStringA>���� ���Ŀ� �°� ����ǥ����� �� �ִ�.
// ���� üũ�� ��� InfixToPostfix(����ǥ���->����ǥ���) ���� �Ѵ�.

#pragma once
#include "afxwin.h"
#include <list>

class PostfixToIntermediate
{

private:

	//�߰� �ڵ�
	CStringA Intermediate;

	//������ ���ڷ� ���� Postfix ������
	std::list<CStringA> Postfix;

	//line ����Ű�� ������
	char * linepointer;

	//line ����
	int linelen;

	//�߰� �ڵ� ����� �Լ�
	void make_Intermediate();

	//���� ������ index ����
	//���� ��ȣ�ΰ�?
	int Is_open_parentheses(int index);

	//index�� ���� ���;���
	//���� ������ index ����
	//�����ΰ�?
	int Is_val(int index);

	//index�� ���� ���;���
	//���� ������ index ����
	//����ΰ�?
	int Is_con(int index);

	//index�� ���� ���;���
	//���� ������ index ����
	//������ �ΰ�?
	int Is_op(int index);

	//������ ��Ƴ��� �迭
	char *oper[2];

public:
	//������
	PostfixToIntermediate(std::list<CStringA> Postfix_tmp);

	//�ùٸ� �ĵ� ���������� �Ѱ���
	CStringA getIntermediate();
};


