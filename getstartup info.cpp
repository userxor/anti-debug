#include "stdafx.h"
#include <windows.h>
bool CheckDebug_STARTUPINFO()
{
	STARTUPINFO gsi = {};
	GetStartupInfo(&gsi);
	if (gsi.dwX || gsi.dwY || gsi.dwXSize || gsi.dwYSize)
	{
		return true;
	}
	return false;
}
int main()
{
	if (CheckDebug_STARTUPINFO())
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