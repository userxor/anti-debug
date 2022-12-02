#include "stdafx.h"
#include <Windows.h>
#include <conio.h>
#define HOOKS_H
int _tmain(int argc, _TCHAR* argv[])
{
	DWORD *dwAddress = (DWORD *)ShellExecuteExW;
	BYTE *b = (BYTE *)dwAddress;
	if ((*b == 0x8b) && (*(b + 1) == 0xff))
	{
		printf("not detect");
	}
	else
	{
		printf("detect");
	}
	_getch();
	return 0;
}