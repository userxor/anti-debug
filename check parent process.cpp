#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <TlHelp32.h>
#include <conio.h>
int _tmain(int argc, _TCHAR* argv[])
{
	int pid;
	int exp_pid;
	HANDLE handle = INVALID_HANDLE_VALUE;
	PROCESSENTRY32 pe = {0};
	pe.dwSize = sizeof(PROCESSENTRY32);
	pid = GetCurrentProcessId();
	handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (Process32First(handle, &pe))
	{
		do if (!_tcsicmp(pe.szExeFile, _T("explorer.exe")))
			exp_pid = pe.th32ProcessID;
		while (Process32Next(handle, &pe));
	}
	if (Process32First(handle, &pe))
	{
		do if (pe.th32ProcessID == pid)
		if (pe.th32ParentProcessID == exp_pid)
		{
			printf("explorer");
		}
		else
		{
			printf("not explorer");
		}
		while (Process32Next(handle, &pe));
	}
	CloseHandle(handle);
	_getche();
	return 0;
}