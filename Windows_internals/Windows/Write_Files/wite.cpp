#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#define BUFFSIZE 100
int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hFile;
	TCHAR buffer[BUFFSIZE]=L"hellloooo";
	hFile = CreateFile(
		argv[1],
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("file doesn't exist.error(%d)"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("file (%s) opened successfully"), argv[1]);
	DWORD nbr;
	//ZeroMemory(buffer, BUFFSIZE);
	BOOL ret = WriteFile(hFile, buffer, sizeof(buffer), &nbr, NULL);
	if (ret == 0)
	{
		_tprintf(_T("file cant be read.error(%d)"), GetLastError());
		getchar();
		return FALSE;
	}
	printf("text is : %S", buffer);
	getchar();
	return 0;

}