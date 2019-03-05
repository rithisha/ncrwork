#include<Windows.h>
#include<stdio.h>
#include "mylib1.h"
#include<iostream>
using namespace std;
BOOL WINAPI main_runtimelink(HANDLE h, DWORD msg, LPVOID res)
{
	switch (msg)
	{
	case DLL_PROCESS_ATTACH:
		printf("DLL PROCESS ATTACHED");
		break;
	case DLL_PROCESS_DETACH:
		printf("DLL PROCESS DETACHED");
		break;
	case DLL_THREAD_ATTACH:
		printf("DLL THREAD ATTACHED");
		break;
	case DLL_THREAD_DETACH:
		printf("DLL THREAD DETACHED");
		break;
	}
	return TRUE;
}

