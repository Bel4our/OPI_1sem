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
    cout << "\n�������� �������� (1-�������� � ASCII, 2-������� � 1251, 3-�����, 4-����� �� ���������) ";
    cin >> choice;
    switch (choice) 
    {
      case '1':
        cout << "������� �������� �� ������ ������? ";
        cin >> count;

        if (!cin) 
        {
          cout << "������������ ����";
          return;
        }
          
        for (int i = 1; i <= count; i++) 
        {
          cout << "������� ������ ���������� ��������: ";                
          cin >> character;
          calculateASCIIDifference(character);
        }
        break;
         
      case '2':
        cout << "������� �������� �� ������ ������? ";
        cin >> count;

        if (!cin)
        {
          cout << "������������ ����";
          return;
        }

        for (int i = 1; i <= count; i++)
        {
          cout << "������� ������ �������� ��������: ";
          cin >> character;
          calculateWindows1251Difference(character);
        }
        break;

      case '3':
        cout << "������� �������� �� ������ ������? ";
        cin >> count;

        if (!cin) 
        {
          cout << "������������ ����";
          return;
        }

        for (int i = 1; i <= count; i++) 
        {
          cout << "������� �����: ";
          cin >> character;
          printCharacterCode(character);
        }
        break;

      case '4':
        cout << "��������� ���������." << endl;
        return;

      default:
        cout << "������������ �����" << endl;
        break;
    }
  }
}