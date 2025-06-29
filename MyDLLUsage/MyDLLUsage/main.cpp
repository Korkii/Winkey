#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>


typedef int(*PFUNC)(void);

int main()
{
	DWORD TargetPID;
	std::cout << "Please type a number: " << std::endl;
	if (!(std::cin >> TargetPID)) {
		std::cout << "Bad input" << std::endl;
		return 1;
	}

	const char* PATH_BUF = "z:\\sus.dll";
	HANDLE TargetProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, FALSE, TargetPID);
	LPVOID PathAddress = VirtualAllocEx(TargetProcess, NULL, std::strlen(path_buf) + 1, MEM_COMMIT, PAGE_READWRITE);
	int WriteResult = WriteProcessMemory(TargetProcess, PathAddress, path_buf, std::strlen(path_buf) + 1, NULL);
	if (WriteResult == FALSE) 
	{
		std::cout << "Writing Failed" << std::endl;
	}
	HANDLE newThread = CreateRemoteThread(TargetProcess, NULL, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, PathAddress, 0, NULL);
	if (newThread == NULL) {
		std::cout << "CreateRemoteThread Failed" << std::endl;
	}
	return 0;
}
