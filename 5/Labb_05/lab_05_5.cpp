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
	cout << "\n�������� �������� (1-�������� � ASCII, 2-������� � 1251, 3-�����, 4-����� �� ���������) ";
	cin >> k;
	switch (k)
	{
	case 1:
	{
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
		break;
	}
	break;
	case 2:
	{
		cout << "������� ����� "; cin >> A;
		if ((A >= '�' && A <= '�') || (A <= '�' && A >= '�'))
		{
			int upcode = toupper(A);
			int downcode = tolower(A);
			diff = abs(upcode - downcode);
			cout << "������� = "<<diff;
		}
		else
		{
			cout << "�� ����� ������������ ��������";
		}
		break;
	}
	case 3:
	{
		cout << "������� �����"; cin >> A;
		if (isdigit(A))
		{
			int code = A;
				cout << "��� ������� = "<<code;
		}
		else
		{
			cout << "������";
		}
		break;
	}
	case 4:
	{
		cout << "����� �� ���������";
		f = false;
		break;
	}
	default:
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "������������ �����";
	}
	}
}