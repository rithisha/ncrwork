#include<stdio.h>
void main()
{
char s[100];
int i;
printf("enter string");
gets(s);
for(i=0;s[i]!='\0';i++)
{
if(s[i]>=65&&s[i]<=90)
{
(s[i]=s[i]+32);
}
else if(s[i]>=97&&s[i]<=122)
{
s[i]=s[i]-32;
}
}
puts(s);
}