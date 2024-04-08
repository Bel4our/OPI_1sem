#include <iostream>
// SemenovDaniil2006
// 53 65 6D 65 6E 6F 76 44 61 6E 69 69 6C 32 30 30 36
// 53 65 6d 65 6e 6f 76 44 61 6e 69 69 6c 32 30 30 36 
// 53 00 65 00 6d 00 65 00 6e 00 6f 00 76 00 44 00 61 00 6e 00 69 00 69 00 6c 00 32 00 30 00 30 00 36 00


// СемёновДаниил2006
// D1 E5 EC B8 ED EE E2 C4 E0 ED E8 E8 32 30 30 36
// D0A1 D0B5 D0BC D191 D0BD D0BE D0B2 D094 D0B0 D0BD D0B8 D0B8 D0BB 32 30 30 36
// 21 04 35 04 3c 04 51 04 3d 04 3e 04 32 04 14 04 30 04 3d 04 38 04 38 04 3b 00 32 00 30 00 30 00 36 00



// Семёнов2006Daniil
// D1 E5 EC B8 ED EE E2 32 30 30 30 36 44 61 6E 69 69 6C
// D0A1 D0B5 D0BC D191 D0BD D0BE D0B 32 30 30 36 44 61 6E 69 69 6C
// 21 04 35 04 3c 04 51 04 3d 04 3e 04 32 00 32 00 30 00 30 00 36 00 44 00 61 00 6e 00 69 00 69 00 6c 00


int main()
{
	int number = 0x12345678;
	char hello[] = "Hello, ";
	char lfie[] = "SemenovDaniil2006";
	char rfie[] = "СемёновДаниил2006";
	char lr[] = "Семёнов2006Daniil";

	wchar_t Lfie[] = L"SemenovDaniil2006";
	wchar_t Rfie[] = L"СемёновДаниил2006";
	wchar_t LR[] = L"Семёнов2006Daniil";

	std::cout << hello << lfie << std::endl;
	return 0;

}