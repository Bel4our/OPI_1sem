#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	float a, b, c;
	cout << "������� ������ ����� "; cin >> a;
	cout << "������� ������ ����� "; cin >> b;
	cout << "������� ������ ����� "; cin >> c;
	if(a<=b && a<=c)
		cout << "���������� �� �����: " << a;
	else
	{
		if(b<=a && b<=c)
			cout << "���������� �� �����: " << b;
		else 
		{
			cout << "���������� �� �����: " << c;
		}
	}
	

}