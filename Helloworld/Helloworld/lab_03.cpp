#include <iostream>
// AlexandrovichIvan2005
// 0041 006C 0065 0078 0061 006E 0064 0072 006F 0076 0069 0063 0068  0049 0076 0061 006E  0032 0030 0030 0035
//
//

// �����������������2005
// 0410 043B 0435 043A 0441 0430 043D 0434 0440 043E 0432 0438 0447  0418 0432 0430 043D  0032 0030 0030 0035
//
//

// �������������2005Ivan
// 0410 043B 0435 043A 0441 0430 043D 0434 0440 043E 0432 0438 0447  0032 0030 0030 0035  0049 0076 0061 006E
//
//

int main()
{
    int number = 0x12345678;
    char hello[] = "Hello, ";
    char lfie[] = "AlexandrovichIvan2005";
    char rfie[] = "�����������������2005";
    char lr[] = "�������������2005Ivan";

    wchar_t Lfie[] = L"AlexandrovichIvan2005";
    wchar_t Rfie[] = L"�����������������2005";
    wchar_t Lr[] = L"�������������2005Ivan";

    std::cout << hello << lfie << std::endl;
    system("Pause");
}