#include "stdafx.h"
#include <Windows.h>
#include <conio.h>
int _tmain(int argc, _TCHAR* argv[])
{
	if (IsDebuggerPresent())
	{
		printf("detect");
	}
	else
	{
		printf("not detect");
	}
	_getch();
	return 0;
}