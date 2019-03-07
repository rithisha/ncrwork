#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int size, i, j, t, flag;
	cout << "enter size of array\n";
	cin >> size;
	int *a = (int *)malloc(size * sizeof(int));//dma
	cout << "enter array elements" << " ";
	for (i = 0; i < size; i++)
		cin >> a[i];
	for (i = 0; i < size; i++)
	{
		flag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (a[i] > a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
				flag++;
			}
		}
		if (flag == 0)//if no swaps occurred,then already list is sorted,so avoid further iteration of i
			break;
	}
	cout << "after sorting elements are\n";
	for (i = 0; i < size; i++)
		cout << a[i] << " ";
	system("pause");
	return 0;
}