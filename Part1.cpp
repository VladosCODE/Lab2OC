#include <iostream>
#include <windows.h>
#include <vector>
#include <bitset>
#define ENG_ALPH 26

using namespace std;
void menu()
{
	cout << "1 - Получение информации о вычислительной системе" << endl;
	cout << "2 - Определение статуса виртуальной памяти" << endl;
	cout << "3 - Определения состояния конкретного участка памяти" << endl;
	cout << "4 - Резервирование региона в автоматическом режиме и в режиме ввода адреса начала региона" << endl;
	cout << "5 - Резервирование региона и передача ему физической памяти" << endl;
	cout << "6 - Запись данных в ячейки памяти по заданным с клавиатуры адресам" << endl;
	cout << "7 - Установку защиты доступа для заданного (с клавиатуры) региона памяти и ее проверку" << endl;
	cout << "8 - Возврат физической памяти и освобождение региона адресного пространства заданного(с клавиатуры) региона памяти" << endl;
	cout << "9 - Выход" << endl;
}
void MyVirtualQuery(void* AdFile)
{
	MEMORY_BASIC_INFORMATION lBuffer;
	int l;
	SIZE_T No_b;
	VirtualQuery(AdFile, &lBuffer, sizeof(lBuffer));
	cout << "Ближайший меньший адрес: ";
	cout << lBuffer.BaseAddress << endl;
	cout << "Базовый адрес региона: ";
	cout << lBuffer.AllocationBase << endl;
	cout << "Атрибут защиты, присвоенный региону при его резервировании: ";
	cout << lBuffer.AllocationProtect << endl;
	cout << "Cуммарный размер (в байтах) группы страниц: ";
	cout << lBuffer.RegionSize << endl;
	cout << "Состояние памяти: ";
	if (lBuffer.State == 0x1000)
		cout << "MEM_COMMIT" << endl;
	else if (lBuffer.State == 0x2000)
		cout << "MEM_RESERVE" << endl;
	else if (lBuffer.State == 0x10000)
		cout << "MEM_FREE" << endl;
	cout << "Атрибут защиты всех смежных страниц: ";
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
	cout << "Тип физической памяти, связанной с группой смежных страниц: ";
	if (lBuffer.Type == MEM_PRIVATE)
		cout << "Этот диапазон виртуальных адресов сопоставлен со страничным файлом." << endl;
	else if (lBuffer.Type == MEM_IMAGE)
		cout << "Этот диапазон виртуальных адресов первоначально был сопоставлен с образом EXE- или DLL-файла, проецируемого в память, но в настоящий момент возможно уже нет." << endl;
	else if (lBuffer.Type == MEM_MAPPED)
		cout << "Этот диапазон виртуальных адресов первоначально был сопоставлен с файлом данных, проецируемым в память, но в настоящий момент возможно уже нет." << endl;
}
int main()
{
	SYSTEM_INFO lpSystemInfo;
	MEMORYSTATUS lpBuffer;
	MEMORY_BASIC_INFORMATION lBuffer;
	int AdFile,AdFile1,AdFile2,AdFile3,AdFile4,AdFile5;
	int ch,k,g,l;
	int* arr = NULL,*arr1 = NULL;
	char str1[] = { "Проверка" };
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
			cout << "Архитектура процессора: ";
			if (lpSystemInfo.wProcessorArchitecture == 9)
				cout << "X64 (AMD или Intel)" << endl;
			else if (lpSystemInfo.wProcessorArchitecture == 6)
				cout << "Intel Itanium Processor Family (IPF)" << endl;
			else if (lpSystemInfo.wProcessorArchitecture == 0)
				cout << "X86" << endl;
			else
				cout << "Неизвестный тип процессора" << endl;
			cout << "Зарезервировано: ";
			cout << lpSystemInfo.wReserved << endl;
			cout << "Размер страницы и гранулярность страничной защиты и обязательства: " << endl;
			cout << lpSystemInfo.dwPageSize << endl;
			cout << "Указатель на младший адрес памяти, доступный приложениям и библиотекам динамической компоновки: " << endl;
			cout << lpSystemInfo.lpMinimumApplicationAddress << endl;
			cout << "Указатель на старший адрес памяти, доступный приложениям и библиотекам динамической компоновки: " << endl;
			cout << lpSystemInfo.lpMaximumApplicationAddress << endl;
			cout << "Маска, представляющая набор процессоров, сконфигурированных в системе: " << endl;
			cout << lpSystemInfo.dwActiveProcessorMask << endl;
			cout << "Количество процессоров в системе: " << endl;
			cout << lpSystemInfo.dwNumberOfProcessors << endl;
			cout << "Тип процессора: " << endl;
			cout << lpSystemInfo.dwProcessorType << endl;
			cout << "Гранулярность для начального адреса, в котором может быть выделена виртуальная память: ";
			cout << lpSystemInfo.dwAllocationGranularity << endl;
			cout << "Уровень архитектурно-зависимого прицессора системы: ";
			if (lpSystemInfo.wProcessorLevel == PROCESSOR_ARCHITECTURE_INTEL)
				cout << "WProcessorLevel определяется поставщиком процессора" << endl;
			else if (lpSystemInfo.wProcessorLevel == PROCESSOR_ARCHITECTURE_IA64)
				cout << "установлен 1" << endl;
			cout << "Ревизия архитектурно-зависимого процессора: ";
			cout << lpSystemInfo.wProcessorRevision << endl;
			break;
		case 2:
			system("cls");
			lpBuffer.dwLength = sizeof(lpBuffer);
			GlobalMemoryStatus(&lpBuffer);
			cout << "Процент используемой памяти: ";
			cout << lpBuffer.dwMemoryLoad << endl;
			cout << "Общий объем физической памяти в байтах: ";
			cout << lpBuffer.dwTotalPhys << endl;
			cout << "Объем доступной физической памяти в байтах: ";
			cout << lpBuffer.dwAvailPhys << endl;
			cout << "Размер файла подкачки в байтах: ";
			cout << lpBuffer.dwTotalPageFile << endl;
			cout << "Доступный объем байтов в файле подкачки: ";
			cout << lpBuffer.dwAvailPageFile << endl;
			cout << "Общий объем виртуальной памяти в байтах: ";
			cout << lpBuffer.dwTotalVirtual << endl;
			cout << "Объем доступной виртуальной памяти: ";
			cout << lpBuffer.dwAvailVirtual << endl;
			break;
		case 3:
			system("cls");
			cout << "Введите адрес участка памяти: ";
			cin >> hex >> AdFile >> dec;
			MyVirtualQuery((void*)AdFile);
			break;
		case 4:
			system("cls");
			cout << "Введите адрес участка памяти: ";
			cin >> hex >> AdFile1 >> dec;
			arr = (int*)VirtualAlloc((void*)AdFile1, 20 * sizeof(int), MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
			if (arr != NULL)
			{
				cout << "Адрес в памяти зарезервирован" << endl;
				cout << "address: 0x" << hex << AdFile1 << endl;
				MyVirtualQuery((void*)arr);
			}
			else
				cout << "Произошла ошибка: " << endl;
			break;
		case 5:
			system("cls");
			cout << "Введите адрес участка памяти: ";
			cin >> hex >> AdFile2 >> dec;
			arr1 = (int*)VirtualAlloc((void*)AdFile2, 20 * sizeof(int), MEM_RESERVE, PAGE_EXECUTE_READWRITE);
			if (arr1 != NULL)
			{
				cout << "Адрес в памяти зарезервирован" << endl;
				MyVirtualQuery((void*)arr1);
				arr1 = (int*)VirtualAlloc((void*)arr1, 20 * sizeof(int), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
				if (arr1 != NULL)
				{
					cout << "-----------------------" << endl;
					cout << "Физическая память передана региону " << endl;
					MyVirtualQuery((void*)arr1);
				}
				else
					cout << "Произошла ошибка " << GetLastError << endl;
			}
			else
				cout << "Произошла ошибка " << GetLastError << endl;
			break;
		case 6:
			system("cls");
			cout << "Введите адрес участка памяти: ";
			cin >> hex >> AdFile3 >> dec;
			cout << "Введие строку: ";
			cin >> str;
			D = (char*)VirtualAlloc((void*)AdFile3, str.length(), MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
			if (D != NULL)
			{
				for (int i = 0;i < str.length();i++)
					*(D + i) = str[i];
				cout << "Проверка запиcи: " << D << endl;
				if (VirtualFree((void*)D, str.length(), MEM_DECOMMIT))
					cout << "Запись была проведена успешно" << endl;
				else
					cout << "Произошла ошибка " << GetLastError << endl;
			}
			else
				cout << "Произошла ошибка " << GetLastError << endl;
			break;
		case 7:
			system("cls");
			DWORD NewP,OldP;
			cout << "Введите адрес участка памяти: ";
			cin >> hex >> AdFile4 >> dec;
			D1 = (char*)VirtualAlloc((void*)AdFile4,1024, MEM_RESERVE | MEM_COMMIT, PAGE_NOACCESS);
			if (D1!= NULL)
			{
				if (VirtualProtect((void*)D, 1024, PAGE_EXECUTE_READWRITE, &OldP)) {
					cout << "Новая защита установлена" << endl;
					MyVirtualQuery((void*)D);
					cout << "New Protect:" << hex << "PAGE_EXECUTE_READWRITE" << endl;
					cout << "Old Protect:" << hex << "PAGE_NOACCESS" << endl;
					D = str1;
					cout << D << endl;
					cout << "Адрес участка памяти с новой защитой " <<hex<< &D << dec<<endl;
				}
				else
					cout << "Произошла ошибка " << GetLastError << endl;
			}
			else
				cout << "Произошла ошибка " << GetLastError << endl;
			break;
		case 8:
			system("cls");
			cout << "Введите адрес участка памяти: ";
			cin >> hex >> AdFile5 >> dec;
			VirtualFree((void*)AdFile5, 4096, MEM_RELEASE);
			cout << "Освобождён" << endl;
			break;
		case 9:
			system("cls");
			cout << "Выход ..." << endl;
			break;
		default:
			cout << "Такого пункта в меню нет";
			break;
		}
	} while (ch != 9);
	return 0;
}