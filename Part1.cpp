#include <iostream>
#include <windows.h>
#include <vector>
#include <bitset>
#define ENG_ALPH 26

using namespace std;
void menu()
{
	cout << "1 - ��������� ���������� � �������������� �������" << endl;
	cout << "2 - ����������� ������� ����������� ������" << endl;
	cout << "3 - ����������� ��������� ����������� ������� ������" << endl;
	cout << "4 - �������������� ������� � �������������� ������ � � ������ ����� ������ ������ �������" << endl;
	cout << "5 - �������������� ������� � �������� ��� ���������� ������" << endl;
	cout << "6 - ������ ������ � ������ ������ �� �������� � ���������� �������" << endl;
	cout << "7 - ��������� ������ ������� ��� ��������� (� ����������) ������� ������ � �� ��������" << endl;
	cout << "8 - ������� ���������� ������ � ������������ ������� ��������� ������������ ���������(� ����������) ������� ������" << endl;
	cout << "9 - �����" << endl;
}
void MyVirtualQuery(void* AdFile)
{
	MEMORY_BASIC_INFORMATION lBuffer;
	int l;
	SIZE_T No_b;
	VirtualQuery(AdFile, &lBuffer, sizeof(lBuffer));
	cout << "��������� ������� �����: ";
	cout << lBuffer.BaseAddress << endl;
	cout << "������� ����� �������: ";
	cout << lBuffer.AllocationBase << endl;
	cout << "������� ������, ����������� ������� ��� ��� ��������������: ";
	cout << lBuffer.AllocationProtect << endl;
	cout << "C�������� ������ (� ������) ������ �������: ";
	cout << lBuffer.RegionSize << endl;
	cout << "��������� ������: ";
	if (lBuffer.State == 0x1000)
		cout << "MEM_COMMIT" << endl;
	else if (lBuffer.State == 0x2000)
		cout << "MEM_RESERVE" << endl;
	else if (lBuffer.State == 0x10000)
		cout << "MEM_FREE" << endl;
	cout << "������� ������ ���� ������� �������: ";
	if (lBuffer.Protect == PAGE_READONLY)
		cout << "PAGE_READONLY" << endl;
	else if (lBuffer.Protect == PAGE_READWRITE)
		cout << "PAGE_READWRITE" << endl;
	else if (lBuffer.Protect == PAGE_WRITECOPY)
		cout << "PAGE_WRITECOPY" << endl;
	else if (lBuffer.Protect == PAGE_READWRITE)
		cout << "PAGE_READWRITE" << endl;
	else if (lBuffer.Protect == PAGE_EXECUTE)
		cout << "PAGE_EXECUTE" << endl;
	else if (lBuffer.Protect == PAGE_EXECUTE_READ)
		cout << "PAGE_EXECUTE_READ" << endl;
	else if (lBuffer.Protect == PAGE_EXECUTE_READWRITE)
		cout << "PAGE_EXECUTE_READWRITE" << endl;
	else if (lBuffer.Protect == PAGE_EXECUTE_WRITECOPY)
		cout << "PAGE_EXECUTE_WRITECOPY" << endl;
	else if (lBuffer.Protect == PAGE_NOCACHE)
		cout << "PAGE_NOCACHE" << endl;
	else if (lBuffer.Protect == PAGE_GUARD)
		cout << "PAGE_GUARD" << endl;
	else
		cout << lBuffer.Protect << endl;
	cout << "��� ���������� ������, ��������� � ������� ������� �������: ";
	if (lBuffer.Type == MEM_PRIVATE)
		cout << "���� �������� ����������� ������� ����������� �� ���������� ������." << endl;
	else if (lBuffer.Type == MEM_IMAGE)
		cout << "���� �������� ����������� ������� ������������� ��� ����������� � ������� EXE- ��� DLL-�����, ������������� � ������, �� � ��������� ������ �������� ��� ���." << endl;
	else if (lBuffer.Type == MEM_MAPPED)
		cout << "���� �������� ����������� ������� ������������� ��� ����������� � ������ ������, ������������ � ������, �� � ��������� ������ �������� ��� ���." << endl;
}
int main()
{
	SYSTEM_INFO lpSystemInfo;
	MEMORYSTATUS lpBuffer;
	MEMORY_BASIC_INFORMATION lBuffer;
	int AdFile,AdFile1,AdFile2,AdFile3,AdFile4,AdFile5;
	int ch,k,g,l;
	int* arr = NULL,*arr1 = NULL;
	char str1[] = { "��������" };
	char* D = NULL;
	char* D1 = NULL;
	string str;
	system("chcp 1251");
	system("cls");
	do
	{
		menu();
		cin >> ch;
		switch (ch)
		{
		case 1:
			system("cls");
			GetSystemInfo(&lpSystemInfo);
			cout << "����������� ����������: ";
			if (lpSystemInfo.wProcessorArchitecture == 9)
				cout << "X64 (AMD ��� Intel)" << endl;
			else if (lpSystemInfo.wProcessorArchitecture == 6)
				cout << "Intel Itanium Processor Family (IPF)" << endl;
			else if (lpSystemInfo.wProcessorArchitecture == 0)
				cout << "X86" << endl;
			else
				cout << "����������� ��� ����������" << endl;
			cout << "���������������: ";
			cout << lpSystemInfo.wReserved << endl;
			cout << "������ �������� � ������������� ���������� ������ � �������������: " << endl;
			cout << lpSystemInfo.dwPageSize << endl;
			cout << "��������� �� ������� ����� ������, ��������� ����������� � ����������� ������������ ����������: " << endl;
			cout << lpSystemInfo.lpMinimumApplicationAddress << endl;
			cout << "��������� �� ������� ����� ������, ��������� ����������� � ����������� ������������ ����������: " << endl;
			cout << lpSystemInfo.lpMaximumApplicationAddress << endl;
			cout << "�����, �������������� ����� �����������, ������������������ � �������: " << endl;
			cout << lpSystemInfo.dwActiveProcessorMask << endl;
			cout << "���������� ����������� � �������: " << endl;
			cout << lpSystemInfo.dwNumberOfProcessors << endl;
			cout << "��� ����������: " << endl;
			cout << lpSystemInfo.dwProcessorType << endl;
			cout << "������������� ��� ���������� ������, � ������� ����� ���� �������� ����������� ������: ";
			cout << lpSystemInfo.dwAllocationGranularity << endl;
			cout << "������� ������������-���������� ���������� �������: ";
			if (lpSystemInfo.wProcessorLevel == PROCESSOR_ARCHITECTURE_INTEL)
				cout << "WProcessorLevel ������������ ����������� ����������" << endl;
			else if (lpSystemInfo.wProcessorLevel == PROCESSOR_ARCHITECTURE_IA64)
				cout << "���������� 1" << endl;
			cout << "������� ������������-���������� ����������: ";
			cout << lpSystemInfo.wProcessorRevision << endl;
			break;
		case 2:
			system("cls");
			lpBuffer.dwLength = sizeof(lpBuffer);
			GlobalMemoryStatus(&lpBuffer);
			cout << "������� ������������ ������: ";
			cout << lpBuffer.dwMemoryLoad << endl;
			cout << "����� ����� ���������� ������ � ������: ";
			cout << lpBuffer.dwTotalPhys << endl;
			cout << "����� ��������� ���������� ������ � ������: ";
			cout << lpBuffer.dwAvailPhys << endl;
			cout << "������ ����� �������� � ������: ";
			cout << lpBuffer.dwTotalPageFile << endl;
			cout << "��������� ����� ������ � ����� ��������: ";
			cout << lpBuffer.dwAvailPageFile << endl;
			cout << "����� ����� ����������� ������ � ������: ";
			cout << lpBuffer.dwTotalVirtual << endl;
			cout << "����� ��������� ����������� ������: ";
			cout << lpBuffer.dwAvailVirtual << endl;
			break;
		case 3:
			system("cls");
			cout << "������� ����� ������� ������: ";
			cin >> hex >> AdFile >> dec;
			MyVirtualQuery((void*)AdFile);
			break;
		case 4:
			system("cls");
			cout << "������� ����� ������� ������: ";
			cin >> hex >> AdFile1 >> dec;
			arr = (int*)VirtualAlloc((void*)AdFile1, 20 * sizeof(int), MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
			if (arr != NULL)
			{
				cout << "����� � ������ ��������������" << endl;
				cout << "address: 0x" << hex << AdFile1 << endl;
				MyVirtualQuery((void*)arr);
			}
			else
				cout << "��������� ������: " << endl;
			break;
		case 5:
			system("cls");
			cout << "������� ����� ������� ������: ";
			cin >> hex >> AdFile2 >> dec;
			arr1 = (int*)VirtualAlloc((void*)AdFile2, 20 * sizeof(int), MEM_RESERVE, PAGE_EXECUTE_READWRITE);
			if (arr1 != NULL)
			{
				cout << "����� � ������ ��������������" << endl;
				MyVirtualQuery((void*)arr1);
				arr1 = (int*)VirtualAlloc((void*)arr1, 20 * sizeof(int), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
				if (arr1 != NULL)
				{
					cout << "-----------------------" << endl;
					cout << "���������� ������ �������� ������� " << endl;
					MyVirtualQuery((void*)arr1);
				}
				else
					cout << "��������� ������ " << GetLastError << endl;
			}
			else
				cout << "��������� ������ " << GetLastError << endl;
			break;
		case 6:
			system("cls");
			cout << "������� ����� ������� ������: ";
			cin >> hex >> AdFile3 >> dec;
			cout << "������ ������: ";
			cin >> str;
			D = (char*)VirtualAlloc((void*)AdFile3, str.length(), MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
			if (D != NULL)
			{
				for (int i = 0;i < str.length();i++)
					*(D + i) = str[i];
				cout << "�������� ����c�: " << D << endl;
				if (VirtualFree((void*)D, str.length(), MEM_DECOMMIT))
					cout << "������ ���� ��������� �������" << endl;
				else
					cout << "��������� ������ " << GetLastError << endl;
			}
			else
				cout << "��������� ������ " << GetLastError << endl;
			break;
		case 7:
			system("cls");
			DWORD NewP,OldP;
			cout << "������� ����� ������� ������: ";
			cin >> hex >> AdFile4 >> dec;
			D1 = (char*)VirtualAlloc((void*)AdFile4,1024, MEM_RESERVE | MEM_COMMIT, PAGE_NOACCESS);
			if (D1!= NULL)
			{
				if (VirtualProtect((void*)D, 1024, PAGE_EXECUTE_READWRITE, &OldP)) {
					cout << "����� ������ �����������" << endl;
					MyVirtualQuery((void*)D);
					cout << "New Protect:" << hex << "PAGE_EXECUTE_READWRITE" << endl;
					cout << "Old Protect:" << hex << "PAGE_NOACCESS" << endl;
					D = str1;
					cout << D << endl;
					cout << "����� ������� ������ � ����� ������� " <<hex<< &D << dec<<endl;
				}
				else
					cout << "��������� ������ " << GetLastError << endl;
			}
			else
				cout << "��������� ������ " << GetLastError << endl;
			break;
		case 8:
			system("cls");
			cout << "������� ����� ������� ������: ";
			cin >> hex >> AdFile5 >> dec;
			VirtualFree((void*)AdFile5, 4096, MEM_RELEASE);
			cout << "���������" << endl;
			break;
		case 9:
			system("cls");
			cout << "����� ..." << endl;
			break;
		default:
			cout << "������ ������ � ���� ���";
			break;
		}
	} while (ch != 9);
	return 0;
}