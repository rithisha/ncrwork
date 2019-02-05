#include<stdio.h>
int main()
{
	int n, sum = 0;
	scanf_s("%d", &n);
	while (n > 0)
	{
		sum += n % 10;
		n = n / 10;
	}
	printf_s("sum is %d", sum);
	return 0;
}