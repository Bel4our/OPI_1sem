#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");
	int diff, big, smal;
	char X;
	cout << "������� ������� ����� "; cin >> X;
	if ((X >= '�' && X <= '�') || (X <= '�' && X >= '�'))
	{
		if (X >= '�' && X <= '�')
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
		cout << "������� = " << diff;
	}
	else
	{
		cout << "�� ����� ������������ ��������";
	}


}