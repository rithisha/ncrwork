#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<shellapi.h>
#include<iostream>
using namespace std;
void DumpEnvString(PTSTR pEnvBlock[])
{
	int current = 0;
	PTSTR pCurr = NULL;
	PTSTR *pEle = (PTSTR *) pEnvBlock;
	while (pEle != NULL)
	{
		pCurr = (PTSTR)(*pEle);
		if (pCurr == NULL)
		{
			pEle = NULL;
		}
		else
		{
			printf(" %S\n",pCurr);
			current++;
			pEle++;
			
		}
		pEle++;
	}

}
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	DumpEnvString(env);
	TCHAR envVarString[] = TEXT("%SystemRoot%");
	TCHAR buff[MAX_PATH];
	DWORD ret;
	ret = ExpandEnvironmentStrings(envVarString, buff, MAX_PATH);
	if (!ret)
	{
		printf("%d\n", GetLastError());
		getchar();
		return 0;
	}
	else
		wcout << buff;
	getchar();
	return 0;
}