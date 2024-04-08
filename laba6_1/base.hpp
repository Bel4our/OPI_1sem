#include <iostream>
#include <Windows.h>
#include "ascii_difference.hpp"
#include "windows1251_difference.hpp"
#include "character_code.hpp"

using namespace std;

void callBase()
{
  setlocale(LC_CTYPE, "Russian");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  char choice;
  char character;
  int count;

  while (true) 
  {
    cout << "\nВыберите действие (1-Латиница в ASCII, 2-Русские в 1251, 3-Цифры, 4-Выход из программы) ";
    cin >> choice;
    switch (choice) 
    {
      case '1':
        cout << "Сколько символов вы хотите ввести? ";
        cin >> count;

        if (!cin) 
        {
          cout << "Некорректный ввод";
          return;
        }
          
        for (int i = 1; i <= count; i++) 
        {
          cout << "Введите символ латинского алфавита: ";                
          cin >> character;
          calculateASCIIDifference(character);
        }
        break;
         
      case '2':
        cout << "Сколько символов вы хотите ввести? ";
        cin >> count;

        if (!cin)
        {
          cout << "Некорректный ввод";
          return;
        }

        for (int i = 1; i <= count; i++)
        {
          cout << "Введите символ русского алфавита: ";
          cin >> character;
          calculateWindows1251Difference(character);
        }
        break;

      case '3':
        cout << "Сколько символов вы хотите ввести? ";
        cin >> count;

        if (!cin) 
        {
          cout << "Некорректный ввод";
          return;
        }

        for (int i = 1; i <= count; i++) 
        {
          cout << "Введите цифру: ";
          cin >> character;
          printCharacterCode(character);
        }
        break;

      case '4':
        cout << "Программа завершена." << endl;
        return;

      default:
        cout << "Некорректный выбор" << endl;
        break;
    }
  }
}