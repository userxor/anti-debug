#include "stdafx.h"
#include <Windows.h>
#include <cstdio>
#include <TlHelp32.h>
#include <conio.h>
int _tmain(int argc, _TCHAR* argv[])
{
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry) == TRUE)
	{
		while (Process32Next(snapshot, &entry) == TRUE)
		{
			if (_stricmp(entry.szExeFile, "notepad.exe") == 0)
			{
				HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
				printf("hi");
				CloseHandle(hProcess);
			}
		}
	}
	CloseHandle(snapshot);
	_getch();
	return 0;
}