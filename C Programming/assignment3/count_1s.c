#include<stdio.h>
#include<stdint.h>

int main()
{
 int8_t n;
 int count=0;
 scanf("%u",&n);
 while(n>0){
    if((n%2)|0)
        count++;
    n=n/2;
}
printf("The no. of 1's are %d",count);
return 0;
}
