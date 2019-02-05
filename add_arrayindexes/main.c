#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[80],c,d,n,i,sum=0;
    printf("enter array size");
    scanf("%d",&n);
    printf("enter els");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter indexes");
    scanf("%d",&c);
    scanf("%d",&d);
    if((c<n)&&(d<n))
    {
        for(i=c;i<=d;i++)
        {
            sum=sum+a[i];
        }

    }
    printf("result is %d",sum);

    return 0;
}
