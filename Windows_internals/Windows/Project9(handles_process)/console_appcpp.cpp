#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
using namespace std;
int main()
{
	STARTUPINFO si;//structure 
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	HANDLE hFile;
	hFile=CreateFile()
	LPWSTR lp = NULL;
	lp = new WCHAR[100];
	wcscpy_s(lp, _countof(L"notepad"), L"notepad");
	if (!CreateProcess(NULL, lp, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		printf("createprocess error(%d)", GetLastError());
		getchar();
		return 0;
	}
	printf("handle of process %ld \n", pi.hProcess);
	printf("handle of process %ld \n", pi.dwProcessId);
	printf("handle of process %ld \n", pi.hThread);
	printf("handle of process %ld \n", pi.dwThreadId);
	printf("\n");
	delete lp;

	lp = new WCHAR[100];
	wcscpy_s(lp, _countof(L"calc.exe"), L"calc.exe");
	if (!CreateProcess(NULL, lp, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		printf("createprocess error(%d)", GetLastError());
		getchar();
		return 0;
	}
	printf("handle of process %ld \n", pi.hProcess);
	printf("handle of process %ld \n", pi.dwProcessId);
	printf("handle of process %ld \n", pi.hThread);
	printf("handle of process %ld \n", pi.dwThreadId);
	printf("\n");
	return 0;
}