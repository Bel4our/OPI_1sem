#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");
	int diff, big, smal;
	char X;
	cout << "Введите русскую букву "; cin >> X;
	if ((X >= 'А' && X <= 'Я') || (X <= 'я' && X >= 'а'))
	{
		if (X >= 'А' && X <= 'Я')
		{
			big = X;
			smal = X + 20;
		}

		else
		{
			smal = X;
			big = X - 20;
		}
		diff = abs(big - smal);
		cout << "Разница = " << diff;
	}
	else
	{
		cout << "Вы ввели неправильное значение";
	}


}