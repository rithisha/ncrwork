#include<stdio.h>
#include<iostream>
using namespace std;
int partition(int a[], int low, int high)
{
	int pivot = a[low];
	int i = low + 1, j = high, t;
	while (1)
	{
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		else
			break;
	}
	t = a[j];
	a[j] = pivot;
	a[low] = t;
	return j;

}
void Quicksort(int a[], int i, int n)
{
	if (i < n)
	{
		int j = partition(a, i, n);
		Quicksort(a, i, j - 1);
		Quicksort(a, j + 1, n);
	}
}
int main()
{
	int size, i;
	cout << "enter size of array\n";
	cin >> size;
	int *a = (int *)malloc(size * sizeof(int));//dma
	cout << "enter array elements" << " ";
	for (i = 0; i < size; i++)
		cin >> a[i];
	Quicksort(a, 0, size-1);
	cout << "after sorting elements are\n";
	for (i = 0; i < size; i++)
		cout << a[i] << " ";
	system("pause");
	return 0;
}