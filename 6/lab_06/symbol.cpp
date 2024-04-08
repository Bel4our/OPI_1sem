#include <iostream>
#include "symbol.h"
#include <Windows.h>
using namespace std;
int symbol()
{
	int k;
	cout << "\nВыберите действие (1-Латиница в ASCII, 2-Русские в 1251, 3-Цифры, 4-Выход из программы) ";
	cin >> k;
	return k;
}