#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include<iostream>
using namespace std;
DWORD exitcode;
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
	 DWORD ret = WaitForSingleObject(hThread, 2000);
	 switch (ret)
	 {
	 case WAIT_TIMEOUT:
		 cout << "TIMEOUT_interval" << endl;
		 break;
	 case WAIT_FAILED: cout << "failed" << endl;
		 break;
	 case WAIT_OBJECT_0:cout << "Thread Terminated\n" << endl;
		 break;
	 }
	// printf("thread creation successfull\n");

	//printf("waiting for user input before exiting the process\n");
	getchar();
	CloseHandle(hThread);
	return 0;
}