#include "InfixToPostfix.h"
#include "stdafx.h"

//������
InfixToPostfix::InfixToPostfix(CString Infix_tmp){
	Infix = new CStringA(Infix_tmp);

	//���� �޼��� �ʱ�ȭ
	errnum_string[0] = "";
	errnum_string[1] = "�ǿ����� �ڸ��� ������ �ƴ� �Ǽ��� �����ϴ�.\n";
	errnum_string[2] = "��ȣ�� �� �� ���Ǿ����ϴ�.\n";
	errnum_string[3] = "��ȣ ����� �߸� �Ǿ����ϴ�\n";
	errnum_string[4] = "���ǵ��� ���� ������ �Դϴ�.\n";
	errnum_string[5] = "�ǿ����� �ڸ��� -�� �������� �ԷµǾ����ϴ�.\n";
	errnum_string[6] = "���ڵڿ� ���� �Ǵ� ��ȣ�� ���� ���� ��� �����ϴ�.\n";

	//������ �ʱ�ȭ
	oper[0] = "IF";
	oper[1] = "MINUS";

	if (Infix->GetLength() == 0){
		Infix->AppendChar(' ');
	}

	//���� ���ڿ� ���� ���� ������ ������ �־��ش�.
	if (Infix->GetAt(Infix->GetLength() - 1) != '\n'){
		Infix->AppendChar('\n');
	}

	//������ �ֺ��� ���� �����
	Infix->Replace("IF", " IF ");
	Infix->Replace("MINUS", " MINUS ");

	//���ڿ� ���� ���
	len = Infix->GetLength();

	//CString class�� char�迭 ó�� ���
	//���̺� ���� ũ�� ��ŭ ���� ��	
	tmpbuf = Infix->GetBuffer(len);

	make_Postfix();
}

//�Ҹ���
InfixToPostfix::~InfixToPostfix(){
	delete Infix;
}

//����ǥ������� ����� �Լ�
void InfixToPostfix::make_Postfix(){
	int i = 0;
	//�ӽ� ������ȣ (���� ù ������ ����ϱ� ����)
	int errnum_tmp;

	//prefix�� �Էµ� CStringA ������ for��
	for (i = 0; i < len; i++){
		errnum = 0;
		errnum_tmp = 0;
		//������ ���� index
		linestart = i;
		//�ӽ� tmp_str �ʱ�ȭ
		tmp_str.Format("");

		//��ȣ �� Ȯ��
		int tmpj = i;
		int count_open_parenthness = 0;
		int count_close_parenthness = 0;
		for (; tmpj < len; tmpj++)
		{
			if (tmpbuf[tmpj] == '(')
				count_open_parenthness++;
			else if (tmpbuf[tmpj] == ')')
				count_close_parenthness++;
			else if (tmpbuf[tmpj] == '\n')
				break;
		}
		//��ȣ�� �ٸ����
		if (count_open_parenthness != count_close_parenthness)
		{
			i = tmpj;
			errnum = 2;
		}
		//��ȣ �� ���� ���
		else{
			//���� �ѱ��
			if (isspace(tmpbuf[i])){
				continue;
			}
			//��ȣ ����
			else if (tmpbuf[i] == '('){
				i = Is_open_parentheses(i);
				errnum_tmp = errnum;
				i++;
				i = check_err_after_program(i);
			}
			//���� ���� Ȯ��
			else if (isalpha(tmpbuf[i])){
				i = Is_val(i);
				errnum_tmp = errnum;
				i++;
				i = check_err_after_program(i);
			}
			//��� ���� Ȯ��
			else if (isdigit(tmpbuf[i])){
				i = Is_con(i);
				errnum_tmp = errnum;
				i++;
				i = check_err_after_program(i);
			}
			//���̳ʽ� ��� ���� Ȯ��
			else if (tmpbuf[i] == '-'){
				i = Is_minus_con(i);
				errnum_tmp = errnum;
				i++;
				i = check_err_after_program(i);
			}
			//���ĺ� - ������ ��ȣ ��� ���� ��
			else{
				errnum = 3;
				errnum_tmp = errnum;
				i = check_err_after_program(i);
			}
		}

		//������ �� index
		lineend = i;
		//ù ������ �޼��� ����
		if (errnum_tmp)
			errnum = errnum_tmp;

		//������ ���� ������ �޼����� �־���
		if (errnum)
		{
			int j;
			for (j = linestart; j < lineend; j++){
				message.AppendChar(tmpbuf[j]);
			}
			if (tmpbuf[j - 1] != '\n')
				message.Append("\r\n");
		}
		else{
			listofPostfix.push_back(tmp_str);
			message.Append(tmp_str);
		}

		//���� ���, ������ �ƹ��͵� ��µ��� ����
		printerror();

	}

}

//�����޼��� ���, ����� errno=0�� ����
void InfixToPostfix::printerror(){
	message.Append(errnum_string[errnum]);
	message.Append("\r\n");
	errnum = 0;
}

//�ϳ��� ���α׷��� ������ ���� ����Ȥ�� �Է¹��� Infix�� ���� ��� index�� �����Ѵ�.
//���� ���α׷��� ���� ���̿� ������ ������ �ٸ� ���ڰ� ������� err üũ�Ѵ�.
int InfixToPostfix::check_err_after_program(int index){
	//���๮�ڰ� ���ö� ���� for��
	if (index < len)
	while (tmpbuf[index] != '\n' && (index != (len - 1))){
		//���� �� �ڿ� �̻��Ѱ��� ������ errnum=2 �� ǥ��
		if (!isspace(tmpbuf[index])){
			errnum = 2;
		}
		++index;
	}
	return index;
}


//���� ������ index ���� err�� �ش� errnum 
//���� ��ȣ�ΰ�?
int InfixToPostfix::Is_open_parentheses(int index){
	int i;
	//�� ���� op
	int this_op_num;
	//seq 0: <term>  ->  <fun>
	//seq 1: <fun>   ->  <term>
	//seq 2: <term>
	//seq 3: )
	tmp_str.AppendChar(tmpbuf[index]);
	//seq 0: <fun> 
	for (i = index + 1; i < len; i++){

		//���� �ѱ��
		if (tmpbuf[i] == ' ' || tmpbuf[i] == '\t') {
			continue;
		}
		else if (isalpha(tmpbuf[i])) {
			i = Is_op(i);
			if (errnum) {
				return i;
			}
			i++;
			//�� ���� op num ���
			this_op_num = current_opnum;
			break;
		}
		//�߸��� ��ġ�� ��ȣ
		else if (tmpbuf[i] == ')') {
			errnum = 2;
			return i;
		}
		//�߸��� ��ȣ ����
		else {
			if (isdigit(tmpbuf[i]))
				errnum = 4;
			else
				errnum = 3;
			return i;
		}
	}
	//������ (������ ����
	if (i == len){
		errnum = 2;
		return i - 1;
	}

	//seq 1: <term>
	for (; i < len; i++){
		//���� �ѱ��
		if (tmpbuf[i] == ' ' || tmpbuf[i] == '\t') {
			continue;
		}
		//��������� ȣ��
		else if (tmpbuf[i] == '(') {
			i = Is_open_parentheses(i);
			if (errnum) {
				return i;
			}
			i++;
			break;
		}
		//���� ���� Ȯ��
		else if (isalpha(tmpbuf[i])) {
			i = Is_val(i);
			if (errnum) {
				return i;
			}
			i++;
			break;
		}
		//��� ���� Ȯ��
		else if (isdigit(tmpbuf[i])) {
			i = Is_con(i);
			if (errnum) {
				return i;
			}
			i++;
			break;
		}
		//���̳ʽ� ��� ���� Ȯ��
		else if (tmpbuf[i] == '-') {
			i = Is_minus_con(i);
			if (errnum) {
				return i;
			}
			i++;
			break;
		}
		//�߸��� ��ġ�� ��ȣ
		else if (tmpbuf[i] == ')') {
			errnum = 2;
			return i;
		}
		//�߸��� ��ȣ ����
		else {
			errnum = 3;
			return i;
		}
	}
	//term �ȳ����� ���� ��
	if (i == len){
		errnum = 2;
		return i - 1;
	}
	tmp_str.AppendChar(' ');
	//seq 2: <term>
	for (; i < len; i++){

		//���� �ѱ��
		if (tmpbuf[i] == ' ' || tmpbuf[i] == '\t'){
			continue;
		}
		//��������� ȣ��
		else if (tmpbuf[i] == '('){
			i = Is_open_parentheses(i);
			if (errnum){
				return i;
			}
			i++;
			break;
		}
		//���� ���� Ȯ��
		else if (isalpha(tmpbuf[i])){
			i = Is_val(i);
			if (errnum){
				return i;
			}
			i++;
			break;
		}
		//��� ���� Ȯ��
		else if (isdigit(tmpbuf[i])){
			i = Is_con(i);
			if (errnum){
				return i;
			}
			i++;
			break;
		}
		//���̳ʽ� ��� ���� Ȯ��
		else if (tmpbuf[i] == '-'){
			i = Is_minus_con(i);
			if (errnum){
				return i;
			}
			i++;
			break;
		}
		//�߸��� ��ġ�� ��ȣ
		else if (tmpbuf[i] == ')'){
			errnum = 2;
			return i;
		}
		//�߸��� ��ȣ ����
		else{
			errnum = 3;
			return i;
		}
	}

	//) ���� ���� ��
	if (i == len){
		errnum = 2;
		return i - 1;
	}

	//seq 3: )
	for (; i < len; i++){

		//���� �ѱ��
		if (tmpbuf[i] == ' ' || tmpbuf[i] == '\t'){
			continue;
		}
		else if (tmpbuf[i] == ')'){
			tmp_str.AppendChar(' ');
			tmp_str.Append(oper[this_op_num]);
			tmp_str.AppendChar(tmpbuf[i]);
			return i;
		}
		//��ȣ �߸���
		else{
			errnum = 2;
			return i;
		}
	}

	errnum = 2;
	return index;
}

//index�� ���� ���;���
//���� ������ index ���� err�� �ش� errnum 
//�����ΰ�?
int InfixToPostfix::Is_val(int index){
	//���� ���ö� ���� for�� ��
	//�Ǵ� ���� �� ���� ���� for��
	for (; index < len; index++){
		//���� �����ų� �ݴ� ��ȣ������ for�� ����
		if (tmpbuf[index] == ' ' || tmpbuf[index] == '\t' || tmpbuf[index] == '\r' || tmpbuf[index] == '\n' || tmpbuf[index] == ')') {
			break;
		}
		//���ڳ� ���� �̿��ǰ��� ������ err
		else if (!isalpha(tmpbuf[index]) && !isdigit(tmpbuf[index])){
			errnum = 3;
			return index;
		}
		tmp_str.AppendChar(tmpbuf[index]);
	}

	return index - 1;


}

//index�� ���� ���;���
//���� ������ index ���� err�� �ش� errnum 
//����ΰ�?
int InfixToPostfix::Is_con(int index){
	//���� ���ö� ���� for�� ��
	//�Ǵ� ���� �� ���� ���� for��
	for (; index < len; index++){
		//���� �����ų� �ݴ� ��ȣ������ for�� ����
		if (tmpbuf[index] == ' ' || tmpbuf[index] == '\t' || tmpbuf[index] == '\r' || tmpbuf[index] == '\n' || tmpbuf[index] == ')'){
			break;
		}
		//. ������ �Ǽ��� �Ǵ��ϰ� err
		else if (tmpbuf[index] == '.'){
			errnum = 1;
			return index;
		}
		//���� �ƴѰ� ������ err
		else if (!isdigit(tmpbuf[index])){
			errnum = 6;
			return index;
		}
		tmp_str.AppendChar(tmpbuf[index]);
	}
	return index - 1;
}

//index�� ���� ���;���
//���� ������ index ���� err�� �ش� errnum 
//������ �ΰ�?
int InfixToPostfix::Is_op(int index){
	//������ ������ true �ƴϸ� false
	bool correct;
	int i, j;

	//������ ���� ��ŭ for�� ��
	for (i = 0; i < (sizeof(oper) / 4); i++){
		//�������� ����
		int OP_len = strlen(oper[i]);

		//���� ���� �����ڰ� �߸� ���ð�� ����� if��
		//������ ���� �ּ� 3�ڰ� �� �־�� ���� �����ȴ�.
		if (index + OP_len + 2 < len){
			correct = true;
			for (j = 0; j < OP_len; j++){
				if (tmpbuf[index + j] != oper[i][j]){
					correct = false;
					break;
				}
			}
			if (correct){
				//������ �ڿ� ���� Ȥ�� ���� ��ȣ �־���Ѵ�.
				if (tmpbuf[index + j] == ' ' || tmpbuf[index + j] == '\t' || tmpbuf[index + j] == '('){
					current_opnum = i;
					return index + j - 1;
				}
				//������ �ڿ� ������ �ƴ� �̻��Ѱ��� ����
				else{

					errnum = 4;
					if (tmpbuf[index + j] == ')')
						errnum = 2;
					return index + j - 1;
				}
			}
		}

	}
	//��ġ�ϴ� ������ ��ã��
	errnum = 4;
	return index;

}

//index�� -���;���
//���� ������ index ���� err�� �ش� errnum 
//-�� ���۵Ǵ� ����ΰ�?
int InfixToPostfix::Is_minus_con(int index){
	//-�� ���� �� ���� �� �����ϴ� if��
	tmp_str.AppendChar(tmpbuf[index]);
	if (index + 1 < len){
		if (tmpbuf[index + 1] == '-'){
			errnum = 5;
			return index + 1;
		}
		else if (isdigit(tmpbuf[index + 1])){
			return Is_con(index + 1);
		}
		else{
			//-�ڿ� �ٸ� ���� ���ö�
			errnum = 3;
			return index;
		}
	}
	//-�ڿ� �ƹ��͵� �ȿ� ��
	errnum = 1;
	return index;
}


//�ùٸ� �ĵ� ���������� �Ѱ���
std::list<CStringA> InfixToPostfix::getPostfix(){
	return listofPostfix;
}

//���� �޼��� + �ùٸ� ���� ����ǥ���
CString InfixToPostfix::getMessage_Postfix(){
	CString tmptmp(message);
	return tmptmp;
}