#include <iostream>

void pruning(char* str, int ptrFirst, int ptrLast) { // �������� ��������� ������
	int countNum = 0;
	int size = strlen(str);

	for (int i = 0; i < size - ptrLast; i++) {
		str[ptrFirst + i] = str[ptrLast + 1 + i];
	}
}


int check_Close_Brackets(char* str, int ptr) { // ���� ������������� ������
	int indexStr = ptr;

	while (str[indexStr] != '\0') {

		if (str[indexStr] == '}') {
			return indexStr;
		}

		indexStr++;
	}
}


int check_Open_Brackets(char* str) { // ���� ������������� ������
	int indexStr = 0;
	int i = -1;

	while (str[indexStr] != '\0') {
		if (str[indexStr] == '{') {
			i = indexStr;
		}
		indexStr++;
	}

	return i;
}
using namespace std;
int main() {
	char* locale = setlocale(LC_ALL, "");
	char str[1000];
	cout << "������� ������:";
	cin >> str;

	char** arr = (char**)malloc(sizeof(char*));
	int countNum = 0; // ������� ���������� ��������� ��� ������


	while (1) {

		int start = check_Open_Brackets(str); // ������ ������������� ������

		if (start == -1) {			//����� �� �����, ���� ������ �����������
			break;
		}

		int end = check_Close_Brackets(str, check_Open_Brackets(str)); // ������ ������������� ������

		char val[1000]; //������������ ��������� ������������ ������ ������
		for (int i = 0; i < end - start - 1 ; i++) {
			val[i] = str[start + i + 1];
		}
		val[end - start -1] = '\0';

		arr[countNum] = (char*)malloc(sizeof(char*) * (strlen(val))); // ���������� ���������� ����� ���������� ������ 

		strcpy_s(arr[countNum], strlen(val) + 1, val);

		pruning(str, start, end); //�������� ��������� �������� ������ �� ��������
		countNum++;
	}


	if (countNum == 0) {
		cout << "������";
	}
	else {
		cout << "��������� � �������: \n( \n";
		for (int i = 0; i < countNum; i++) {
			cout << "�������� �" << i + 1 << ": " << arr[i] << "\n";
		}
		cout << ") \n���������� ������:" << str << "\n\n\n\n\n\n";
	}
	
}