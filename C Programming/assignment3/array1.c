#include<stdio.h>
int main()
{
    int n,i=0,a[80],sum,sum1=0,j;
    scanf("%d",&n);
    printf("enter array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter req sum");
    scanf("%d",&sum);
    sum1=a[0];
    i=0;
    for(j=1;(j<n && sum1 != sum);)
    {
        if(sum1>sum)
        {
            sum1=sum1-a[i];
            i++;
        }
        else
        {
            sum1+=a[j];
            j++;
        }

    }
    printf("%d %d are indexes",i,j-1);

return 0;
}
