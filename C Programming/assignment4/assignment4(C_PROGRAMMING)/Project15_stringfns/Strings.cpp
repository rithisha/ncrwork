#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

void strcpy1(char *s2, char *s1)
{
	while (*s1)
	{
		*s2 = *s1;
		*s2++;
		*s1++;
	}
	*s2 = '\0';
}
void strcat1(char *s1, char *s2)
{
	while (*s1)//till end of main string
	{
		*s1++;
	}
	while (*s2)
	{
		*s1 = *s2;
		*s2++;
		*s1++;
	}
	*s1 = '\0';
}
int strcmp1(char *s1, char *s2)
{
	char *a, *b;
	a = s1, b = s2;
	while (*s1++ == *s2++)
	{
		if ((*s1) == '\0')
			return 0;
	}
	//*s1--; *s2--;
	if ((*a - *b) > 0)
		return 1;
	else
		return -1;
}
void strrev1(char *str)
{
	char *p, *q, ch;
	p = str; q = str;
	int length, i;
	for (length = 0; str[length] != '\0'; ++length);

	for (i = 0; i < length - 1; i++)
		q++;
	for (i = 0; i < length / 2; i++)
	{
		ch = *p;
		*p = *q;
		*q = ch;
		p++;
		q--;
	}
}
int main()
{
	char *s,*s1=NULL;
	int c, res,size,size1;
	printf("enter size of input string\n");
	scanf("%d", &size);
	s = (char *)malloc(size * sizeof(char));
	printf("enter string\n");
	scanf("%s", s);//main string
	printf("enter choice 1.strrev 2.strcpy 3.strcat 4.strcmp\n");
	scanf("%d", &c);
	switch (c)
	{
	case 1:strrev1(s); printf("%s ", s);
		break;
	case 2:s1 = (char *)malloc(size * sizeof(char));
		strcpy1(s1, s); printf("%s ", s1);
		break;
	case 3:printf("enter size of string to concat\n");
		scanf("%d", &size1);
	     s1 = (char *)malloc(size1 * sizeof(char));
		printf("enter string to concat\n");
		scanf("%s",s1 );
		strcat1(s, s1); printf("%s", s);
		break;
	case 4:printf("enter string2\n"); scanf("%s", s1);
		res = strcmp1(s, s1);
		if (res == 0)
			printf("equal");
		else if (res == 1)
			printf("%s is greater than %s", s, s1);
		else if (res == -1)
			printf("%s is less than %s", s, s1);
		break;
	}
	getchar();
	return 0;
}
