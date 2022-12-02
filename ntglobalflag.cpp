#include "stdafx.h"
#include <intrin.h>
#include <conio.h>
bool MethodNtGlobalFlag()
{
	auto peb = (char*)__readfsdword(0x30);
	auto ntGlobalFlag = *(peb + 0x68);
	return ((ntGlobalFlag & 0x70) == 0x70);
}
int _tmain(int argc, _TCHAR* argv[])
{
	if (MethodNtGlobalFlag())
	{
		printf("hi");
	}
	_getche();
	return 0;
}