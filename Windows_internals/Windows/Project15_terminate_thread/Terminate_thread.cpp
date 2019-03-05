#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include<stdlib.h>
DWORD exitcode = 1;
DWORD WINAPI thread_func(LPVOID iparam)
{
	for (int i = 0; i < 10; i++)
	{
		printf("i=(%d)\n", i);
		Sleep(1000);
	}
	return 0;
}

int main()
{
	DWORD thID1;
	HANDLE hThread;
	hThread = CreateThread(NULL, 0, thread_func, NULL, 0, &thID1);
	if (hThread == NULL)
	{
		printf("unable to create the thread");
		getchar();
		return 1;
	}
	WaitForSingleObject(hThread, 5000);
	TerminateThread(hThread, exitcode);//thread can be terminated outside using terminatethread.
	BOOL ret = GetExitCodeThread(hThread, &exitcode);
	printf("exitcode %d ", exitcode);
	if (ret == 0)
	{
		printf("thread closed unsuccessfully \n");

	}
	else
		printf("closed successfully\n");


	
	getchar();
	CloseHandle(hThread);
	return 0;
}