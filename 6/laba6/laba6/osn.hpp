#include <iostream>
#include <clocale>
#include <cctype>
#include <Windows.h>
#include "process.hpp"


using namespace std;

void osn() {
    setlocale(LC_CTYPE, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char choice;
    char character;
    int n;
    bool f = true;

    while (f) {
        cout << "\n�������� �������� (1-�������� � ASCII, 2-������� � 1251, 3-�����, 4-����� �� ���������) ";
        cin >> choice;

        switch (choice) {
        case '1':
            cout << "������� �������� �� ������ ������? ";
            cin >> n;
            if (!cin) {
                cout << "������������ ����";
                return;
            }
            else {
                for (int i = 1; i <= n; i++) {
                    cout << "������� ������ ���������� ��������: ";
                    cin >> character;
                    case1(character);
                }
            }
            break;
           
        case '2':
            cout << "������� �������� �� ������ ������? ";
           
            cin >> n;
            if (!cin) {
                cout << "������������ ����";
                return;
            }
            else {
                for (int i = 1; i <= n; i++) {
                    cout << "������� ������ �������� ��������: ";
                    cin >> character;
                    case2(character);
                }
            }
            break;
        case '3':
            cout << "������� �������� �� ������ ������? ";
           
            cin >> n;
            if (!cin) {
                cout << "������������ ����";
                return;
            }
            else {
                for (int i = 1; i <= n; i++) {
                    cout << "������� �����: ";
                    cin >> character;
                    case3(character);
                }
            }
            break;
        case '4':
            cout << "��������� ���������" << endl;
            f = false;
            break;
        default:
            cout << "������������ �����" << endl;
            break;
        }
    }

 
}