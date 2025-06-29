#include <windows.h>
#include <winuser.h>
#include <stdio.h>
#define DLL_EXPORT
#include "mydll.h"

extern "C"
{
	DECLDIR void Share()
	{
		printf("Exported func\n");
	}


	DECLDIR int DisplayMessageBox()
	{
		int msgboxID = MessageBox(
			NULL,
			(LPCWSTR)L"Visual Studio made me sad",
			(LPCWSTR)L"top 3 worst programs to exist",
			MB_ICONINFORMATION
		);

		switch (msgboxID)
		{
		case IDCANCEL:
			// TODO: add code
			break;

		}
		return msgboxID;
	}

	void Keep()
	{
		printf("Not exported in DLL \n");
	}
}

BOOL APIENTRY DllMain(
	HANDLE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Share();
		Keep();
		break;
	
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}