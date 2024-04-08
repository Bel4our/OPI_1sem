#include <iostream>
#include "case2.h"
#include <Windows.h>
using namespace std;
int case2() {
	int A, diff;
	cout << "Введите букву "; cin >> A;
	if ((A >= 'А' && A <= 'Я') || (A <= 'я' && A >= 'а'))
	{
		int upcode = toupper(A);
		int downcode = tolower(A);
		diff = abs(upcode - downcode);
		cout << "Разница = " << diff;
	}
	else
	{
		cout << "Вы ввели неправильное значение";
	}
	return 0;
}