#include <iostream>
#include "case2.h"
#include <Windows.h>
using namespace std;
int case2() {
	int A, diff;
	cout << "������� ����� "; cin >> A;
	if ((A >= '�' && A <= '�') || (A <= '�' && A >= '�'))
	{
		int upcode = toupper(A);
		int downcode = tolower(A);
		diff = abs(upcode - downcode);
		cout << "������� = " << diff;
	}
	else
	{
		cout << "�� ����� ������������ ��������";
	}
	return 0;
}