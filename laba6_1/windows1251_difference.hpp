#include <iostream>

using namespace std;

void calculateWindows1251Difference(char character) 
{
  if ((character >= '�' && character <= '�') || (character >= '�' && character <= '�')) 
  {
    int upperCaseCode = toupper(character);
    int lowerCaseCode = tolower(character);
    int difference = abs(upperCaseCode - lowerCaseCode);
    cout << "����� ������� " << difference << endl;
  }
  else
  {
    cout << "������ �� �������� ������ �������� ��������" << endl;
  }
}