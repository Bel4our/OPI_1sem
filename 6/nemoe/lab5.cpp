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
        cout << "Выберите вариант использования:" << endl;
        cout << "1 - Определение разницы в ASCII" << endl;
        cout << "2 - Определение разницы в Windows-1251" << endl;
        cout << "3 - Вывод кода символа, соответствующего цифре" << endl;
        cout << "4 - Выход из программы" << endl;

        cout << "Введите номер варианта (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Введите символ латинского алфавита: ";
            cin >> character;
            if (isalpha(character) && isascii(character))
            {
                int uppercaseCode = toupper(character);
                int lowercaseCode = tolower(character);
                int difference = uppercaseCode - lowercaseCode;
                cout << "Разница между кодами символов в прописном и строчном написании: " << abs(difference) << endl;
            }
            else
            {
                cout << "Символ не явл. буквой лат.алф." << endl;
            }
            break;

        case 2:

            cout << "Введите символ русского алфавита: ";
            cin >> character;
            if (character >= (0xc0) && character <= (0xff))
            {
                int uppercaseCode = toupper(character);
                int lowercaseCode = tolower(character);
                int difference = uppercaseCode - lowercaseCode;
                cout << "Разница между кодами символов в прописном и строчном написании: " << abs(difference) << endl;
            }
            else
            {
                cout << "Символ не явл. буквой рус.алф." << endl;
            }
            break;

        case 3:
            cout << "Введите цифру: ";
            cin >> character;
            if (isdigit(character))
            {
                int code = (character);
                cout << "Код символа '" << character << "': " << code << endl;
            }
            else
            {
                cout << "Ошибка: Введен символ, не являющийся цифрой." << endl;
            }
            break;

        case 4:
            cout << "Программа завершена." << endl;
            return 0;
        default:
            cout << "Ошибка: Введен неверный номер варианта. Попробуйте еще раз." << endl;
            break;
        }
    }

    return 0;
}