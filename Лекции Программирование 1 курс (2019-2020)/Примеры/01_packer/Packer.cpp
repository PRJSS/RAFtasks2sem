// Packer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

// Функция для проверки и корректировки текста.
// Удаляет неподдерживаемые символы
// Поддерживаемые символы: 'a' - 'z', 'A' - 'Z', ' ', ',', '.'
// Переданная строка модифицируется
// возвращает длину полученной очищенной строки 
DWORD CheckTextIsCorrect(char* sText)
{
	char* psOut = sText;
	char* psIn = sText;
	while(*psIn != 0)
	{
		if (*psIn >= 'A' && *psIn <= 'Z')
			*psOut++ = *psIn;
		else if (*psIn >= 'a' && *psIn <= 'z')
			*psOut++ = *psIn;
		else if (*psIn == ' ' || *psIn == ',' || *psIn == '.')
			*psOut++ = *psIn;
		psIn++;
	}
	*psOut = 0;
	return psOut - sText;
}

int main(int argc, char* argv[])
{
	cout << "The program for basic coding of messages v0.9" << endl;
	cout << "Warning: the program supports english letters and spaces only" << endl;
	char sMessage[4096];
	cout << "Please, enter the message: ";
	cin.getline(sMessage, 4096);
	cout << endl;
	if (!CheckTextIsCorrect(sMessage))
	{
		cout << "Message is incorrect or zero length." << endl;
		_getch();
		return 0;
	}
	DWORD iPassword = GetTickCount();
	srand(iPassword);
	cout << endl << "Your password is: " << iPassword << endl;
	cout << "Message: " << sMessage << endl << endl;
	
	cout << "Coded message: " << endl;
	
	cout << setbase(16) << setfill('0') << setw(2);
	for (int i = 0; sMessage[i]; i++)
	{
		sMessage[i] ^= rand();
		cout << "0x" << setw(2) << (UINT)(BYTE)sMessage[i] << ", ";
		if (i % 12 == 11)
			cout << endl;
	}
	cout << endl;
	_getch();
	return 0;
}

