#include <iostream>

using namespace std;

void calculateWindows1251Difference(char character) 
{
  if ((character >= 'А' && character <= 'Я') || (character >= 'а' && character <= 'я')) 
  {
    int upperCaseCode = toupper(character);
    int lowerCaseCode = tolower(character);
    int difference = abs(upperCaseCode - lowerCaseCode);
    cout << "Вывод разницы " << difference << endl;
  }
  else
  {
    cout << "Символ не является буквой русского алфавита" << endl;
  }
}