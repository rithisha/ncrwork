#include<stdio.h>
#include<conio.h>
int main()
{
	int n, sum = 0;
	scanf_s("%d", &n);
	while (n > 0)
	{
		sum += n % 10;
		n = n / 10;
	}
	printf("sum is %d", sum);
	getchar();
	return 0;
}
//cdthgkjh