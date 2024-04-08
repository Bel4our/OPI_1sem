#include <iostream>

using namespace std;

void calculateASCIIDifference(char character)
{
  if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z')) 
  {
    int upperCaseCode = toupper(character);
    int lowerCaseCode = tolower(character);
    int difference = abs(upperCaseCode - lowerCaseCode);
    cout << "Вывод разницы " << difference << endl;
  } 
  else
  {
    cout << "Символ не является буквой латинского алфавита" << endl;
  }
}