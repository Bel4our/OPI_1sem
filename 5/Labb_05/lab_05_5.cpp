#include <iostream>
#include <Windows.h>
#include <limits>
#ifdef max;
#undef max;
#endif
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	int k, diff;
	char A;
	bool f = true;
	while(f)
	{
	cout << "\nВыберите действие (1-Латиница в ASCII, 2-Русские в 1251, 3-Цифры, 4-Выход из программы) ";
	cin >> k;
	switch (k)
	{
	case 1:
	{
		cout << "Введите букву "; cin >> A;
		if ((A >= 'A' && A <= 'Z') || (A <= 'z' && A >= 'a'))
		{
			int upcode = toupper(A);
			int downcode = tolower(A);
			diff = abs(upcode - downcode);
			cout << "Разница = " << diff;
		}
		else {
			cout << "Вы ввели неправильное значение";
		}
		break;
	}
	break;
	case 2:
	{
		cout << "Введите букву "; cin >> A;
		if ((A >= 'А' && A <= 'Я') || (A <= 'я' && A >= 'а'))
		{
			int upcode = toupper(A);
			int downcode = tolower(A);
			diff = abs(upcode - downcode);
			cout << "Разница = "<<diff;
		}
		else
		{
			cout << "Вы ввели неправильное значение";
		}
		break;
	}
	case 3:
	{
		cout << "Введите цифру"; cin >> A;
		if (isdigit(A))
		{
			int code = A;
				cout << "Код символа = "<<code;
		}
		else
		{
			cout << "Ошибка";
		}
		break;
	}
	case 4:
	{
		cout << "Выход из программы";
		f = false;
		break;
	}
	default:
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Некорректный выбор";
	}
	}
}