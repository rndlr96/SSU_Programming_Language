#include "stdafx.h"
#include "MyStack.h"


MyStack::MyStack(){
	for (int i = 0; i < 40; i++)
		item[i] = NULL;
	count = 0;
}

void MyStack::push(char * input){
	item[count] = new char[strlen(input) + 1];
	memset(item[count], 0, strlen(input) + 1);
	strcpy(item[count], input);
	count++;
}

char * MyStack::pop(){
	count--;
	return item[count];
}

int MyStack::size(){
	return count;
}

int factorial(int a) {
	int sum = 1;
	for (; a > 0; a--) {
		sum *= a;
	}
	return sum;
}

char* toyValue(char* op, char* operand2, char* operand1 ) {
	if (strcmp(op, "IF") == 0) {
		char tmp[20] = { 0 };
		if (atoi(operand1) > 0) {
			sprintf(tmp, "%d", atoi(operand2));
			return tmp;
		}
		else {
			sprintf(tmp, "0");
			return tmp;
		}
	}

	else if (strcmp(op, "MINUS") == 0) {
		char tmp[20] = { 0 };
		sprintf(tmp, "%d", atoi(operand1) - atoi(operand2));
		return tmp;
	}

	else if (strcmp(op, "MOD") == 0) {
		char tmp[20] = { 0 };
		sprintf(tmp, "%d", atoi(operand1) % atoi(operand2));
		return tmp;
	}

	else if (strcmp(op, "FACTORIAL") == 0) {
		char tmp[20] = { 0 };
		sprintf(tmp, "%d", factorial(atoi(operand2)));
		return tmp;
	}
}