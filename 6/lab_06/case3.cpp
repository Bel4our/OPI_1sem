#include <iostream>
#include "case3.h"
#include <Windows.h>
using namespace std;
int case3() {
	int A;
	cout << "Введите цифру от 0 до 9: "; cin >> A;
	if (isdigit(A))
	{
		int code = static_cast <int>(A);
		cout << "Код = " << code;
	}
	else
	{
		cout << "Ошибка";
	}
	return 0;
}