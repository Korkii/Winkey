#include <windows.h>
#include <stdio.h>
#define LIBRARY "D:\\xorwork\\win\\mydll\\Debug\\mydll.dll"

typedef int(*PFUNC)(void);

int main()
{
	HMODULE hModule = LoadLibraryA(LIBRARY);
	if (hModule == NULL) {
		printf("failed to library\n");
		return 0;
	}
	PFUNC pFunc = (PFUNC)GetProcAddress(hModule, "DisplayMessageBox");
	if (pFunc != NULL) {
		(*pFunc)();
	}
	else {
		printf("failed to load\n");
	}
	return 0;
}