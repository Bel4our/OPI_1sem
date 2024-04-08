#include <iostream>
#include <clocale>
#include <cctype>
#include <Windows.h>

using namespace std;

void case1(char character) {  

    setlocale(LC_CTYPE, "Russian");

    if ((character >= 'A' && character <= 'Z') || (character <= 'z' && character >= 'a')) {  
        int uppercaseCode = toupper(character);
        int lowercaseCode = tolower(character);
        int difference = abs(uppercaseCode - lowercaseCode);
        cout << "Разница = " << difference << endl;
    }
    else {  
        cout << "Символ не является буквой латинского алфавита" << endl;
    }
}

void case2(char character) {  
    if ((character >= 'А' && character <= 'Я') || (character <= 'я' && character >= 'а')) {  
        int uppercaseCode = toupper(character);
        int lowercaseCode = tolower(character);
        int difference = abs(uppercaseCode - lowercaseCode);
        cout << "Разница = " << difference << endl;
    }
    else {  
        cout << "Символ не является буквой русского алфавита" << endl;
    }
}

void case3(char character) {  
    if (isdigit(character)) {  
        int code = static_cast<int>(character);
        cout << "Код символа = "<< code << endl;
    }
    else {  
        cout << "Вы ввели неправильное значение" << endl;
    }
}