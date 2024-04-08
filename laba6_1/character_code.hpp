#include <iostream>

using namespace std;

void printCharacterCode(char character)
{
  if (isdigit(character)) 
  {
    int code = character;
    cout << "Код символа = " << code << endl;
  }
  else
  {
    cout << "Символ не является цифрой" << endl;
  }
}