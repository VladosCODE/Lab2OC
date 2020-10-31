#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
using namespace std;

TCHAR Name[] = TEXT("Local\\MyFileMappingObject2");

int main()
{
	HANDLE MapFile,MyFile;
	LPCTSTR SMF;
	TCHAR* str = new TCHAR[100];
	system("chcp 1251");
	system("cls");
	MyFile = CreateFile("MyText.txt", GENERIC_READ | GENERIC_WRITE, NULL, NULL,CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (MyFile != INVALID_HANDLE_VALUE)
	{
		MapFile = CreateFileMapping(MyFile, NULL, PAGE_READWRITE, 0, 256, Name);
		if (MapFile != NULL)
		{
			SMF = (LPTSTR)MapViewOfFile(MapFile, FILE_MAP_ALL_ACCESS, 0, 0, 256);

			if (SMF != NULL)
			{
				cout << "Введите строку: ";
				cin >> str;
				CopyMemory((PVOID)SMF,str, (_tcslen(str) * sizeof(TCHAR)));
				_getch();
				UnmapViewOfFile(SMF);
				CloseHandle(MapFile);
				CloseHandle(MyFile);
			}
			else
			{
				cout << "Произошла ошибка " << GetLastError << " при отображении проецируемого файла в адресное пространство" << endl;
				CloseHandle(MapFile);
				CloseHandle(MyFile);
			}
		}
		else
		{
			cout << "Произошла ошибка " << GetLastError << " при создании проекции файла" << endl;
			CloseHandle(MapFile);
			CloseHandle(MyFile);
		}
	}
	else
	{
		cout << "Произошла ошибка " << GetLastError << " при создании файла" << endl;
		CloseHandle(MyFile);
	}
	return 0;

}