#include<stdio.h>
#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	LPWSTR *szArglist;//long ptr to wide string
	int nArgs;
	szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);//The address returned by CommandLineToArgvW is addr of first ele in array of LPWSTR values
	if (NULL == szArglist)
	{
		cout << "CommandLineToArgvW process failed\n";
		return 0;
	}
	else
	{
		for (int i = 0; i < nArgs; i++)
		{
			cout << i << " ";
			wcout << szArglist[i] << endl;
		}
	}
		return 0;
}