#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	float a, b, c;
	cout << "Введите первое число "; cin >> a;
	cout << "Введите второе число "; cin >> b;
	cout << "Введите третье число "; cin >> c;
	if(a<=b && a<=c)
		cout << "Наименьшее из чисел: " << a;
	else
	{
		if(b<=a && b<=c)
			cout << "Наименьшее из чисел: " << b;
		else 
		{
			cout << "Наименьшее из чисел: " << c;
		}
	}
	

}