#include <iostream>
#include <Windows.h>
#include <thread>
#include <ctime>

#include "globals.h"
#include "classicMode.h"
#include "symmetricMode.h"
#include "selfEater.h"



using namespace std;

int main() {
	CreateField();
	CursorVisible(false);

	srand(time(NULL));

	char mode;
	
	while (programWork) {
		cout << "1 - classic mode\n2 - self eater\n3 - symmetric mode\n4 - exit " << endl;
		cin >> mode;
		switch (mode)
		{
		case '1':
			ClassicMode();
			break;
		case '2':
			selfEater();
			break;
		case '3':
			symmetricMode();
			break;
		case '4':
			programWork = false;
			break;
		default:
			cout << "wrong answer\n";
			break;
		}
	}
	return 0;
}