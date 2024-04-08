#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int k, diff;
	char A, a;
	cout << "Выберите действие (1-4) ";
	cin >> k;
	switch (k)
	{
	case 1:
	{
		cout << "Ведите прописную букву "; cin >> A;
		cout << "Ведите строчную букву "; cin >> a;
		diff = abs(A - a);
		cout << "Разница - " << diff;
	}
	break;
	case 2:
	{
		cout << "Ведите прописную букву "; cin >> A;
		cout << "Ведите строчную букву "; cin >> a;
		diff = abs(A - a);
		cout << "Разница - "<<hex<<diff;
	}
	case 3: 
	{

	}
	}
}