#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int size, i, loc, j, min, t;//loc=minelement_location
	cout << "enter size\n";
	cin >> size;
	int *a = (int *)malloc(size * sizeof(int));//dma
	cout << "enter array elements" << " ";
	for (i = 0; i < size; i++)
		cin >> a[i];
	for (i = 0; i < size; i++)
	{
		min = a[i]; loc = i;
		for (j = i + 1; j < size; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				loc = j;
			}
		}

		t = a[i];
		a[i] = a[loc];
		a[loc] = t;
	}
	cout << "after sorting elements are\n";
	for (i = 0; i < size; i++)
		cout << a[i] << " ";
	system("pause");
	return 0;
}