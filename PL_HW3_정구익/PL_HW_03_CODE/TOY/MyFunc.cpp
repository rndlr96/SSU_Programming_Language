
#include "stdafx.h"
#include "MyFunc.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>

MyFunc::MyFunc(char *input){
	//��� �ʱ�ȭ
	memset(op, 0, 15);
	oprNum = 0;
	tokenNum = 0;

	char *token;
	char tmpdef[10] = { 0 };
	int i = 0;
	int j = 0;

	//�����
	while (input[i] != ')'){
		//(������ �������� �Լ��̸�
		while (input[i] != '('){
			op[i]= input[i];
			i++;
		}
		i++;
		//�Ķ���� ������ �κ� tmpdef�� ����
		while (input[i] != ')'){
			tmpdef[j] = input[i];
		i++;
		j++;
		}
	}
	i++;

	
	char tmpopr[10] = { 0 };
	for (int k = 0; k < strlen(tmpdef); k++){
		//err �Ķ���ʹ� ���ĺ� �ҹ��� �ϳ���
		if (tmpdef[k] >= 'a' && tmpdef[k] <= 'z'){
			char tmpchar[2];
			tmpchar[0] = tmpdef[k];
			tmpchar[1] = '\0';
			strcat(tmpopr, tmpchar);
		}
		else if (tmpdef[k] == ' '){
				operands[oprNum] = new char[strlen(tmpopr)];
				memset(operands[oprNum], 0, strlen(tmpopr));
				strcpy(operands[oprNum], tmpopr);
				oprNum++;
				memset(tmpopr, 0, 10);
		}
		else{
			//err �Ķ���ʹ� ���ĺ� �ҹ��ڸ�
		}
	}
	operands[oprNum] = new char[strlen(tmpopr)];
	memset(operands[oprNum], 0, strlen(tmpopr));
	strcpy(operands[oprNum], tmpopr);
	oprNum++;

	//�Ȱ��� (,),����, ���ڷ� ��ū�� ������
	while (input[i] != '\0'){
		if (input[i] == '('){
			tokenTable[tokenNum] = new char[2];
			tokenTable[tokenNum][0] = '(';
			tokenTable[tokenNum][1] = '\0';
			tokenNum++; 
		}
		else if (input[i] == ')'){
			tokenTable[tokenNum] = new char[2];
			tokenTable[tokenNum][0] = ')';
			tokenTable[tokenNum][1] = '\0';
			tokenNum++;
		}
		else if (input[i] == '.' || input[i] == '-' || (input[i] >= '0' && input[i] <= '9')){
			int tmp = i;
			while (input[i] == '.' || input[i] == '-' || (input[i] >= '0'&&input[i] <= '9'))
				i++;
			tokenTable[tokenNum] = new char[i - tmp + 1];
			memset(tokenTable[tokenNum], 0, i - tmp + 1);

			strncpy(tokenTable[tokenNum], input + tmp, i - tmp);
			tokenNum++;
			i--;
		}
		//�����ο��� �Ķ���Ͱ� ���̱� ������ �ҹ��ڵ� �޴´�
		else if ((input[i] >= 'A'&& input[i] <= 'Z') || (input[i] >= 'a'&&input[i] <= 'z') || input[i]=='/'){
			int tmp = i;
			while ((input[i] >= 'A'&& input[i] <= 'Z') || (input[i] >= 'a'&&input[i] <= 'z') || input[i] == '/')
				i++;
			tokenTable[tokenNum] = new char[i - tmp + 1];
			memset(tokenTable[tokenNum], 0, i - tmp + 1);

			strncpy(tokenTable[tokenNum], input + tmp, i - tmp);
			tokenNum++;
			i--;
		}
		i++;
	}

}