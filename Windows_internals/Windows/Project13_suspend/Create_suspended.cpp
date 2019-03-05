#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include<stdlib.h>
DWORD WINAPI thread_func(LPVOID data)
{
	for (int i = 0; i < 1000; i++)
	{
		printf("i=(%d)\n", i);
	}
	return 0;
}

int main()
{
	DWORD thID1;
	HANDLE hThread;
	hThread = CreateThread(NULL, 0, thread_func, NULL, CREATE_SUSPENDED, &thID1);
	
	if (NULL == hThread)
	{
		printf("Unable to create thread %d\n", GetLastError());
		getchar();
		return 0;
	}
	else
	{
		WaitForSingleObject(hThread, 5000);
		ResumeThread(hThread);//as in create_suspended mode the thread functioning resumes with this command.
	}
	

	getchar();
	CloseHandle(hThread);
	return 0;
}