#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");

	string c;
	cin >> c;
	int r = size(c);
	if (r != 1) {
		cout << "(";
	}
	else {
		
		int s = c[0];
		if (s >= '0' && s <= '9')
			cout << s;
		else
			cout << "(";
	}
	
}