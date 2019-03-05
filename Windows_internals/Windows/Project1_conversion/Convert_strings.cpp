#include<stdio.h>
#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;

int main()   //ANSI needs many codepages based on lang. (8 bits) UNICODE MAX 32bits(4 bytes) //variable with encoding possible UTF8,UTF16
{
	WCHAR wideArray[25];//65536 values to UNICODE,2/4 bytes 
	CHAR charArray[25];//256 values ANSI
	int x,y,res;

	cout << "enter wchar array\n";
	wcin >> wideArray;
	cout << "enter char array\n";
	cin >> charArray;

	//Checking if the given array is unicode or not
	x = IsTextUnicode(wideArray, wcslen(wideArray), NULL);
	if (x == 0)
		printf("%S is not unicode text\n", wideArray);
	else
		printf("%S is unicode text\n", wideArray);

	y = IsTextUnicode(charArray, strlen(charArray), NULL);
	if (y == 0)
		printf("%s is not unicode text\n", charArray);
	else
		printf("%s is unicode text\n", charArray);

	//Converting  MultiByte to WideCharacter Array
	int req = MultiByteToWideChar(CP_UTF8, 0, charArray, -1, NULL, 0);//returns size of given Multibyte array
	printf("Size required = %d\n", req);
	if (req == 0)
		cout << "Error occured " << GetLastError();
	WCHAR *wideArray2 = new WCHAR[req];//allocating space for new widearray
	res = MultiByteToWideChar(CP_UTF8, 0, charArray, strlen(charArray), wideArray2, req);
	if (res == 0)
		cout << "MultiByte is not converted to WideCharacter\n";
	else
	{
		cout << "MultiByte is converted to WideCharacter\n" << endl;
		wcout << wideArray2;
		//_tprintf(_T("%S"), wideArray2);
	}

	//converting WideCharacter to MultiByte 
	req = WideCharToMultiByte(CP_UTF8, 0, wideArray, -1, NULL, 0, NULL, NULL);
	if (req == 0)
		cout << "Error occured " << GetLastError();
	CHAR *charArray2 = new CHAR[req];
	printf("Required bytes = %d\n", req);
	res = WideCharToMultiByte(CP_UTF8, 0, wideArray, -1, charArray2, req, NULL, NULL);
	if (res == 0)
		cout << "WideCharacter is not converted to MultiByte\n";
	else
		cout << "WideCharacter is converted to MultiByte\n"<<endl<<charArray2;

	return 0;
}