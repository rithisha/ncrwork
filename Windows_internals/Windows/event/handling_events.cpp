#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
using namespace std;
int main()
{
	HANDLE g_hEvent = CreateEvent(
		NULL,
		FALSE,
		FALSE,
		TEXT("namedevent")
	);
	if (g_hEvent != NULL)
		printf("opened\n");
	getchar();
	return 0;
}