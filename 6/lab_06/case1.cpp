#include <iostream>
#include "case1.h"
#include <Windows.h>
using namespace std;
int case1()
{
	int diff,A;
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	cout << "������� ����� "; cin >> A;
	if ((A >= 'A' && A <= 'Z') || (A <= 'z' && A >= 'a'))
	{
		int upcode = toupper(A);
		int downcode = tolower(A);
		diff = abs(upcode - downcode);
		cout << "������� = " << diff;
	}
	else {
		cout << "�� ����� ������������ ��������";
	}
	return 0;
}
