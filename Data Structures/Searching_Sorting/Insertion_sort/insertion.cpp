#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int size, i, j, temp_var;
	cout << "enter size\n";
	cin >> size;
	int *a = (int *)malloc(size * sizeof(int));//dma
	cout << "enter array elements" << " ";
	for (i = 0; i < size; i++)
		cin >> a[i];
	for (i = 1; i < size; i++)
	{
		temp_var = a[i];//for inner loop
		j = i - 1;
		while (j >= 0 && a[j] > temp_var)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp_var;
	}
	cout << "after sorting elements are\n";
	for (i = 0; i < size; i++)
		cout << a[i] << " ";
		system("pause");
	return 0;
}