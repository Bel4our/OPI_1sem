#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int diff, big, small;
	char X;
	cout << "Введите латинскую букву "; cin >> X;
	if ((X >= 'A' && X <= 'Z') || (X <= 'z' && X >= 'a'))
	{
		if (X >= 'A' && X <= 'Z')
		{
			big = X;
			small = X + 32;
		}

		else
		{
			small = X;
			big = X - 32;
		}
		diff = abs(big - small);
		cout << "Разница = " << diff;
	}
	else
	{
		cout << "Вы ввели неправильное значение";
	}


}