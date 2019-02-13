#include<stdio.h>
replace(char *c)
{
int i,count=0;
for(i=0;i<strlen(c);i++)
{
if(c[i]==' ')
{
c[i]='-';
count++;
}
}
printf("%s",c);
return count;

}

void main()
{
int n;
char *cat = "The cat sat";

n=replace(cat);
printf("\n%d",n);
}
