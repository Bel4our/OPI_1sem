#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	float x, sum = 0;
	string s;
	while (sum <= 5)
	{
		cout << "¬ведите название товара: "; cin >> s;
		cout << "¬ведите цену товара: "; cin >> x; cout << endl;
		sum += x;
		if (sum<= 5)
		{
			cout << s << ": " << x << endl;
		}
		
	}
}