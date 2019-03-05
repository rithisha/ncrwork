#include<stdio.h>

#include<iostream>
using namespace std;
void main()
{
	int size;
	cout << "enter array size" << endl;
	cin >> size;

	int  i, low, high, mid, ele, flag = 0;
	int *a=(int *)malloc(size*sizeof(int));//dma
	cout << "enter array elements" << endl;
	for (i = 0; i < size; i++)
		cin >> a[i];
	cout << "enter element";
	cin >> ele;
	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (ele < a[mid])
			high = mid - 1;
		else if (ele > a[mid])
			low = mid + 1;
		else
		{
			cout << "element found  " << endl;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << "element not found\n";
	system("pause");
}