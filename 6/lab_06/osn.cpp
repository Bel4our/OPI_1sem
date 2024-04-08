#include <iostream>
#include <Windows.h>
#include "case1.h"
#include "case2.h"
#include "case3.h"
#include "case4.h"
#include "symbol.h"
using namespace std;

int main()
{
	bool f=true;
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	while (f)
	{
		int k = symbol();
		switch (k) {
		case 1: case1(); break;
		case 2: case2(); break;
		case 3: case3(); break;
		case4: case4(); break;
		}
	}
}
