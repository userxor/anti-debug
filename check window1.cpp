#include "stdafx.h"
#include <windows.h>
BOOL CALLBACK EnumWindowProc(HWND hWnd, LPARAM lParam)
{
	TCHAR winTitle[0x100] = {};
	GetWindowText(hWnd, winTitle, 0x100);
	if (_tcsstr(winTitle, TEXT("Chrome")))
	{
		*((int*)lParam) = true;
		return false;
	}
	return true;
}
bool CheckDebug_EnumWindow()
{
	int nFind = false;
	EnumWindows(EnumWindowProc, (LPARAM)&nFind);
	return nFind != 0;
}
int main()
{
	if (CheckDebug_EnumWindow())
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	getchar();
	return 0;
}