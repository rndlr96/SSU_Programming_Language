
// PostfixToIntermediate.cpp : cpp ����
// ����ǥ����� �߰� �ڵ�� ��ȯ�ϴ� class
// ������ ���ڷ� �޴� list<CStringA>���� ���Ŀ� �°� ����ǥ����� �� �ִ�.
// ���� üũ�� ��� InfixToPostfix(����ǥ���->����ǥ���) ���� �Ѵ�.


#include "PostfixToIntermediate.h"
#include "stdafx.h"

//������
PostfixToIntermediate::PostfixToIntermediate(std::list<CStringA> Postfix_tmp){
	Postfix = Postfix_tmp;
	//������ �ʱ�ȭ
	oper[0] = "IF";
	oper[1] = "MINUS";

	//�߰��ڵ� �����
	make_Intermediate();
}

//�߰� �ڵ� ����� �Լ�
void PostfixToIntermediate::make_Intermediate(){
	//����Ʈ�� ���� ���� �տ��� �ϳ� �� ������.
	//(CStringA�ϳ��� ����ǥ��� ���� �ϳ�)
	while (!Postfix.empty())
	{
		//�պκ� line�� ����
		CStringA line = Postfix.front().GetString();
		//list item�ϳ� ������
		Postfix.pop_front();
		//���� ����
		linelen = line.GetLength();
		//CStrinA char*�� ����ϱ� ����
		linepointer = line.GetBuffer();
		int i = 0;
		//���α׷� ���� �κ�
		Intermediate.Append("begin\r\n");

		//��ȣ ���� Ȯ��
		if (linepointer[i] == '('){
			Is_open_parentheses(i);
		}
		//���� ���� Ȯ��
		else if (isalpha(linepointer[i]) || linepointer[i] == '-'){
			Is_val(i);
		}
		//��� ���� Ȯ��
		else if (isdigit(linepointer[i])){
			Is_con(i);
		}
		//���α׷� �� �κ�
		Intermediate.Append("end\r\n");
	}
}

//���� ������ index ����
//���� ��ȣ�ΰ�?
int PostfixToIntermediate::Is_open_parentheses(int index){
	index++;

	//term1 Ȯ��

	//��ȣ ���� Ȯ��
	if (linepointer[index] == '('){
		index = Is_open_parentheses(index);
	}
	//���� ���� Ȯ��
	else if (isalpha(linepointer[index]) || linepointer[index] == '-'){
		index = Is_val(index);
	}
	//��� ���� Ȯ��
	else if (isdigit(linepointer[index])){
		index = Is_con(index);
	}
	index += 2;

	//term2 Ȯ��

	//��ȣ ���� Ȯ��
	if (linepointer[index] == '('){
		index = Is_open_parentheses(index);
	}
	//���� ���� Ȯ��
	else if (isalpha(linepointer[index]) || linepointer[index] == '-'){
		index = Is_val(index);
	}
	//��� ���� Ȯ��
	else if (isdigit(linepointer[index])){
		index = Is_con(index);
	}
	index += 2;

	//function Ȯ��
	index = Is_op(index);

	return index + 1;
}

//index�� ���� ���;���
//���� ������ index ����
//�����ΰ�?
int PostfixToIntermediate::Is_val(int index){
	int i;
	//push
	Intermediate.Append("push ");
	//���� ������ index ã��
	for (i = index; i < linelen; i++){
		if (linepointer[i] == ' '){
			break;
		}
		else{
			Intermediate.AppendChar(linepointer[i]);
		}
	}
	Intermediate.Append("\r\n");
	return i - 1;
}

//index�� ���� ���;���
//���� ������ index ����
//����ΰ�?
int PostfixToIntermediate::Is_con(int index){
	int i;
	//push
	Intermediate.Append("push ");
	//��� ������ index ã��
	for (i = index; i < linelen; i++){
		if (linepointer[i] == ' '){
			break;
		}
		else{
			Intermediate.AppendChar(linepointer[i]);
		}
	}
	Intermediate.Append("\r\n");
	return i - 1;
}

//index�� ���� ���;���
//���� ������ index ����
//������ �ΰ�?
int PostfixToIntermediate::Is_op(int index){
	int i, j;
	bool correct;
	for (i = 0; i < (sizeof(oper) / 4); i++){
		//�������� ����
		int OP_len = strlen(oper[i]);

		//���� index �� ������ ������ ���� ��ü ���� ���̺��� �۾ƾߵȴ�.
		//�ȱ׷��� ���� ª�� �������ε� �� ������ ã�ٰ� �޸� ���� ���� ����
		if (index + OP_len < linelen){
			correct = true;
			for (j = 0; j < OP_len; j++){
				if (linepointer[index + j] != oper[i][j]){
					correct = false;
					break;
				}
			}
			//�ش翬���� �ϰ��
			if (correct){
				Intermediate.Append(oper[i]);
				break;
			}
		}
	}
	Intermediate.Append("\r\n");
	return index + j - 1;
}

//�ùٸ� �ĵ� ���������� �Ѱ���
CStringA PostfixToIntermediate::getIntermediate(){
	return Intermediate;
}