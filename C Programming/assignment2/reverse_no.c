#include <stdio.h>
int main()
{
    int n,rem,reverse = 0;
     scanf("%d", &n);

    while (n > 0)
    {
        rem= n % 10;
        reverse = reverse * 10 + rem;
        n=n/10;
    }
    printf("reverse is  = %d", reverse);
    return 0;
}
