#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int k, diff;
	char A, a;
	cout << "�������� �������� (1-4) ";
	cin >> k;
	switch (k)
	{
	case 1:
	{
		cout << "������ ��������� ����� "; cin >> A;
		cout << "������ �������� ����� "; cin >> a;
		diff = abs(A - a);
		cout << "������� - " << diff;
	}
	break;
	case 2:
	{
		cout << "������ ��������� ����� "; cin >> A;
		cout << "������ �������� ����� "; cin >> a;
		diff = abs(A - a);
		cout << "������� - "<<hex<<diff;
	}
	case 3: 
	{

	}
	}
}