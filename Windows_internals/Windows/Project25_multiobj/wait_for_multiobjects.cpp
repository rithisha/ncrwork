#include<Windows.h>
#include<stdio.h>
#include<iostream>
using namespace std;
DWORD WINAPI thread_function(LPVOID data)
{  //printing no.s demo
	for (int i = 20; i < 30; i++)
		cout << " " << i;
	Sleep(4000);
	return 0;


}
DWORD WINAPI thread_function1(LPVOID data)
{  //printing no.s demo
	for (int i = 0; i < 10; i++)
		cout << " " << i;
	Sleep(3000);
	return 0;
}
int main()
{
	DWORD thid1, thid2;
	HANDLE hThread, hThread1;
	HANDLE arry_hand[2];
	hThread = CreateThread(NULL, 0, thread_function, NULL, 0, &thid1);//(Sec_atts is NULL when handle cant be inherited,stack size 0(default),,ptr to be passed to thread,dwcreationflags,threadid)
	if (hThread == NULL)
		cout << "thread creation unsuccessful(%d)" << GetLastError() << endl;
	else
		cout << "thread successfully created\n" << endl;

	hThread1 = CreateThread(NULL, 0, thread_function1, NULL, 0, &thid2);
	if (hThread1 == NULL)
		cout << "thread creation unsuccessful(%d)" << GetLastError() << endl;
	else
		cout << "thread successfully created\n" << endl;
	DWORD ret=WaitForMultipleObjects(2, arry_hand, FALSE, INFINITE);//no.of obj handles,array,whether to wait for all objects,msecs
	switch (ret)
	{
	case WAIT_OBJECT_0 + 0:cout << "Thread 1 terminated" << endl;
		break;
	case WAIT_OBJECT_0 + 1:cout << "Thread 2 terminated" << endl;
		break;
	case WAIT_FAILED:cout << "WAIT failed" << endl;
		break;
	case WAIT_TIMEOUT:cout << "wait Timeout" << endl;
		break;
	}
	getchar();
	CloseHandle(hThread);
	CloseHandle(hThread1);
	return 0;
}
