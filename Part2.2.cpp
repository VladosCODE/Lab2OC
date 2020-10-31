#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <tchar.h>
#pragma comment(lib, "user32.lib")

using namespace std;

TCHAR Name[] = TEXT("Local\\MyFileMappingObject2");

int main()
{
	HANDLE MapFile;
	LPCTSTR SMF;
	system("chcp 1251");
	system("cls");
	MapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS,FALSE,Name);               
	if (MapFile != NULL)
	{
		SMF = (LPTSTR)MapViewOfFile(MapFile, FILE_MAP_ALL_ACCESS, 0, 0, 256);
		if (SMF != NULL)
		{
			MessageBox(NULL, SMF, TEXT("Check_Window"), MB_OK);
			UnmapViewOfFile(SMF);
			CloseHandle(MapFile);
		}
		else
		{
			cout << "Произошла ошибка " << GetLastError << " при отображении проецируемого файла в адресное пространство" << endl;
			UnmapViewOfFile(SMF);
			CloseHandle(MapFile);
		}
	}
	else
	{
		cout << "Произошла ошибка " << GetLastError << " при открытии проекцируемого файла" << endl;
		CloseHandle(MapFile);
	}
	return 0;
}