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
        cout << "������� = " << difference << endl;
    }
    else {  
        cout << "������ �� �������� ������ ���������� ��������" << endl;
    }
}

void case2(char character) {  
    if ((character >= '�' && character <= '�') || (character <= '�' && character >= '�')) {  
        int uppercaseCode = toupper(character);
        int lowercaseCode = tolower(character);
        int difference = abs(uppercaseCode - lowercaseCode);
        cout << "������� = " << difference << endl;
    }
    else {  
        cout << "������ �� �������� ������ �������� ��������" << endl;
    }
}

void case3(char character) {  
    if (isdigit(character)) {  
        int code = static_cast<int>(character);
        cout << "��� ������� = "<< code << endl;
    }
    else {  
        cout << "�� ����� ������������ ��������" << endl;
    }
}