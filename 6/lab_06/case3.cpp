#include <iostream>
#include "case3.h"
#include <Windows.h>
using namespace std;
int case3() {
	int A;
	cout << "������� ����� �� 0 �� 9: "; cin >> A;
	if (isdigit(A))
	{
		int code = static_cast <int>(A);
		cout << "��� = " << code;
	}
	else
	{
		cout << "������";
	}
	return 0;
}