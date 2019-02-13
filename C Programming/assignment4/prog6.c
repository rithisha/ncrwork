#include<stdio.h>
void main()
{
char s[100];
int l;
gets(s);
l=strlen(s);
reverse(s,0,l-1);
printf("%s",s);
}
reverse(char a[], int i,int j)
{char temp;

if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
i++;
j--;
reverse(a,i,j);
}
else
return 0;
//printf("%s",a);

}