#include<stdio.h>
#include<iostream>
using namespace std;
void merge(int a[], int i1, int mid, int high)
{
	int i, k, l = 0;
	i = i1;
	k = mid + 1;
	int *b;
	b = new int[high - i1 + 1];
	while (i <= mid && k <= high)
	{
		if (a[i] < a[k])
			b[l++] = a[i++];
		else
			b[l++] = a[k++];
	}
	while (i <= mid)
		b[l++] = a[i++];
	while (k <= high)
		b[l++] = a[k++];
	l = 0;
	for (i = i1; i <= high; i++)
		a[i] = b[l++];
}
void mergeSort(int a[], int low, int high)
{
	if (low < high)
	{
		int mid;
		mid = (low+high)/2;
		mergeSort(a,low, mid);
		mergeSort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

int main()
{
	int size, i, loc, j, min, t;
	cout << "enter size\n";
	cin >> size;
	int *a = (int *)malloc(size * sizeof(int));//dma
	cout << "enter array elements" << " ";
	for (i = 0; i < size; i++)
		cin >> a[i];
	mergeSort(a, 0, size-1);
	cout << "after sorting elements are\n";
	for (i = 0; i < size; i++)
		cout << a[i] << " ";
	system("pause");
	return 0;
}