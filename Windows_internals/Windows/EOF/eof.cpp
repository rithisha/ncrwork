#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#define BUFFSIZE 100
int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hFile;
	TCHAR buffer[BUFFSIZE];
	hFile = CreateFile(
		argv[1],
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
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
	while(1)
	{
	ZeroMemory(buffer, sizeof(buffer));
	BOOL ret = ReadFile(hFile, buffer, BUFFSIZE, &nbr, NULL);
	if (ret == 0)
	{
		_tprintf(_T("file cant be read.error(%d)"), GetLastError());
		getchar();
		return FALSE;
	}
	if (ret&&nbr == 0)
	{
		_tprintf(_T("EOF REACHED\n"));
		break;
	}
	_tprintf(_T("text is : %S"), buffer);
	}

	
	getchar();
	return 0;

}