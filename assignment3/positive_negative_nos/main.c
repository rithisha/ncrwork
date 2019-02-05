#include <stdio.h>
#include <stdlib.h>
void arrange(int a[],int n)
{
    int j=0,i,temp;
    for(i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            if(i!=j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
            j++;
        }

    }
}
int main()
{  int n,i,a[80];
   printf("enter array size");
    scanf("%d",&n);
    printf("enter els");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
     arrange(a,n);
    printf("sorted array");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);

    }



        return 0;
}
