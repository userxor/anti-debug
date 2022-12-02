#include "stdafx.h"
#include <Windows.h>
#include <conio.h>
int _tmain(int argc, _TCHAR* argv[])
{
	HWND Find = FindWindow(NULL, L"OllyDbg");
	if (Find)
	{
		printf("hi");
	}
	_getch();
	return 0;
}