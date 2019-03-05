#include<stdio.h>
#include<Windows.h>
//#include "mylib1.h"
typedef int(*add_dll)(int, int);
typedef int(*subtract_dll)(int, int);
typedef int(*mul)(int, int);
typedef int(*divv)(int, int);
typedef int(*MYPROC)(int, int);
int main()
{
	HMODULE hd1;
	int sum, sub, mul,div;
	MYPROC ADD, SUB, MUL, DIV;
	hd1 = LoadLibraryEx(
		TEXT("C:\\Users\\Rithisha\\Desktop\\ncr training\\ncrwork\\Windows_internals\\Windows\\Debug\\DLL_Runtimelink.dll"),
		NULL,
		NULL
	);
	if (hd1 == NULL)
	{
		printf("load library failed %d", GetLastError());
		getchar();
		return 0;
	}
	ADD = (MYPROC)GetProcAddress(hd1, (LPSTR)"add_dll");
	if (ADD == NULL)
	{
		printf("cant call process add %d", GetLastError());
		getchar();
		return 0;
	}
	sum = ADD(10, 20);
	printf("sum %d", sum);
	SUB=(MYPROC)GetProcAddress(hd1, (LPSTR)"subtract_dll");
	if (SUB == NULL)
	{
		printf("cant call process SUB %d", GetLastError());
		getchar();
		return 0;
	}
	sub = SUB(10, 20);
	printf("difference is %d", sub);
    MUL = (MYPROC)GetProcAddress(hd1, (LPSTR)"mul");
	if(MUL==NULL)
	{
		printf("cant call process MUL %d", GetLastError());
		getchar();
		return 0;
	}
	mul = MUL(20, 10);
	printf("product is %d", mul);
	DIV = (MYPROC)GetProcAddress(hd1, (LPSTR)"divv");
	if (DIV == NULL)
	{
		printf("cant call process DIV %d", GetLastError());
		getchar();
		return 0;
	}
	div = DIV(20, 10);
	printf("quotient is %d", div);
	FreeLibrary(hd1);
	return 0;
}