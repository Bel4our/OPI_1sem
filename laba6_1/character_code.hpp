#include <iostream>

using namespace std;

void printCharacterCode(char character)
{
  if (isdigit(character)) 
  {
    int code = character;
    cout << "��� ������� = " << code << endl;
  }
  else
  {
    cout << "������ �� �������� ������" << endl;
  }
}