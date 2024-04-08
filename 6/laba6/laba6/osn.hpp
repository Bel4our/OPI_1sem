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
        cout << "\nВыберите действие (1-Латиница в ASCII, 2-Русские в 1251, 3-Цифры, 4-Выход из программы) ";
        cin >> choice;

        switch (choice) {
        case '1':
            cout << "Сколько символов вы хотите ввести? ";
            cin >> n;
            if (!cin) {
                cout << "Некорректный ввод";
                return;
            }
            else {
                for (int i = 1; i <= n; i++) {
                    cout << "Введите символ латинского алфавита: ";
                    cin >> character;
                    case1(character);
                }
            }
            break;
           
        case '2':
            cout << "Сколько символов вы хотите ввести? ";
           
            cin >> n;
            if (!cin) {
                cout << "Некорректный ввод";
                return;
            }
            else {
                for (int i = 1; i <= n; i++) {
                    cout << "Введите символ русского алфавита: ";
                    cin >> character;
                    case2(character);
                }
            }
            break;
        case '3':
            cout << "Сколько символов вы хотите ввести? ";
           
            cin >> n;
            if (!cin) {
                cout << "Некорректный ввод";
                return;
            }
            else {
                for (int i = 1; i <= n; i++) {
                    cout << "Введите цифру: ";
                    cin >> character;
                    case3(character);
                }
            }
            break;
        case '4':
            cout << "Программа завершена" << endl;
            f = false;
            break;
        default:
            cout << "Некорректный выбор" << endl;
            break;
        }
    }

 
}