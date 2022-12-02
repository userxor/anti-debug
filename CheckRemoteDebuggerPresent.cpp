#include "stdafx.h"
#include <Windows.h>
#include <conio.h>
int _tmain(int argc, _TCHAR* argv[])
{
	BOOL debugbool = FALSE;
	CheckRemoteDebuggerPresent(GetCurrentProcess(), &debugbool);
	if (debugbool)
	{
		printf("good bye");
	}
	_getch();
	return 0;
}