#include <iostream> 
#include <clocale>
#include <cctype>
#include <Windows.h>

using namespace std;

int main()
{

    setlocale(LC_CTYPE, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    unsigned char character;

    while (true)
    {
        cout << "�������� ������� �������������:" << endl;
        cout << "1 - ����������� ������� � ASCII" << endl;
        cout << "2 - ����������� ������� � Windows-1251" << endl;
        cout << "3 - ����� ���� �������, ���������������� �����" << endl;
        cout << "4 - ����� �� ���������" << endl;

        cout << "������� ����� �������� (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "������� ������ ���������� ��������: ";
            cin >> character;
            if (isalpha(character) && isascii(character))
            {
                int uppercaseCode = toupper(character);
                int lowercaseCode = tolower(character);
                int difference = uppercaseCode - lowercaseCode;
                cout << "������� ����� ������ �������� � ��������� � �������� ���������: " << abs(difference) << endl;
            }
            else
            {
                cout << "������ �� ���. ������ ���.���." << endl;
            }
            break;

        case 2:

            cout << "������� ������ �������� ��������: ";
            cin >> character;
            if (character >= (0xc0) && character <= (0xff))
            {
                int uppercaseCode = toupper(character);
                int lowercaseCode = tolower(character);
                int difference = uppercaseCode - lowercaseCode;
                cout << "������� ����� ������ �������� � ��������� � �������� ���������: " << abs(difference) << endl;
            }
            else
            {
                cout << "������ �� ���. ������ ���.���." << endl;
            }
            break;

        case 3:
            cout << "������� �����: ";
            cin >> character;
            if (isdigit(character))
            {
                int code = (character);
                cout << "��� ������� '" << character << "': " << code << endl;
            }
            else
            {
                cout << "������: ������ ������, �� ���������� ������." << endl;
            }
            break;

        case 4:
            cout << "��������� ���������." << endl;
            return 0;
        default:
            cout << "������: ������ �������� ����� ��������. ���������� ��� ���." << endl;
            break;
        }
    }

    return 0;
}